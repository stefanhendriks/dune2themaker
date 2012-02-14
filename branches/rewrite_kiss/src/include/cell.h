#ifndef CELL_H
#define CELL_H

#include <iostream>

#include "terraintypes.h"

using namespace std;

class Cell {

	public:
		Cell() { 
			this->tile = 0;
			this->terrainType = TerrainTypes::getSand();
		}

		Cell(int tile) { 
			this->tile = tile; 
		}

		// Setters
		void setTile(int tile) { 
			this->tile = tile; 
		}

		// Getters
		TerrainType getTerrainType() { 
			return terrainType; 
		}

		int getTile() {
			return this->tile; 
		}

	private:
		// cell properties
		int tile;
		

		// properties of type of terrain
		TerrainType terrainType;

};

#endif