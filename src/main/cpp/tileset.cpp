#include "tileset.h"

#include <iostream>

using namespace std;

Tileset::~Tileset() {
	SDL_FreeSurface(tiledSurface);
	tiledSurface = NULL;
}

Tileset::Tileset(SDL_Surface * surface, int tileWidth, int tileHeight) {
	this->tiledSurface = NULL;
	this->tileHeight = 0;
	this->tileWidth = 0;
	this->maxTilesWidth = 0;
	this->maxTilesHeight = 0;

	if (!surface) {
		cout << "WARN: Tileset has no surface." << endl;
		return;
	}

	tiledSurface = surface;
	this->tileHeight = tileHeight;
	this->tileWidth = tileWidth;

	this->maxTilesWidth = (surface->w / tileWidth);
	this->maxTilesHeight = (surface->h / tileHeight);
	
	cout << "Tileset constructed with surface of [" << surface->w << "X" << surface->h << "]";
	cout << ". Using a tile size of [" << tileWidth << "X" << tileHeight << "]";
	cout << " resulting in a tileset with dimensions [" << maxTilesWidth << "X" << maxTilesHeight << "]";
	cout << endl;
}

SDL_Rect Tileset::get(int index) {
	int x = index % maxTilesWidth;
	int y = (index / maxTilesWidth);
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