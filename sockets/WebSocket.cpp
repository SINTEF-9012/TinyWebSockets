/*
 * WebSocket.cpp
 *
 *  Created on: Dec 7, 2013
 *      Author: vassik
 */


#include "WebSocket.h"
#include "../libs/Utility.h"

using namespace WebSockets;

WebSocket::WebSocket(int _port) {
	this->port = _port;
	this->observer = new WebSocketObserver();
}

WebSocket::~WebSocket(){
	delete this->observer;
}

void WebSocket::setObserver(ThingMLCallback* _onopen,
		ThingMLCallback* _onclose,
		ThingMLCallback* _onmessage,
		ThingMLCallback* _onerror){
	delete this->observer;
	this->observer = new WebSocketObserver(_onopen, _onclose, _onmessage, _onerror);
}

void WebSocket::Destroy(){
	delete this;
}

