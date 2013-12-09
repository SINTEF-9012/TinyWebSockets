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

class WebSocketServer : WebSocket {

	public:
		WebSocketServer(int _port);
		WebSocketServer(int _port, ThingMLCallback* _onopen, ThingMLCallback* _onclose, ThingMLCallback* _onmessage, ThingMLCallback* _onerror);
		virtual ~WebSocketServer();
		void Destroy();

	public:
		virtual void open();
		virtual void close();
		virtual void sendMessage(char* message);

	protected:
		virtual void onOpen();
		virtual void onClose();
		virtual void onError(char*error);
		virtual void onMessage(char* message);

};

#endif /* WEBSOCKETSERVER_H_ */
