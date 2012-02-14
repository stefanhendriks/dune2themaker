#include "gamefactory.h"

#include "gamestate.h"
#include "battlefield.h"

#include "map.h"
#include "mapcamera.h"
#include "mapdrawer.h"

#include "settings.h"

#include <iostream>

using namespace std;

Game GameFactory::create() {
	cout << "Initializing SDL..." << endl;

	Settings settings;
	settings.screenWidth = 800;
	settings.screenHeight = 600;

	if((SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO)==-1)) { 
		printf("Could not initialize SDL: %s.\n", SDL_GetError());
		exit(1);
	}

	SDL_Surface * screen = SDL_SetVideoMode(settings.screenWidth, settings.screenHeight, 16, SDL_SWSURFACE);
	if ( screen == NULL ) {
		printf("Unable to set %dx%d video: %s\n", settings.screenWidth, settings.screenHeight, SDL_GetError());
		exit(1);
	}
		
	SDL_ShowCursor(0); 

	cout << "SDL Init, screen surface allocated and showcursus set to 0." << endl;

	Game game;

	// TODO: create game state factory
	BattleField * battleField = new BattleField();
	battleField->setScreen(screen);

	Map * map = new Map(64, 64);
	battleField->setMap(map);

	MapCamera * mapCamera = new MapCamera(map, settings.screenWidth / 32, settings.screenHeight / 32);
	battleField->setMapCamera(mapCamera);

	MapDrawer * mapDrawer = new MapDrawer(settings.screenWidth / 32, settings.screenHeight / 32);
	battleField->setMapDrawer(mapDrawer);

	battleField->init();


	game.setGameState(battleField);
	game.setScreen(screen);
	
	if (game.init() != 0) {
		cout << "Error initializing game." << endl;
		exit(1);
	}

	return game;
}
