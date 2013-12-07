/*
 * Utility.cpp
 *
 *  Created on: Dec 6, 2013
 *      Author: vassik
 */

#include <stdio.h>

#include "Utility.h"
#include "Log.h"

using namespace WebSockets;

WebSocketObserver::WebSocketObserver(ThingMLCallback* _msg_callback,
		ThingMLCallback* _open_callback,
		ThingMLCallback* _close_callback,
		ThingMLCallback* _error_callback)
{
	this->msg_callback = _msg_callback;
	this->open_callback = _open_callback;
	this->close_callback = _close_callback;
	this->error_callback = _error_callback;
};

WebSocketObserver::WebSocketObserver()
{
	this->msg_callback = NULL;
	this->open_callback = NULL;
	this->close_callback = NULL;
	this->error_callback = NULL;
}

void WebSocketObserver::onMessage(char* message){
	Log::Write(LogLevel_Info, "WebSocketObserver::onMessage is called");
	if(this->msg_callback != NULL){
		this->msg_callback->fn_callback(this->msg_callback->instance, message);
	}else{
		Log::Write(LogLevel_Info, "callback is not set for onMessage");
	}
}

void WebSocketObserver::onError(char* error){
	Log::Write(LogLevel_Info, "WebSocketObserver::onError is called");
	if(this->error_callback != NULL){
		this->error_callback->fn_callback(this->error_callback->instance, error);
	}else{
		Log::Write(LogLevel_Info, "callback is not set for onError");
	}
}

void WebSocketObserver::onOpen(){
	Log::Write(LogLevel_Info, "WebSocketObserver::onOpen is called");
	if(this->open_callback != NULL){
		this->open_callback->fn_callback(this->open_callback->instance);
	}else{
		Log::Write(LogLevel_Info, "callback is not set for onOpen");
	}
}

void WebSocketObserver::onClose(){
	Log::Write(LogLevel_Info, "WebSocketObserver::onClose is called");
	if(this->close_callback != NULL){
		this->close_callback->fn_callback(this->close_callback->instance);
	}else{
		Log::Write(LogLevel_Info, "callback is not set for onClose");
	}
}

WebSocketObserver::~WebSocketObserver(){
	Log::Write(LogLevel_Info, "WebSocketObserver::~WebSocketObserver is called");
	if(this->msg_callback != NULL){
		delete this->msg_callback;
	}
	if(this->error_callback != NULL){
		delete this->error_callback;
	}
	if(this->open_callback != NULL){
		delete this->open_callback;
	}
	if(this->close_callback != NULL){
		delete this->close_callback;
	}
}


