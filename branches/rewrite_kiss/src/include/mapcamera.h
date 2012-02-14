#ifndef MAPCAMERA_H
#define MAPCAMERA_H

#include "map.h"

class MapCamera {

	public:
		MapCamera(Map * map, int viewportWidth, int viewportHeight);
		~MapCamera();
		
		int getX() { return x; }
		int getY() { return y; }

		void moveTo(int x, int y);

	private:
		void handleMapBoundaries();

		int x, y;
		int viewportHeight, viewportWidth;

		Map * map;

	
};

#endif