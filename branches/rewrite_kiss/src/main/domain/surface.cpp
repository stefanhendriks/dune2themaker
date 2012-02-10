#include "surface.h"

Surface::Surface() {
	// empty constructor
}

SDL_Surface * Surface::load(char * file) {
    SDL_Surface * temp = NULL;
    SDL_Surface * result = NULL;
 
    if((temp = SDL_LoadBMP(file)) == NULL) {
        return NULL;
    }
 
    result = SDL_DisplayFormat(temp);
    SDL_FreeSurface(temp);
 
    return result;
}



