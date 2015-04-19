// -----------------------------------------------
// Include Headers
//

#include "GameEngine.h"
#include "GameTimer.h"
#include <SDL_events.h>

#ifdef _WIN32
#include <Windows.h>
#endif

// -----------------------------------------------
// Legacy Declarations
//

#include "../qcommon/shared/q_shared.h"
void Qcommon_Init(int32_t argc, char **argv);
void Sys_Error(char *error, ...);
void SDL_ProcEvent(SDL_Event *event, uint32_t time);
extern SDL_bool	Minimized;
extern cvar_t	*dedicated;
void Qcommon_Frame(int32_t msec);
void CL_Shutdown(void);
void Qcommon_Shutdown(void);
void DeinitConProc(void);

// -----------------------------------------------
// Initialize Globals
//

Game::Engine *Handler::Game = nullptr;

// -----------------------------------------------
// Constructor
// Initialize engine.
//

Game::Engine::Engine(int argc, char *argv[])
: abortLoop(false)
{
#ifdef _WIN32
	SetProcessDPIAware();
#endif

#ifndef _WIN32
	nostdout = Cvar_Get("nostdout", "0", 0);
	if (!nostdout->value) {
		fcntl(0, F_SETFL, fcntl(0, F_GETFL, 0) | FNDELAY);
	}
#endif

	try
	{
		Qcommon_Init(argc, argv);
	}
	catch (...)
	{
		Sys_Error("Error during initialization");
	}

	Handler::Game = this;
}

// -----------------------------------------------
// Destructor
// Clean up after engine.
//

Game::Engine::~Engine()
{
	CL_Shutdown();
	Qcommon_Shutdown();

#ifdef _WIN32
	if (dedicated && dedicated->value)
		FreeConsole();

	// shut down QHOST hooks if necessary
	DeinitConProc();
#endif

	Handler::Game = nullptr;
	MessageBoxA(NULL, "Destructor Finished", "Caption", MB_OK);
}

// -----------------------------------------------
// run()
// Execute main game loop.
//

int Game::Engine::run()
{
	Game::Timer timer;
	uint32_t lastFrame = timer.getCurrent(), thisFrame;

	SDL_Event event;

	while (!abortLoop)
	{
		if (Minimized || (dedicated && dedicated->value))
		{
			Game::Timer::Delay(1);
		}

		while (SDL_PollEvent(&event))
			SDL_ProcEvent(&event, event.common.timestamp);

		for (thisFrame = timer.getCurrent(); thisFrame <= lastFrame; thisFrame = timer.getCurrent())
			Game::Timer::Delay();

		try
		{
			Qcommon_Frame(thisFrame - lastFrame);
		}
		catch (...)
		{
			// do nothing?
		}

		lastFrame = thisFrame;
	}

	return 0;
}
