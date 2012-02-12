#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <SDL/SDL.h>

class GameState {

	public:
		virtual int init();

		virtual void handleEvents();
		virtual void update();
		virtual void render();

		virtual void onEvent(SDL_Event * event);

		virtual void shutdown();

		void setScreen(SDL_Surface * screen) {
			this->screen = screen;
		};

	protected:
		SDL_Surface * screen;

	private:

};

#endif