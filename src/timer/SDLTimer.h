/*
 *  Timer class headers based on SDL functions
 *  created by: Peter Gaal, 2011
 *  
 *  This is a derived timer class which uses SDL functions to get timing information
 *
 */

#ifndef SDL_TIMER_H
#define SDL_TIMER_H

#include "Timer.h"

class SDLTimer : public Timer {
	public:
		// constructor
		SDLTimer();

		/* virtual */
		int getElapsedTimeSinceCreationInMsec();
		/* virtual */
		float getElapsedTimeSinceCreationInSec();
		/* virtual */
		int getDeltaTimeSinceLastCalledInMsec();
		/* virtual */
		float getDeltaTimeSinceLastCalledInSec();

	private:
		// Ticks value after creating class
		int m_TickStart;
		int m_TickLast;
};

#endif
