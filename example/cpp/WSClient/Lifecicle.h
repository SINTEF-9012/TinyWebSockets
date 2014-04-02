/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *           Header for Thing Lifecicle
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#ifndef Lifecicle_H_
#define Lifecicle_H_


#include "thingml_typedefs.h"

/*****************************************************************************
 * Headers for type : Lifecicle
 *****************************************************************************/

// Definition of the instance stuct:
struct Lifecicle_Instance {
// Variables for the ID of the instance
int id;
// Variables for the current instance state
int Lifecicle_behavior_State;
// Variables for the properties of the instance
char * Lifecicle_pingmessage_var;
};

// Declaration of prototypes outgoing messages:
void Lifecicle_behavior_OnEntry(int state, struct Lifecicle_Instance *_instance);
void Lifecicle_handle_messaging_onMessage(struct Lifecicle_Instance *_instance, char * msg);
void Lifecicle_handle_err_onError(struct Lifecicle_Instance *_instance, char * errorMsg);
void Lifecicle_handle_lifecycle_client_launched(struct Lifecicle_Instance *_instance);
void Lifecicle_handle_lifecycle_onClose(struct Lifecicle_Instance *_instance);
void Lifecicle_handle_lifecycle_onOpen(struct Lifecicle_Instance *_instance);
void Lifecicle_handle_signal_clock_tick(struct Lifecicle_Instance *_instance);
// Declaration of callbacks for incomming messages:
void register_Lifecicle_send_lifecycle_start_listener(void (*_listener)(struct Lifecicle_Instance*));
void register_Lifecicle_send_lifecycle_stop_listener(void (*_listener)(struct Lifecicle_Instance*));
void register_Lifecicle_send_lifecycle_start_client_listener(void (*_listener)(struct Lifecicle_Instance*));
void register_Lifecicle_send_lifecycle_start_server_listener(void (*_listener)(struct Lifecicle_Instance*));
void register_Lifecicle_send_lifecycle_stop_client_listener(void (*_listener)(struct Lifecicle_Instance*));
void register_Lifecicle_send_lifecycle_stop_server_listener(void (*_listener)(struct Lifecicle_Instance*));
void register_Lifecicle_send_messaging_send_listener(void (*_listener)(struct Lifecicle_Instance*, char *));

// Definition of the states:
#define LIFECICLE_BEHAVIOR_STATE 0
#define LIFECICLE_BEHAVIOR_RUNCLIENT_STATE 1
#define LIFECICLE_BEHAVIOR_LOOP_STATE 2




#endif //Lifecicle_H_