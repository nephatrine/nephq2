#ifndef SYSTEM_GAMEENGINE_H
#define SYSTEM_GAMEENGINE_H 1

#include "Shared.h"

namespace Game
{
	class Engine
	{
	public:
		Engine(int argc, char *argv[]);
		~Engine();

		bool_t abort() { bool_t retCode = !abortLoop; abortLoop = true; return retCode; }
		int run();

		uint32_t lastTicks() const { return timeLast; } // curtime
		uint32_t newTicks();                            // Sys_Milliseconds

	private:
		uint32_t timeStarted;
		uint32_t timeLast;
		bool_t abortLoop;
	};
}

namespace Handler
{
	extern Game::Engine *Game;
}

#endif
