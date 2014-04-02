/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *      Implementation for Application WSClient
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <signal.h>
#include <pthread.h>
#include "thingml_typedefs.h"
#include "runtime.h"
#include "Lifecicle.h"
#include "ClockLinux.h"
#include "WebSClient.h"


// NO C_HEADERS Annotation


/*****************************************************************************
 * Definitions for configuration : WSClient
 *****************************************************************************/

//Declaration of instance variables
struct Lifecicle_Instance WSClient_lifecicle_var;
struct ClockLinux_Instance WSClient_clock_var;
struct WebSClient_Instance WSClient_client_var;

// Enqueue of messages Lifecicle::lifecycle::stop_client
void enqueue_Lifecicle_send_lifecycle_stop_client(struct Lifecicle_Instance *_instance){
fifo_lock();
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (1 >> 8) & 0xFF );
_fifo_enqueue( 1 & 0xFF );

// ID of the source instance
_fifo_enqueue( (_instance->id >> 8) & 0xFF );
_fifo_enqueue( _instance->id & 0xFF );
}
else {
printf("THINGML: FIFO FULL (lost msg stop_client)\n");
}
fifo_unlock_and_notify();
}
// Enqueue of messages Lifecicle::lifecycle::stop
void enqueue_Lifecicle_send_lifecycle_stop(struct Lifecicle_Instance *_instance){
fifo_lock();
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (2 >> 8) & 0xFF );
_fifo_enqueue( 2 & 0xFF );

// ID of the source instance
_fifo_enqueue( (_instance->id >> 8) & 0xFF );
_fifo_enqueue( _instance->id & 0xFF );
}
else {
printf("THINGML: FIFO FULL (lost msg stop)\n");
}
fifo_unlock_and_notify();
}
// Enqueue of messages Lifecicle::lifecycle::start
void enqueue_Lifecicle_send_lifecycle_start(struct Lifecicle_Instance *_instance){
fifo_lock();
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (3 >> 8) & 0xFF );
_fifo_enqueue( 3 & 0xFF );

// ID of the source instance
_fifo_enqueue( (_instance->id >> 8) & 0xFF );
_fifo_enqueue( _instance->id & 0xFF );
}
else {
printf("THINGML: FIFO FULL (lost msg start)\n");
}
fifo_unlock_and_notify();
}
// Enqueue of messages Lifecicle::lifecycle::start_client
void enqueue_Lifecicle_send_lifecycle_start_client(struct Lifecicle_Instance *_instance){
fifo_lock();
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (4 >> 8) & 0xFF );
_fifo_enqueue( 4 & 0xFF );

// ID of the source instance
_fifo_enqueue( (_instance->id >> 8) & 0xFF );
_fifo_enqueue( _instance->id & 0xFF );
}
else {
printf("THINGML: FIFO FULL (lost msg start_client)\n");
}
fifo_unlock_and_notify();
}
// Enqueue of messages Lifecicle::lifecycle::start_server
void enqueue_Lifecicle_send_lifecycle_start_server(struct Lifecicle_Instance *_instance){
fifo_lock();
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (5 >> 8) & 0xFF );
_fifo_enqueue( 5 & 0xFF );

// ID of the source instance
_fifo_enqueue( (_instance->id >> 8) & 0xFF );
_fifo_enqueue( _instance->id & 0xFF );
}
else {
printf("THINGML: FIFO FULL (lost msg start_server)\n");
}
fifo_unlock_and_notify();
}
// Enqueue of messages Lifecicle::lifecycle::stop_server
void enqueue_Lifecicle_send_lifecycle_stop_server(struct Lifecicle_Instance *_instance){
fifo_lock();
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (6 >> 8) & 0xFF );
_fifo_enqueue( 6 & 0xFF );

// ID of the source instance
_fifo_enqueue( (_instance->id >> 8) & 0xFF );
_fifo_enqueue( _instance->id & 0xFF );
}
else {
printf("THINGML: FIFO FULL (lost msg stop_server)\n");
}
fifo_unlock_and_notify();
}
// Enqueue of messages Lifecicle::messaging::send
void enqueue_Lifecicle_send_messaging_send(struct Lifecicle_Instance *_instance, char * msg){
fifo_lock();
if ( fifo_byte_available() > 12 ) {

_fifo_enqueue( (7 >> 8) & 0xFF );
_fifo_enqueue( 7 & 0xFF );

// ID of the source instance
_fifo_enqueue( (_instance->id >> 8) & 0xFF );
_fifo_enqueue( _instance->id & 0xFF );

// parameter msg
ptr_union_t __ptrunion_msg;
__ptrunion_msg.pointer = (void*)msg;
_fifo_enqueue( __ptrunion_msg.buffer[0] );
_fifo_enqueue( __ptrunion_msg.buffer[1] );
_fifo_enqueue( __ptrunion_msg.buffer[2] );
_fifo_enqueue( __ptrunion_msg.buffer[3] );
_fifo_enqueue( __ptrunion_msg.buffer[4] );
_fifo_enqueue( __ptrunion_msg.buffer[5] );
_fifo_enqueue( __ptrunion_msg.buffer[6] );
_fifo_enqueue( __ptrunion_msg.buffer[7] );
}
else {
printf("THINGML: FIFO FULL (lost msg send)\n");
}
fifo_unlock_and_notify();
}
// Enqueue of messages ClockLinux::signal::clock_tick
void enqueue_ClockLinux_send_signal_clock_tick(struct ClockLinux_Instance *_instance){
fifo_lock();
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (8 >> 8) & 0xFF );
_fifo_enqueue( 8 & 0xFF );

// ID of the source instance
_fifo_enqueue( (_instance->id >> 8) & 0xFF );
_fifo_enqueue( _instance->id & 0xFF );
}
else {
printf("THINGML: FIFO FULL (lost msg clock_tick)\n");
}
fifo_unlock_and_notify();
}
// Enqueue of messages WebSClient::lifecycle::server_launched
void enqueue_WebSClient_send_lifecycle_server_launched(struct WebSClient_Instance *_instance){
fifo_lock();
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (9 >> 8) & 0xFF );
_fifo_enqueue( 9 & 0xFF );

// ID of the source instance
_fifo_enqueue( (_instance->id >> 8) & 0xFF );
_fifo_enqueue( _instance->id & 0xFF );
}
else {
printf("THINGML: FIFO FULL (lost msg server_launched)\n");
}
fifo_unlock_and_notify();
}
// Enqueue of messages WebSClient::lifecycle::onClose
void enqueue_WebSClient_send_lifecycle_onClose(struct WebSClient_Instance *_instance){
fifo_lock();
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (10 >> 8) & 0xFF );
_fifo_enqueue( 10 & 0xFF );

// ID of the source instance
_fifo_enqueue( (_instance->id >> 8) & 0xFF );
_fifo_enqueue( _instance->id & 0xFF );
}
else {
printf("THINGML: FIFO FULL (lost msg onClose)\n");
}
fifo_unlock_and_notify();
}
// Enqueue of messages WebSClient::lifecycle::onOpen
void enqueue_WebSClient_send_lifecycle_onOpen(struct WebSClient_Instance *_instance){
fifo_lock();
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (11 >> 8) & 0xFF );
_fifo_enqueue( 11 & 0xFF );

// ID of the source instance
_fifo_enqueue( (_instance->id >> 8) & 0xFF );
_fifo_enqueue( _instance->id & 0xFF );
}
else {
printf("THINGML: FIFO FULL (lost msg onOpen)\n");
}
fifo_unlock_and_notify();
}
// Enqueue of messages WebSClient::lifecycle::client_launched
void enqueue_WebSClient_send_lifecycle_client_launched(struct WebSClient_Instance *_instance){
fifo_lock();
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (12 >> 8) & 0xFF );
_fifo_enqueue( 12 & 0xFF );

// ID of the source instance
_fifo_enqueue( (_instance->id >> 8) & 0xFF );
_fifo_enqueue( _instance->id & 0xFF );
}
else {
printf("THINGML: FIFO FULL (lost msg client_launched)\n");
}
fifo_unlock_and_notify();
}
// Enqueue of messages WebSClient::err::onError
void enqueue_WebSClient_send_err_onError(struct WebSClient_Instance *_instance, char * errorMsg){
fifo_lock();
if ( fifo_byte_available() > 12 ) {

_fifo_enqueue( (13 >> 8) & 0xFF );
_fifo_enqueue( 13 & 0xFF );

// ID of the source instance
_fifo_enqueue( (_instance->id >> 8) & 0xFF );
_fifo_enqueue( _instance->id & 0xFF );

// parameter errorMsg
ptr_union_t __ptrunion_errorMsg;
__ptrunion_errorMsg.pointer = (void*)errorMsg;
_fifo_enqueue( __ptrunion_errorMsg.buffer[0] );
_fifo_enqueue( __ptrunion_errorMsg.buffer[1] );
_fifo_enqueue( __ptrunion_errorMsg.buffer[2] );
_fifo_enqueue( __ptrunion_errorMsg.buffer[3] );
_fifo_enqueue( __ptrunion_errorMsg.buffer[4] );
_fifo_enqueue( __ptrunion_errorMsg.buffer[5] );
_fifo_enqueue( __ptrunion_errorMsg.buffer[6] );
_fifo_enqueue( __ptrunion_errorMsg.buffer[7] );
}
else {
printf("THINGML: FIFO FULL (lost msg onError)\n");
}
fifo_unlock_and_notify();
}
// Enqueue of messages WebSClient::messaging::onMessage
void enqueue_WebSClient_send_messaging_onMessage(struct WebSClient_Instance *_instance, char * msg){
fifo_lock();
if ( fifo_byte_available() > 12 ) {

_fifo_enqueue( (14 >> 8) & 0xFF );
_fifo_enqueue( 14 & 0xFF );

// ID of the source instance
_fifo_enqueue( (_instance->id >> 8) & 0xFF );
_fifo_enqueue( _instance->id & 0xFF );

// parameter msg
ptr_union_t __ptrunion_msg;
__ptrunion_msg.pointer = (void*)msg;
_fifo_enqueue( __ptrunion_msg.buffer[0] );
_fifo_enqueue( __ptrunion_msg.buffer[1] );
_fifo_enqueue( __ptrunion_msg.buffer[2] );
_fifo_enqueue( __ptrunion_msg.buffer[3] );
_fifo_enqueue( __ptrunion_msg.buffer[4] );
_fifo_enqueue( __ptrunion_msg.buffer[5] );
_fifo_enqueue( __ptrunion_msg.buffer[6] );
_fifo_enqueue( __ptrunion_msg.buffer[7] );
}
else {
printf("THINGML: FIFO FULL (lost msg onMessage)\n");
}
fifo_unlock_and_notify();
}

// Dispatch for messages Lifecicle::lifecycle::stop_client
void dispatch_Lifecicle_send_lifecycle_stop_client(struct Lifecicle_Instance *_instance){
if (_instance == &WSClient_lifecicle_var) {
WebSClient_handle_lifecycle_stop_client(&WSClient_client_var);
}
}
// Dispatch for messages Lifecicle::lifecycle::stop
void dispatch_Lifecicle_send_lifecycle_stop(struct Lifecicle_Instance *_instance){
if (_instance == &WSClient_lifecicle_var) {
}
}
// Dispatch for messages Lifecicle::lifecycle::start
void dispatch_Lifecicle_send_lifecycle_start(struct Lifecicle_Instance *_instance){
if (_instance == &WSClient_lifecicle_var) {
}
}
// Dispatch for messages Lifecicle::lifecycle::start_client
void dispatch_Lifecicle_send_lifecycle_start_client(struct Lifecicle_Instance *_instance){
if (_instance == &WSClient_lifecicle_var) {
WebSClient_handle_lifecycle_start_client(&WSClient_client_var);
}
}
// Dispatch for messages Lifecicle::lifecycle::start_server
void dispatch_Lifecicle_send_lifecycle_start_server(struct Lifecicle_Instance *_instance){
if (_instance == &WSClient_lifecicle_var) {
}
}
// Dispatch for messages Lifecicle::lifecycle::stop_server
void dispatch_Lifecicle_send_lifecycle_stop_server(struct Lifecicle_Instance *_instance){
if (_instance == &WSClient_lifecicle_var) {
}
}
// Dispatch for messages Lifecicle::messaging::send
void dispatch_Lifecicle_send_messaging_send(struct Lifecicle_Instance *_instance, char * msg){
if (_instance == &WSClient_lifecicle_var) {
WebSClient_handle_messaging_send(&WSClient_client_var, msg);
}
}
// Dispatch for messages ClockLinux::signal::clock_tick
void dispatch_ClockLinux_send_signal_clock_tick(struct ClockLinux_Instance *_instance){
if (_instance == &WSClient_clock_var) {
Lifecicle_handle_signal_clock_tick(&WSClient_lifecicle_var);
}
}
// Dispatch for messages WebSClient::lifecycle::server_launched
void dispatch_WebSClient_send_lifecycle_server_launched(struct WebSClient_Instance *_instance){
if (_instance == &WSClient_client_var) {
}
}
// Dispatch for messages WebSClient::lifecycle::onClose
void dispatch_WebSClient_send_lifecycle_onClose(struct WebSClient_Instance *_instance){
if (_instance == &WSClient_client_var) {
Lifecicle_handle_lifecycle_onClose(&WSClient_lifecicle_var);
}
}
// Dispatch for messages WebSClient::lifecycle::onOpen
void dispatch_WebSClient_send_lifecycle_onOpen(struct WebSClient_Instance *_instance){
if (_instance == &WSClient_client_var) {
Lifecicle_handle_lifecycle_onOpen(&WSClient_lifecicle_var);
}
}
// Dispatch for messages WebSClient::lifecycle::client_launched
void dispatch_WebSClient_send_lifecycle_client_launched(struct WebSClient_Instance *_instance){
if (_instance == &WSClient_client_var) {
Lifecicle_handle_lifecycle_client_launched(&WSClient_lifecicle_var);
}
}
// Dispatch for messages WebSClient::err::onError
void dispatch_WebSClient_send_err_onError(struct WebSClient_Instance *_instance, char * errorMsg){
if (_instance == &WSClient_client_var) {
Lifecicle_handle_err_onError(&WSClient_lifecicle_var, errorMsg);
}
}
// Dispatch for messages WebSClient::messaging::onMessage
void dispatch_WebSClient_send_messaging_onMessage(struct WebSClient_Instance *_instance, char * msg){
if (_instance == &WSClient_client_var) {
Lifecicle_handle_messaging_onMessage(&WSClient_lifecicle_var, msg);
}
}

void processMessageQueue() {
fifo_lock();
while (fifo_empty()) fifo_wait();
byte mbuf[10];
uint8_t mbufi = 0;

// Read the code of the next port/message in the queue
uint16_t code = fifo_dequeue() << 8;

code += fifo_dequeue();

// Switch to call the appropriate handler
switch(code) {
case 1:
while (mbufi < 2) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_Lifecicle_send_lifecycle_stop_client((struct Lifecicle_Instance*)instance_by_id((mbuf[0] << 8) + mbuf[1]) /* instance */);
break;
case 2:
while (mbufi < 2) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_Lifecicle_send_lifecycle_stop((struct Lifecicle_Instance*)instance_by_id((mbuf[0] << 8) + mbuf[1]) /* instance */);
break;
case 3:
while (mbufi < 2) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_Lifecicle_send_lifecycle_start((struct Lifecicle_Instance*)instance_by_id((mbuf[0] << 8) + mbuf[1]) /* instance */);
break;
case 4:
while (mbufi < 2) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_Lifecicle_send_lifecycle_start_client((struct Lifecicle_Instance*)instance_by_id((mbuf[0] << 8) + mbuf[1]) /* instance */);
break;
case 5:
while (mbufi < 2) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_Lifecicle_send_lifecycle_start_server((struct Lifecicle_Instance*)instance_by_id((mbuf[0] << 8) + mbuf[1]) /* instance */);
break;
case 6:
while (mbufi < 2) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_Lifecicle_send_lifecycle_stop_server((struct Lifecicle_Instance*)instance_by_id((mbuf[0] << 8) + mbuf[1]) /* instance */);
break;
case 7:
while (mbufi < 10) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_Lifecicle_send_messaging_send((struct Lifecicle_Instance*)instance_by_id((mbuf[0] << 8) + mbuf[1]) /* instance */,
(char *)((ptr_union_t*)(mbuf + 2))->pointer /* msg */ );
break;
case 8:
while (mbufi < 2) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_ClockLinux_send_signal_clock_tick((struct ClockLinux_Instance*)instance_by_id((mbuf[0] << 8) + mbuf[1]) /* instance */);
break;
case 9:
while (mbufi < 2) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_WebSClient_send_lifecycle_server_launched((struct WebSClient_Instance*)instance_by_id((mbuf[0] << 8) + mbuf[1]) /* instance */);
break;
case 10:
while (mbufi < 2) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_WebSClient_send_lifecycle_onClose((struct WebSClient_Instance*)instance_by_id((mbuf[0] << 8) + mbuf[1]) /* instance */);
break;
case 11:
while (mbufi < 2) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_WebSClient_send_lifecycle_onOpen((struct WebSClient_Instance*)instance_by_id((mbuf[0] << 8) + mbuf[1]) /* instance */);
break;
case 12:
while (mbufi < 2) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_WebSClient_send_lifecycle_client_launched((struct WebSClient_Instance*)instance_by_id((mbuf[0] << 8) + mbuf[1]) /* instance */);
break;
case 13:
while (mbufi < 10) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_WebSClient_send_err_onError((struct WebSClient_Instance*)instance_by_id((mbuf[0] << 8) + mbuf[1]) /* instance */,
(char *)((ptr_union_t*)(mbuf + 2))->pointer /* errorMsg */ );
break;
case 14:
while (mbufi < 10) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_WebSClient_send_messaging_onMessage((struct WebSClient_Instance*)instance_by_id((mbuf[0] << 8) + mbuf[1]) /* instance */,
(char *)((ptr_union_t*)(mbuf + 2))->pointer /* msg */ );
break;
}
}

void initialize_configuration_WSClient() {
// Initialize connectors
register_Lifecicle_send_lifecycle_start_listener(enqueue_Lifecicle_send_lifecycle_start);
register_Lifecicle_send_lifecycle_stop_listener(enqueue_Lifecicle_send_lifecycle_stop);
register_Lifecicle_send_lifecycle_start_client_listener(enqueue_Lifecicle_send_lifecycle_start_client);
register_Lifecicle_send_lifecycle_start_server_listener(enqueue_Lifecicle_send_lifecycle_start_server);
register_Lifecicle_send_lifecycle_stop_client_listener(enqueue_Lifecicle_send_lifecycle_stop_client);
register_Lifecicle_send_lifecycle_stop_server_listener(enqueue_Lifecicle_send_lifecycle_stop_server);
register_Lifecicle_send_messaging_send_listener(enqueue_Lifecicle_send_messaging_send);
register_ClockLinux_send_signal_clock_tick_listener(enqueue_ClockLinux_send_signal_clock_tick);
register_WebSClient_send_lifecycle_onOpen_listener(enqueue_WebSClient_send_lifecycle_onOpen);
register_WebSClient_send_lifecycle_onClose_listener(enqueue_WebSClient_send_lifecycle_onClose);
register_WebSClient_send_lifecycle_server_launched_listener(enqueue_WebSClient_send_lifecycle_server_launched);
register_WebSClient_send_lifecycle_client_launched_listener(enqueue_WebSClient_send_lifecycle_client_launched);
register_WebSClient_send_err_onError_listener(enqueue_WebSClient_send_err_onError);
register_WebSClient_send_messaging_onMessage_listener(enqueue_WebSClient_send_messaging_onMessage);

// Init the ID, state variables and properties for instance WSClient_lifecicle
WSClient_lifecicle_var.id = add_instance( (void*) &WSClient_lifecicle_var);
WSClient_lifecicle_var.Lifecicle_behavior_State = LIFECICLE_BEHAVIOR_RUNCLIENT_STATE;
WSClient_lifecicle_var.Lifecicle_pingmessage_var = "ping message";

// Init the ID, state variables and properties for instance WSClient_clock
WSClient_clock_var.id = add_instance( (void*) &WSClient_clock_var);
WSClient_clock_var.ClockLinux_ClockImpl_State = CLOCKLINUX_CLOCKIMPL_TICKING_STATE;
WSClient_clock_var.Clock_period_var = 5000;

// Init the ID, state variables and properties for instance WSClient_client
WSClient_client_var.id = add_instance( (void*) &WSClient_client_var);
WSClient_client_var.WebSClient_behavior_State = WEBSCLIENT_BEHAVIOR_INIT_STATE;
WSClient_client_var.WebSClient__host_var = "localhost";
WSClient_client_var.WebSocket__port_var = "7681";

Lifecicle_behavior_OnEntry(LIFECICLE_BEHAVIOR_STATE, &WSClient_lifecicle_var);
ClockLinux_ClockImpl_OnEntry(CLOCKLINUX_CLOCKIMPL_STATE, &WSClient_clock_var);
WebSClient_behavior_OnEntry(WEBSCLIENT_BEHAVIOR_STATE, &WSClient_client_var);
}


// NO C_GLOBALS Annotation

int main(int argc, char *argv[]) {
  init_runtime();
  // NO C_MAIN Annotation
  printf("THINGML: Starting in debug mode...\n");
initialize_configuration_WSClient();

  while (1) {
    
    processMessageQueue();
  }
  return 0;
}