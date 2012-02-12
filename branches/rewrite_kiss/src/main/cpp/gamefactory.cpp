#include "gamefactory.h"

#include <iostream>

using namespace std;

Game GameFactory::create() {
	cout << "Initializing SDL..." << endl;

	if((SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO)==-1)) { 
		printf("Could not initialize SDL: %s.\n", SDL_GetError());
		exit(1);
	}

	SDL_Surface * screen = SDL_SetVideoMode(640, 480, 16, SDL_SWSURFACE);
	if ( screen == NULL ) {
		printf("Unable to set 640x480 video: %s\n", SDL_GetError());
		exit(1);
	}
		
	SDL_ShowCursor(0); 

	cout << "SDL Init, screen surface allocated and showcursus set to 0." << endl;

	Game game;

	GameState * gameState = new BattleField();
	gameState->setScreen(screen);
	gameState->init();

	game.setGameState(gameState);
	game.setScreen(screen);
	
	if (game.init() != 0) {
		cout << "Error initializing game." << endl;
		exit(1);
	}

	return game;
}
