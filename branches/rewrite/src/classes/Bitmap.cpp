/*
 *  basic Bitmap class - implementation
 *  created by: Peter Gaal, 2011
 *  
 */

#include "Bitmap.h"
#include "SDL/SDL.h"
#include "assert.h"

Bitmap::Bitmap()
{
	// initialize surface to NULL
	m_surf = 0;
}

Bitmap::~Bitmap()
{
	// if surface is created, then free it
	if (m_surf)
	{
		SDL_FreeSurface(m_surf);
		m_surf = 0;
	}
}

void Bitmap::Load(char *filename)
{
	// if there is and old valid surface, then free it
	if (m_surf)
	{
		SDL_FreeSurface(m_surf);
		m_surf = 0;
	}
	// try to load bitmap from file
	m_surf = SDL_LoadBMP(filename);
	assert(m_surf);
}


void Bitmap::Render(SDL_Surface *Target)
{
	// try to catch access violation bugs
	assert(Target);
	// render it to default position (left-top corner)
	Bitmap::Render(Target, 0, 0);
}


void Bitmap::Render(SDL_Surface *Target, int x, int y)
{
	// try to catch access violation bugs
	assert(m_surf);
	assert(Target);

	// protect runtime problems if surfaces are not valid
	// better to not draw 
	if ((!m_surf) || (!Target))
		return;

	// blit the bitmap surface on target surface
	SDL_Rect dst_rect;
	dst_rect.x = x;
	dst_rect.y = y;
	
	SDL_BlitSurface(m_surf, 0, Target, &dst_rect);
}

void Bitmap::Render(SDL_Surface *Target, int x, int y, SDL_Rect *srcrect)
{
	// try to catch access violation bugs
	assert(m_surf);
	assert(Target);

	// protect runtime problems if surfaces are not valid
	// better to not draw 
	if ((!m_surf) || (!Target))
		return;

	// blit the bitmap surface on target surface
	SDL_Rect dst_rect;
	dst_rect.x = x;
	dst_rect.y = y;
	
	SDL_BlitSurface(m_surf, srcrect, Target, &dst_rect);
}

void Bitmap::SetColorKey(int r, int g, int b)
{
	assert(m_surf);
	if (!m_surf)
		return;
	// define color key
	SDL_SetColorKey(m_surf, SDL_SRCCOLORKEY, SDL_MapRGB(m_surf->format, r, g, b) );
}

void Bitmap::ClearColorKey()
{
	assert(m_surf);
	if (!m_surf)
		return;
	// clear color key
	SDL_SetColorKey(m_surf, 0, 0);
}

