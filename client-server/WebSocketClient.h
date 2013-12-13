/*
 * WebSocketClient.h
 *
 *  Created on: Dec 13, 2013
 *      Author: vassik
 */

#ifndef WEBSOCKETCLIENT_H_
#define WEBSOCKETCLIENT_H_

#include "../libwebsockets/libwebsockets.h"
#include "../libs/Utility.h"
#include "WebSocketClientPoll.h"


class WebSocketClient : WebSocket {

	public:
		struct libwebsocket_context *context;
		struct libwebsocket *wsi;
		const char* host;
		const char* subprotocol;

	private:
		int force_exit;
		WebSocketClientPoll* client_poll;

	public:
		WebSocketClient(WebSocketClientPoll* client_poll, char* host, int port, char* subprotocol);
		WebSocketClient(int _port);
		virtual ~WebSocketClient();
		virtual void Destroy();

	public:
		virtual int getPort();
		virtual int open();
		virtual int close();
		virtual int sendMessage(char* message);
		static int callback_web_socket_client(struct libwebsocket_context *context,
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



#endif /* WEBSOCKETCLIENT_H_ */
