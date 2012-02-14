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
	return getCell(toCell(x, y));
}

int Map::toCell(int x, int y) {
	return (y * width) + x;
}

int Map::toCellAbove(int cell) {
	if ((cell - width) < 0)	return -1;
	return (cell - width);
}

int Map::toCellBelow(int cell) {
	if ((cell + width) >= size) return -1;
	return (cell + width);	
}

int Map::toCellLeft(int cell) {
	int x = cell % width;

	if (x - 1 < 0) return -1;
	if (cell - 1 < 0) return -1;

	return cell - 1;
}

int Map::toCellRight(int cell) {
	int x = cell % width;

	if (x + 1 >= width) return -1;
	if (cell + 1 >= size) return -1;

	return cell + 1;
}

int Map::toCellUpperLeft(int cell) {
	int above = toCellAbove(cell);
	if (above < 0) return -1;
	return toCellLeft(above);
}

int Map::toCellUpperRight(int cell) {
	int above = toCellAbove(cell);
	if (above < 0) return -1;
	return toCellRight(above);
}

int Map::toCellLowerLeft(int cell) {
	int below = toCellBelow(cell);
	if (below < 0) return -1;
	return toCellLeft(below);		
}

int Map::toCellLowerRight(int cell) {
	int below = toCellBelow(cell);
	if (below < 0) return -1;
	return toCellRight(below);		
}

Cell * Map::getCell(int index) {
	if (index >= size || index < 0) {
		cout << "Request for cell at index [" << index << "], while min is [0] and max is [" << size << "]. Dimensions are [" << height << "X" << width << "]" << endl;
		return NULL;
	}
	return cells[index];
}