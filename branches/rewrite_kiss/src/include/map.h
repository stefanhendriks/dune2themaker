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

	private:
		Cell ** cells;
		int size;

		// dimensions
		int width;
		int height;

};

#endif