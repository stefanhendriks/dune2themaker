/*
 *  Timer class headers based on SDL functions
 *  created by: Peter Gaal, 2011
 *  
 *  This is a derived timer class which uses SDL functions to get timing information
 *
 */


#ifndef TIMER_SDL_H
#define TIMER_SDL_H

#include "timer_base.h"


class Timer_SDL: public Timer
{
public:
	// constructor
	Timer_SDL();
	/* virtual */ int ElapsedTime_msec();
	/* virtual */ float ElapsedTime_sec();
	/* virtual */ int DeltaTime_msec();
	/* virtual */ float DeltaTime_sec();

private:
	// Ticks value after creating class
	int m_TickStart;
	int m_TickLast;
};


#endif
