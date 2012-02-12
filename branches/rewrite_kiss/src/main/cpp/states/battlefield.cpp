#include "battlefield.h"
#include "surfacedao.h"
#include "surfacedrawer.h"

#include <iostream>

using namespace std;

BattleField::BattleField() {
	test = NULL;
}

int BattleField::init() {
	// load resources
	SurfaceDao surfaceDao;
	test = surfaceDao.load("resources/images/MS_Normal.bmp");
	if (test == NULL) {
		cerr << "Could not load MS_Normal.bmp" << endl;
		return -1;
	}	
}

void BattleField::handleEvents() {
	
}

void BattleField::update() {
	
}

void BattleField::render() {
	SurfaceDrawer surfaceDrawer;
	int mouseX, mouseY;
	SDL_GetMouseState(&mouseX, &mouseY); 
	surfaceDrawer.drawTransparant(test, screen, mouseX + 50, mouseY + 50);
}

void BattleField::onEvent(SDL_Event * event) {
	
}

void BattleField::shutdown() {
	// clean up resources for this game state
	SDL_FreeSurface(test);
}