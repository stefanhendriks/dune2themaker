#include "battlefield.h"
#include "surfacedao.h"
#include "surfacedrawer.h"

#include <iostream>

using namespace std;

BattleField::BattleField() {
	test = NULL;
	tileset = NULL;

	//
	map = new Map(64, 64);
	Cell * cell = map->getCell(0, 1); // equals cell 64
	cell->setTile(24);
}

int BattleField::init() {
	// load resources
	SurfaceDao surfaceDao;
	test = surfaceDao.load((char *)"resources/images/MS_Normal.bmp");
	if (test == NULL) {
		cout << "Could not load MS_Normal.bmp" << endl;
		return -1;
	}

	SDL_Surface * tilesetSurface = surfaceDao.load((char *)"resources/images/tileset_terrain.bmp");
	if (tilesetSurface == NULL) {
		cout << "tilesetSurface is NULL" << endl;
		return -1;
	}

	this->tileset = new Tileset(tilesetSurface, 32, 32);

	return 0;	
}

void BattleField::handleEvents() {
	
}

void BattleField::update() {
	
}

void BattleField::render() {
	SurfaceDrawer surfaceDrawer;
	int mouseX, mouseY;
	SDL_GetMouseState(&mouseX, &mouseY);
	for (int x = 0; x < 20; x++) {
		for (int y = 0; y < 20; y++) {
			Cell * cell = map->getCell(x, y);
			int tile = cell->getTile();
			surfaceDrawer.draw(tileset, screen, tile, x * 32, y * 32);		
		}
	}

	
	//surfaceDrawer.drawTransparant(test, screen, mouseX + 50, mouseY + 50);
}

void BattleField::onEvent(SDL_Event * event) {
	
}

void BattleField::shutdown() {
	// clean up resources for this game state
	SDL_FreeSurface(test);
	delete tileset;
}