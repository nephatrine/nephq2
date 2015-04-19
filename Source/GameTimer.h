#ifndef GAME_TIMER_H
#define GAME_TIMER_H 1

#include "Shared.h"

namespace Game
{
	class Timer
	{
	private:
		uint32_t timeStarted;
		uint32_t timeLast;

	public:
		Timer();
		~Timer();

		uint32_t getLast() const { return timeLast; } // curtime
		uint32_t getCurrent();                        // Sys_Milliseconds

		static void Delay(const uint32_t ms = 0);
	};
}

namespace Handler
{
	extern Game::Timer *Timer;
}

#endif
