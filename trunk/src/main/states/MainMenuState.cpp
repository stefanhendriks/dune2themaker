#include "MainMenuState.h"

void MainMenuState::draw() {
		
}

void MainMenuState::updateState(StateRunner * stateRunner) {
	guiWindow->interact();
	if (key[KEY_ESC]) {
		this->flagToQuitGame();
	}
}

void MainMenuState::manageTime() {

}


