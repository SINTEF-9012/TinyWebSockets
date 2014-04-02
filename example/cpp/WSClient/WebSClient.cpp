/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *        Implementation for Thing WebSClient
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#include "WebSClient.h"

/*****************************************************************************
 * Implementation for type : WebSClient
 *****************************************************************************/

// Declaration of prototypes:
void WebSClient_behavior_OnExit(int state, struct WebSClient_Instance *_instance);
void WebSClient_send_lifecycle_onOpen(struct WebSClient_Instance *_instance);
void WebSClient_send_lifecycle_onClose(struct WebSClient_Instance *_instance);
void WebSClient_send_lifecycle_server_launched(struct WebSClient_Instance *_instance);
void WebSClient_send_lifecycle_client_launched(struct WebSClient_Instance *_instance);
void WebSClient_send_err_onError(struct WebSClient_Instance *_instance, char * errorMsg);
void WebSClient_send_messaging_onMessage(struct WebSClient_Instance *_instance, char * msg);
void on_open_callback_client(void *_instance, ...);
void on_close_callback_client(void *_instance, ...);
void on_error_callback_client(void *_instance, ...);
void on_message_callback_client(void *_instance, ...);
void f_WebSClient_init_client(struct WebSClient_Instance *_instance);

// Declaration of functions:
// Definition of function on_open_callback_client
void on_open_callback_client(void *_instance, ...) {
{
printf("\tWebSocketClient: on_open_callback\n");
printf("THINGML: -> WebSClient_send_lifecycle_onOpen\n");
WebSClient_send_lifecycle_onOpen((WebSClient_Instance *) _instance);
}
}

// Definition of function on_close_callback_client
void on_close_callback_client(void *_instance, ...) {
{
printf("\tWebSocketClient: on_close_callback\n");
printf("THINGML: -> WebSClient_send_lifecycle_onClose\n");
WebSClient_send_lifecycle_onClose((WebSClient_Instance *) _instance);
}
}

// Definition of function on_error_callback_client
void on_error_callback_client(void *_instance, ...) {
{
va_list arguments;
va_start(arguments, _instance);
char* message = va_arg(arguments, char*);
va_end(arguments);
printf("\tWebSocketClient: on_error_callback with message -> %s\n", message);
printf("THINGML: -> WebSClient_send_err_onError\n");
WebSClient_send_err_onError((WebSClient_Instance *) _instance, message);
}
}

// Definition of function on_message_callback_client
void on_message_callback_client(void *_instance, ...) {
{
va_list arguments;
va_start(arguments, _instance);
char* message = va_arg(arguments, char*);
va_end(arguments);
printf("\tWebSocketClient: on_message_callback with message -> %s\n", message);
printf("THINGML: -> WebSClient_send_messaging_onMessage\n");
WebSClient_send_messaging_onMessage((WebSClient_Instance *) _instance, message);
}
}

// Definition of function init_client
void f_WebSClient_init_client(struct WebSClient_Instance *_instance) {
{
_instance->WebSClient_client_var = WebSocketFacade::InitWebSocketClient(_instance->WebSClient__host_var, atoi(_instance->WebSocket__port_var), NULL);;
ThingMLCallback* tml_op_open_callback = new ThingMLCallback(on_open_callback_client, _instance);
ThingMLCallback* tml_op_close_callback = new ThingMLCallback(on_close_callback_client, _instance);
ThingMLCallback* tml_op_error_callback = new ThingMLCallback(on_error_callback_client, _instance);
ThingMLCallback* tml_op_message_callback = new ThingMLCallback(on_message_callback_client, _instance);
_instance->WebSClient_client_var->setCallbacks(tml_op_open_callback, tml_op_close_callback, tml_op_message_callback, tml_op_error_callback);
}
}


// On Entry Actions:
void WebSClient_behavior_OnEntry(int state, struct WebSClient_Instance *_instance) {
switch(state) {
case WEBSCLIENT_BEHAVIOR_STATE:
_instance->WebSClient_behavior_State = WEBSCLIENT_BEHAVIOR_INIT_STATE;
WebSClient_behavior_OnEntry(_instance->WebSClient_behavior_State, _instance);
break;
case WEBSCLIENT_BEHAVIOR_INIT_STATE:
{
printf("\tINIT CLIENT ON HOST: %s %s\n",_instance->WebSClient__host_var, _instance->WebSocket__port_var);
f_WebSClient_init_client(_instance);
}
break;
case WEBSCLIENT_BEHAVIOR_START_STATE:
{
printf("\tclient attempts to establish connection\n");
_instance->WebSClient_client_var->open();
printf("THINGML: -> WebSClient_send_lifecycle_client_launched\n");
WebSClient_send_lifecycle_client_launched(_instance);
}
break;
case WEBSCLIENT_BEHAVIOR_SERVE_STATE:
{
printf("\tclient is in a serving state\n");
}
break;
case WEBSCLIENT_BEHAVIOR_STOPPED_STATE:
_instance->WebSClient_client_var->close();
break;
default: break;
}
}

// On Exit Actions:
void WebSClient_behavior_OnExit(int state, struct WebSClient_Instance *_instance) {
switch(state) {
case WEBSCLIENT_BEHAVIOR_STATE:
WebSClient_behavior_OnExit(_instance->WebSClient_behavior_State, _instance);
break;
case WEBSCLIENT_BEHAVIOR_INIT_STATE:
break;
case WEBSCLIENT_BEHAVIOR_START_STATE:
break;
case WEBSCLIENT_BEHAVIOR_SERVE_STATE:
break;
case WEBSCLIENT_BEHAVIOR_STOPPED_STATE:
break;
default: break;
}
}

// Event Handlers for incomming messages:
void WebSClient_handle_lifecycle_stop_client(struct WebSClient_Instance *_instance) {
printf("THINGML: <- WebSClient_handle_lifecycle_stop_client\n");
if (_instance->WebSClient_behavior_State == WEBSCLIENT_BEHAVIOR_SERVE_STATE) {
if (1) {
WebSClient_behavior_OnExit(WEBSCLIENT_BEHAVIOR_SERVE_STATE, _instance);
_instance->WebSClient_behavior_State = WEBSCLIENT_BEHAVIOR_STOPPED_STATE;
WebSClient_behavior_OnEntry(WEBSCLIENT_BEHAVIOR_STOPPED_STATE, _instance);
}
}
}
void WebSClient_handle_lifecycle_start_client(struct WebSClient_Instance *_instance) {
printf("THINGML: <- WebSClient_handle_lifecycle_start_client\n");
if (_instance->WebSClient_behavior_State == WEBSCLIENT_BEHAVIOR_INIT_STATE) {
if (1) {
WebSClient_behavior_OnExit(WEBSCLIENT_BEHAVIOR_INIT_STATE, _instance);
_instance->WebSClient_behavior_State = WEBSCLIENT_BEHAVIOR_START_STATE;
WebSClient_behavior_OnEntry(WEBSCLIENT_BEHAVIOR_START_STATE, _instance);
}
}
else if (_instance->WebSClient_behavior_State == WEBSCLIENT_BEHAVIOR_STOPPED_STATE) {
if (1) {
WebSClient_behavior_OnExit(WEBSCLIENT_BEHAVIOR_STOPPED_STATE, _instance);
_instance->WebSClient_behavior_State = WEBSCLIENT_BEHAVIOR_START_STATE;
WebSClient_behavior_OnEntry(WEBSCLIENT_BEHAVIOR_START_STATE, _instance);
}
}
}
void WebSClient_handle_messaging_send(struct WebSClient_Instance *_instance, char * msg) {
printf("THINGML: <- WebSClient_handle_messaging_send\n");
if (_instance->WebSClient_behavior_State == WEBSCLIENT_BEHAVIOR_START_STATE) {
if (1) {
WebSClient_behavior_OnExit(WEBSCLIENT_BEHAVIOR_START_STATE, _instance);
_instance->WebSClient_behavior_State = WEBSCLIENT_BEHAVIOR_SERVE_STATE;
WebSClient_behavior_OnEntry(WEBSCLIENT_BEHAVIOR_SERVE_STATE, _instance);
}
}
else if (_instance->WebSClient_behavior_State == WEBSCLIENT_BEHAVIOR_SERVE_STATE) {
if (1) {
{
char dev_value[1024];
snprintf(dev_value, 1024, "%s from client 0x%08x", strdup(msg), _instance->WebSClient_client_var);
_instance->WebSClient_client_var->sendMessage(dev_value);
}
}
}
}

// Observers for outgoing messages:
void (*WebSClient_send_lifecycle_onOpen_listener)(struct WebSClient_Instance*)= 0x0;
void register_WebSClient_send_lifecycle_onOpen_listener(void (*_listener)(struct WebSClient_Instance*)){
WebSClient_send_lifecycle_onOpen_listener = _listener;
}
void WebSClient_send_lifecycle_onOpen(struct WebSClient_Instance *_instance){
if (WebSClient_send_lifecycle_onOpen_listener != 0x0) WebSClient_send_lifecycle_onOpen_listener(_instance);
}
void (*WebSClient_send_lifecycle_onClose_listener)(struct WebSClient_Instance*)= 0x0;
void register_WebSClient_send_lifecycle_onClose_listener(void (*_listener)(struct WebSClient_Instance*)){
WebSClient_send_lifecycle_onClose_listener = _listener;
}
void WebSClient_send_lifecycle_onClose(struct WebSClient_Instance *_instance){
if (WebSClient_send_lifecycle_onClose_listener != 0x0) WebSClient_send_lifecycle_onClose_listener(_instance);
}
void (*WebSClient_send_lifecycle_server_launched_listener)(struct WebSClient_Instance*)= 0x0;
void register_WebSClient_send_lifecycle_server_launched_listener(void (*_listener)(struct WebSClient_Instance*)){
WebSClient_send_lifecycle_server_launched_listener = _listener;
}
void WebSClient_send_lifecycle_server_launched(struct WebSClient_Instance *_instance){
if (WebSClient_send_lifecycle_server_launched_listener != 0x0) WebSClient_send_lifecycle_server_launched_listener(_instance);
}
void (*WebSClient_send_lifecycle_client_launched_listener)(struct WebSClient_Instance*)= 0x0;
void register_WebSClient_send_lifecycle_client_launched_listener(void (*_listener)(struct WebSClient_Instance*)){
WebSClient_send_lifecycle_client_launched_listener = _listener;
}
void WebSClient_send_lifecycle_client_launched(struct WebSClient_Instance *_instance){
if (WebSClient_send_lifecycle_client_launched_listener != 0x0) WebSClient_send_lifecycle_client_launched_listener(_instance);
}
void (*WebSClient_send_err_onError_listener)(struct WebSClient_Instance*, char *)= 0x0;
void register_WebSClient_send_err_onError_listener(void (*_listener)(struct WebSClient_Instance*, char *)){
WebSClient_send_err_onError_listener = _listener;
}
void WebSClient_send_err_onError(struct WebSClient_Instance *_instance, char * errorMsg){
if (WebSClient_send_err_onError_listener != 0x0) WebSClient_send_err_onError_listener(_instance, errorMsg);
}
void (*WebSClient_send_messaging_onMessage_listener)(struct WebSClient_Instance*, char *)= 0x0;
void register_WebSClient_send_messaging_onMessage_listener(void (*_listener)(struct WebSClient_Instance*, char *)){
WebSClient_send_messaging_onMessage_listener = _listener;
}
void WebSClient_send_messaging_onMessage(struct WebSClient_Instance *_instance, char * msg){
if (WebSClient_send_messaging_onMessage_listener != 0x0) WebSClient_send_messaging_onMessage_listener(_instance, msg);
}

