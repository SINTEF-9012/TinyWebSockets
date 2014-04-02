/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *        Implementation for Thing Lifecicle
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#include "Lifecicle.h"

/*****************************************************************************
 * Implementation for type : Lifecicle
 *****************************************************************************/

// Declaration of prototypes:
void Lifecicle_behavior_OnExit(int state, struct Lifecicle_Instance *_instance);
void Lifecicle_send_lifecycle_start(struct Lifecicle_Instance *_instance);
void Lifecicle_send_lifecycle_stop(struct Lifecicle_Instance *_instance);
void Lifecicle_send_lifecycle_start_client(struct Lifecicle_Instance *_instance);
void Lifecicle_send_lifecycle_start_server(struct Lifecicle_Instance *_instance);
void Lifecicle_send_lifecycle_stop_client(struct Lifecicle_Instance *_instance);
void Lifecicle_send_lifecycle_stop_server(struct Lifecicle_Instance *_instance);
void Lifecicle_send_messaging_send(struct Lifecicle_Instance *_instance, char * msg);

// Declaration of functions:

// On Entry Actions:
void Lifecicle_behavior_OnEntry(int state, struct Lifecicle_Instance *_instance) {
switch(state) {
case LIFECICLE_BEHAVIOR_STATE:
_instance->Lifecicle_behavior_State = LIFECICLE_BEHAVIOR_RUNCLIENT_STATE;
Lifecicle_behavior_OnEntry(_instance->Lifecicle_behavior_State, _instance);
break;
case LIFECICLE_BEHAVIOR_RUNCLIENT_STATE:
{
fprintf(stdout, "\trunning client...\n");

printf("THINGML: -> Lifecicle_send_lifecycle_start_client\n");
Lifecicle_send_lifecycle_start_client(_instance);
}
break;
case LIFECICLE_BEHAVIOR_LOOP_STATE:
break;
default: break;
}
}

// On Exit Actions:
void Lifecicle_behavior_OnExit(int state, struct Lifecicle_Instance *_instance) {
switch(state) {
case LIFECICLE_BEHAVIOR_STATE:
Lifecicle_behavior_OnExit(_instance->Lifecicle_behavior_State, _instance);
break;
case LIFECICLE_BEHAVIOR_RUNCLIENT_STATE:
break;
case LIFECICLE_BEHAVIOR_LOOP_STATE:
break;
default: break;
}
}

// Event Handlers for incomming messages:
void Lifecicle_handle_messaging_onMessage(struct Lifecicle_Instance *_instance, char * msg) {
printf("THINGML: <- Lifecicle_handle_messaging_onMessage\n");
if (1) {
{
printf("test::onMessage %s\n",msg);
}
}
}
void Lifecicle_handle_err_onError(struct Lifecicle_Instance *_instance, char * errorMsg) {
printf("THINGML: <- Lifecicle_handle_err_onError\n");
if (1) {
fprintf(stdout, ("test::onError"));

}
}
void Lifecicle_handle_lifecycle_client_launched(struct Lifecicle_Instance *_instance) {
printf("THINGML: <- Lifecicle_handle_lifecycle_client_launched\n");
if (_instance->Lifecicle_behavior_State == LIFECICLE_BEHAVIOR_RUNCLIENT_STATE) {
if (1) {
Lifecicle_behavior_OnExit(LIFECICLE_BEHAVIOR_RUNCLIENT_STATE, _instance);
_instance->Lifecicle_behavior_State = LIFECICLE_BEHAVIOR_LOOP_STATE;
Lifecicle_behavior_OnEntry(LIFECICLE_BEHAVIOR_LOOP_STATE, _instance);
}
}
}
void Lifecicle_handle_lifecycle_onClose(struct Lifecicle_Instance *_instance) {
printf("THINGML: <- Lifecicle_handle_lifecycle_onClose\n");
if (1) {
fprintf(stdout, ("test::onClose"));

}
}
void Lifecicle_handle_lifecycle_onOpen(struct Lifecicle_Instance *_instance) {
printf("THINGML: <- Lifecicle_handle_lifecycle_onOpen\n");
if (1) {
fprintf(stdout, ("test::onOpen"));

}
}
void Lifecicle_handle_signal_clock_tick(struct Lifecicle_Instance *_instance) {
printf("THINGML: <- Lifecicle_handle_signal_clock_tick\n");
if (_instance->Lifecicle_behavior_State == LIFECICLE_BEHAVIOR_LOOP_STATE) {
if (1) {
Lifecicle_behavior_OnExit(LIFECICLE_BEHAVIOR_LOOP_STATE, _instance);
_instance->Lifecicle_behavior_State = LIFECICLE_BEHAVIOR_LOOP_STATE;
{
fprintf(stdout, "sending ping...\n");

printf("THINGML: -> Lifecicle_send_messaging_send\n");
Lifecicle_send_messaging_send(_instance, _instance->Lifecicle_pingmessage_var);
}
Lifecicle_behavior_OnEntry(LIFECICLE_BEHAVIOR_LOOP_STATE, _instance);
}
}
}

// Observers for outgoing messages:
void (*Lifecicle_send_lifecycle_start_listener)(struct Lifecicle_Instance*)= 0x0;
void register_Lifecicle_send_lifecycle_start_listener(void (*_listener)(struct Lifecicle_Instance*)){
Lifecicle_send_lifecycle_start_listener = _listener;
}
void Lifecicle_send_lifecycle_start(struct Lifecicle_Instance *_instance){
if (Lifecicle_send_lifecycle_start_listener != 0x0) Lifecicle_send_lifecycle_start_listener(_instance);
}
void (*Lifecicle_send_lifecycle_stop_listener)(struct Lifecicle_Instance*)= 0x0;
void register_Lifecicle_send_lifecycle_stop_listener(void (*_listener)(struct Lifecicle_Instance*)){
Lifecicle_send_lifecycle_stop_listener = _listener;
}
void Lifecicle_send_lifecycle_stop(struct Lifecicle_Instance *_instance){
if (Lifecicle_send_lifecycle_stop_listener != 0x0) Lifecicle_send_lifecycle_stop_listener(_instance);
}
void (*Lifecicle_send_lifecycle_start_client_listener)(struct Lifecicle_Instance*)= 0x0;
void register_Lifecicle_send_lifecycle_start_client_listener(void (*_listener)(struct Lifecicle_Instance*)){
Lifecicle_send_lifecycle_start_client_listener = _listener;
}
void Lifecicle_send_lifecycle_start_client(struct Lifecicle_Instance *_instance){
if (Lifecicle_send_lifecycle_start_client_listener != 0x0) Lifecicle_send_lifecycle_start_client_listener(_instance);
}
void (*Lifecicle_send_lifecycle_start_server_listener)(struct Lifecicle_Instance*)= 0x0;
void register_Lifecicle_send_lifecycle_start_server_listener(void (*_listener)(struct Lifecicle_Instance*)){
Lifecicle_send_lifecycle_start_server_listener = _listener;
}
void Lifecicle_send_lifecycle_start_server(struct Lifecicle_Instance *_instance){
if (Lifecicle_send_lifecycle_start_server_listener != 0x0) Lifecicle_send_lifecycle_start_server_listener(_instance);
}
void (*Lifecicle_send_lifecycle_stop_client_listener)(struct Lifecicle_Instance*)= 0x0;
void register_Lifecicle_send_lifecycle_stop_client_listener(void (*_listener)(struct Lifecicle_Instance*)){
Lifecicle_send_lifecycle_stop_client_listener = _listener;
}
void Lifecicle_send_lifecycle_stop_client(struct Lifecicle_Instance *_instance){
if (Lifecicle_send_lifecycle_stop_client_listener != 0x0) Lifecicle_send_lifecycle_stop_client_listener(_instance);
}
void (*Lifecicle_send_lifecycle_stop_server_listener)(struct Lifecicle_Instance*)= 0x0;
void register_Lifecicle_send_lifecycle_stop_server_listener(void (*_listener)(struct Lifecicle_Instance*)){
Lifecicle_send_lifecycle_stop_server_listener = _listener;
}
void Lifecicle_send_lifecycle_stop_server(struct Lifecicle_Instance *_instance){
if (Lifecicle_send_lifecycle_stop_server_listener != 0x0) Lifecicle_send_lifecycle_stop_server_listener(_instance);
}
void (*Lifecicle_send_messaging_send_listener)(struct Lifecicle_Instance*, char *)= 0x0;
void register_Lifecicle_send_messaging_send_listener(void (*_listener)(struct Lifecicle_Instance*, char *)){
Lifecicle_send_messaging_send_listener = _listener;
}
void Lifecicle_send_messaging_send(struct Lifecicle_Instance *_instance, char * msg){
if (Lifecicle_send_messaging_send_listener != 0x0) Lifecicle_send_messaging_send_listener(_instance, msg);
}

