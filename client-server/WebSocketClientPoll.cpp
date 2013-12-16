/*
 * WebSocketClientFactory.cpp
 *
 *  Created on: Dec 13, 2013
 *      Author: vassik
 */

#include <iostream>
#include <list>


#include "WebSocketClientPoll.h"
//#include "../sockets/WebSocket.h"
#include "WebSocketClient.h"

using namespace WebSockets;
using namespace std;

WebSocketClientPoll* WebSocketClientPoll::s_instance = NULL;

WebSocketClientPoll* WebSocketClientPoll::Init(){
	if(s_instance == NULL){
		s_instance = new WebSocketClientPoll();
	}
	return s_instance;
}

WebSocketClientPoll::WebSocketClientPoll(){}

WebSocketClientPoll::~WebSocketClientPoll(){}

void WebSocketClientPoll::appendClient(WebSocketClient* client){
	clients.push_back(client);
}

WebSocketClientPoll* WebSocketClientPoll::Get(){
	return WebSocketClientPoll::Init();
}

void WebSocketClientPoll::Destroy(){
	WebSocketClientPoll* wscp = WebSocketClientPoll::Get();
	list<WebSocketClient*> clients = wscp->getClients();
	for(list<WebSocketClient*>::iterator it =  clients.begin(); it != clients.end(); ++it){
		(*it)->Destroy();
	}
	delete s_instance;
	s_instance = NULL;
}

list<WebSocketClient*> WebSocketClientPoll::getClients(){
	return clients;
}



