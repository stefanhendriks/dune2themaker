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

void BattleField::onMouseEvent(SDL_MouseButtonEvent * mouse) {
	// TEMP: provide some feedback
	int mouseX, mouseY;
	SDL_GetMouseState(&mouseX, &mouseY);
	mouseX += mapCamera->getX();
	mouseY += mapCamera->getY();
	int x = mouseX / 32;
	int y = mouseY / 32;

	if ((mouse->button == SDL_BUTTON_LEFT) ) { // || (mouse->button == 5) --> mouse wheel down
		// manipulate map
		MapEditor * mapEditor = new MapEditor(map);
		mapEditor->setTerrain(x, y, TERRAIN_ROCK);
	}

	if ((mouse->button == SDL_BUTTON_RIGHT) ) { // || (mouse->button == 5) --> mouse wheel down
		// manipulate map
		MapEditor * mapEditor = new MapEditor(map);
		mapEditor->smoothCellsAroundCell(map->toCell(x, y));
	}
}

void BattleField::handleEvents() {
	
}

void BattleField::update() {
	
}

void BattleField::render() {
	mapDrawer->drawMap(screen, map, mapCamera);
}

void BattleField::shutdown() {
	delete tileset;
	delete map;
}
