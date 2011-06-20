// THIS IS JUST A TEST APPLICATION TO SEE IF SDL WORKS AND SUCH.

#include <iostream>

#include "game/D2TMGame.h"
#include "game/D2TMGameFactory.h"

#include <SDL/SDL.h>

using namespace std;

int main(int argc, char **argv) {
	// initialize SDL
	SDL_Init(SDL_INIT_VIDEO);

	D2TMGameFactory * d2tmGameFactory = new D2TMGameFactory();
	D2TMGame * game = d2tmGameFactory->createGame(NULL); // TODO: pass a game configuration here by reading a game.cfg, or arguments, etc.

	while (game->isPlaying()) {
		game->handlePassedTime();
		game->handleEvents();
		game->render();
	}

	// quit
	SDL_Quit();
	return 0;
}
