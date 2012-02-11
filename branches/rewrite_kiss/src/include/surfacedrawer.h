#ifndef SURFACEDRAWER_H
#define SURFACEDRAWER_H

#include <SDL/SDL.h>

class SurfaceDrawer {

	public:
		void draw(SDL_Surface * from, SDL_Surface * dest, int x, int y);
		void draw(SDL_Surface * from, SDL_Surface * dest, int fromX, int fromY, int width, int height, int x, int y);
		void drawTransparant(SDL_Surface * from, SDL_Surface * to, int x, int y);
		
		void clearToColor(SDL_Surface * target, Uint32 color);
	
};

#endif
