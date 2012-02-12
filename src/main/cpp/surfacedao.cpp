#include "surfacedao.h"

#include <iostream>

using namespace std;

SDL_Surface * SurfaceDao::load(char * file) {
    SDL_Surface * temp = NULL;
    SDL_Surface * result = NULL;
 
    if((temp = SDL_LoadBMP(file)) == NULL) {
    	cout << "Failed to load [" << file << "]." << endl;
        return NULL;
    }
 
    result = SDL_DisplayFormat(temp);
    SDL_FreeSurface(temp);
 
    return result;
}

