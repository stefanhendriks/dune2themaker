#include <iostream>

#include "Game.h"
#include "D2TMGame.h"

using namespace std;

D2TMGame::D2TMGame(GameConfiguration const * startingGameConfiguration) {

}


D2TMGame::~D2TMGame() {
}

void D2TMGame::handlePassedTime() {

}

void D2TMGame::handleEvents() {

}

void D2TMGame::render() {

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
