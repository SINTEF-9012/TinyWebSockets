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

#include "../libs/Utility.h"

using namespace WebSockets;
using namespace std;

class WebSocketClient;

class WebSocketClientPoll {

	public:
		static WebSocketClientPoll* s_instance;

	private:
		list<WebSocketClient*> clients;
		WebSocketClientPoll();
		~WebSocketClientPoll();

	public:
		static WebSocketClientPoll* Init();
		static WebSocketClientPoll* Get();
		static void Destroy();
		list<WebSocketClient*> getClients();
		void appendClient(WebSocketClient* client);
};


#endif /* WEBSOCKETCLIENTFACTORY_H_ */
