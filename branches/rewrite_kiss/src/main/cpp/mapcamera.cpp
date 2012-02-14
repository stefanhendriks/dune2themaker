#include "mapcamera.h"

MapCamera::MapCamera() {
	x = y = 0;
}

MapCamera::MapCamera(int x, int y) {
	this->x = x;
	this->y = y;
}

MapCamera::~MapCamera() {
	
}

void MapCamera::moveTo(int x, int y) {
	this->x = x;
	this->y = y;
}