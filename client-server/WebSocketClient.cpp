/*
 * WebSocketClient.cpp
 *
 *  Created on: Dec 13, 2013
 *      Author: vassik
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <syslog.h>
#include <pthread.h>
#include <list>

#include "libwebsockets/lws_config.h"
#include "libwebsockets/libwebsockets.h"

#include "WebSocketClient.h"
#include "../libs/Utility.h"
#include "../libs/Log.h"

#include "WebSocketFacade.h"

using namespace WebSockets;
using namespace std;

WebSocketClient::WebSocketClient(WebSocketFacade* facade, const char* host, int port, const char* subprotocol) : WebSocket(port) {
	this->host = host;
	this->subprotocol = subprotocol;
	this->context = NULL;
	this->wsi = NULL;
	this->force_exit = 0;
	this->facade = facade;
	this->facade->addWebSocketClient(this);
	this->messageToSend = NULL;
	this->is_connected = 0;
}

WebSocketClient::~WebSocketClient(){}

void WebSocketClient::Destroy(){
	Log::Write(LogLevel_Debug, "WebSocketClient::Destroy() : destroying object 0x%08x", this);
	delete this;
}

int WebSocketClient::getPort(){
	return WebSocket::getPort();
}

int WebSocketClient::open(){
	if(this->is_connected){
		Log::Write(LogLevel_Info, "WebSocketClient::open() : client 0x%08x is already connected...\n", this);
		return 1;
	}
	int use_ssl = 0;
	int ietf_version = -1; /* latest */
	struct lws_context_creation_info info;
	pthread_t thread;
	this->force_exit = 0;

	memset(&info, 0, sizeof info);

	static struct libwebsocket_protocols protocols[] = {
		{
			this->subprotocol, /* name */
			callback_web_socket_client, /* callback */
			sizeof(struct per_session_data__lws_mirror), /* per_session_data_size */
			128, /* max frame size / rx buffer */
		},
		{ NULL, NULL, 0, 0 } /* terminator */
	};

	info.port = CONTEXT_PORT_NO_LISTEN;
	info.protocols = protocols;
#ifndef LWS_NO_EXTENSIONS
	info.extensions = libwebsocket_get_internal_extensions();
#endif
	info.gid = -1;
	info.uid = -1;

	this->context = libwebsocket_create_context(&info);
	if (this->context == NULL) {
		Log::Write(LogLevel_Error, "WebSocketClient::open() : creating libwebsocket context failed\n");
		return 1;
	}

	/* create a client websocket using dumb increment protocol */

	this->wsi = libwebsocket_client_connect(this->context, this->host, this->getPort(), use_ssl,
			"/", this->host, this->host,
			this->subprotocol, ietf_version);

	if (this->wsi == NULL) {
		Log::Write(LogLevel_Error, "WebSocketClient::open() : libwebsocket connect failed for client %d\n");
		libwebsocket_context_destroy(this->context);
		return 0;
	}

	Log::Write(LogLevel_Info, "WebSocketClient::open() : client 0x%08x is waiting for connect...\n", this);
	int iret1 = pthread_create(&thread, NULL, &startServicing, this);
	return iret1;
}

int WebSocketClient::close(){
	this->force_exit = 1;
	return 0;
}

int WebSocketClient::sendMessage(const char* message) {
	if(!this->is_connected){
		Log::Write(LogLevel_Info, "WebSocketClient::sendMessage() : client is not connected, can not send anything ...");
		return 1;
	}
	this->messageToSend = message;
	libwebsocket_callback_on_writable(this->context, this->wsi);
	return 0;
}

int WebSocketClient::callback_web_socket_client(struct libwebsocket_context *context,
			struct libwebsocket *wsi,
			enum libwebsocket_callback_reasons reason,
					       void *user, void *in, size_t len){

	if(wsi != NULL){
		WebSocketFacade* poll = WebSocketFacade::Get();
		WebSocketClient* client = NULL;
		list<WebSocketClient*> clients = poll->GetWebSocketClients();
		for(list<WebSocketClient*>::iterator it = clients.begin(); it != clients.end(); ++it){
			WebSocketClient* wsc_buf = (WebSocketClient*) (*it);
			if(wsi == wsc_buf->wsi){
				client = wsc_buf;
				break;
			}
		}

		if(client == NULL)
			Log::Write(LogLevel_Info, "WebSocketClient::callback_web_socket_client() : can not find a client connected to the socket 0x%08x\n", wsi);

		switch (reason) {
			case LWS_CALLBACK_CLIENT_ESTABLISHED: {
					Log::Write(LogLevel_Info, "WebSocketClient::callback_web_socket_client() :  LWS_CALLBACK_CLIENT_ESTABLISHED for the client 0x%08x\n", client);
					client->onOpen();
					client->is_connected = 1;
				} break;
			case LWS_CALLBACK_CLOSED: {
					Log::Write(LogLevel_Info, "WebSocketClient::callback_web_socket_client() : LWS_CALLBACK_CLOSED for the client 0x%08x\n", client);
					client->close();
					client->onClose();
					client->is_connected = 0;
				} break;
			case LWS_CALLBACK_CLIENT_RECEIVE: {
					Log::Write(LogLevel_Info, "WebSocketClient::callback_web_socket_client() : LWS_CALLBACK_CLIENT_RECEIVE for the client 0x%08x\n", client);
					client->onMessage((char*) in);
				} break;
			case LWS_CALLBACK_CLIENT_WRITEABLE: {
					if(client->messageToSend != NULL){
						int message_size = strlen(client->messageToSend);
						unsigned char *payload = (unsigned char*) malloc(LWS_SEND_BUFFER_PRE_PADDING + message_size + LWS_SEND_BUFFER_POST_PADDING);
						memcpy(payload + LWS_SEND_BUFFER_PRE_PADDING, client->messageToSend, message_size);
						int n = libwebsocket_write(wsi, (unsigned char *) payload + LWS_SEND_BUFFER_PRE_PADDING, message_size, LWS_WRITE_TEXT);
						free(payload);
						if (n < 0){
							Log::Write(LogLevel_Error, "WebSocketClient::callback_web_socket_client() : failed to write string to the socket for the client 0x%08x\n", client);
							return -1;
						}

						if (n < message_size) {
							Log::Write(LogLevel_Error, "WebSocketClient::callback_web_socket_client() : partial write to the socket by  0x%08x\n", client);
							return -1;
						}
						client->messageToSend = NULL;
					}else{
						Log::Write(LogLevel_Info, "WebSocketClient::callback_web_socket_client() : nothing to send by 0x%08x\n", client);
					}
				} break;
			default:
				break;
		}
	}

	return 0;
}

void WebSocketClient::setCallbacks(ThingMLCallback* _onopen,
		ThingMLCallback* _onclose,
		ThingMLCallback* _onmessage,
		ThingMLCallback* _onerror){
	this->setObserver(_onopen, _onclose, _onmessage, _onerror);
}

void WebSocketClient::onOpen(){
	this->observer->onOpen();
}

void WebSocketClient::onClose(){
	this->observer->onClose();
}

void WebSocketClient::onError(const char* error){
	this->observer->onError(error);
}

void WebSocketClient::onMessage(const char* message){
	this->observer->onMessage(message);
}

void* WebSocketClient::startServicing(void *ptr){
	WebSocketClient* client = (WebSocketClient*) ptr;
	int n = 0;
	while (n >= 0 && !client->force_exit) {
		n = libwebsocket_service(client->context, 50);
	}
	Log::Write(LogLevel_Debug, "WebSocketClient::startServicing() : client 0x%08x stops servicing\n", client);
	libwebsocket_context_destroy(client->context);
	return NULL;
}
