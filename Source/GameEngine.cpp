// -----------------------------------------------
// Include Headers
//

#include "GameEngine.h"
#include "SystemMessage.h"
#include <SDL_events.h>

// -----------------------------------------------
// Legacy Declarations
//

#include "../qcommon/shared/q_shared.h"
void Qcommon_Init( int32_t argc, char **argv );
void Sys_Error( char *error, ... );
void SDL_ProcEvent( SDL_Event *event, uint32_t time );
extern SDL_bool Minimized;
extern cvar_t   *dedicated;
void Qcommon_Frame( int32_t msec );
void CL_Shutdown( void );
void Qcommon_Shutdown( void );
void DeinitConProc( void );

// -----------------------------------------------
// Global Functions/Variables
//

Game::Engine *Game::Engine::handle = nullptr;

bool_t Game::Engine::Abort()
{	bool_t retCode = false;

	if( Game::Engine::handle )
	{	retCode = !( Game::Engine::handle->abortLoop );
		Game::Engine::handle->abortLoop = true;
	}
	
	return retCode;
}

uint32_t Game::Engine::GetTick()
{	return Game::Engine::handle ? Game::Engine::handle->timer.getLast() : 0;
}

uint32_t Game::Engine::NewTick()
{	return Game::Engine::handle ? Game::Engine::handle->timer.getCurrent() : 0;
}

// -----------------------------------------------
// Initialize engine.
//

Game::Engine::Engine( int argc, char *argv[] )
	: abortLoop( false )
{	if( Game::Engine::handle )
	{	System::Message::Fatal( "Too many Game::Engine initialized." );
		abortLoop = true;
	}
	else Game::Engine::handle = this;
	
#ifndef _WIN32
	nostdout = Cvar_Get( "nostdout", "0", 0 );
	
	if( !nostdout->value )
		fcntl( 0, F_SETFL, fcntl( 0, F_GETFL, 0 ) | FNDELAY );
		
#endif
		
	try
	{	Qcommon_Init( argc, argv );
	}
	catch( ... )
	{	Sys_Error( "Error during initialization" );
	}
}

// -----------------------------------------------
// Clean up after engine.
//

Game::Engine::~Engine()
{	CL_Shutdown();
	Qcommon_Shutdown();
#ifdef _WIN32
	//  if (dedicated && dedicated->value)
	//      FreeConsole();
	// shut down QHOST hooks if necessary
	DeinitConProc();
#endif
	
	if( Game::Engine::handle == this )
		Game::Engine::handle = nullptr;
		
	System::Message::Information( "Destructor Finished" );
}

// -----------------------------------------------
// Execute main game loop.
//

int Game::Engine::run()
{	uint32_t lastFrame = timer.getCurrent(), thisFrame;
	SDL_Event event;
	
	while( !abortLoop )
	{	while( SDL_PollEvent( &event ) )
			SDL_ProcEvent( &event, event.common.timestamp );
			
		if( Minimized || ( dedicated && dedicated->value ) )
			System::Timer::Delay( 1 );
			
		for( thisFrame = timer.getCurrent(); thisFrame <= lastFrame; thisFrame = timer.getCurrent() )
			System::Timer::Delay();
			
		try
		{	Qcommon_Frame( thisFrame - lastFrame );
		}
		catch( ... )
		{	// do nothing?
		}
		
		lastFrame = thisFrame;
	}
	
	return 0;
}
