/*
 * WebSocketServer.h
 *
 *  Created on: Dec 7, 2013
 *      Author: vassik
 */

#ifndef WEBSOCKETSERVER_H_
#define WEBSOCKETSERVER_H_

#include <iostream>

#include "../sockets/WebSocket.h"
#include "../libwebsockets/libwebsockets.h"
#include "../libs/Constants.h"

using namespace WebSockets;

struct per_session_data__lws_mirror {
	struct libwebsocket *wsi;
	int ringbuffer_tail;
};

struct a_message {
	void *payload;
	size_t len;
};


class WebSocketServer : WebSocket {

	public:
		static WebSocketServer* s_instance;
		static int ringbuffer_head;
		static struct a_message ringbuffer[MAX_MESSAGE_QUEUE];
		static int close_testing;
		static int force_exit;

		WebSocketServer(int _port);
		WebSocketServer(int _port, ThingMLCallback* _onopen, ThingMLCallback* _onclose, ThingMLCallback* _onmessage, ThingMLCallback* _onerror);
		virtual int getPort();

		static WebSocketServer* Init(int _port);
		static WebSocketServer* Init(int _port, ThingMLCallback* _onopen, ThingMLCallback* _onclose, ThingMLCallback* _onmessage, ThingMLCallback* _onerror);
		static WebSocketServer* Get();
		static WebSocketServer* SetCallback(ThingMLCallback* _onopen, ThingMLCallback* _onclose, ThingMLCallback* _onmessage, ThingMLCallback* _onerror);

		virtual ~WebSocketServer();
		static void Destroy();

	public:
		virtual int open();
		virtual int close();
		virtual int sendMessage(char* message);
		static int callback_web_socket_server(struct libwebsocket_context *context,
					struct libwebsocket *wsi,
					enum libwebsocket_callback_reasons reason,
							       void *user, void *in, size_t len);

	protected:
		virtual void onOpen();
		virtual void onClose();
		virtual void onError(char*error);
		virtual void onMessage(char* message);

};



#endif /* WEBSOCKETSERVER_H_ */
