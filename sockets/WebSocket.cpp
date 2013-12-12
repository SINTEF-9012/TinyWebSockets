/*
 * WebSocket.cpp
 *
 *  Created on: Dec 7, 2013
 *      Author: vassik
 */


#include "WebSocket.h"
#include "../libs/Utility.h"

#include "../libs/Constants.h"

WebSocket::WebSocket(int _port) : Socket(_port){
	this->observer = new WebSocketObserver();
}

int WebSocket::getPort(){
	return Socket::getPort();
}

WebSocket::~WebSocket(){
	delete this->observer;
}

void WebSocket::setObserver(ThingMLCallback* _onopen,
		ThingMLCallback* _onclose,
		ThingMLCallback* _onmessage,
		ThingMLCallback* _onerror){
	this->onopen = _onopen;
	this->onclose = _onclose;
	this->onmessage = _onmessage;
	this->onerror = _onerror;
	delete this->observer;
	this->observer = new WebSocketObserver(this->onopen, this->onclose, this->onmessage, this->onerror);
}

