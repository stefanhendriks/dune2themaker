#ifndef MAPEDITOR_H
#define MAPEDITOR_H

#include "map.h"

class MapEditor {

	public:
		MapEditor(Map * map);
		~MapEditor();
		
		void randomize();

		void smooth(int cell);
		void smoothCellsAroundCell(int cell);

		void setTile(int x, int y, int tile);
		void setTerrain(int x, int y, TerrainTypes terrainType);

		void setTile(int cell, int tile);
		void setTerrain(int cell, TerrainTypes terrainType);

		bool isTerrainType(int cell, TerrainTypes terrainType);
		
		int getDefaultTerrainIndex(bool up, bool down, bool left, bool right);

	protected:
		int smoothRock(int cell);

		bool isAboveSpecificTerrainType(int sourceCell, TerrainTypes terrainType);
		bool isBelowSpecificTerrainType(int sourceCell, TerrainTypes terrainType);
		bool isLeftSpecificTerrainType(int sourceCell, TerrainTypes terrainType);
		bool isRightSpecificTerrainType(int sourceCell, TerrainTypes terrainType);

		int getDefaultTerrainTile(TerrainTypes terrainType);

	private:	
		Map * map;
};

#endif