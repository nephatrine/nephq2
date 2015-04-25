#include "SystemMessage.h"
#include "SystemTimer.h"
#include <SDL_hints.h>
#include <SDL_timer.h>

bool_t System::Timer::tuned = false;

System::Timer::Timer()
	: timeStarted( 0 ), timeLast( 0 )
{	Tune();
	timeStarted = SDL_GetTicks();
}

uint32_t System::Timer::getCurrent()
{	return timeLast = ( SDL_GetTicks() - timeStarted );
}

void System::Timer::Delay( const uint32_t ms )
{	SDL_Delay( ms );
}

bool_t System::Timer::Tune()
{	if( !tuned )
	{	if( !SDL_SetHintWithPriority( SDL_HINT_TIMER_RESOLUTION, "1", SDL_HINT_OVERRIDE ) )
			System::Message::Warning( "Unable to set OS timer resolution." );
		else tuned = true;
	}
	
	return tuned;
}
