#include "surfacedrawer.h"


void SurfaceDrawer::draw(SDL_Surface * from, SDL_Surface * dest, int x, int y) {
	if(from == NULL || dest == NULL) {
		return;
	}

	SDL_Rect rect;
	rect.x = x;
	rect.y = y;

	SDL_BlitSurface(from, NULL, dest, &rect);
}

void SurfaceDrawer::drawTransparant(SDL_Surface * from, SDL_Surface * dest, int x, int y) {
 	Uint32 colorkey = SDL_MapRGB(from->format, 255, 0, 255);
    SDL_SetColorKey(from, SDL_SRCCOLORKEY, colorkey);
    draw(from, dest, x, y);
    SDL_SetColorKey(from, 0, 0); 
}

void SurfaceDrawer::clearToColor(SDL_Surface * target, Uint32 color) {
	if (target == NULL) return;
	SDL_FillRect (target, NULL, color); 	
}

