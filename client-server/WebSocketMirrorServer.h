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


class WebSocketMirrorServer : WebSocket {

	public:
		static WebSocketMirrorServer* s_instance;
		static const char *web_socket_subprotocol;
		struct libwebsocket_context *context;

		int force_exit;
		int ringbuffer_head;
		struct a_message ringbuffer[MAX_MESSAGE_QUEUE];

		WebSocketMirrorServer(int _port);
		virtual int getPort();

		static WebSocketMirrorServer* Init(int _port);
		static WebSocketMirrorServer* Init(int _port, ThingMLCallback* _onopen, ThingMLCallback* _onclose, ThingMLCallback* _onmessage, ThingMLCallback* _onerror);
		static WebSocketMirrorServer* Get();
		static WebSocketMirrorServer* SetCallback(ThingMLCallback* _onopen, ThingMLCallback* _onclose, ThingMLCallback* _onmessage, ThingMLCallback* _onerror);

		virtual ~WebSocketMirrorServer();
		static void Destroy();

	public:
		virtual int open();
		virtual int close();
		virtual int sendMessage(char* message);
		static int callback_web_socket_server(struct libwebsocket_context *context,
					struct libwebsocket *wsi,
					enum libwebsocket_callback_reasons reason,
							       void *user, void *in, size_t len);
	private:
		void reset();

	protected:
		virtual void onOpen();
		virtual void onClose();
		virtual void onError(char*error);
		virtual void onMessage(char* message);

		static void* startServicing(void *ptr);

};



#endif /* WEBSOCKETSERVER_H_ */
