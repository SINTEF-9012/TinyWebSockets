/*
 * run.cpp
 *
 *  Created on: Dec 7, 2013
 *      Author: vassik
 */

#include <signal.h>
#include <iostream>
#include <cstdarg>

#include "client-server/WebSocketMirrorServer.h"
#include "libs/Log.h"
#include "libs/Utility.h"

#include "client-server/WebSocketFacade.h"
#include "client-server/WebSocketClient.h"

using namespace std;
using namespace WebSockets;

void on_open_callback(void* instance, ...){
	Log::Write(LogLevel_Info, "on_open_callback is called by 0x%08x", instance);
}

void on_close_callback(void* instance, ...){
	Log::Write(LogLevel_Info, "on_close_callback is called by 0x%08x", instance);
}

void on_error_callback(void* instance, ...){
	va_list arguments;
	va_start(arguments, instance);
	char* message = va_arg(arguments, char*);
	va_end(arguments);
	Log::Write(LogLevel_Info, "on_error_callback is called by 0x%08x with message %s", instance, message);
}

void on_message_callback(void* instance, ...){
	va_list arguments;
	va_start(arguments, instance);
	char* message = va_arg(arguments, char*);
	va_end(arguments);
	Log::Write(LogLevel_Info, "on_message_callback is called by 0x%08x with message %s", instance, message);
}


int main(int argc, char **argv) {
	const char* localhost = "localhost";

	WebSocketClient* wcs = WebSocketFacade::InitWebSocketClient(localhost, 7681, NULL);
	WebSocketClient* wcs1 = WebSocketFacade::InitWebSocketClient(localhost, 7681, NULL);

	ThingMLCallback* tml_op_open_callback = new ThingMLCallback(on_open_callback, wcs);
	ThingMLCallback* tml_op_close_callback = new ThingMLCallback(on_close_callback, wcs);
	ThingMLCallback* tml_op_error_callback = new ThingMLCallback(on_error_callback, wcs);
	ThingMLCallback* tml_op_message_callback = new ThingMLCallback(on_message_callback, wcs);

	ThingMLCallback* tml_op_open_callback1 = new ThingMLCallback(on_open_callback, wcs1);
	ThingMLCallback* tml_op_close_callback1 = new ThingMLCallback(on_close_callback, wcs1);
	ThingMLCallback* tml_op_error_callback1 = new ThingMLCallback(on_error_callback, wcs1);
	ThingMLCallback* tml_op_message_callback1 = new ThingMLCallback(on_message_callback, wcs1);

	wcs->setCallbacks(tml_op_open_callback, tml_op_close_callback, tml_op_message_callback, tml_op_error_callback);
	wcs1->setCallbacks(tml_op_open_callback1, tml_op_close_callback1, tml_op_message_callback1, tml_op_error_callback1);

	cout << "just before while !!!\n" << endl;

	string ch;
	bool loop = true;
	while (loop){
		getline(cin, ch);
		if(ch == "c"){
			wcs->close();
		}
		if(ch == "q"){
			loop = false;
		}
		if(ch == "o"){
			wcs->open();
		}
		if(ch == "s"){
			wcs->sendMessage("something");
		}
		if(ch == "c1"){
			wcs1->close();
		}
		if(ch == "o1"){
			wcs1->open();
		}
		if(ch == "s1"){
			wcs1->sendMessage("something1");
		}
	}

	cout << "before destroy!!! \n" << endl;
	WebSocketFacade::Destroy();
	cout << "just before exit \n" << endl;
}
