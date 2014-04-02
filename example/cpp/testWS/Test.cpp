/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *        Implementation for Thing Test
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#include "Test.h"

/*****************************************************************************
 * Implementation for type : Test
 *****************************************************************************/

// Declaration of prototypes:
void Test_behavior_OnExit(int state, struct Test_Instance *_instance);
void Test_send_lifecycle_start(struct Test_Instance *_instance);
void Test_send_lifecycle_stop(struct Test_Instance *_instance);
void Test_send_lifecycle_start_client(struct Test_Instance *_instance);
void Test_send_lifecycle_start_server(struct Test_Instance *_instance);
void Test_send_lifecycle_stop_client(struct Test_Instance *_instance);
void Test_send_lifecycle_stop_server(struct Test_Instance *_instance);
void Test_send_messaging_send(struct Test_Instance *_instance, char * msg);

// Declaration of functions:

// On Entry Actions:
void Test_behavior_OnEntry(int state, struct Test_Instance *_instance) {
switch(state) {
case TEST_BEHAVIOR_STATE:
_instance->Test_behavior_State = TEST_BEHAVIOR_RUNSERVER_STATE;
Test_behavior_OnEntry(_instance->Test_behavior_State, _instance);
break;
case TEST_BEHAVIOR_RUNSERVER_STATE:
{
fprintf(stdout, "\trunning server...\n");

printf("THINGML: -> Test_send_lifecycle_start_server\n");
Test_send_lifecycle_start_server(_instance);
}
break;
case TEST_BEHAVIOR_RUNCLIENT_STATE:
{
fprintf(stdout, "\trunning client...\n");

printf("THINGML: -> Test_send_lifecycle_start_client\n");
Test_send_lifecycle_start_client(_instance);
}
break;
case TEST_BEHAVIOR_LOOP_STATE:
break;
default: break;
}
}

// On Exit Actions:
void Test_behavior_OnExit(int state, struct Test_Instance *_instance) {
switch(state) {
case TEST_BEHAVIOR_STATE:
Test_behavior_OnExit(_instance->Test_behavior_State, _instance);
break;
case TEST_BEHAVIOR_RUNSERVER_STATE:
break;
case TEST_BEHAVIOR_RUNCLIENT_STATE:
break;
case TEST_BEHAVIOR_LOOP_STATE:
break;
default: break;
}
}

// Event Handlers for incomming messages:
void Test_handle_lifecycle_onOpen(struct Test_Instance *_instance) {
printf("THINGML: <- Test_handle_lifecycle_onOpen\n");
if (1) {
fprintf(stdout, ("test::onOpen"));

}
}
void Test_handle_lifecycle_client_launched(struct Test_Instance *_instance) {
printf("THINGML: <- Test_handle_lifecycle_client_launched\n");
if (_instance->Test_behavior_State == TEST_BEHAVIOR_RUNCLIENT_STATE) {
if (1) {
Test_behavior_OnExit(TEST_BEHAVIOR_RUNCLIENT_STATE, _instance);
_instance->Test_behavior_State = TEST_BEHAVIOR_LOOP_STATE;
Test_behavior_OnEntry(TEST_BEHAVIOR_LOOP_STATE, _instance);
}
}
}
void Test_handle_lifecycle_server_launched(struct Test_Instance *_instance) {
printf("THINGML: <- Test_handle_lifecycle_server_launched\n");
if (_instance->Test_behavior_State == TEST_BEHAVIOR_RUNSERVER_STATE) {
if (1) {
Test_behavior_OnExit(TEST_BEHAVIOR_RUNSERVER_STATE, _instance);
_instance->Test_behavior_State = TEST_BEHAVIOR_RUNCLIENT_STATE;
Test_behavior_OnEntry(TEST_BEHAVIOR_RUNCLIENT_STATE, _instance);
}
}
}
void Test_handle_lifecycle_onClose(struct Test_Instance *_instance) {
printf("THINGML: <- Test_handle_lifecycle_onClose\n");
if (1) {
fprintf(stdout, ("test::onClose"));

}
}
void Test_handle_messaging_onMessage(struct Test_Instance *_instance, char * msg) {
printf("THINGML: <- Test_handle_messaging_onMessage\n");
if (1) {
{
printf("test::onMessage %s\n",msg);
}
}
}
void Test_handle_signal_clock_tick(struct Test_Instance *_instance) {
printf("THINGML: <- Test_handle_signal_clock_tick\n");
if (_instance->Test_behavior_State == TEST_BEHAVIOR_LOOP_STATE) {
if (1) {
Test_behavior_OnExit(TEST_BEHAVIOR_LOOP_STATE, _instance);
_instance->Test_behavior_State = TEST_BEHAVIOR_LOOP_STATE;
{
fprintf(stdout, "sending ping...\n");

printf("THINGML: -> Test_send_messaging_send\n");
Test_send_messaging_send(_instance, _instance->Test_pingmessage_var);
}
Test_behavior_OnEntry(TEST_BEHAVIOR_LOOP_STATE, _instance);
}
}
}
void Test_handle_err_onError(struct Test_Instance *_instance, char * errorMsg) {
printf("THINGML: <- Test_handle_err_onError\n");
if (1) {
fprintf(stdout, ("test::onError"));

}
}

// Observers for outgoing messages:
void (*Test_send_lifecycle_start_listener)(struct Test_Instance*)= 0x0;
void register_Test_send_lifecycle_start_listener(void (*_listener)(struct Test_Instance*)){
Test_send_lifecycle_start_listener = _listener;
}
void Test_send_lifecycle_start(struct Test_Instance *_instance){
if (Test_send_lifecycle_start_listener != 0x0) Test_send_lifecycle_start_listener(_instance);
}
void (*Test_send_lifecycle_stop_listener)(struct Test_Instance*)= 0x0;
void register_Test_send_lifecycle_stop_listener(void (*_listener)(struct Test_Instance*)){
Test_send_lifecycle_stop_listener = _listener;
}
void Test_send_lifecycle_stop(struct Test_Instance *_instance){
if (Test_send_lifecycle_stop_listener != 0x0) Test_send_lifecycle_stop_listener(_instance);
}
void (*Test_send_lifecycle_start_client_listener)(struct Test_Instance*)= 0x0;
void register_Test_send_lifecycle_start_client_listener(void (*_listener)(struct Test_Instance*)){
Test_send_lifecycle_start_client_listener = _listener;
}
void Test_send_lifecycle_start_client(struct Test_Instance *_instance){
if (Test_send_lifecycle_start_client_listener != 0x0) Test_send_lifecycle_start_client_listener(_instance);
}
void (*Test_send_lifecycle_start_server_listener)(struct Test_Instance*)= 0x0;
void register_Test_send_lifecycle_start_server_listener(void (*_listener)(struct Test_Instance*)){
Test_send_lifecycle_start_server_listener = _listener;
}
void Test_send_lifecycle_start_server(struct Test_Instance *_instance){
if (Test_send_lifecycle_start_server_listener != 0x0) Test_send_lifecycle_start_server_listener(_instance);
}
void (*Test_send_lifecycle_stop_client_listener)(struct Test_Instance*)= 0x0;
void register_Test_send_lifecycle_stop_client_listener(void (*_listener)(struct Test_Instance*)){
Test_send_lifecycle_stop_client_listener = _listener;
}
void Test_send_lifecycle_stop_client(struct Test_Instance *_instance){
if (Test_send_lifecycle_stop_client_listener != 0x0) Test_send_lifecycle_stop_client_listener(_instance);
}
void (*Test_send_lifecycle_stop_server_listener)(struct Test_Instance*)= 0x0;
void register_Test_send_lifecycle_stop_server_listener(void (*_listener)(struct Test_Instance*)){
Test_send_lifecycle_stop_server_listener = _listener;
}
void Test_send_lifecycle_stop_server(struct Test_Instance *_instance){
if (Test_send_lifecycle_stop_server_listener != 0x0) Test_send_lifecycle_stop_server_listener(_instance);
}
void (*Test_send_messaging_send_listener)(struct Test_Instance*, char *)= 0x0;
void register_Test_send_messaging_send_listener(void (*_listener)(struct Test_Instance*, char *)){
Test_send_messaging_send_listener = _listener;
}
void Test_send_messaging_send(struct Test_Instance *_instance, char * msg){
if (Test_send_messaging_send_listener != 0x0) Test_send_messaging_send_listener(_instance, msg);
}

