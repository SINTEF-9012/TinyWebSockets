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

class WebSocket : Socket {

	protected:
		WebSocketObserver* observer;

	public:
		WebSocket(int _port);
		WebSocket(int _port, ThingMLCallback* _onopen, ThingMLCallback* _onclose, ThingMLCallback* _onerror, ThingMLCallback* _onmessage);
		virtual ~WebSocket();
};


#endif /* WEBSOCKET_H_ */
