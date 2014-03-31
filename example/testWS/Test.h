/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *           Header for Thing Test
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#ifndef Test_H_
#define Test_H_


#include "thingml_typedefs.h"

/*****************************************************************************
 * Headers for type : Test
 *****************************************************************************/

// Definition of the instance stuct:
struct Test_Instance {
// Variables for the ID of the instance
int id;
// Variables for the current instance state
int Test_behavior_State;
// Variables for the properties of the instance
char * Test_pingmessage_var;
};

// Declaration of prototypes outgoing messages:
void Test_behavior_OnEntry(int state, struct Test_Instance *_instance);
void Test_handle_lifecycle_onOpen(struct Test_Instance *_instance);
void Test_handle_lifecycle_client_launched(struct Test_Instance *_instance);
void Test_handle_lifecycle_server_launched(struct Test_Instance *_instance);
void Test_handle_lifecycle_onClose(struct Test_Instance *_instance);
void Test_handle_messaging_onMessage(struct Test_Instance *_instance, char * msg);
void Test_handle_signal_clock_tick(struct Test_Instance *_instance);
void Test_handle_err_onError(struct Test_Instance *_instance, char * errorMsg);
// Declaration of callbacks for incomming messages:
void register_Test_send_lifecycle_start_listener(void (*_listener)(struct Test_Instance*));
void register_Test_send_lifecycle_stop_listener(void (*_listener)(struct Test_Instance*));
void register_Test_send_lifecycle_start_client_listener(void (*_listener)(struct Test_Instance*));
void register_Test_send_lifecycle_start_server_listener(void (*_listener)(struct Test_Instance*));
void register_Test_send_lifecycle_stop_client_listener(void (*_listener)(struct Test_Instance*));
void register_Test_send_lifecycle_stop_server_listener(void (*_listener)(struct Test_Instance*));
void register_Test_send_messaging_send_listener(void (*_listener)(struct Test_Instance*, char *));

// Definition of the states:
#define TEST_BEHAVIOR_STATE 0
#define TEST_BEHAVIOR_RUNSERVER_STATE 1
#define TEST_BEHAVIOR_RUNCLIENT_STATE 2
#define TEST_BEHAVIOR_LOOP_STATE 3




#endif //Test_H_