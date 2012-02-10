#include "gamerules.h"
#include "game.h"
#include "colors.h"

#include <iostream>

using namespace std;


int Game::init() {
	if((SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO)==-1)) { 
        	printf("Could not initialize SDL: %s.\n", SDL_GetError());
	        return -1;
	}

	screen = SDL_SetVideoMode(640, 480, 16, SDL_SWSURFACE);
	if ( screen == NULL ) {
		printf("Unable to set 640x480 video: %s\n", SDL_GetError());
		return -1;
	}

	// load resources
	mouse = surfaceDao.load("resources/images/MS_Normal.bmp");

	return 0;
}

void Game::handleEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		onEvent(&event);
	}
}

void Game::onEvent(SDL_Event * event) {
	if(event->type == SDL_QUIT) {
		running = false;
	}
}

void Game::update() {

}

void Game::render() {
	surfaceDrawer.clearToColor(screen, Colors::black(screen));

	int mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY); 

	surfaceDrawer.draw(mouse, screen, mouseX, mouseY);

	// flip screen at the end
	SDL_Flip(screen); 
}

void Game::shutdown() {
	SDL_FreeSurface(mouse);

	SDL_Quit();
}

int Game::execute() {
	if (init() != 0) {
		return -1;
	}

	while (running) {
		handleEvents();
		update();
		render();
	}

	shutdown();

	return 0;
}
