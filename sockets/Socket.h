/*
 * socket.h
 *
 *  Created on: Dec 7, 2013
 *      Author: vassik
 */

#ifndef SOCKET_H_
#define SOCKET_H_

#include "../libs/Utility.h"

using namespace WebSockets;

class Socket {

	protected:
		int port;
		ThingMLCallback* onopen;
		ThingMLCallback* onclose;
		ThingMLCallback* onerror;
		ThingMLCallback* onmessage;

	public:
		Socket(int _port);
		virtual ~Socket() {};
		virtual int getPort(){return this->port;};

	public:
		virtual int open() = 0;
		virtual int close() = 0;
		virtual int sendMessage(char* message) = 0;

	protected:
		virtual void onOpen() = 0;
		virtual void onClose() = 0;
		virtual void onError(char*error) = 0;
		virtual void onMessage(char* message) = 0;
};



#endif /* SOCKET_H_ */
