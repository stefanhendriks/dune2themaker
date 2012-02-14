#include "mapcamera.h"

MapCamera::MapCamera(Map * map, int viewportWidth, int viewportHeight) {
	this->x = 0;
	this->y = 0;
	this->viewportWidth = viewportWidth;
	this->viewportHeight = viewportHeight;
	this->map = map;
}

MapCamera::~MapCamera() {
	map = NULL;
}

void MapCamera::moveTo(int x, int y) {
	this->x = x;
	this->y = y;
	handleMapBoundaries();
}

void MapCamera::handleMapBoundaries() {
	if (map == NULL)	return;

	int outerX = x + viewportWidth;
	int outerY = y + viewportHeight;

	if (outerX > map->getWidth()) {
		x = map->getWidth() - viewportWidth;
	}

	if (outerY > map->getHeight()) {
		y = map->getHeight() - viewportHeight;
	}

	if (x < 0) x = 0;
	if (y < 0) y = 0;
}
