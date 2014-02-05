/*
 * WebSocketMirrorServer.cpp
 *
 *  Created on: Dec 7, 2013
 *      Author: vassik
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <syslog.h>
#include <pthread.h>

#include "WebSocketMirrorServer.h"
#include "WebSocketFacade.h"
#include "../libs/Log.h"
#include "libwebsockets.h"
#include "../libs/Constants.h"
#include "../libs/Utility.h"

using namespace WebSockets;


WebSocketMirrorServer* WebSocketMirrorServer::s_instance = NULL;
const char* WebSocketMirrorServer::web_socket_subprotocol = LWS_MIRROR_PROTOCOL;

WebSocketMirrorServer* WebSocketMirrorServer::Init(WebSocketFacade* facade, int _port, const char* subprotocol) {
	if(s_instance == NULL){
		s_instance = new WebSocketMirrorServer(facade, _port, subprotocol);
	}
	return s_instance;
}

WebSocketMirrorServer* WebSocketMirrorServer::Get(){
	return s_instance;
}

WebSocketMirrorServer* WebSocketMirrorServer::setCallbacks(ThingMLCallback* _onopen,
		ThingMLCallback* _onclose,
		ThingMLCallback* _onmessage,
		ThingMLCallback* _onerror){
	WebSocketMirrorServer* server = WebSocketMirrorServer::Get();
	if(server != NULL){
		server->setObserver(_onopen, _onclose, _onmessage, _onerror);
	}
	return server;
}

void WebSocketMirrorServer::Halt(){
	WebSocketMirrorServer *wss = WebSocketMirrorServer::Get();
	Log::Write(LogLevel_Debug, "WebSocketMirrorServer::Destroy() : destroying object 0x%08x", wss);
	if(s_instance != NULL){
		wss->Destroy();
		s_instance = NULL;
	}
}

void WebSocketMirrorServer::Destroy(){
	WebSocket::Destroy();
}

void WebSocketMirrorServer::reset(){
	this->ringbuffer_head = 0;
	this->context = NULL;
	for (int n = 0; n < MAX_MESSAGE_QUEUE; n++){
		this->ringbuffer[n].payload = NULL;
		this->ringbuffer[n].len = 0;
	}
}

WebSocketMirrorServer::WebSocketMirrorServer(WebSocketFacade* facade, int _port, const char* subprotocol) : WebSocket(_port){
	s_instance = this;
	this->subprotocol = (subprotocol == NULL) ? web_socket_subprotocol : subprotocol;
	this->ringbuffer_head = 0;
	this->context = NULL;
	this->force_exit = 0;
	for (int n = 0; n < MAX_MESSAGE_QUEUE; n++){
		this->ringbuffer[n].payload = NULL;
		this->ringbuffer[n].len = 0;
	}
	facade->setWebSocketMirrorServer(this);
}

int WebSocketMirrorServer::getPort(){
	return WebSocket::getPort();
}

WebSocketMirrorServer::~WebSocketMirrorServer(){
	Log::Write(LogLevel_Debug, "WebSocketMirrorServer:::~WebSocketMirrorServer() : destroying object 0x%08x", this);
}


int WebSocketMirrorServer::open(){
	pthread_t thread;
	this->force_exit = 0;
	const char *iface = NULL;
	struct lws_context_creation_info info;

	static struct libwebsocket_protocols protocols[] = {
		{
			web_socket_subprotocol, /* name */
			callback_web_socket_server, /* callback */
			sizeof(struct per_session_data__lws_mirror), /* per_session_data_size */
			128, /* max frame size / rx buffer */
		},
		{ NULL, NULL, 0, 0 } /* terminator */
	};

	memset(&info, 0, sizeof info);
	info.port = this->getPort();
	info.iface = iface;
	info.protocols = protocols;

#ifndef LWS_NO_EXTENSIONS
	info.extensions = libwebsocket_get_internal_extensions();
#endif

	info.ssl_cert_filepath = NULL;
	info.ssl_private_key_filepath = NULL;

	info.gid = -1;
	info.uid = -1;
	info.options = 0;

	context = libwebsocket_create_context(&info);
	if (context == NULL) {
		lwsl_err("libwebsocket init failed\n");
		return -1;
	}

	int iret1 = pthread_create( &thread, NULL, &startServicing, this);
	return iret1;
}

void* WebSocketMirrorServer::startServicing(void* arg){
	WebSocketMirrorServer* wss = (WebSocketMirrorServer*) arg;
	int n = 0;
	while (n >= 0 && !wss->force_exit) {
		n = libwebsocket_service(wss->context, 50);
	}
	Log::Write(LogLevel_Debug, "WebSocketMirrorServer stops servicing\n");
	libwebsocket_context_destroy(wss->context);

	lwsl_notice("libwebsockets-test-server exited cleanly\n");
	return NULL;
}

int WebSocketMirrorServer::close(){
	force_exit = 1;
	return 0;
}

int WebSocketMirrorServer::sendMessage(const char* message){
	return 0;
}

void WebSocketMirrorServer::onClose(){
	this->observer->onClose();
}

void WebSocketMirrorServer::onError(const char* error){
	this->observer->onError(error);
}

void WebSocketMirrorServer::onMessage(const char* message){
	this->observer->onMessage(message);
}

void WebSocketMirrorServer::onOpen(){
	this->observer->onOpen();
}


int WebSocketMirrorServer::callback_web_socket_server(struct libwebsocket_context *context,
		struct libwebsocket *wsi,
		enum libwebsocket_callback_reasons reason,
				       void *user, void *in, size_t len){
	int n;
	WebSocketMirrorServer* wss = WebSocketMirrorServer::Get();
	struct per_session_data__lws_mirror *pss = (struct per_session_data__lws_mirror *) user;

	switch (reason) {

		case LWS_CALLBACK_ESTABLISHED:
			lwsl_info("callback_lws_mirror: LWS_CALLBACK_ESTABLISHED\n");
			pss->ringbuffer_tail = wss->ringbuffer_head;
			pss->wsi = wsi;
			wss->onOpen();
			break;

		case LWS_CALLBACK_PROTOCOL_DESTROY:
			lwsl_notice("mirror protocol cleaning up\n");
			wss->reset();
			wss->onClose();
			break;

		case LWS_CALLBACK_SERVER_WRITEABLE:
			while (pss->ringbuffer_tail != wss->ringbuffer_head) {

				n = libwebsocket_write(wsi, (unsigned char *)
						wss->ringbuffer[pss->ringbuffer_tail].payload +
					   LWS_SEND_BUFFER_PRE_PADDING,
					   wss->ringbuffer[pss->ringbuffer_tail].len,
									LWS_WRITE_TEXT);
				if (n < (int) wss->ringbuffer[pss->ringbuffer_tail].len) {
					const char *error_message = "ERROR writing to mirror socket";
					lwsl_err("%s\n", error_message);
					wss->onError(error_message);
					return -1;
				}
				if (n < (int) wss->ringbuffer[pss->ringbuffer_tail].len){
					const char *error_message = "mirror partial write";
					lwsl_err("%s %d vs %d\n", error_message,
							n, wss->ringbuffer[pss->ringbuffer_tail].len);
					wss->onError(error_message);
				}

				if (pss->ringbuffer_tail == (MAX_MESSAGE_QUEUE - 1))
					pss->ringbuffer_tail = 0;
				else
					pss->ringbuffer_tail++;

				if (((wss->ringbuffer_head - pss->ringbuffer_tail) &
					  (MAX_MESSAGE_QUEUE - 1)) == (MAX_MESSAGE_QUEUE - 15))
					libwebsocket_rx_flow_allow_all_protocol(
							   libwebsockets_get_protocol(wsi));

				if (lws_send_pipe_choked(wsi)) {
					libwebsocket_callback_on_writable(context, wsi);
					break;
				}
			}
			break;

		case LWS_CALLBACK_RECEIVE:
			if (((wss->ringbuffer_head - pss->ringbuffer_tail) &
					  (MAX_MESSAGE_QUEUE - 1)) == (MAX_MESSAGE_QUEUE - 1)) {
				const char *error_message = "LWS_CALLBACK_RECEIVE: throttling!\n";;
				lwsl_err(error_message);
				wss->onError(error_message);
				goto choke;
			}

			if (wss->ringbuffer[wss->ringbuffer_head].payload)
				free(wss->ringbuffer[wss->ringbuffer_head].payload);

			wss->ringbuffer[wss->ringbuffer_head].payload =
					malloc(LWS_SEND_BUFFER_PRE_PADDING + len +
							  LWS_SEND_BUFFER_POST_PADDING);
			wss->ringbuffer[wss->ringbuffer_head].len = len;
			memcpy((char *)wss->ringbuffer[wss->ringbuffer_head].payload +
						  LWS_SEND_BUFFER_PRE_PADDING, in, len);
			if (wss->ringbuffer_head == (MAX_MESSAGE_QUEUE - 1))
				wss->ringbuffer_head = 0;
			else
				wss->ringbuffer_head++;

			if (((wss->ringbuffer_head - pss->ringbuffer_tail) &
					  (MAX_MESSAGE_QUEUE - 1)) != (MAX_MESSAGE_QUEUE - 2))
				goto done;

choke:
			libwebsocket_rx_flow_control(wsi, 0);

done:
			libwebsocket_callback_on_writable_all_protocol(
							   libwebsockets_get_protocol(wsi));
			wss->onMessage((char*) in);
			break;

		case LWS_CALLBACK_FILTER_PROTOCOL_CONNECTION:
			Log::Write(LogLevel_Info, "WebSocketMirrorServer() : handshake\n");
			break;

		default:
			break;
	}

	return 0;
}
