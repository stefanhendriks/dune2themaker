#include "mapdrawer.h"

MapDrawer::MapDrawer(int viewWidth, int viewHeight) {
	this->viewWidth = viewWidth;
	this->viewHeight = viewHeight;
}

MapDrawer::~MapDrawer() {
	
}

void MapDrawer::drawMap(Map * map, MapCamera * camera) {
	if (map == NULL || camera == NULL) return;
}

void MapDrawer::drawMinimap(Map * map, MapCamera * camera, int x, int y) {
	if (map == NULL || camera == NULL) return;
		
}
