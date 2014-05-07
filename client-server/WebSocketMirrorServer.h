/*
 * WebSocketServer.h
 *
 *  Created on: Dec 7, 2013
 *      Author: vassik
 */

#ifndef WEBSOCKETSERVER_H_
#define WEBSOCKETSERVER_H_

#include <iostream>

#include "libwebsockets/lws_config.h"
#include "libwebsockets/libwebsockets.h"

#include "../sockets/WebSocket.h"
#include "../libs/Constants.h"
#include "../libs/Utility.h"

namespace WebSockets {

	class WebSocketFacade;

	class WebSocketMirrorServer : WebSocket {

		private:
			WebSocketMirrorServer(WebSocketFacade* facade, int _port, const char* subprotocol);
			virtual ~WebSocketMirrorServer();

		public:
			int force_exit;
			int ringbuffer_head;
			const char* subprotocol;

		public:
			static WebSocketMirrorServer* s_instance;
			static const char* web_socket_subprotocol;
			struct libwebsocket_context *context;
			struct a_message ringbuffer[MAX_MESSAGE_QUEUE];

			static WebSocketMirrorServer* Init(WebSocketFacade* facade, int _port, const char* subprotocol);
			static WebSocketMirrorServer* Get();
			static int callback_web_socket_server(struct libwebsocket_context *context,
						struct libwebsocket *wsi,
						enum libwebsocket_callback_reasons reason,
									   void *user, void *in, size_t len);
			static void Halt();
			static void* startServicing(void *ptr);

		public:
			virtual WebSocketMirrorServer* setCallbacks(ThingMLCallback* _onopen, ThingMLCallback* _onclose,
					ThingMLCallback* _onmessage, ThingMLCallback* _onerror);
			virtual int open();
			virtual int close();
			virtual int sendMessage(const char* message);
			virtual void Destroy();
			virtual int getPort();

		private:
			void reset();

		protected:
			virtual void onOpen();
			virtual void onClose();
			virtual void onError(const char*error);
			virtual void onMessage(const char* message);
	};

}


#endif /* WEBSOCKETSERVER_H_ */
