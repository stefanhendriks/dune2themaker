#ifndef MOUSE_H
#define MOUSE_h

#include <SDL/SDL.h>

class Mouse {

	public:
		Mouse();

		bool isLeftMouseButtonPressed() { return leftMouseButtonPressed; }
		bool isRightMouseButtonPressed() { return rightMouseButtonPressed; }

		void onMouseDownEvent(SDL_MouseButtonEvent * mouse);
		void onMouseUpEvent(SDL_MouseButtonEvent * mouse);

	private:
		bool leftMouseButtonPressed, rightMouseButtonPressed;
	
};

#endif