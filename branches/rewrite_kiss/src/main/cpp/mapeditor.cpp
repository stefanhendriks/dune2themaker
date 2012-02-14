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


void MapEditor::smooth(int cell) {
	map->getCell(cell);
}

bool MapEditor::isTerrainType(int cell, TerrainTypes terrainType) {
	Cell * cellObj = map->getCell(cell);
	if (cellObj == NULL) return false;
	return cellObj->getTerrainType() == terrainType;
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
