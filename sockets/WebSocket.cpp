/*
 * WebSocket.cpp
 *
 *  Created on: Dec 7, 2013
 *      Author: vassik
 */


#include "WebSocket.h"
#include "../libs/Utility.h"

WebSocket::WebSocket(int _port) : Socket(_port){
	this->observer = new WebSocketObserver();
}

WebSocket::WebSocket(int _port,
		ThingMLCallback* _onopen,
		ThingMLCallback* _onclose,
		ThingMLCallback* _onerror,
		ThingMLCallback* _onmessage) : Socket(_port, _onopen, _onclose, _onerror, _onmessage){
	this->observer = new WebSocketObserver(this->onmessage, this->onopen, this->onclose, this->onerror);
}

WebSocket::~WebSocket(){
	delete this->observer;
}

