/*
 *  Timer class headers based on SDL functions
 *  created by: Peter Gaal, 2011
 *  
 *  This is a derived timer class which uses SDL functions to get timing information
 *
 */

#include "SDLTimer.h"
#include "SDL/SDL.h"


SDLTimer::SDLTimer()
{
	m_TickStart = SDL_GetTicks();
	m_TickLast = SDL_GetTicks();
}

int SDLTimer::getElapsedTimeSinceCreationInMsec()
{
	return SDL_GetTicks() - m_TickStart;
}

float SDLTimer::getElapsedTimeSinceCreationInSec()
{
	return float(SDL_GetTicks() - m_TickStart) / 1000.0f;
}

int SDLTimer::getDeltaTimeSinceLastCalledInMsec()
{
	int new_Ticks = SDL_GetTicks();
	if (new_Ticks == m_TickLast)
		return 0;
	int delta_Time = new_Ticks - m_TickLast;
	m_TickLast = new_Ticks;
	return delta_Time;

}

float SDLTimer::getDeltaTimeSinceLastCalledInSec()
{
	return float(getDeltaTimeSinceLastCalledInMsec()) / 1000.0f;

}
