/*
 *  Sprite abstract class
 *  created by: Peter Gaal, 2011
 * 
 *  this is the basic Sprite class
 *  other classes will implement functions as necessary
 */

#ifndef SPRITE_H
#define SPRITE_H

#include "SDL/SDL.h"
#include "BitmapList.h"

class Sprite
{
public:
	// default constructor, possible to use bitmap index parameter
	Sprite(int Index = -1)
	{ 
		m_BitmapListContainer = BitmapList::GetInstance();
		m_BitmapIndex = Index;
	}
	// destructor
	virtual ~Sprite(){};
	// set Bitmap Index
	void SetIndex(int Index)
	{
		m_BitmapIndex = Index;
	}
	// Update sprite parameters, the input is an elapsed time in [s] since the last call
	virtual void Update(float deltaTime) = 0;
	// Update sprite parameters, the input is an elapsed time in [ms] since the last call
	virtual void Update_ms(int deltaTime) = 0;
	// set position (left and top) of the sprite
	virtual void SetPosition(int x, int y)
	{
		m_xpos = x;
		m_ypos = y;
	};
	// Render sprite on target surface
	virtual void Render(SDL_Surface *Target) = 0;

protected:
	int m_BitmapIndex;		// index of bitmap what we use 
	int m_xpos, m_ypos;     // x and y position of sprite
	BitmapList* m_BitmapListContainer;
};



#endif
