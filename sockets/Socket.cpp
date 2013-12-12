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
