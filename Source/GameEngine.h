#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H 1

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

	private:
		bool_t abortLoop;
	};
}

namespace Handler
{
	extern Game::Engine *Game;
}

#endif
