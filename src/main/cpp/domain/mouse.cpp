#include "mouse.h"

Mouse::Mouse() {
	leftMouseButtonPressed = false;
	rightMouseButtonPressed = false;
}

void Mouse::onMouseDownEvent(SDL_MouseButtonEvent * mouse) {
	if ((mouse->button == SDL_BUTTON_LEFT) ) {
		leftMouseButtonPressed = true;
	}

	if ((mouse->button == SDL_BUTTON_RIGHT) ) {
		rightMouseButtonPressed = true;
	}
}

void Mouse::onMouseUpEvent(SDL_MouseButtonEvent * mouse) {
	if ((mouse->button == SDL_BUTTON_LEFT) ) {
		leftMouseButtonPressed = false;
	}

	if ((mouse->button == SDL_BUTTON_RIGHT) ) {
		rightMouseButtonPressed = false;
	}
}
