#include <iostream>

#include <SDL/SDL.h>

#include "Game.h"
#include "D2TMGame.h"

using namespace std;

D2TMGame::D2TMGame(GameConfiguration const * startingGameConfiguration) {
	//set a 640x480x32 double-buffered window
	screen = SDL_SetVideoMode(640,480,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
	playing = true;
}


D2TMGame::~D2TMGame() {
  SDL_FreeSurface(screen);
}

void D2TMGame::run() {
	while (isPlaying()) {
		handlePassedTime();
		handleEvents();
		render();
	}
}


void D2TMGame::handlePassedTime() {

}

void D2TMGame::handleEvents() {
	//e stores the event union which is fetched from the event queue
	SDL_Event e;

	//check the event queue
	while (SDL_PollEvent(&e)) {
		switch (e.type) {
			case SDL_KEYDOWN:
				if (e.key.keysym.sym == SDLK_ESCAPE) {
					playing = false;
					break;
				}
			case SDL_QUIT:
				playing = false;
				break;
		}
	}
}

void D2TMGame::render() {
	  SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,0,0,0));
	  SDL_Flip(screen);
}


void D2TMGame::setTimer(Timer const * newTimer) {
	if (newTimer == NULL) {
		cerr << "Could not set new timer, because timer class to set is [null]";
		return;
	}

	if (timer) {
		delete timer;
	}

	timer = newTimer;
}
