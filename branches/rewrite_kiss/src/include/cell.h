#ifndef CELL_H
#define CELL_H

#include <iostream>

#include "terraintypes.h"

using namespace std;

class Cell {

	public:
		Cell() { 
			this->tile = 0;
			this->terrainType = TERRAIN_SAND;
		}

		Cell(int tile) { 
			this->tile = tile; 
		}

		// Setters
		void setTile(int tile) { 
			this->tile = tile; 
		}

		void setTerrainType(TerrainTypes terrainType) {
			this->terrainType = terrainType;
		}
		
		// Getters
		TerrainTypes getTerrainType() { 
			return terrainType; 
		}

		int getTile() {
			return this->tile; 
		}

		bool isSand() {
			return terrainType == TERRAIN_SAND;
		}

		bool isRock() {
			return terrainType == TERRAIN_ROCK;
		}

		bool isSpice() {
			return terrainType == TERRAIN_SPICE;
		}

	private:
		// cell properties
		int tile;
		

		// properties of type of terrain
		TerrainTypes terrainType;

};

#endif