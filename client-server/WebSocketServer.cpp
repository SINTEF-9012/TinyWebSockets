/*
 * WebSocketServer.cpp
 *
 *  Created on: Dec 7, 2013
 *      Author: vassik
 */

#include "WebSocketServer.h"
#include "../libs/Log.h"

using namespace WebSockets;


WebSocketServer::WebSocketServer(int _port) : WebSocket(_port){

}

WebSocketServer::WebSocketServer(int _port,
		ThingMLCallback* _onopen,
		ThingMLCallback* _onclose,
		ThingMLCallback* _onmessage,
		ThingMLCallback* _onerror) : WebSocket(_port, _onopen, _onclose, _onmessage, _onerror){

}

WebSocketServer::~WebSocketServer(){}

void WebSocketServer::open(){
	this->onOpen();
}

void WebSocketServer::close(){

}

void WebSocketServer::sendMessage(char* message){

}

void WebSocketServer::onClose(){
	this->observer->onClose();
}

void WebSocketServer::onError(char* error){
	this->observer->onError(error);
}

void WebSocketServer::onMessage(char* message){
	this->observer->onMessage(message);
}

void WebSocketServer::onOpen(){
	this->observer->onOpen();
}

void WebSocketServer::Destroy(){
	Log::Write(LogLevel_Info, "WebSocketServer::Destroy() : destroying object 0x%08x", this);
	delete this;
}
