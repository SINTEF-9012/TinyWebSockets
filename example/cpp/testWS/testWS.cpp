/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *      Implementation for Application testWS
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
#include "WebSMirrorServer.h"
#include "Test.h"
#include "WebSClient.h"
#include "ClockLinux.h"


// NO C_HEADERS Annotation


/*****************************************************************************
 * Definitions for configuration : testWS
 *****************************************************************************/

//Declaration of instance variables
struct WebSMirrorServer_Instance testWS_server_var;
struct Test_Instance testWS_test_var;
struct WebSClient_Instance testWS_client_var;
struct ClockLinux_Instance testWS_clock_var;

// Enqueue of messages WebSMirrorServer::lifecycle::client_launched
void enqueue_WebSMirrorServer_send_lifecycle_client_launched(struct WebSMirrorServer_Instance *_instance){
fifo_lock();
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (1 >> 8) & 0xFF );
_fifo_enqueue( 1 & 0xFF );

// ID of the source instance
_fifo_enqueue( (_instance->id >> 8) & 0xFF );
_fifo_enqueue( _instance->id & 0xFF );
}
else {
printf("THINGML: FIFO FULL (lost msg client_launched)\n");
}
fifo_unlock_and_notify();
}
// Enqueue of messages WebSMirrorServer::lifecycle::server_launched
void enqueue_WebSMirrorServer_send_lifecycle_server_launched(struct WebSMirrorServer_Instance *_instance){
fifo_lock();
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (2 >> 8) & 0xFF );
_fifo_enqueue( 2 & 0xFF );

// ID of the source instance
_fifo_enqueue( (_instance->id >> 8) & 0xFF );
_fifo_enqueue( _instance->id & 0xFF );
}
else {
printf("THINGML: FIFO FULL (lost msg server_launched)\n");
}
fifo_unlock_and_notify();
}
// Enqueue of messages WebSMirrorServer::lifecycle::onOpen
void enqueue_WebSMirrorServer_send_lifecycle_onOpen(struct WebSMirrorServer_Instance *_instance){
fifo_lock();
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (3 >> 8) & 0xFF );
_fifo_enqueue( 3 & 0xFF );

// ID of the source instance
_fifo_enqueue( (_instance->id >> 8) & 0xFF );
_fifo_enqueue( _instance->id & 0xFF );
}
else {
printf("THINGML: FIFO FULL (lost msg onOpen)\n");
}
fifo_unlock_and_notify();
}
// Enqueue of messages WebSMirrorServer::lifecycle::onClose
void enqueue_WebSMirrorServer_send_lifecycle_onClose(struct WebSMirrorServer_Instance *_instance){
fifo_lock();
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (4 >> 8) & 0xFF );
_fifo_enqueue( 4 & 0xFF );

// ID of the source instance
_fifo_enqueue( (_instance->id >> 8) & 0xFF );
_fifo_enqueue( _instance->id & 0xFF );
}
else {
printf("THINGML: FIFO FULL (lost msg onClose)\n");
}
fifo_unlock_and_notify();
}
// Enqueue of messages WebSMirrorServer::err::onError
void enqueue_WebSMirrorServer_send_err_onError(struct WebSMirrorServer_Instance *_instance, char * errorMsg){
fifo_lock();
if ( fifo_byte_available() > 12 ) {

_fifo_enqueue( (5 >> 8) & 0xFF );
_fifo_enqueue( 5 & 0xFF );

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
// Enqueue of messages WebSMirrorServer::messaging::onMessage
void enqueue_WebSMirrorServer_send_messaging_onMessage(struct WebSMirrorServer_Instance *_instance, char * msg){
fifo_lock();
if ( fifo_byte_available() > 12 ) {

_fifo_enqueue( (6 >> 8) & 0xFF );
_fifo_enqueue( 6 & 0xFF );

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
// Enqueue of messages Test::lifecycle::stop_client
void enqueue_Test_send_lifecycle_stop_client(struct Test_Instance *_instance){
fifo_lock();
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (7 >> 8) & 0xFF );
_fifo_enqueue( 7 & 0xFF );

// ID of the source instance
_fifo_enqueue( (_instance->id >> 8) & 0xFF );
_fifo_enqueue( _instance->id & 0xFF );
}
else {
printf("THINGML: FIFO FULL (lost msg stop_client)\n");
}
fifo_unlock_and_notify();
}
// Enqueue of messages Test::lifecycle::stop
void enqueue_Test_send_lifecycle_stop(struct Test_Instance *_instance){
fifo_lock();
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (8 >> 8) & 0xFF );
_fifo_enqueue( 8 & 0xFF );

// ID of the source instance
_fifo_enqueue( (_instance->id >> 8) & 0xFF );
_fifo_enqueue( _instance->id & 0xFF );
}
else {
printf("THINGML: FIFO FULL (lost msg stop)\n");
}
fifo_unlock_and_notify();
}
// Enqueue of messages Test::lifecycle::start
void enqueue_Test_send_lifecycle_start(struct Test_Instance *_instance){
fifo_lock();
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (9 >> 8) & 0xFF );
_fifo_enqueue( 9 & 0xFF );

// ID of the source instance
_fifo_enqueue( (_instance->id >> 8) & 0xFF );
_fifo_enqueue( _instance->id & 0xFF );
}
else {
printf("THINGML: FIFO FULL (lost msg start)\n");
}
fifo_unlock_and_notify();
}
// Enqueue of messages Test::lifecycle::stop_server
void enqueue_Test_send_lifecycle_stop_server(struct Test_Instance *_instance){
fifo_lock();
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (10 >> 8) & 0xFF );
_fifo_enqueue( 10 & 0xFF );

// ID of the source instance
_fifo_enqueue( (_instance->id >> 8) & 0xFF );
_fifo_enqueue( _instance->id & 0xFF );
}
else {
printf("THINGML: FIFO FULL (lost msg stop_server)\n");
}
fifo_unlock_and_notify();
}
// Enqueue of messages Test::lifecycle::start_client
void enqueue_Test_send_lifecycle_start_client(struct Test_Instance *_instance){
fifo_lock();
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (11 >> 8) & 0xFF );
_fifo_enqueue( 11 & 0xFF );

// ID of the source instance
_fifo_enqueue( (_instance->id >> 8) & 0xFF );
_fifo_enqueue( _instance->id & 0xFF );
}
else {
printf("THINGML: FIFO FULL (lost msg start_client)\n");
}
fifo_unlock_and_notify();
}
// Enqueue of messages Test::lifecycle::start_server
void enqueue_Test_send_lifecycle_start_server(struct Test_Instance *_instance){
fifo_lock();
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (12 >> 8) & 0xFF );
_fifo_enqueue( 12 & 0xFF );

// ID of the source instance
_fifo_enqueue( (_instance->id >> 8) & 0xFF );
_fifo_enqueue( _instance->id & 0xFF );
}
else {
printf("THINGML: FIFO FULL (lost msg start_server)\n");
}
fifo_unlock_and_notify();
}
// Enqueue of messages Test::messaging::send
void enqueue_Test_send_messaging_send(struct Test_Instance *_instance, char * msg){
fifo_lock();
if ( fifo_byte_available() > 12 ) {

_fifo_enqueue( (13 >> 8) & 0xFF );
_fifo_enqueue( 13 & 0xFF );

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
// Enqueue of messages WebSClient::lifecycle::client_launched
void enqueue_WebSClient_send_lifecycle_client_launched(struct WebSClient_Instance *_instance){
fifo_lock();
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (14 >> 8) & 0xFF );
_fifo_enqueue( 14 & 0xFF );

// ID of the source instance
_fifo_enqueue( (_instance->id >> 8) & 0xFF );
_fifo_enqueue( _instance->id & 0xFF );
}
else {
printf("THINGML: FIFO FULL (lost msg client_launched)\n");
}
fifo_unlock_and_notify();
}
// Enqueue of messages WebSClient::lifecycle::server_launched
void enqueue_WebSClient_send_lifecycle_server_launched(struct WebSClient_Instance *_instance){
fifo_lock();
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (15 >> 8) & 0xFF );
_fifo_enqueue( 15 & 0xFF );

// ID of the source instance
_fifo_enqueue( (_instance->id >> 8) & 0xFF );
_fifo_enqueue( _instance->id & 0xFF );
}
else {
printf("THINGML: FIFO FULL (lost msg server_launched)\n");
}
fifo_unlock_and_notify();
}
// Enqueue of messages WebSClient::lifecycle::onOpen
void enqueue_WebSClient_send_lifecycle_onOpen(struct WebSClient_Instance *_instance){
fifo_lock();
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (16 >> 8) & 0xFF );
_fifo_enqueue( 16 & 0xFF );

// ID of the source instance
_fifo_enqueue( (_instance->id >> 8) & 0xFF );
_fifo_enqueue( _instance->id & 0xFF );
}
else {
printf("THINGML: FIFO FULL (lost msg onOpen)\n");
}
fifo_unlock_and_notify();
}
// Enqueue of messages WebSClient::lifecycle::onClose
void enqueue_WebSClient_send_lifecycle_onClose(struct WebSClient_Instance *_instance){
fifo_lock();
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (17 >> 8) & 0xFF );
_fifo_enqueue( 17 & 0xFF );

// ID of the source instance
_fifo_enqueue( (_instance->id >> 8) & 0xFF );
_fifo_enqueue( _instance->id & 0xFF );
}
else {
printf("THINGML: FIFO FULL (lost msg onClose)\n");
}
fifo_unlock_and_notify();
}
// Enqueue of messages WebSClient::err::onError
void enqueue_WebSClient_send_err_onError(struct WebSClient_Instance *_instance, char * errorMsg){
fifo_lock();
if ( fifo_byte_available() > 12 ) {

_fifo_enqueue( (18 >> 8) & 0xFF );
_fifo_enqueue( 18 & 0xFF );

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

_fifo_enqueue( (19 >> 8) & 0xFF );
_fifo_enqueue( 19 & 0xFF );

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
// Enqueue of messages ClockLinux::signal::clock_tick
void enqueue_ClockLinux_send_signal_clock_tick(struct ClockLinux_Instance *_instance){
fifo_lock();
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (20 >> 8) & 0xFF );
_fifo_enqueue( 20 & 0xFF );

// ID of the source instance
_fifo_enqueue( (_instance->id >> 8) & 0xFF );
_fifo_enqueue( _instance->id & 0xFF );
}
else {
printf("THINGML: FIFO FULL (lost msg clock_tick)\n");
}
fifo_unlock_and_notify();
}

// Dispatch for messages WebSMirrorServer::lifecycle::client_launched
void dispatch_WebSMirrorServer_send_lifecycle_client_launched(struct WebSMirrorServer_Instance *_instance){
if (_instance == &testWS_server_var) {
Test_handle_lifecycle_client_launched(&testWS_test_var);
}
}
// Dispatch for messages WebSMirrorServer::lifecycle::server_launched
void dispatch_WebSMirrorServer_send_lifecycle_server_launched(struct WebSMirrorServer_Instance *_instance){
if (_instance == &testWS_server_var) {
Test_handle_lifecycle_server_launched(&testWS_test_var);
}
}
// Dispatch for messages WebSMirrorServer::lifecycle::onOpen
void dispatch_WebSMirrorServer_send_lifecycle_onOpen(struct WebSMirrorServer_Instance *_instance){
if (_instance == &testWS_server_var) {
Test_handle_lifecycle_onOpen(&testWS_test_var);
}
}
// Dispatch for messages WebSMirrorServer::lifecycle::onClose
void dispatch_WebSMirrorServer_send_lifecycle_onClose(struct WebSMirrorServer_Instance *_instance){
if (_instance == &testWS_server_var) {
Test_handle_lifecycle_onClose(&testWS_test_var);
}
}
// Dispatch for messages WebSMirrorServer::err::onError
void dispatch_WebSMirrorServer_send_err_onError(struct WebSMirrorServer_Instance *_instance, char * errorMsg){
if (_instance == &testWS_server_var) {
Test_handle_err_onError(&testWS_test_var, errorMsg);
}
}
// Dispatch for messages WebSMirrorServer::messaging::onMessage
void dispatch_WebSMirrorServer_send_messaging_onMessage(struct WebSMirrorServer_Instance *_instance, char * msg){
if (_instance == &testWS_server_var) {
Test_handle_messaging_onMessage(&testWS_test_var, msg);
}
}
// Dispatch for messages Test::lifecycle::stop_client
void dispatch_Test_send_lifecycle_stop_client(struct Test_Instance *_instance){
if (_instance == &testWS_test_var) {
WebSClient_handle_lifecycle_stop_client(&testWS_client_var);
}
}
// Dispatch for messages Test::lifecycle::stop
void dispatch_Test_send_lifecycle_stop(struct Test_Instance *_instance){
if (_instance == &testWS_test_var) {
}
}
// Dispatch for messages Test::lifecycle::start
void dispatch_Test_send_lifecycle_start(struct Test_Instance *_instance){
if (_instance == &testWS_test_var) {
WebSMirrorServer_handle_lifecycle_start(&testWS_server_var);
}
}
// Dispatch for messages Test::lifecycle::stop_server
void dispatch_Test_send_lifecycle_stop_server(struct Test_Instance *_instance){
if (_instance == &testWS_test_var) {
WebSMirrorServer_handle_lifecycle_stop_server(&testWS_server_var);
}
}
// Dispatch for messages Test::lifecycle::start_client
void dispatch_Test_send_lifecycle_start_client(struct Test_Instance *_instance){
if (_instance == &testWS_test_var) {
WebSClient_handle_lifecycle_start_client(&testWS_client_var);
}
}
// Dispatch for messages Test::lifecycle::start_server
void dispatch_Test_send_lifecycle_start_server(struct Test_Instance *_instance){
if (_instance == &testWS_test_var) {
WebSMirrorServer_handle_lifecycle_start_server(&testWS_server_var);
}
}
// Dispatch for messages Test::messaging::send
void dispatch_Test_send_messaging_send(struct Test_Instance *_instance, char * msg){
if (_instance == &testWS_test_var) {
WebSClient_handle_messaging_send(&testWS_client_var, msg);
}
}
// Dispatch for messages WebSClient::lifecycle::client_launched
void dispatch_WebSClient_send_lifecycle_client_launched(struct WebSClient_Instance *_instance){
if (_instance == &testWS_client_var) {
Test_handle_lifecycle_client_launched(&testWS_test_var);
}
}
// Dispatch for messages WebSClient::lifecycle::server_launched
void dispatch_WebSClient_send_lifecycle_server_launched(struct WebSClient_Instance *_instance){
if (_instance == &testWS_client_var) {
Test_handle_lifecycle_server_launched(&testWS_test_var);
}
}
// Dispatch for messages WebSClient::lifecycle::onOpen
void dispatch_WebSClient_send_lifecycle_onOpen(struct WebSClient_Instance *_instance){
if (_instance == &testWS_client_var) {
Test_handle_lifecycle_onOpen(&testWS_test_var);
}
}
// Dispatch for messages WebSClient::lifecycle::onClose
void dispatch_WebSClient_send_lifecycle_onClose(struct WebSClient_Instance *_instance){
if (_instance == &testWS_client_var) {
Test_handle_lifecycle_onClose(&testWS_test_var);
}
}
// Dispatch for messages WebSClient::err::onError
void dispatch_WebSClient_send_err_onError(struct WebSClient_Instance *_instance, char * errorMsg){
if (_instance == &testWS_client_var) {
Test_handle_err_onError(&testWS_test_var, errorMsg);
}
}
// Dispatch for messages WebSClient::messaging::onMessage
void dispatch_WebSClient_send_messaging_onMessage(struct WebSClient_Instance *_instance, char * msg){
if (_instance == &testWS_client_var) {
Test_handle_messaging_onMessage(&testWS_test_var, msg);
}
}
// Dispatch for messages ClockLinux::signal::clock_tick
void dispatch_ClockLinux_send_signal_clock_tick(struct ClockLinux_Instance *_instance){
if (_instance == &testWS_clock_var) {
Test_handle_signal_clock_tick(&testWS_test_var);
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
dispatch_WebSMirrorServer_send_lifecycle_client_launched((struct WebSMirrorServer_Instance*)instance_by_id((mbuf[0] << 8) + mbuf[1]) /* instance */);
break;
case 2:
while (mbufi < 2) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_WebSMirrorServer_send_lifecycle_server_launched((struct WebSMirrorServer_Instance*)instance_by_id((mbuf[0] << 8) + mbuf[1]) /* instance */);
break;
case 3:
while (mbufi < 2) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_WebSMirrorServer_send_lifecycle_onOpen((struct WebSMirrorServer_Instance*)instance_by_id((mbuf[0] << 8) + mbuf[1]) /* instance */);
break;
case 4:
while (mbufi < 2) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_WebSMirrorServer_send_lifecycle_onClose((struct WebSMirrorServer_Instance*)instance_by_id((mbuf[0] << 8) + mbuf[1]) /* instance */);
break;
case 5:
while (mbufi < 10) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_WebSMirrorServer_send_err_onError((struct WebSMirrorServer_Instance*)instance_by_id((mbuf[0] << 8) + mbuf[1]) /* instance */,
(char *)((ptr_union_t*)(mbuf + 2))->pointer /* errorMsg */ );
break;
case 6:
while (mbufi < 10) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_WebSMirrorServer_send_messaging_onMessage((struct WebSMirrorServer_Instance*)instance_by_id((mbuf[0] << 8) + mbuf[1]) /* instance */,
(char *)((ptr_union_t*)(mbuf + 2))->pointer /* msg */ );
break;
case 7:
while (mbufi < 2) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_Test_send_lifecycle_stop_client((struct Test_Instance*)instance_by_id((mbuf[0] << 8) + mbuf[1]) /* instance */);
break;
case 8:
while (mbufi < 2) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_Test_send_lifecycle_stop((struct Test_Instance*)instance_by_id((mbuf[0] << 8) + mbuf[1]) /* instance */);
break;
case 9:
while (mbufi < 2) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_Test_send_lifecycle_start((struct Test_Instance*)instance_by_id((mbuf[0] << 8) + mbuf[1]) /* instance */);
break;
case 10:
while (mbufi < 2) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_Test_send_lifecycle_stop_server((struct Test_Instance*)instance_by_id((mbuf[0] << 8) + mbuf[1]) /* instance */);
break;
case 11:
while (mbufi < 2) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_Test_send_lifecycle_start_client((struct Test_Instance*)instance_by_id((mbuf[0] << 8) + mbuf[1]) /* instance */);
break;
case 12:
while (mbufi < 2) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_Test_send_lifecycle_start_server((struct Test_Instance*)instance_by_id((mbuf[0] << 8) + mbuf[1]) /* instance */);
break;
case 13:
while (mbufi < 10) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_Test_send_messaging_send((struct Test_Instance*)instance_by_id((mbuf[0] << 8) + mbuf[1]) /* instance */,
(char *)((ptr_union_t*)(mbuf + 2))->pointer /* msg */ );
break;
case 14:
while (mbufi < 2) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_WebSClient_send_lifecycle_client_launched((struct WebSClient_Instance*)instance_by_id((mbuf[0] << 8) + mbuf[1]) /* instance */);
break;
case 15:
while (mbufi < 2) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_WebSClient_send_lifecycle_server_launched((struct WebSClient_Instance*)instance_by_id((mbuf[0] << 8) + mbuf[1]) /* instance */);
break;
case 16:
while (mbufi < 2) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_WebSClient_send_lifecycle_onOpen((struct WebSClient_Instance*)instance_by_id((mbuf[0] << 8) + mbuf[1]) /* instance */);
break;
case 17:
while (mbufi < 2) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_WebSClient_send_lifecycle_onClose((struct WebSClient_Instance*)instance_by_id((mbuf[0] << 8) + mbuf[1]) /* instance */);
break;
case 18:
while (mbufi < 10) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_WebSClient_send_err_onError((struct WebSClient_Instance*)instance_by_id((mbuf[0] << 8) + mbuf[1]) /* instance */,
(char *)((ptr_union_t*)(mbuf + 2))->pointer /* errorMsg */ );
break;
case 19:
while (mbufi < 10) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_WebSClient_send_messaging_onMessage((struct WebSClient_Instance*)instance_by_id((mbuf[0] << 8) + mbuf[1]) /* instance */,
(char *)((ptr_union_t*)(mbuf + 2))->pointer /* msg */ );
break;
case 20:
while (mbufi < 2) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_ClockLinux_send_signal_clock_tick((struct ClockLinux_Instance*)instance_by_id((mbuf[0] << 8) + mbuf[1]) /* instance */);
break;
}
}

void initialize_configuration_testWS() {
// Initialize connectors
register_WebSMirrorServer_send_lifecycle_onOpen_listener(enqueue_WebSMirrorServer_send_lifecycle_onOpen);
register_WebSMirrorServer_send_lifecycle_onClose_listener(enqueue_WebSMirrorServer_send_lifecycle_onClose);
register_WebSMirrorServer_send_lifecycle_server_launched_listener(enqueue_WebSMirrorServer_send_lifecycle_server_launched);
register_WebSMirrorServer_send_lifecycle_client_launched_listener(enqueue_WebSMirrorServer_send_lifecycle_client_launched);
register_WebSMirrorServer_send_err_onError_listener(enqueue_WebSMirrorServer_send_err_onError);
register_WebSMirrorServer_send_messaging_onMessage_listener(enqueue_WebSMirrorServer_send_messaging_onMessage);
register_Test_send_lifecycle_start_listener(enqueue_Test_send_lifecycle_start);
register_Test_send_lifecycle_stop_listener(enqueue_Test_send_lifecycle_stop);
register_Test_send_lifecycle_start_client_listener(enqueue_Test_send_lifecycle_start_client);
register_Test_send_lifecycle_start_server_listener(enqueue_Test_send_lifecycle_start_server);
register_Test_send_lifecycle_stop_client_listener(enqueue_Test_send_lifecycle_stop_client);
register_Test_send_lifecycle_stop_server_listener(enqueue_Test_send_lifecycle_stop_server);
register_Test_send_messaging_send_listener(enqueue_Test_send_messaging_send);
register_WebSClient_send_lifecycle_onOpen_listener(enqueue_WebSClient_send_lifecycle_onOpen);
register_WebSClient_send_lifecycle_onClose_listener(enqueue_WebSClient_send_lifecycle_onClose);
register_WebSClient_send_lifecycle_server_launched_listener(enqueue_WebSClient_send_lifecycle_server_launched);
register_WebSClient_send_lifecycle_client_launched_listener(enqueue_WebSClient_send_lifecycle_client_launched);
register_WebSClient_send_err_onError_listener(enqueue_WebSClient_send_err_onError);
register_WebSClient_send_messaging_onMessage_listener(enqueue_WebSClient_send_messaging_onMessage);
register_ClockLinux_send_signal_clock_tick_listener(enqueue_ClockLinux_send_signal_clock_tick);

// Init the ID, state variables and properties for instance testWS_server
testWS_server_var.id = add_instance( (void*) &testWS_server_var);
testWS_server_var.WebSMirrorServer_behavior_State = WEBSMIRRORSERVER_BEHAVIOR_INIT_STATE;
testWS_server_var.WebSocket__port_var = "7681";

// Init the ID, state variables and properties for instance testWS_test
testWS_test_var.id = add_instance( (void*) &testWS_test_var);
testWS_test_var.Test_behavior_State = TEST_BEHAVIOR_RUNSERVER_STATE;
testWS_test_var.Test_pingmessage_var = "ping message";

// Init the ID, state variables and properties for instance testWS_client
testWS_client_var.id = add_instance( (void*) &testWS_client_var);
testWS_client_var.WebSClient_behavior_State = WEBSCLIENT_BEHAVIOR_INIT_STATE;
testWS_client_var.WebSClient__host_var = "localhost";
testWS_client_var.WebSocket__port_var = "7681";

// Init the ID, state variables and properties for instance testWS_clock
testWS_clock_var.id = add_instance( (void*) &testWS_clock_var);
testWS_clock_var.ClockLinux_ClockImpl_State = CLOCKLINUX_CLOCKIMPL_TICKING_STATE;
testWS_clock_var.Clock_period_var = 5000;

WebSMirrorServer_behavior_OnEntry(WEBSMIRRORSERVER_BEHAVIOR_STATE, &testWS_server_var);
Test_behavior_OnEntry(TEST_BEHAVIOR_STATE, &testWS_test_var);
WebSClient_behavior_OnEntry(WEBSCLIENT_BEHAVIOR_STATE, &testWS_client_var);
ClockLinux_ClockImpl_OnEntry(CLOCKLINUX_CLOCKIMPL_STATE, &testWS_clock_var);
}


// NO C_GLOBALS Annotation

int main(int argc, char *argv[]) {
  init_runtime();
  // NO C_MAIN Annotation
  printf("THINGML: Starting in debug mode...\n");
initialize_configuration_testWS();

  while (1) {
    
    processMessageQueue();
  }
  return 0;
}