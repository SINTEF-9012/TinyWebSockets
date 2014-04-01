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
	this->observer->setOpenCallback(_onopen);
	this->observer->setCloseCallback(_onclose);
	this->observer->setMessageCallback(_onmessage);
	this->observer->setErrorCallback(_onerror);
}

void WebSocket::Destroy(){
	delete this;
}

