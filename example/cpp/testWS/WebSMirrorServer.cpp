/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *        Implementation for Thing WebSMirrorServer
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#include "WebSMirrorServer.h"

/*****************************************************************************
 * Implementation for type : WebSMirrorServer
 *****************************************************************************/

// Declaration of prototypes:
void WebSMirrorServer_behavior_OnExit(int state, struct WebSMirrorServer_Instance *_instance);
void WebSMirrorServer_send_lifecycle_onOpen(struct WebSMirrorServer_Instance *_instance);
void WebSMirrorServer_send_lifecycle_onClose(struct WebSMirrorServer_Instance *_instance);
void WebSMirrorServer_send_lifecycle_server_launched(struct WebSMirrorServer_Instance *_instance);
void WebSMirrorServer_send_lifecycle_client_launched(struct WebSMirrorServer_Instance *_instance);
void WebSMirrorServer_send_err_onError(struct WebSMirrorServer_Instance *_instance, char * errorMsg);
void WebSMirrorServer_send_messaging_onMessage(struct WebSMirrorServer_Instance *_instance, char * msg);
void on_open_callback(void *_instance, ...);
void on_close_callback(void *_instance, ...);
void on_error_callback(void *_instance, ...);
void on_message_callback(void *_instance, ...);
void f_WebSMirrorServer_init_server(struct WebSMirrorServer_Instance *_instance);

// Declaration of functions:
// Definition of function on_open_callback
void on_open_callback(void *_instance, ...) {
{
printf("\tWebSocketMirrorServer: on_open_callback");
printf("THINGML: -> WebSMirrorServer_send_lifecycle_onOpen\n");
WebSMirrorServer_send_lifecycle_onOpen((WebSMirrorServer_Instance *) _instance);
}
}

// Definition of function on_close_callback
void on_close_callback(void *_instance, ...) {
{
printf("\tWebSocketMirrorServer: on_close_callback");
printf("THINGML: -> WebSMirrorServer_send_lifecycle_onClose\n");
WebSMirrorServer_send_lifecycle_onClose((WebSMirrorServer_Instance *) _instance);
}
}

// Definition of function on_error_callback
void on_error_callback(void *_instance, ...) {
{
va_list arguments;
va_start(arguments, _instance);
char* message = va_arg(arguments, char*);
va_end(arguments);
printf("\tWebSocketMirrorServer: on_error_callback with message -> %s\n", message);
printf("THINGML: -> WebSMirrorServer_send_err_onError\n");
WebSMirrorServer_send_err_onError((WebSMirrorServer_Instance *) _instance, message);
}
}

// Definition of function on_message_callback
void on_message_callback(void *_instance, ...) {
{
va_list arguments;
va_start(arguments, _instance);
char* message = va_arg(arguments, char*);
va_end(arguments);
printf("\tWebSocketMirrorServer: on_message_callback with message -> %s\n", message);
printf("THINGML: -> WebSMirrorServer_send_messaging_onMessage\n");
WebSMirrorServer_send_messaging_onMessage((WebSMirrorServer_Instance *) _instance, message);
}
}

// Definition of function init_server
void f_WebSMirrorServer_init_server(struct WebSMirrorServer_Instance *_instance) {
{
_instance->WebSMirrorServer_server_var = WebSocketFacade::InitWebSocketMirrorServer(atoi(_instance->WebSocket__port_var), NULL);;
ThingMLCallback* tml_op_open_callback = new ThingMLCallback(on_open_callback, _instance);
ThingMLCallback* tml_op_close_callback = new ThingMLCallback(on_close_callback, _instance);
ThingMLCallback* tml_op_error_callback = new ThingMLCallback(on_error_callback, _instance);
ThingMLCallback* tml_op_message_callback = new ThingMLCallback(on_message_callback, _instance);
_instance->WebSMirrorServer_server_var->setCallbacks(tml_op_open_callback, tml_op_close_callback, tml_op_message_callback, tml_op_error_callback);
}
}


// On Entry Actions:
void WebSMirrorServer_behavior_OnEntry(int state, struct WebSMirrorServer_Instance *_instance) {
switch(state) {
case WEBSMIRRORSERVER_BEHAVIOR_STATE:
_instance->WebSMirrorServer_behavior_State = WEBSMIRRORSERVER_BEHAVIOR_INIT_STATE;
WebSMirrorServer_behavior_OnEntry(_instance->WebSMirrorServer_behavior_State, _instance);
break;
case WEBSMIRRORSERVER_BEHAVIOR_INIT_STATE:
{
printf("\tINIT ON PORT: %s\n",_instance->WebSocket__port_var);
f_WebSMirrorServer_init_server(_instance);
}
break;
case WEBSMIRRORSERVER_BEHAVIOR_STARTED_STATE:
{
printf("\tserver attempts to start\n");
_instance->WebSMirrorServer_server_var->open();
printf("THINGML: -> WebSMirrorServer_send_lifecycle_server_launched\n");
WebSMirrorServer_send_lifecycle_server_launched(_instance);
}
break;
case WEBSMIRRORSERVER_BEHAVIOR_STOPPED_STATE:
_instance->WebSMirrorServer_server_var->close();
break;
default: break;
}
}

// On Exit Actions:
void WebSMirrorServer_behavior_OnExit(int state, struct WebSMirrorServer_Instance *_instance) {
switch(state) {
case WEBSMIRRORSERVER_BEHAVIOR_STATE:
WebSMirrorServer_behavior_OnExit(_instance->WebSMirrorServer_behavior_State, _instance);
break;
case WEBSMIRRORSERVER_BEHAVIOR_INIT_STATE:
break;
case WEBSMIRRORSERVER_BEHAVIOR_STARTED_STATE:
break;
case WEBSMIRRORSERVER_BEHAVIOR_STOPPED_STATE:
break;
default: break;
}
}

// Event Handlers for incomming messages:
void WebSMirrorServer_handle_lifecycle_start_server(struct WebSMirrorServer_Instance *_instance) {
printf("THINGML: <- WebSMirrorServer_handle_lifecycle_start_server\n");
if (_instance->WebSMirrorServer_behavior_State == WEBSMIRRORSERVER_BEHAVIOR_INIT_STATE) {
if (1) {
WebSMirrorServer_behavior_OnExit(WEBSMIRRORSERVER_BEHAVIOR_INIT_STATE, _instance);
_instance->WebSMirrorServer_behavior_State = WEBSMIRRORSERVER_BEHAVIOR_STARTED_STATE;
WebSMirrorServer_behavior_OnEntry(WEBSMIRRORSERVER_BEHAVIOR_STARTED_STATE, _instance);
}
}
}
void WebSMirrorServer_handle_lifecycle_stop_server(struct WebSMirrorServer_Instance *_instance) {
printf("THINGML: <- WebSMirrorServer_handle_lifecycle_stop_server\n");
if (_instance->WebSMirrorServer_behavior_State == WEBSMIRRORSERVER_BEHAVIOR_STARTED_STATE) {
if (1) {
WebSMirrorServer_behavior_OnExit(WEBSMIRRORSERVER_BEHAVIOR_STARTED_STATE, _instance);
_instance->WebSMirrorServer_behavior_State = WEBSMIRRORSERVER_BEHAVIOR_STOPPED_STATE;
WebSMirrorServer_behavior_OnEntry(WEBSMIRRORSERVER_BEHAVIOR_STOPPED_STATE, _instance);
}
}
}
void WebSMirrorServer_handle_lifecycle_start(struct WebSMirrorServer_Instance *_instance) {
printf("THINGML: <- WebSMirrorServer_handle_lifecycle_start\n");
if (_instance->WebSMirrorServer_behavior_State == WEBSMIRRORSERVER_BEHAVIOR_STOPPED_STATE) {
if (1) {
WebSMirrorServer_behavior_OnExit(WEBSMIRRORSERVER_BEHAVIOR_STOPPED_STATE, _instance);
_instance->WebSMirrorServer_behavior_State = WEBSMIRRORSERVER_BEHAVIOR_STARTED_STATE;
WebSMirrorServer_behavior_OnEntry(WEBSMIRRORSERVER_BEHAVIOR_STARTED_STATE, _instance);
}
}
}

// Observers for outgoing messages:
void (*WebSMirrorServer_send_lifecycle_onOpen_listener)(struct WebSMirrorServer_Instance*)= 0x0;
void register_WebSMirrorServer_send_lifecycle_onOpen_listener(void (*_listener)(struct WebSMirrorServer_Instance*)){
WebSMirrorServer_send_lifecycle_onOpen_listener = _listener;
}
void WebSMirrorServer_send_lifecycle_onOpen(struct WebSMirrorServer_Instance *_instance){
if (WebSMirrorServer_send_lifecycle_onOpen_listener != 0x0) WebSMirrorServer_send_lifecycle_onOpen_listener(_instance);
}
void (*WebSMirrorServer_send_lifecycle_onClose_listener)(struct WebSMirrorServer_Instance*)= 0x0;
void register_WebSMirrorServer_send_lifecycle_onClose_listener(void (*_listener)(struct WebSMirrorServer_Instance*)){
WebSMirrorServer_send_lifecycle_onClose_listener = _listener;
}
void WebSMirrorServer_send_lifecycle_onClose(struct WebSMirrorServer_Instance *_instance){
if (WebSMirrorServer_send_lifecycle_onClose_listener != 0x0) WebSMirrorServer_send_lifecycle_onClose_listener(_instance);
}
void (*WebSMirrorServer_send_lifecycle_server_launched_listener)(struct WebSMirrorServer_Instance*)= 0x0;
void register_WebSMirrorServer_send_lifecycle_server_launched_listener(void (*_listener)(struct WebSMirrorServer_Instance*)){
WebSMirrorServer_send_lifecycle_server_launched_listener = _listener;
}
void WebSMirrorServer_send_lifecycle_server_launched(struct WebSMirrorServer_Instance *_instance){
if (WebSMirrorServer_send_lifecycle_server_launched_listener != 0x0) WebSMirrorServer_send_lifecycle_server_launched_listener(_instance);
}
void (*WebSMirrorServer_send_lifecycle_client_launched_listener)(struct WebSMirrorServer_Instance*)= 0x0;
void register_WebSMirrorServer_send_lifecycle_client_launched_listener(void (*_listener)(struct WebSMirrorServer_Instance*)){
WebSMirrorServer_send_lifecycle_client_launched_listener = _listener;
}
void WebSMirrorServer_send_lifecycle_client_launched(struct WebSMirrorServer_Instance *_instance){
if (WebSMirrorServer_send_lifecycle_client_launched_listener != 0x0) WebSMirrorServer_send_lifecycle_client_launched_listener(_instance);
}
void (*WebSMirrorServer_send_err_onError_listener)(struct WebSMirrorServer_Instance*, char *)= 0x0;
void register_WebSMirrorServer_send_err_onError_listener(void (*_listener)(struct WebSMirrorServer_Instance*, char *)){
WebSMirrorServer_send_err_onError_listener = _listener;
}
void WebSMirrorServer_send_err_onError(struct WebSMirrorServer_Instance *_instance, char * errorMsg){
if (WebSMirrorServer_send_err_onError_listener != 0x0) WebSMirrorServer_send_err_onError_listener(_instance, errorMsg);
}
void (*WebSMirrorServer_send_messaging_onMessage_listener)(struct WebSMirrorServer_Instance*, char *)= 0x0;
void register_WebSMirrorServer_send_messaging_onMessage_listener(void (*_listener)(struct WebSMirrorServer_Instance*, char *)){
WebSMirrorServer_send_messaging_onMessage_listener = _listener;
}
void WebSMirrorServer_send_messaging_onMessage(struct WebSMirrorServer_Instance *_instance, char * msg){
if (WebSMirrorServer_send_messaging_onMessage_listener != 0x0) WebSMirrorServer_send_messaging_onMessage_listener(_instance, msg);
}

