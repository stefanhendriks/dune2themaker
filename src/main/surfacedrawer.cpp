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

void SurfaceDrawer::clearToColor(SDL_Surface * target, Uint32 color) {
	if (target == NULL) return;
	SDL_FillRect (target, NULL, color); 	
}

