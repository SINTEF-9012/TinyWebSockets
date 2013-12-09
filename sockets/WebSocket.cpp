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
		ThingMLCallback* _onmessage,
		ThingMLCallback* _onerror) : Socket(_port, _onopen, _onclose,  _onmessage, _onerror){
	this->observer = new WebSocketObserver(this->onopen, this->onclose, this->onmessage, this->onerror);
}

WebSocket::~WebSocket(){
	delete this->observer;
}

