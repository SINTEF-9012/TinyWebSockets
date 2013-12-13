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

#include "WebSocketClient.h"
#include "../libwebsockets/libwebsockets.h"
#include "../sockets/WebSocket.h"
#include "../libs/Utility.h"
#include "../libs/Log.h"

using namespace WebSockets;
using namespace std;

WebSocketClient::WebSocketClient(WebSocketClientPoll* client_poll, char* host, int port, char* subprotocol) : WebSocket(port) {
	this->host = host;
	this->subprotocol = subprotocol;
	this->context = NULL;
	this->wsi = NULL;
	this->force_exit = 0;
	this->client_poll = client_poll;
	this->client_poll->appendClient(this);
}

WebSocketClient::WebSocketClient(int port) : WebSocket(port){
	this->host = NULL;
	this->subprotocol = NULL;
	this->context = NULL;
	this->wsi = NULL;
	this->force_exit = 0;
	this->client_poll = NULL;
}

WebSocketClient::~WebSocketClient(){

}

void WebSocketClient::Destroy(){
	Log::Write(LogLevel_Debug, "WebSocketClient::Destroy() : destroying object 0x%08x", this);
	delete this;
}

int WebSocketClient::getPort(){
	return WebSocket::getPort();
}

int WebSocketClient::open(){
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


	/*
	 * create the websockets context.  This tracks open connections and
	 * knows how to route any traffic and which protocol version to use,
	 * and if each connection is client or server side.
	 *
	 * For this client-only demo, we tell it to not listen on any port.
	 */

	info.port = this->getPort();
	info.protocols = protocols;
#ifndef LWS_NO_EXTENSIONS
	info.extensions = libwebsocket_get_internal_extensions();
#endif
	info.gid = -1;
	info.uid = -1;

	this->context = libwebsocket_create_context(&info);
	if (this->context == NULL) {
		Log::Write(LogLevel_Error, "Creating libwebsocket context failed\n");
		return 1;
	}

	/* create a client websocket using dumb increment protocol */

	this->wsi = libwebsocket_client_connect(context, this->host, this->getPort(), use_ssl,
			"/", this->host, this->host,
			this->subprotocol, ietf_version);

	if (this->wsi == NULL) {
		Log::Write(LogLevel_Error, "libwebsocket connect failed for client %d\n");
		libwebsocket_context_destroy(this->context);
		return 0;
	}

	Log::Write(LogLevel_Info, "Client 0x%08x is waiting for connect...\n", this);

	/*
	 * sit there servicing the websocket context to handle incoming
	 * packets, and drawing random circles on the mirror protocol websocket
	 * nothing happens until the client websocket connection is
	 * asynchronously established
	 */
	int iret1 = pthread_create(&thread, NULL, &startServicing, this);
	return iret1;
}

int WebSocketClient::close(){
	this->force_exit = 1;
	return 0;
}

int WebSocketClient::sendMessage(char* message) {
	libwebsocket_callback_on_writable(this->context, this->wsi);
	return 0;
}

int WebSocketClient::callback_web_socket_client(struct libwebsocket_context *context,
			struct libwebsocket *wsi,
			enum libwebsocket_callback_reasons reason,
					       void *user, void *in, size_t len){

	WebSocketClientPoll* poll = WebSocketClientPoll::Get();
	WebSocketClient* client = NULL;
	list<WebSocket*> clients = poll->getClients();
	for(list<WebSocket*>::iterator it = clients.begin(); it != clients.end(); ++it){
		if(dynamic_cast<WebSocketClient*>(*it)){
			WebSocketClient* wsc_buf = (WebSocketClient*) (*it);
			if(wsi == wsc_buf->wsi){
				client = wsc_buf;
			}
		}
	}

	if(client == NULL){
		Log::Write(LogLevel_Error, "WebSocketClient::callback_web_socket_client can not locate client in the poll\n");
		return 0;
	}

	switch (reason) {
		case LWS_CALLBACK_CLIENT_ESTABLISHED: {
				Log::Write(LogLevel_Info, "callback_lws_mirror: LWS_CALLBACK_CLIENT_ESTABLISHED\n");
				client->onOpen();
				//libwebsocket_callback_on_writable(context, wsi);
			} break;
		case LWS_CALLBACK_CLOSED: {
				Log::Write(LogLevel_Info, "WS_CALLBACK_CLOSED\n");
				client->onClose();
			} break;
		case LWS_CALLBACK_CLIENT_RECEIVE: {
				Log::Write(LogLevel_Info, "LWS_CALLBACK_CLIENT_RECEIVE\n");
				client->onMessage((char*) in);
			} break;
		case LWS_CALLBACK_CLIENT_WRITEABLE: {
				char *message = "hello!hello!hello!hello!hello!hello!hello!hello!hello!";
				int message_size = strlen(message);
				printf("%s - %d\n", message, message_size);

				void *payload = malloc(LWS_SEND_BUFFER_PRE_PADDING + message_size + LWS_SEND_BUFFER_POST_PADDING);

				memcpy(payload + LWS_SEND_BUFFER_PRE_PADDING, message, message_size);
				int n = libwebsocket_write(wsi, (unsigned char *) payload + LWS_SEND_BUFFER_PRE_PADDING, message_size, LWS_WRITE_TEXT);
				free(payload);
				if (n < 0){
					Log::Write(LogLevel_Error, "failed to write string to the socket for the client 0x%08x\n", client);
					return -1;
				}

				if (n < message_size) {
					Log::Write(LogLevel_Error, "Partial write to the socket by  0x%08x\n", client);
					return -1;
				}
			} break;
		default:
			break;
	}

	return 0;
}

void WebSocketClient::onOpen(){
	this->observer->onOpen();
}

void WebSocketClient::onClose(){
	this->observer->onClose();
}

void WebSocketClient::onError(char* error){
	this->observer->onError(error);
}

void WebSocketClient::onMessage(char* message){
	this->observer->onMessage(message);
}

void* WebSocketClient::startServicing(void *ptr){
	WebSocketClient* client = (WebSocketClient*) ptr;
	int n = 0;
	while (n >= 0 && !client->force_exit) {
		n = libwebsocket_service(client->context, 10);
	}
	Log::Write(LogLevel_Debug, "WebSocketClient 0x%08x stops servicing\n", client);
	libwebsocket_context_destroy(client->context);
	return NULL;
}
