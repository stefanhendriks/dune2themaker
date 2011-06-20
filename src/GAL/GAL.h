/*
 * Game Abstraction Layer.
 *
 * Hiding several boiler plate / library code from the game implementation. Making it easy to play sounds, draw
 * pictures, load up resources and more.
 *
 * This abstraction layer is SDL specific for the time being.
 *
 */

#ifndef GAL_INTERFACE_H
#define GAL_INTERFACE_H

#include <SDL/SDL.h>

class GAL {
	public:
		void drawSurface(SDL_Surface * surface, int x, int y);
};

#endif
