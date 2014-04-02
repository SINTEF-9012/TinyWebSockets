/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *      Implementation for Application WSServer
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


// NO C_HEADERS Annotation


/*****************************************************************************
 * Definitions for configuration : WSServer
 *****************************************************************************/

//Declaration of instance variables
struct WebSMirrorServer_Instance WSServer_server_var;



void processMessageQueue() {
fifo_lock();
while (fifo_empty()) fifo_wait();
byte mbuf[2];
uint8_t mbufi = 0;

// Read the code of the next port/message in the queue
uint16_t code = fifo_dequeue() << 8;

code += fifo_dequeue();

// Switch to call the appropriate handler
switch(code) {
}
}

void initialize_configuration_WSServer() {
// Initialize connectors

// Init the ID, state variables and properties for instance WSServer_server
WSServer_server_var.id = add_instance( (void*) &WSServer_server_var);
WSServer_server_var.WebSMirrorServer_behavior_State = WEBSMIRRORSERVER_BEHAVIOR_INIT_STATE;
WSServer_server_var.WebSocket__port_var = "7681";

WebSMirrorServer_behavior_OnEntry(WEBSMIRRORSERVER_BEHAVIOR_STATE, &WSServer_server_var);
}


// NO C_GLOBALS Annotation

int main(int argc, char *argv[]) {
  init_runtime();
  // NO C_MAIN Annotation
  printf("THINGML: Starting in debug mode...\n");
initialize_configuration_WSServer();

  while (1) {
    
    processMessageQueue();
  }
  return 0;
}