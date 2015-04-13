//
// NephQ2 Headers
//

#include "GameEngine.h"

//
// System Headers
//

#ifdef _WIN32
#include <Windows.h>
#endif
#include <SDL_events.h> // SDL_PollEvent
#include <SDL_main.h>   // SDL_main
#include <SDL_timer.h>  // SDL_GetTicks

//
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

//
// Code
//

Game::Engine *Handler::Game = nullptr;

uint32_t Game::Engine::newTicks()
{
	return timeLast = (SDL_GetTicks() - timeStarted);
}

Game::Engine::Engine(int argc, char *argv[])
: timeStarted(0), timeLast(0), abortLoop(false)
{
#ifdef _WIN32
	// Fix Windows DPI Scaling
	SetProcessDPIAware();
#endif

#ifndef _WIN32
	nostdout = Cvar_Get("nostdout", "0", 0);
	if (!nostdout->value) {
		fcntl(0, F_SETFL, fcntl(0, F_GETFL, 0) | FNDELAY);
	}
#endif

	//
	// Really Dumb Try/Catch
	// Slightly better than the setjmp/longjmp it's replacing.
	//

	try
	{
		Qcommon_Init(argc, argv);
	}
	catch (...)
	{
		Sys_Error("Error during initialization");
	}

	// We're ready to start.
	Handler::Game = this;
	timeStarted = SDL_GetTicks();
}

Game::Engine::~Engine()
{
	CL_Shutdown();
	Qcommon_Shutdown();

#ifdef _WIN32
	timeEndPeriod(1);
#endif

#ifdef _WIN32
	if (dedicated && dedicated->value)
		FreeConsole();

	// shut down QHOST hooks if necessary
	DeinitConProc();
#endif

	Handler::Game = nullptr;
	MessageBoxA(NULL, "Text", "Caption", MB_OK);
}

int Game::Engine::run()
{
	SDL_Event event;
	uint32_t lastFrame = newTicks(), thisFrame;

	while (!abortLoop)
	{
		// if at a full screen console, don't update unless needed
		if (Minimized || (dedicated && dedicated->value))
		{
			SDL_Delay(1);
		}

		// Event Processing
		while (SDL_PollEvent(&event))
		{
			SDL_ProcEvent(&event, event.common.timestamp);
		}

		// Timer Logic
		for (thisFrame = newTicks(); thisFrame <= lastFrame; thisFrame = newTicks()) { /*SDL_Delay(0);*/ }

		// Game Logic

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

//
// Entry Point
//

int main(int argc, char *argv[])
{
	Game::Engine game(argc, argv);
	int retCode = game.run();
	return retCode;
}
