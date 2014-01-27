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

void sighandler(int sig)
{
	WebSocketMirrorServer* wss = WebSocketMirrorServer::Get();
	wss->close();
	wss->Destroy();
}

int main(int argc, char **argv) {
	//signal(SIGINT, sighandler);

	//WebSocketMirrorServer* wss = WebSocketMirrorServer::Init(7681);
	WebSocketMirrorServer* wss = WebSocketFacade::InitWebSocketMirrorServer(7681, NULL);

	ThingMLCallback* tml_op_open_callback = new ThingMLCallback(on_open_callback, wss);
	ThingMLCallback* tml_op_close_callback = new ThingMLCallback(on_close_callback, wss);
	ThingMLCallback* tml_op_error_callback = new ThingMLCallback(on_error_callback, wss);
	ThingMLCallback* tml_op_message_callback = new ThingMLCallback(on_message_callback, wss);

	wss->setCallbacks(tml_op_open_callback, tml_op_close_callback, tml_op_message_callback, tml_op_error_callback);
	//wss = WebSocketMirrorServer::SetCallback(tml_op_open_callback, tml_op_close_callback, tml_op_message_callback, tml_op_error_callback);

	const char* localhost = "localhost";

	//WebSocketClient* wsc1 = new WebSocketClient(WebSocketFacade::Init(), localhost, 7681, NULL);
	//WebSocketClient* wsc2 = new WebSocketClient(WebSocketFacade::Init(), localhost, 7681, NULL);

	WebSocketClient* wsc1 = WebSocketFacade::InitWebSocketClient(localhost, 7681, NULL);
	WebSocketClient* wsc2 = WebSocketFacade::InitWebSocketClient(localhost, 7681, NULL);

	ThingMLCallback* tml_op_open_callback1 = new ThingMLCallback(on_open_callback, wsc1);
		ThingMLCallback* tml_op_close_callback1 = new ThingMLCallback(on_close_callback, wsc1);
		ThingMLCallback* tml_op_error_callback1 = new ThingMLCallback(on_error_callback, wsc1);
		ThingMLCallback* tml_op_message_callback1 = new ThingMLCallback(on_message_callback, wsc1);

		ThingMLCallback* tml_op_open_callback2 = new ThingMLCallback(on_open_callback, wsc2);
				ThingMLCallback* tml_op_close_callback2 = new ThingMLCallback(on_close_callback, wsc2);
				ThingMLCallback* tml_op_error_callback2 = new ThingMLCallback(on_error_callback, wsc2);
				ThingMLCallback* tml_op_message_callback2 = new ThingMLCallback(on_message_callback, wsc2);

	wsc1->setCallbacks(tml_op_open_callback1, tml_op_close_callback1, tml_op_message_callback1, tml_op_error_callback1);
	wsc2->setCallbacks(tml_op_open_callback2, tml_op_close_callback2, tml_op_message_callback2, tml_op_error_callback2);

	cout << "just before while !!!\n" << endl;

	string ch;
	bool loop = true;
	while (loop){
		getline(cin, ch);
		if(ch == "c"){
			wss->close();
		}
		if(ch == "q"){
			loop = false;
		}
		if(ch == "o"){
			wss->open();
		}
		if(ch == "o1"){
			wsc1->open();
		}
		if(ch == "o2"){
			wsc2->open();
		}
		if(ch == "s1"){
			wsc1->sendMessage("wsc1->sendMessage");
		}
		if(ch == "s2"){
			wsc2->sendMessage("wsc2->sendMessage");
		}
		if(ch == "c1"){
			wsc1->close();
		}
		if(ch == "c2"){
			wsc2->close();
		}
	}

	//WebSocketMirrorServer::Halt();
	WebSocketFacade::Destroy();
	cout << "just before exit \n" << endl;
}
