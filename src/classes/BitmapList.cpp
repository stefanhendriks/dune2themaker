/*
 *  Bitmap List class implementation
 *  created by: Peter Gaal, 2011
 */


#include "BitmapList.h"
#include "Bitmap.h"
#include "SDL/SDL.h"
#include "assert.h"
#include "Singleton.h"

DefSingleton(BitmapList);

BitmapList::BitmapList()
{
	// clear Bitmap array
	memset(m_List, 0, sizeof(m_List));
}

BitmapList::~BitmapList()
{
	Bitmap* tempBitmap;
	for (int i=0; i<MAX_BITMAPS; i++)
	{
		tempBitmap = m_List[i];
		// clear all non-empty Sprite objects
		if (!tempBitmap)
		{
			delete tempBitmap;
			m_List[i] = 0;
		}

	}
}

void BitmapList::LoadBitmap(int Index, char *filename)
{
	Bitmap* tempBitmap;
	assert((Index>=0) && (Index<MAX_BITMAPS));
	if ( (Index<0) || (Index>=MAX_BITMAPS) )
		return;
	tempBitmap = m_List[Index];
	if (!tempBitmap)
	{
		tempBitmap = new Bitmap;
		m_List[Index] = tempBitmap;
	}
	tempBitmap->Load(filename);
}

Bitmap* BitmapList::GetBitmap(int Index)
{
	assert((Index>=0) && (Index<MAX_BITMAPS));
	if ( (Index<0) || (Index>=MAX_BITMAPS) )
		return 0;
	assert(m_List[Index]);
	return m_List[Index];
}

