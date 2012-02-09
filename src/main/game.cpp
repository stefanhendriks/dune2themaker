#include "gamerules.h"
#include "game.h"

#include <iostream>

using namespace std;

void Game::evaluateGameOfLifeRulesWithNeighbourCount(int neighbours) {
	GameRules gamerules;
	cout << "Evaluating rules with [" << neighbours << "] neighbours -- Start" << endl;
	cout << "With " << neighbours << " shouldRemainAlive returns " << gamerules.shouldRemainAlive(neighbours) << endl;
	cout << "With " << neighbours << " shouldRevive returns " << gamerules.shouldRevive(neighbours) << endl;
	cout << "With " << neighbours << " shouldDie returns " << gamerules.shouldDie(neighbours) << endl;
	cout << "DONE Evaluating rules with [" << neighbours << "] neighbours" << endl;
}

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

	return 0;
}
