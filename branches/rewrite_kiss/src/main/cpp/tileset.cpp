#include "tileset.h"


Tileset::Tileset(SDL_Surface * surface, int tileWidth, int tileHeight) {
	tiledSurface = NULL;
	tileHeight = 0;
	tileWidth = 0;

	if (!surface) {
		return;
	}

	tiledSurface = surface;
	this->tileHeight = tileHeight;
	this->tileWidth = tileWidth;
}