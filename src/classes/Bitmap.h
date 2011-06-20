/*
 *  basic Bitmap class interface
 *  created by: Peter Gaal, 2011
 * 
 *  this is just a container for loading bitmaps and manipulating with them,
 *  for example rendering.
 */


#ifndef BITMAP_H
#define BITMAP_H

#include "SDL/SDL.h"

class Bitmap
{
public:
	Bitmap();
	~Bitmap();
	void Load(char * filename);
	void Render(SDL_Surface *Target);
	void Render(SDL_Surface *Target, int x, int y);
	void Render(SDL_Surface *Target, int x, int y, SDL_Rect *srcrect);
	void SetColorKey(int r, int g, int b);
	void ClearColorKey();
private:
	SDL_Surface *m_surf;
};



#endif
