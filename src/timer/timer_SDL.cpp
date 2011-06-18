/*
 *  Timer class headers based on SDL functions
 *  created by: Peter Gaal, 2011
 *  
 *  This is a derived timer class which uses SDL functions to get timing information
 *
 */

#include "timer_SDL.h"
#include "SDL/SDL.h"


Timer_SDL::Timer_SDL()
{
	m_TickStart = SDL_GetTicks();
	m_TickLast = SDL_GetTicks();
}

int Timer_SDL::ElapsedTime_msec()
{
	return SDL_GetTicks() - m_TickStart;
}

float Timer_SDL::ElapsedTime_sec()
{
	return float(SDL_GetTicks() - m_TickStart) / 1000.0f;
}

int Timer_SDL::DeltaTime_msec()
{
	int new_Ticks = SDL_GetTicks();
	if (new_Ticks == m_TickLast)
		return 0;
	int delta_Time = new_Ticks - m_TickLast;
	m_TickLast = new_Ticks;
	return delta_Time;

}

float Timer_SDL::DeltaTime_sec()
{
	return float(DeltaTime_msec()) / 1000.0f;

}
