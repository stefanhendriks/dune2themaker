#ifndef MAPEDITOR_H
#define MAPEDITOR_H

#include "map.h"

class MapEditor {

	public:
		MapEditor(Map * map);
		~MapEditor();
		
		void randomize();

		void smooth(int cell);

		void setTile(int x, int y, int tile);

		bool isTerrainType(int cell, TerrainTypes terrainType);
		
		int getDefaultTerrainIndex(bool up, bool down, bool left, bool right);

	private:	
		Map * map;
};

#endif