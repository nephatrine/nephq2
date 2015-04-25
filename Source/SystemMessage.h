#ifndef SYSTEM_MESSAGE_H
#define SYSTEM_MESSAGE_H 1

#include "Shared.h"

namespace System
{
	namespace Message
	{
		void Information( const std::string &message );
		void Warning( const std::string &message );
		void Error( const std::string &message );
		void Fatal( const std::string &message );
	}
}

#endif
