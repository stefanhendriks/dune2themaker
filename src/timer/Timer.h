/*
 *  Base timer class for game timing functions
 *  created by: Peter Gaal, 2011
 *  
 *  This is a base class for timing functions. In derived classes we will implement
 *  OS or library specific timing classes. The basic derived class will be implemented
 *  on SDL library timing functions. On some architectures (os versions) there is hard
 *  to get an accurate timing. On windows architecture sometimes you have timer resolution
 *  with 55ms accuracy on a default timer, but you can use high performance counters.
 *  Some linux kernels and/or architectures have 10 ms accuracy. For game functions is
 *  better to get a good timer resolution, 10 ms should be enough (it is 100 fps).
 *  The SDL library has good accuracy, I can get in test 1 ms accuracy.
 *
 */


#ifndef TIMER_H
#define TIMER_H

class Timer
{
public:
	// Elapsed time in [ms], after starting the game or creating the timer class
	// return is int - which is faster than float
	virtual int getElapsedTimeSinceCreationInMsec() = 0;

	// elapsed time in [s], after starting the game or creating the time class
	// return is float - more precise
	virtual float getElapsedTimeSinceCreationInSec() = 0;

	// delta time in [ms] units, this is the elapsed time from last call of this function
	// return as int - if the elapsed time is exactly in ms units, it must handle those problems
	// so the time measurement must be accurate, many small time increments must make the same result
	// as in absolute elapsed time, so if I call this function every 0.2ms and always get 0 as a result
	// then it is bad
	virtual int getDeltaTimeSinceLastCalledInMsec() = 0;

	// delta time in [s] units, this is the elapsed time from last call of this function
	// return as float
	virtual float getDeltaTimeSinceLastCalledInSec() = 0;
};



#endif
