#include "GameTimer.h"
#include <SDL_timer.h>

#ifdef _WIN32
#include <Windows.h>
#endif

Game::Timer *Handler::Timer = nullptr;

Game::Timer::Timer()
: timeStarted(0), timeLast(0)
{
	if (Handler::Timer == nullptr)
	{
		Handler::Timer = this;
	}
	timeStarted = SDL_GetTicks();
}

Game::Timer::~Timer()
{
	if (Handler::Timer == this)
	{
#ifdef _WIN32
		timeEndPeriod(1);
#endif
	}
}

uint32_t Game::Timer::getCurrent()
{
	return timeLast = (SDL_GetTicks() - timeStarted);
}

void Game::Timer::Delay(const uint32_t ms)
{
	SDL_Delay(ms);
}