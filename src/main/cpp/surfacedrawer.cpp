#include "surfacedrawer.h"

void SurfaceDrawer::draw(Tileset * tileSet, SDL_Surface * dest, int index, int x, int y) {
	if (tileSet == NULL) {
		return;	
	}

	SDL_Surface * from = tileSet->getSurface();
	if (from == NULL) return;	
	
	SDL_Rect rect = tileSet->get(index);

	SDL_Rect destRect;
	destRect.x = x;
	destRect.y = y;

	SDL_BlitSurface(from, &rect, dest, &destRect);
}

void SurfaceDrawer::draw(SDL_Surface * from, SDL_Surface * dest, int x, int y) {
	if(from == NULL || dest == NULL) {
		return;
	}

	SDL_Rect rect;
	rect.x = x;
	rect.y = y;

	// SDL Docs say:
	// int SDL_BlitSurface(SDL_Surface *src, SDL_Rect *srcrect, SDL_Surface *dst, SDL_Rect *dstrect);
	// only X and Y will be used in dstrect (width and height skipped).
	SDL_BlitSurface(from, NULL, dest, &rect);
}

void SurfaceDrawer::draw(SDL_Surface * from, SDL_Surface * dest, int fromX, int fromY, int width, int height, int x, int y) {
	if(from == NULL || dest == NULL) {
		return;
	}
 
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;

	SDL_Rect fromRect;

	fromRect.x = fromX;
	fromRect.y = fromY;
	fromRect.w = width;
	fromRect.h = height;

	SDL_BlitSurface(from, &fromRect, dest, &rect);
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

