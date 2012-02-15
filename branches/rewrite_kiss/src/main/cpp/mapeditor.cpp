#include "mapeditor.h"

MapEditor::MapEditor(Map * map) {
	this->map = map;
}

MapEditor::~MapEditor() {
	map = NULL;
}

void MapEditor::setTile(int x, int y, int tile) {
	Cell * cellObj = map->getCell(x, y);
	if (cellObj == NULL) return;
	cellObj->setTile(tile);
}

void MapEditor::setTerrain(int x, int y, TerrainTypes terrainType) {
	Cell * cellObj = map->getCell(x, y);
	if (cellObj == NULL) return;

	cellObj->setTerrainType(terrainType);
	cellObj->setTile(getDefaultTerrainTile(terrainType));
}

void MapEditor::smoothCellsAroundCell(int cell) {
	smooth(map->toCellAbove(cell));
	smooth(map->toCellBelow(cell));
	smooth(map->toCellLeft(cell));
	smooth(map->toCellRight(cell));

	smooth(map->toCellUpperLeft(cell));
	smooth(map->toCellUpperRight(cell));
	smooth(map->toCellLowerLeft(cell));
	smooth(map->toCellLowerRight(cell));

	smooth(cell);
}

void MapEditor::smooth(int cell) {
	Cell * cellObj = map->getCell(cell);
	if (cellObj == NULL) return;
	
	int facingIndex = -1;

	if (cellObj->getTerrainType() == TERRAIN_ROCK ||
		cellObj->getTerrainType() == TERRAIN_SLAB ||
		cellObj->getTerrainType() == TERRAIN_MOUNTAIN) {
		facingIndex = smoothRock(cell);
	}

	if (facingIndex < 0) return;

	int defaultIndex = getDefaultTerrainTile(cellObj->getTerrainType());
	cellObj->setTile(defaultIndex + facingIndex);
}

// TODO: make this configurable somewhere!?
int MapEditor::getDefaultTerrainTile(TerrainTypes terrainType) {
	if (terrainType == TERRAIN_ROCK) return 40;
	return 40;
}


bool MapEditor::isTerrainType(int cell, TerrainTypes terrainType) {
	Cell * cellObj = map->getCell(cell);
	if (cellObj == NULL) return false;
	return cellObj->getTerrainType() == terrainType;
}

bool MapEditor::isAboveSpecificTerrainType(int sourceCell, TerrainTypes terrainType) {
	if (sourceCell < 0)	return false;
	int above = map->toCellAbove(sourceCell);
	return isTerrainType(above, terrainType);
}

bool MapEditor::isBelowSpecificTerrainType(int sourceCell, TerrainTypes terrainType) {
	if (sourceCell < 0)	return false;
	int under = map->toCellBelow(sourceCell);
	return isTerrainType(under, terrainType);
}

bool MapEditor::isLeftSpecificTerrainType(int sourceCell, TerrainTypes terrainType) {
	if (sourceCell < 0)	return false;
	int left = map->toCellLeft(sourceCell);
	return isTerrainType(left, terrainType);
}

bool MapEditor::isRightSpecificTerrainType(int sourceCell, TerrainTypes terrainType) {
	if (sourceCell < 0)	return false;
	int right = map->toCellRight(sourceCell);
	return isTerrainType(right, terrainType);
}

int MapEditor::smoothRock(int cell) {
	cout << "Smooth rock at [" << cell << "]" << endl;
	bool a, d, l, r;

	a = isAboveSpecificTerrainType(cell, TERRAIN_ROCK) || 
		isAboveSpecificTerrainType(cell, TERRAIN_SLAB) || 
		isAboveSpecificTerrainType(cell, TERRAIN_MOUNTAIN) || 
		isAboveSpecificTerrainType(cell, TERRAIN_WALL);

	d = isBelowSpecificTerrainType(cell, TERRAIN_ROCK) || 
		isBelowSpecificTerrainType(cell, TERRAIN_SLAB) || 
		isBelowSpecificTerrainType(cell, TERRAIN_MOUNTAIN) || 
		isBelowSpecificTerrainType(cell, TERRAIN_WALL);

	l = isLeftSpecificTerrainType(cell, TERRAIN_ROCK) || 
		isLeftSpecificTerrainType(cell, TERRAIN_SLAB) || 
		isLeftSpecificTerrainType(cell, TERRAIN_MOUNTAIN) || 
		isLeftSpecificTerrainType(cell, TERRAIN_WALL);

	r = isRightSpecificTerrainType(cell, TERRAIN_ROCK) || 
		isRightSpecificTerrainType(cell, TERRAIN_SLAB) || 
		isRightSpecificTerrainType(cell, TERRAIN_MOUNTAIN) || 
		isRightSpecificTerrainType(cell, TERRAIN_WALL);

	return getDefaultTerrainIndex(a, d, l, r);
}

/**
 * Return an index of the terrain cell. It does not matter what kind of terrain type
 * we are talking about here, the index remains the same. (zero based)
 *
 * NOTE: This is not true foright walls!
 */
int MapEditor::getDefaultTerrainIndex(bool up, bool down, bool left, bool right) {
	if (left == false && up == false && right == false && down == false) return 9; // lonely tile
	if (left == true && up == false && right == false && down == false) return 11; // at the left only
	if (left == false && up == false && right == true && down == false) return 12; // at the right only
	if (left == false && up == true && right == false && down == false) return 13; // at the top only
	if (left == false && up == false && right == false && down == true) return 14; // at the bottom only
	if (left == true && up == false && right == true && down == false) return 10;	// one way connection  (left/right)
	if (left == false && up == true && right == false && down == true) return 15;  // one way connection  (up/down)

	if (left == true && up == true && right == false && down == false) return 6;
	if (left == true && up == false && right == false && down == true) return 7;
	if (left == false && up == true && right == true && down == false) return 8;
	if (left == false && up == false && right == true && down == true) return 5;

	if (left == true && up == true && right == false && down == true) return 2;
	if (left == false && up == true && right == true && down == true) return 1;
	if (left == true && up == true && right == true && down == false) return 4;
	if (left == true && up == false && right == true && down == true) return 3;

	return 0;
}
