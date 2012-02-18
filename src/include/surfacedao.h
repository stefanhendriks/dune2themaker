#ifndef SURFACEREPO
#define SURFACEREPO

// Data Access Object for fetching SDL Surfaces
#include <SDL/SDL.h>


class SurfaceDao {

	public:
		SDL_Surface * load(char * file);

};

#endif

