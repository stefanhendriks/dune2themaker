#ifndef MAPDRAWER_H
#define MAPDRAWER_H

#include "surfacedrawer.h"

#include "map.h"
#include "mapcamera.h"

class MapDrawer {

	public:
		MapDrawer(int viewWidth, int viewHeight, int tilesizeWidth, int tilesizeHeight);
		~MapDrawer();

		void drawMap(SDL_Surface * dest, Map * map, MapCamera * camera);
		void drawMinimap(SDL_Surface * dest, Map * map, MapCamera * camera, int x, int y);

		void setTileset(Tileset * tileset) {
			this->tileset = tileset;
		}

	private:
		int viewWidth;
		int viewHeight;

		int tilesizeWidth;
		int tilesizeHeight;

		// resources
		Tileset * tileset;

		// dependencies
		SurfaceDrawer surfaceDrawer;
	
};

#endif