/*
 * run.cpp
 *
 *  Created on: Dec 7, 2013
 *      Author: vassik
 */

#include "client-server/WebSocketServer.h"

int main(int argc, char **argv) {
	WebSocketServer* wss = new WebSocketServer(7120);
	wss->open();
	wss->Destroy();
}


