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
	Cell * cell = map->getCell(0, 1); 
	int tile = cell->getTile();
	cout << "Cell has tile [" << tile << "]" << endl;
	surfaceDrawer.draw(tileset, screen, tile, mouseX + 50, mouseY + 50);
	//surfaceDrawer.drawTransparant(test, screen, mouseX + 50, mouseY + 50);
}

void BattleField::onEvent(SDL_Event * event) {
	
}

void BattleField::shutdown() {
	// clean up resources for this game state
	SDL_FreeSurface(test);
	delete tileset;
}