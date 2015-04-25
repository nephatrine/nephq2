#ifndef SYSTEM_TIMER_H
#define SYSTEM_TIMER_H 1

#include "Shared.h"

namespace System
{
	class Timer
	{	public:
			Timer();
			
			uint32_t getLast() const { return timeLast; }
			uint32_t getCurrent();
			
			static void Delay( const uint32_t ms = 0 );
			static bool_t Tune();
			
		private:
			static bool_t tuned;
			uint32_t timeStarted;
			uint32_t timeLast;
	};
}

#endif
