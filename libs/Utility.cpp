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


WebSocketObserver::WebSocketObserver(ThingMLCallback* _open_callback,
		ThingMLCallback* _close_callback,
		ThingMLCallback* _msg_callback,
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
	Log::Write(LogLevel_Info, "WebSocketObserver::~WebSocketObserver is called 0x%08x", this);
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



void dump_handshake_info(struct libwebsocket *wsi)
{
	int n;
	static const char *token_names[] = {
		/*[WSI_TOKEN_GET_URI]		=*/ "GET URI",
		/*[WSI_TOKEN_POST_URI]		=*/ "POST URI",
		/*[WSI_TOKEN_HOST]		=*/ "Host",
		/*[WSI_TOKEN_CONNECTION]	=*/ "Connection",
		/*[WSI_TOKEN_KEY1]		=*/ "key 1",
		/*[WSI_TOKEN_KEY2]		=*/ "key 2",
		/*[WSI_TOKEN_PROTOCOL]		=*/ "Protocol",
		/*[WSI_TOKEN_UPGRADE]		=*/ "Upgrade",
		/*[WSI_TOKEN_ORIGIN]		=*/ "Origin",
		/*[WSI_TOKEN_DRAFT]		=*/ "Draft",
		/*[WSI_TOKEN_CHALLENGE]		=*/ "Challenge",

		/* new for 04 */
		/*[WSI_TOKEN_KEY]		=*/ "Key",
		/*[WSI_TOKEN_VERSION]		=*/ "Version",
		/*[WSI_TOKEN_SWORIGIN]		=*/ "Sworigin",

		/* new for 05 */
		/*[WSI_TOKEN_EXTENSIONS]	=*/ "Extensions",

		/* client receives these */
		/*[WSI_TOKEN_ACCEPT]		=*/ "Accept",
		/*[WSI_TOKEN_NONCE]		=*/ "Nonce",
		/*[WSI_TOKEN_HTTP]		=*/ "Http",

		"Accept:",
		"If-Modified-Since:",
		"Accept-Encoding:",
		"Accept-Language:",
		"Pragma:",
		"Cache-Control:",
		"Authorization:",
		"Cookie:",
		"Content-Length:",
		"Content-Type:",
		"Date:",
		"Range:",
		"Referer:",
		"Uri-Args:",

		/*[WSI_TOKEN_MUXURL]	=*/ "MuxURL",
	};
	char buf[256];

	for (n = 0; n < sizeof(token_names) / sizeof(token_names[0]); n++) {
		if (!lws_hdr_total_length(wsi, n))
			continue;

		lws_hdr_copy(wsi, buf, sizeof buf, n);

		fprintf(stderr, "    %s = %s\n", token_names[n], buf);
	}
}
