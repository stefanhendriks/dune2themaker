#ifndef SURFACE_H
#define SURFACE_H

#include <SDL/SDL.h>

class Surface {

	public:
		Surface();

	public:
		static SDL_Surface * load(char * file);

};

#endif
