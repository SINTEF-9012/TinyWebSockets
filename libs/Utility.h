/*
 * Utility.h
 *
 *  Created on: Dec 6, 2013
 *      Author: vassik
 */

#ifndef UTILITY_H_
#define UTILITY_H_

#include "Log.h"
#include "libwebsockets.h"

namespace WebSockets {

	struct per_session_data__lws_mirror {
		struct libwebsocket *wsi;
		int ringbuffer_tail;
	};

	struct a_message {
		void *payload;
		size_t len;
	};

	typedef int (wsspCallback)(struct libwebsocket_context *context,
			struct libwebsocket *wsi,
			enum libwebsocket_callback_reasons reason,
						   void *user, void *in, size_t len);

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
			virtual void onMessage(const char* message);
			virtual void onOpen();
			virtual void onClose();
			virtual void onError(const char* error);

			virtual void setMessageCallback(ThingMLCallback* _callback) {msg_callback = _callback;};
			virtual void setOpenCallback(ThingMLCallback* _callback) {open_callback = _callback;};
			virtual void setCloseCallback(ThingMLCallback* _callback) {close_callback = _callback;};
			virtual void setErrorCallback(ThingMLCallback* _callback) {error_callback = _callback;};
	};

}

extern "C" {
	//LWS_VISIBLE int lws_hdr_total_length(struct libwebsocket *wsi, enum lws_token_indexes h);
	//LWS_VISIBLE int lws_hdr_copy(struct libwebsocket *wsi, char *dest, int len, enum lws_token_indexes h);
	void dump_handshake_info(struct libwebsocket *wsi);
}

#endif /* UTILITY_H_ */
