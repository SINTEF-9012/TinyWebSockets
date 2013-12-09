/*
 * run.cpp
 *
 *  Created on: Dec 7, 2013
 *      Author: vassik
 */

#include "client-server/WebSocketServer.h"
#include "libs/Log.h"
#include "libs/Utility.h"

using namespace WebSockets;

void on_open_callback(void* instance){
	Log::Write(LogLevel_Info, "on_open_callback is called by 0x%08x", instance);
}

void on_close_callback(void* instance){
	Log::Write(LogLevel_Info, "on_close_callback is called by 0x%08x", instance);
}

void on_error_callback(void* instance, char* message){
	Log::Write(LogLevel_Info, "on_error_callback is called by 0x%08x with message %s", instance, message);
}

void on_message_callback(void* instance, char* message){
	Log::Write(LogLevel_Info, "on_message_callback is called by 0x%08x with message %s", instance, message);
}

int main(int argc, char **argv) {
	WebSocketServer* wss;

	ThingMLCallback* tml_op_open_callback = new ThingMLCallback(on_open_callback, wss);
	ThingMLCallback* tml_op_close_callback = new ThingMLCallback(on_close_callback, wss);
	ThingMLCallback* tml_op_error_callback = new ThingMLCallback(on_error_callback, wss);
	ThingMLCallback* tml_op_message_callback = new ThingMLCallback(on_message_callback, wss);

	wss = new WebSocketServer(7120, tml_op_open_callback, tml_op_close_callback, tml_op_message_callback, tml_op_error_callback);
	wss->open();
	wss->Destroy();
}


