/*
 * websocket.h
 *
 *  Created on: Dec 7, 2013
 *      Author: vassik
 */

#ifndef WEBSOCKET_H_
#define WEBSOCKET_H_

#include "Socket.h"
#include "../libs/Utility.h"
#include "../libwebsockets/libwebsockets.h"

class WebSocket : Socket {

	protected:
		WebSocketObserver* observer;

	public:
		WebSocket(int _port);
		virtual ~WebSocket();
		virtual int getPort();
		virtual void Destroy();

		virtual void setObserver(ThingMLCallback* _onopen, ThingMLCallback* _onclose, ThingMLCallback* _onerror, ThingMLCallback* _onmessage);
};


#endif /* WEBSOCKET_H_ */
