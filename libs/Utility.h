/*
 * Utility.h
 *
 *  Created on: Dec 6, 2013
 *      Author: vassik
 */

#ifndef UTILITY_H_
#define UTILITY_H_

#include "Log.h"

namespace WebSockets {

	//TODO: using of this structure requires the -fpermissive flag while compiling since it is not type safe
	//probably we need to look into this
	typedef void (*pthingMLCallback)(void* _instance, ...);
	struct ThingMLCallback {
		pthingMLCallback fn_callback;
		void* instance;

		ThingMLCallback(pthingMLCallback _callback, void* _instance):
			fn_callback(_callback),
			instance(_instance){
		};
		~ThingMLCallback(){
			Log::Write(LogLevel_Debug, "~ThingMLCallback() is called 0x%08x", this);
		}
	};

	class WebSocketObserver {

		private:
			ThingMLCallback* msg_callback;
			ThingMLCallback* open_callback;
			ThingMLCallback* close_callback;
			ThingMLCallback* error_callback;

		public:
			WebSocketObserver();
			WebSocketObserver(ThingMLCallback* _msg_callback,
				ThingMLCallback* _open_callback,
				ThingMLCallback* _close_callback,
				ThingMLCallback* _error_callback);

			virtual ~WebSocketObserver();

		public:
			virtual void onMessage(char* message);
			virtual void onOpen();
			virtual void onClose();
			virtual void onError(char* error);
	};

}

#endif /* UTILITY_H_ */