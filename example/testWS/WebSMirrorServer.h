/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *           Header for Thing WebSMirrorServer
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#ifndef WebSMirrorServer_H_
#define WebSMirrorServer_H_


#include "thingml_typedefs.h"

/*****************************************************************************
 * Headers for type : WebSMirrorServer
 *****************************************************************************/


// BEGIN: Code from the c_header annotation WebSMirrorServer

#include <stdlib.h>
#include <cstdarg>
#include "tinyws/client-server/WebSocketFacade.h"
#include "tinyws/client-server/WebSocketClient.h"
#include "tinyws/client-server/WebSocketMirrorServer.h"

using namespace WebSockets;

// END: Code from the c_header annotation WebSMirrorServer

// Definition of the instance stuct:
struct WebSMirrorServer_Instance {
// Variables for the ID of the instance
int id;
// Variables for the current instance state
int WebSMirrorServer_behavior_State;
// Variables for the properties of the instance
WebSocketMirrorServer* WebSMirrorServer_server_var;
const char* WebSocket__port_var;
};

// Declaration of prototypes outgoing messages:
void WebSMirrorServer_behavior_OnEntry(int state, struct WebSMirrorServer_Instance *_instance);
void WebSMirrorServer_handle_lifecycle_start_server(struct WebSMirrorServer_Instance *_instance);
void WebSMirrorServer_handle_lifecycle_stop_server(struct WebSMirrorServer_Instance *_instance);
void WebSMirrorServer_handle_lifecycle_start(struct WebSMirrorServer_Instance *_instance);
// Declaration of callbacks for incomming messages:
void register_WebSMirrorServer_send_lifecycle_onOpen_listener(void (*_listener)(struct WebSMirrorServer_Instance*));
void register_WebSMirrorServer_send_lifecycle_onClose_listener(void (*_listener)(struct WebSMirrorServer_Instance*));
void register_WebSMirrorServer_send_lifecycle_server_launched_listener(void (*_listener)(struct WebSMirrorServer_Instance*));
void register_WebSMirrorServer_send_lifecycle_client_launched_listener(void (*_listener)(struct WebSMirrorServer_Instance*));
void register_WebSMirrorServer_send_err_onError_listener(void (*_listener)(struct WebSMirrorServer_Instance*, char *));
void register_WebSMirrorServer_send_messaging_onMessage_listener(void (*_listener)(struct WebSMirrorServer_Instance*, char *));

// Definition of the states:
#define WEBSMIRRORSERVER_BEHAVIOR_STATE 0
#define WEBSMIRRORSERVER_BEHAVIOR_INIT_STATE 1
#define WEBSMIRRORSERVER_BEHAVIOR_STARTED_STATE 2
#define WEBSMIRRORSERVER_BEHAVIOR_STOPPED_STATE 3




#endif //WebSMirrorServer_H_