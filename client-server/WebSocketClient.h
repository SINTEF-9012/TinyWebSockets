/*
 * WebSocketClient.h
 *
 *  Created on: Dec 13, 2013
 *      Author: vassik
 */

#ifndef WEBSOCKETCLIENT_H_
#define WEBSOCKETCLIENT_H_

#include "libwebsockets/lws_config.h"
#include "libwebsockets/libwebsockets.h"

#include "../libs/Utility.h"
#include "../sockets/WebSocket.h"

namespace WebSockets {

	class WebSocketFacade;

	class WebSocketClient : WebSocket {

		public:
			struct libwebsocket_context *context;
			struct libwebsocket *wsi;
			const char* host;
			const char* subprotocol;
			const char* messageToSend;

		private:
			int force_exit;
			WebSocketFacade* facade;
			int is_connected;

		public:
			WebSocketClient(WebSocketFacade* facade, const char* host, int port, const char* subprotocol);
			virtual ~WebSocketClient();
			virtual void Destroy();

		public:
			virtual int getPort();
			virtual int open();
			virtual int close();
			virtual int sendMessage(const char* message);
			static int callback_web_socket_client(struct libwebsocket_context *context,
						struct libwebsocket *wsi,
						enum libwebsocket_callback_reasons reason,
									   void *user, void *in, size_t len);
			virtual void setCallbacks(ThingMLCallback* _onopen, ThingMLCallback* _onclose, ThingMLCallback* _onmessage, ThingMLCallback* _onerror);

		private:
			void reset();

		protected:
			virtual void onOpen();
			virtual void onClose();
			virtual void onError(const char*error);
			virtual void onMessage(const char* message);

			static void* startServicing(void *ptr);

	};
}

#endif /* WEBSOCKETCLIENT_H_ */
