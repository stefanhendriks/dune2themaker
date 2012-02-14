#ifndef MAP_H
#define MAP_H

#include <vector>

#include "cell.h"

class Map {

	public:
		Map(int width, int height);
		~Map();

		Cell * getCell(int x, int y);
		Cell * getCell(int index);
		
		int toCell(int x, int y);

		int toCellAbove(int cell);
		int toCellBelow(int cell);
		int toCellLeft(int cell);
		int toCellRight(int cell);

		int toCellUpperLeft(int cell);
		int toCellUpperRight(int cell);
		int toCellLowerLeft(int cell);
		int toCellLowerRight(int cell);

		int getWidth() { return width; }
		int getHeight() { return height; }

	private:
		Cell ** cells;
		int size;

		// dimensions
		int width;
		int height;

};

#endif