/*
 * Log.h
 *
 *  Created on: Dec 6, 2013
 *      Author: vassik
 */

#ifndef LOG_H_
#define LOG_H_

namespace WebSockets {

	enum LogLevel
	{
		LogLevel_Error,		/**< A serious issue with the library or the network */
		LogLevel_Warning,	/**< A minor issue from which the library should be able to recover */
		LogLevel_Info,		/**< Everything's working fine...these messages provide streamlined feedback on each message */
		LogLevel_Debug,		/**< Very detailed information on progress that will create a huge log file quickly
									But this level (as others) can be queued and sent to the log only on an error or warning */
	};

	class Log {

		private:
			bool disable;
			bool error;
			bool warn;
			bool info;
			bool debug;

		public:
			Log();
			static Log* Create();
			static Log* Create(bool _disable);
			static Log* Create(bool _error, bool _warn, bool _info, bool _debug);
			static Log* Get();
			static void Write(LogLevel _level, char const* _format, ... );

			static Log* s_instance;
	};
}


#endif /* LOG_H_ */
