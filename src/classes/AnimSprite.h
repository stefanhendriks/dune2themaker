/*
 *  Animated Sprite class
 *  created by: Peter Gaal, 2011
 * 
 *  This is an animated sprite. The basic idea is to have a rectangular
 *  areas in a bitmap (which is in bitmap list) and they will make a single frame.
 *  In this class it will be from the same bitmap.
 *  
 */


#ifndef ANIM_SPRITE_H
#define ANIM_SPRITE_H

#include "SDL/SDL.h"
#include "Sprite.h"
#include "BitmapList.h"
#include "Bitmap.h"
#include <vector>

using namespace std;

// this is now only for internal usage, we don't need use this
// structure from other classes. This class will be in vector
typedef struct AnimSprite_FrameRecord
{
	int x;					// x-coordinate
	int y;					// y-coordinate
	int w;					// width
	int h;					// height
	float FrameLength;		// Length of frame in seconds
} AnimSprite_FrameRecord;

// animated sprite class
class AnimSprite: public Sprite
{
public:
	AnimSprite();
	/* virtual */ ~AnimSprite(); 
	/* virtual */ void Update(float deltaTime); 
	/* virtual */ void Update_ms(int deltaTime);
	/* virtual */ void Render(SDL_Surface *Target);
	void AddFrame(int x, int y, int w, int h, float FrameLength);
private:
	// we hold the time information here
	float m_TimeCounter;
	// current frame on output
	unsigned int m_CurrentFrame;
	vector<AnimSprite_FrameRecord*> m_FrameList;
};


#endif
