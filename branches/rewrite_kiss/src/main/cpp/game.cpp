#include "game.h"
#include "colors.h"

#include <iostream>

using namespace std;

Game::Game() {
	gameState = NULL;
}

Game::~Game() {
}

int Game::init() {
	// load resources
	mouse = surfaceDao.load("resources/images/MS_Normal.bmp");

	return 0;
}

void Game::handleEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		onEvent(&event);
	}

	if (gameState)	gameState->handleEvents();
}

void Game::onEvent(SDL_Event * event) {
	if(event->type == SDL_QUIT) {
		running = false;
	}

	if (gameState)	gameState->onEvent(event);
}

void Game::update() {
	if (gameState)	gameState->update();
}

void Game::render() {
	surfaceDrawer.clearToColor(screen, Colors::black(screen));

	if (gameState)	gameState->render();

	// draw mouse (always for now)
	int mouseX, mouseY;
	SDL_GetMouseState(&mouseX, &mouseY); 
	surfaceDrawer.drawTransparant(mouse, screen, mouseX, mouseY);

	// flip screen at the end
	SDL_Flip(screen); 
}

void Game::shutdown() {
	if (gameState)	gameState->shutdown();
	delete gameState;

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
