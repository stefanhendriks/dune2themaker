#ifndef MAPDRAWER_H
#define MAPDRAWER_H

#include "surfacedrawer.h"

#include "map.h"
#include "mapcamera.h"

class MapDrawer {

	public:
		MapDrawer(int viewWidth, int viewHeight);
		~MapDrawer();

		void drawMap(Map * map, MapCamera * camera);
		void drawMinimap(Map * map, MapCamera * camera, int x, int y);

		void setTileset(Tileset * tileset) {
			this->tileset = tileset;
		}

	private:
		int viewWidth;
		int viewHeight;

		// resources
		Tileset * tileset;

		// dependencies
		SurfaceDrawer surfaceDrawer;
	
};

#endif