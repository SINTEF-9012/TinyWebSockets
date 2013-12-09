/*
 * socket.cpp
 *
 *  Created on: Dec 7, 2013
 *      Author: vassik
 */

#include <iostream>

#include "Socket.h"
#include "../libs/Utility.h"

using namespace WebSockets;

Socket::Socket(int _port){
	this->port = _port;
	this->onclose = NULL;
	this->onerror = NULL;
	this->onmessage = NULL;
	this->onopen = NULL;
}

Socket::Socket(int _port,
		ThingMLCallback* _onopen,
		ThingMLCallback* _onclose,
		ThingMLCallback* _onmessage,
		ThingMLCallback* _onerror){
	this->port = _port;
	this->onclose = _onclose;
	this->onerror = _onerror;
	this->onmessage = _onmessage;
	this->onopen = _onopen;
}
