#ifndef CELL_H
#define CELL_H

#include <iostream>

using namespace std;

class Cell {

	public:
		Cell() { this->tile = 0; }
		Cell(int tile) { this->tile = tile; };

		int getTile() { return this->tile; }
		void setTile(int tile) { this->tile = tile; }

	private:
		int tile;

};

#endif