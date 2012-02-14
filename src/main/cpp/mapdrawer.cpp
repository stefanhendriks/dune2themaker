#include "mapdrawer.h"

MapDrawer::MapDrawer(int viewWidth, int viewHeight, int tilesizeWidth, int tilesizeHeight) {
	this->tilesizeWidth = tilesizeWidth;
	this->tilesizeHeight = tilesizeHeight;
	this->viewWidth = viewWidth / tilesizeWidth;
	this->viewHeight = viewHeight / tilesizeHeight;
}

MapDrawer::~MapDrawer() {
	
}

void MapDrawer::drawMap(SDL_Surface * dest, Map * map, MapCamera * camera) {
	if (map == NULL || camera == NULL || dest == NULL) return;

	for (int x = camera->getX(); x < camera->getXWithViewportWidth(); x++) {
		for (int y = camera->getY(); y < camera->getYWithViewportHeight(); y++) {
			Cell * cell = map->getCell(x, y);
			surfaceDrawer.draw(tileset, dest, cell->getTile(), x * tilesizeWidth, y * tilesizeHeight);
		}
	}
}

void MapDrawer::drawMinimap(SDL_Surface * dest, Map * map, MapCamera * camera, int x, int y) {
	if (map == NULL || camera == NULL || dest == NULL) return;
		
}
