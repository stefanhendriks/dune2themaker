// THIS IS JUST A TEST APPLICATION TO SEE IF SDL WORKS AND SUCH.

#include <iostream>

#include "game/GameConfiguration.h"
#include "game/D2TMGame.h"
#include "game/D2TMGameFactory.h"

#include <SDL/SDL.h>

using namespace std;

int main(int argc, char **argv) {
	// Initialize
	SDL_Init(SDL_INIT_VIDEO);

	D2TMGameFactory * d2tmGameFactory = new D2TMGameFactory();
	GameConfiguration * gameConfiguration = NULL; // TODO: get game configuration here by reading a game.cfg, or arguments, etc.
	D2TMGame * game = d2tmGameFactory->createGame(gameConfiguration);

	if (game) {
		game->run();
	} else {
		cerr << "Error launching Dune 2 - The Maker.";
	}

	// Clean up and shut down
	delete game;
	delete d2tmGameFactory;
	SDL_Quit();
	return 0;
}
