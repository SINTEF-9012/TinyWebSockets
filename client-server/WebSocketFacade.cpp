/*
 * WebSocketClientFactory.cpp
 *
 *  Created on: Dec 13, 2013
 *      Author: vassik
 */

#include <iostream>
#include <list>


#include "WebSocketFacade.h"
#include "WebSocketClient.h"
#include "WebSocketMirrorServer.h"

#include <syslog.h>

using namespace WebSockets;
using namespace std;

WebSocketFacade* WebSocketFacade::s_instance = NULL;
int WebSocketFacade::default_debug_level = 7;

WebSocketFacade::WebSocketFacade(){
	this->mirrorServer = NULL;
	this->clients;
}

WebSocketFacade::~WebSocketFacade(){}

WebSocketFacade* WebSocketFacade::Init(){
	if(s_instance == NULL){
		WebSocketFacade::SetLogLevel(default_debug_level);
		s_instance = new WebSocketFacade();
	}
	return s_instance;
}

WebSocketFacade* WebSocketFacade::Init(int debug_level){
	if(s_instance == NULL){
		WebSocketFacade::SetLogLevel(debug_level);
		s_instance = new WebSocketFacade();
	}
	return s_instance;
}

WebSocketFacade* WebSocketFacade::Get(){
	return WebSocketFacade::Init();
}

WebSocketClient* WebSocketFacade::InitWebSocketClient(const char* host, int port, const char* subprotocol){
	return new WebSocketClient(WebSocketFacade::Get(), host, port, subprotocol);
}

WebSocketMirrorServer* WebSocketFacade::InitWebSocketMirrorServer(int port, const char* subprotocol){
	return WebSocketMirrorServer::Init(WebSocketFacade::Get(), port, subprotocol);
}

void WebSocketFacade::Destroy(){
	WebSocketFacade* wscp = WebSocketFacade::Get();
	list<WebSocketClient*> clients = wscp->GetWebSocketClients();
	for(list<WebSocketClient*>::iterator it =  clients.begin(); it != clients.end(); ++it){
		(*it)->Destroy();
	}
	WebSocketMirrorServer::Halt();
	s_instance->mirrorServer = NULL;
	delete s_instance;
	s_instance = NULL;
#ifndef WIN32
	closelog();
#endif
}

list<WebSocketClient*> WebSocketFacade::GetWebSocketClients(){
	return s_instance->clients;
}

WebSocketMirrorServer* WebSocketFacade::GetWebSocketMirrorServer(){
	return s_instance->mirrorServer;
}

void WebSocketFacade::SetLogLevel(int debug_level){
#ifndef WIN32
	int syslog_options = LOG_PID | LOG_PERROR;
#endif
#ifndef WIN32
	/* we will only try to log things according to our debug_level */
	setlogmask(LOG_UPTO (LOG_DEBUG));
	openlog("lwsts", syslog_options, LOG_DAEMON);
#endif
	/* tell the library what debug level to emit and to send it to syslog */
	lws_set_log_level(debug_level, lwsl_emit_syslog);
}

void WebSocketFacade::addWebSocketClient(WebSocketClient* client){
	clients.push_back(client);
}

void WebSocketFacade::setWebSocketMirrorServer(WebSocketMirrorServer* server){
	mirrorServer = server;
}



