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

namespace WebSockets {
	using namespace std;

	class WebSocketClient;
	class WebSocketMirrorServer;

	class WebSocketFacade {

		public:
			static WebSocketFacade* s_instance;
			static int default_debug_level;

		private:
			list<WebSocketClient*> clients;
			WebSocketMirrorServer* mirrorServer;
			WebSocketFacade();
			~WebSocketFacade();

		public:
			static WebSocketFacade* Init();
			static WebSocketFacade* Init(int debug_level);
			static WebSocketFacade* Get();
			static WebSocketClient* InitWebSocketClient(const char* host, int port, const char* subprotocol);
			static WebSocketMirrorServer* InitWebSocketMirrorServer(int port, const char* subprotocol);
			static void Destroy();
			static list<WebSocketClient*> GetWebSocketClients();
			static WebSocketMirrorServer* GetWebSocketMirrorServer();
			static void SetLogLevel(int debug_level);

			void addWebSocketClient(WebSocketClient* client);
			void setWebSocketMirrorServer(WebSocketMirrorServer* server);
	};
}

#endif /* WEBSOCKETCLIENTFACTORY_H_ */
