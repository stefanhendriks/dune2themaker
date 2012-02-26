#include "battlefield.h"
#include "surfacedao.h"
#include "surfacedrawer.h"

#include "mapeditor.h"

#include <iostream>

using namespace std;

BattleField::BattleField() {
	tileset = NULL;
	map = NULL;
}

int BattleField::init() {
	// load resources
	SurfaceDao surfaceDao;

	SDL_Surface * tilesetSurface = surfaceDao.load((char *)"resources/images/tileset_terrain.bmp");
	if (tilesetSurface == NULL) {
		cout << "tilesetSurface is NULL" << endl;
		return -1;
	}

	this->tileset = new Tileset(tilesetSurface, 32, 32);

	mapDrawer->setTileset(this->tileset);

	return 0;
}

void BattleField::onKeyboardEvent(SDL_KeyboardEvent * key) {
	if (key->type == SDL_KEYDOWN) {
		if (key->keysym.sym == SDLK_ESCAPE) {
			game->stop();
		}	
	}	
}

void BattleField::onMouseDownEvent(SDL_MouseButtonEvent * event) {
	mouse.onMouseDownEvent(event);
}

void BattleField::onMouseUpEvent(SDL_MouseButtonEvent * event) {
	mouse.onMouseUpEvent(event);
}

void BattleField::handleEvents() {
	
}

void BattleField::update() {
	// TEMP: provide some feedback
	int mouseX, mouseY;
	SDL_GetMouseState(&mouseX, &mouseY);
	cout << "mouseX and mouseY = [" << mouseX << "," << mouseY << "]" << endl;

	mouseX += mapCamera->getX();
	mouseY += mapCamera->getY();
	int x = mouseX / 32;
	int y = mouseY / 32;

	MapEditor * mapEditor = new MapEditor(map);

	if (mouse.isLeftMouseButtonPressed()) {
		mapEditor->setTerrain(x, y, TERRAIN_ROCK);
	}

	if (mouse.isRightMouseButtonPressed()) {
		mapEditor->smoothCellsAroundCell(map->toCell(x, y));
	}
	
	delete mapEditor;
}

void BattleField::render() {
	mapDrawer->drawMap(screen, map, mapCamera);
}

void BattleField::shutdown() {
	delete tileset;
	delete map;
}
