/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *           Header for Thing WebSClient
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#ifndef WebSClient_H_
#define WebSClient_H_


#include "thingml_typedefs.h"

/*****************************************************************************
 * Headers for type : WebSClient
 *****************************************************************************/


// BEGIN: Code from the c_header annotation WebSClient

#include <stdio.h>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <cstdarg>
#include "tinyws/client-server/WebSocketFacade.h"
#include "tinyws/client-server/WebSocketClient.h"

using namespace WebSockets;

// END: Code from the c_header annotation WebSClient

// Definition of the instance stuct:
struct WebSClient_Instance {
// Variables for the ID of the instance
int id;
// Variables for the current instance state
int WebSClient_behavior_State;
// Variables for the properties of the instance
WebSocketClient* WebSClient_client_var;
const char* WebSClient__host_var;
uint8_t WebSClient_status_var;
const char* WebSocket__port_var;
};

// Declaration of prototypes outgoing messages:
void WebSClient_behavior_OnEntry(int state, struct WebSClient_Instance *_instance);
void WebSClient_handle_lifecycle_stop_client(struct WebSClient_Instance *_instance);
void WebSClient_handle_lifecycle_start_client(struct WebSClient_Instance *_instance);
void WebSClient_handle_messaging_send(struct WebSClient_Instance *_instance, char * msg);
// Declaration of callbacks for incomming messages:
void register_WebSClient_send_lifecycle_onOpen_listener(void (*_listener)(struct WebSClient_Instance*));
void register_WebSClient_send_lifecycle_onClose_listener(void (*_listener)(struct WebSClient_Instance*));
void register_WebSClient_send_lifecycle_server_launched_listener(void (*_listener)(struct WebSClient_Instance*));
void register_WebSClient_send_lifecycle_client_launched_listener(void (*_listener)(struct WebSClient_Instance*));
void register_WebSClient_send_err_onError_listener(void (*_listener)(struct WebSClient_Instance*, char *));
void register_WebSClient_send_messaging_onMessage_listener(void (*_listener)(struct WebSClient_Instance*, char *));

// Definition of the states:
#define WEBSCLIENT_BEHAVIOR_STATE 0
#define WEBSCLIENT_BEHAVIOR_INIT_STATE 1
#define WEBSCLIENT_BEHAVIOR_START_STATE 2
#define WEBSCLIENT_BEHAVIOR_SERVE_STATE 3
#define WEBSCLIENT_BEHAVIOR_STOPPED_STATE 4




#endif //WebSClient_H_