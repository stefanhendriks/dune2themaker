/*
 *  Static Sprite class
 *  created by: Peter Gaal, 2011
 * 
 *  This is a simple type of sprite, when it draws only
 *  simple bitmap to a specified position
 *  
 */

#ifndef STATIC_SPRITE_H
#define STATIC_SPRITE_H

#include "SDL/SDL.h"
#include "Sprite.h"
#include "BitmapList.h"
#include "Bitmap.h"

class StaticSprite: public Sprite
{
public:
	              // this is empty, because static sprite is not dependant on time
	/* virtual */ void Update(float deltaTime){}; 
	              // this is empty too
	/* virtual */ void Update_ms(int deltaTime){};
	              // render
	/* virtual */ void Render(SDL_Surface *Target)
	{
		m_BitmapListContainer->GetBitmap(m_BitmapIndex)->Render(Target, m_xpos, m_ypos);
	}
};


#endif
