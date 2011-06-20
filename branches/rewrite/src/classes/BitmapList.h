/*
 *  Bitmap List
 *  created by: Peter Gaal, 2011
 */

#ifndef BITMAP_LIST_H
#define BITMAP_LIST_H

#include "SDL/SDL.h"
#include "Bitmap.h"
#include "Singleton.h"

#define MAX_BITMAPS 1024

enum Bitmaps
{
	BMP_BEGIN = 0,
	BMP_END
};

class BitmapList: public Singleton<BitmapList>
{
public:
	BitmapList();
	~BitmapList();
	void LoadBitmap(int Index, char * filename);
	Bitmap* GetBitmap(int Index);
private:
	Bitmap* m_List[MAX_BITMAPS];
};



#endif
