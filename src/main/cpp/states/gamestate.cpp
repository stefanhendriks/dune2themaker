#include "gamestate.h"

int GameState::init() {
	// pure virtual
	return 0;
}

void GameState::handleEvents() {
	// pure virtual
}

void GameState::update() {
	// pure virtual
}

void GameState::render() {
	// pure virtual
}

void GameState::onKeyboardEvent(SDL_KeyboardEvent * key) {
	// pure virtual
}

void GameState::onMouseDownEvent(SDL_MouseButtonEvent * mouse) {
	// pure virtual
}

void GameState::onMouseUpEvent(SDL_MouseButtonEvent * mouse) {
	// pure virtual
}

void GameState::shutdown() {
	//  pure virtual
}