#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H 1

#include "SystemTimer.h"

namespace Game
{
	class Engine
	{	public:
			Engine( int argc, char *argv[] );
			~Engine();
			int run();
			
			// Really there's no reason this should be an object.
			// I should use procedural functions or static methods.
			
			Engine( const Engine &other ) = delete;
			Engine( Engine &&other ) = delete;
			Engine &operator=( const Engine &other ) = delete;
			Engine &operator=( Engine &&other ) = delete;
			
			static bool_t Abort();
			static uint32_t GetTick();
			static uint32_t NewTick();
			
		private:
			static Engine *handle;
			bool_t abortLoop;
			System::Timer timer;
	};
}

#endif
