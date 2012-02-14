#include "battlefield.h"
#include "surfacedao.h"
#include "surfacedrawer.h"

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

	// 
	Cell * cell = map->getCell(0, 1); // equals cell 64
	cell->setTile(24);

	return 0;
}

void BattleField::onKeyboardEvent(SDL_KeyboardEvent * key) {
	if (key->type == SDL_KEYDOWN) {
		if (key->keysym.sym == SDLK_ESCAPE) {
			game->stop();
		}	
	}	
}

void BattleField::onMouseEvent(SDL_Event * event) {
	
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
