/*
 * Log.cpp
 *
 *  Created on: Dec 6, 2013
 *      Author: vassik
 */

#include <stddef.h>
#include <stdarg.h>
#include <stdio.h>

#include <iostream>

#include "Log.h"

using namespace WebSockets;
using namespace std;

Log* Log::s_instance = NULL;

Log::Log(){
	disable = false;
	error = true;
	warn = true;
	info = true;
	debug = true;
}

Log* Log::Create(){
	if(s_instance == NULL){
		s_instance = new Log();
	}
	return s_instance;
}

Log* Log::Create(bool _disable) {
	if(s_instance == NULL){
		s_instance = new Log();
		s_instance->disable = _disable;
	}
	return s_instance;
}

Log* Log::Create(bool _error, bool _warn, bool _info, bool _debug){
	if(s_instance == NULL){
		s_instance = new Log();
		s_instance->error = _error;
		s_instance->warn = _warn;
		s_instance->info = _info;
		s_instance->debug = _debug;
	}
	return s_instance;
}

Log* Log::Get(){
	return Log::Create();
}

void Log::Write(LogLevel _level, const char* _format, ...){
	char lineBuf[1024] = {};
	va_list args;
	va_start( args, _format );
	if( _format != NULL && _format[0] != '\0' ){
		vsnprintf(lineBuf, sizeof(lineBuf), _format, args );
	}
	va_end(args);
	Log* logger = Log::Get();
	switch(_level){
		case LogLevel_Error :
			if(!logger->disable && logger->error){
				cout << "[Error] " << lineBuf << endl;
			}
			break;
		case LogLevel_Warning :
			if(!logger->disable && logger->warn){
				cout << "[Warning] " << lineBuf << endl;
			}
			break;
		case LogLevel_Info :
			if(!logger->disable && logger->info){
				cout << "[Info] " << lineBuf << endl;
			}
			break;
		case LogLevel_Debug :
			if(!logger->disable && logger->debug){
				cout << "[Debug] " << lineBuf << endl;
			}
			break;
	}
}
