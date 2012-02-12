#ifndef TILESET_H
#define TILESET_H

#include <SDL/SDL.h>

class Tileset {

	public:
		~Tileset();		
		Tileset(SDL_Surface * surface, int tileWidth, int tileHeight);
		
		SDL_Rect get(int index);
		SDL_Rect get(int x, int y);

		SDL_Surface * getSurface() { return tiledSurface; };

	private:
		SDL_Surface * tiledSurface;

		int tileWidth;
		int tileHeight;

		int maxTilesWidth;
		int maxTilesHeight;

};

#endif