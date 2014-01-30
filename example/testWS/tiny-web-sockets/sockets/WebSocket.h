/*
 * websocket.h
 *
 *  Created on: Dec 7, 2013
 *      Author: vassik
 */

#ifndef WEBSOCKET_H_
#define WEBSOCKET_H_

#include "../libs/Utility.h"
#include "../libwebsockets/libwebsockets.h"

using namespace WebSockets;

class WebSocket {

	protected:
		int port;
		WebSocketObserver* observer;

	public:
		WebSocket(int _port);
		virtual ~WebSocket();
		virtual int getPort(){return this->port;};
		virtual void Destroy();

		virtual void setObserver(ThingMLCallback* _onopen, ThingMLCallback* _onclose, ThingMLCallback* _onerror, ThingMLCallback* _onmessage);

	public:
		virtual int open() = 0;
		virtual int close() = 0;
		virtual int sendMessage(const char* message) = 0;

	protected:
		virtual void onOpen() = 0;
		virtual void onClose() = 0;
		virtual void onError(const char* error) = 0;
		virtual void onMessage(const char* message) = 0;
};


#endif /* WEBSOCKET_H_ */
