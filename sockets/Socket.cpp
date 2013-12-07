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
		ThingMLCallback* _onerror,
		ThingMLCallback* _onmessage){
	this->port = _port;
	this->onclose = _onopen;
	this->onerror = _onclose;
	this->onmessage = _onerror;
	this->onopen = _onmessage;
}
