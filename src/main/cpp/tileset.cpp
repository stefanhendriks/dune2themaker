#include "tileset.h"

#include <iostream>

using namespace std;

Tileset::~Tileset() {
	SDL_FreeSurface(tiledSurface);
	tiledSurface = NULL;
}

Tileset::Tileset(SDL_Surface * surface, int tileWidth, int tileHeight) {
	this->tiledSurface = NULL;
	this->tileHeight = tileHeight;
	this->tileWidth = tileWidth;
	this->maxTilesWidth = 0;
	this->maxTilesHeight = 0;


	if (surface == NULL) {
		cout << "WARN: Tileset has no surface." << endl;
		return;
	}

	tiledSurface = surface;

	init(surface->w, surface->h);
}

void Tileset::init(int surfaceWidth, int surfaceHeight) {
	this->maxTilesWidth = (surfaceWidth / tileWidth);
	this->maxTilesHeight = (surfaceHeight / tileHeight);
	
	cout << "Tileset constructed with surface of [" << surfaceWidth << "X" << surfaceHeight << "]";
	cout << ". Using a tile size of [" << tileWidth << "X" << tileHeight << "]";
	cout << " resulting in a tileset with dimensions [" << maxTilesWidth << "X" << maxTilesHeight << "]";
	cout << endl;
}

// Note: This is zero based. meaning, index 0 = 0,0. 
// when index > maxTilesWidth (it is 0 to maxTilesWidth!) then it flips.
SDL_Rect Tileset::get(int index) {
	int x = index % maxTilesWidth;
	int y = (index / maxTilesWidth);
	cout << "X,Y for index [" << index << "] is [" << x << "," << y << "]" << endl;
	return get(x, y);
}

SDL_Rect Tileset::get(int x, int y) {
	SDL_Rect rect;
	rect.x = (x * tileWidth);
	rect.y = (y * tileHeight);
	rect.w = tileWidth;
	rect.h = tileHeight;
	return rect;
}