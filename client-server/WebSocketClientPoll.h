/*
 * WebSocketClientFactory.h
 *
 *  Created on: Dec 13, 2013
 *      Author: vassik
 */

#ifndef WEBSOCKETCLIENTFACTORY_H_
#define WEBSOCKETCLIENTFACTORY_H_


#include <iostream>
#include <list>

#include "../sockets/WebSocket.h"
#include "../libs/Utility.h"

using namespace WebSockets;
using namespace std;

class WebSocketClientPoll {

	public:
		static WebSocketClientPoll* s_instance;

	private:
		list<WebSocket*> clients;
		WebSocketClientPoll();
		~WebSocketClientPoll();

	public:
		static WebSocketClientPoll* Init();
		static WebSocketClientPoll* Get();
		static void Destroy();
		list<WebSocket*> getClients();
		void appendClient(WebSocket* client);

};


#endif /* WEBSOCKETCLIENTFACTORY_H_ */
