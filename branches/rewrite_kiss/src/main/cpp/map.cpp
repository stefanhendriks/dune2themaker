#include <cstddef>
#include <iostream>

#include "map.h"

using namespace std;

Map::Map(int width, int height) {
	this->cells = NULL;
	this->size = 0;
	this->width = width;
	this->height = height;

	if (width < 1 || height < 1) return;

	this->size = (width * height);

	this->cells = new Cell * [this->size];

	cout << "Map constructed with dimensions [" << width << "x" << height << "]";
	cout << ", size [" << this->size << "]" << endl;

	for (int i = 0; i < this->size; i++) {
		this->cells[i] = new Cell(0);
	}
}

Map::~Map() {
	for (int i = 0; i < size; i++) {
		delete cells[i];
	}
	delete [] cells;
	cells = NULL;
}

Cell * Map::getCell(int x, int y) {
	int cell = (y * width) + x;
	//cout << "x,y [" << x << "," << y << "] makes cell [" << cell << "]" << endl;
	return getCell(cell);
}

Cell * Map::getCell(int index) {
	if (index >= size || index < 0) {
		cout << "Request for cell at index [" << index << "], while min is [0] and max is [" << size << "]. Dimensions are [" << height << "X" << width << "]" << endl;
		return NULL;
	}
	return cells[index];
}