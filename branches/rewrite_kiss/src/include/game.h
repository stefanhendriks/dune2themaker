#ifndef GAME_H
#define GAME_H

#include <SDL/SDL.h>

#include "surfacedao.h"
#include "surfacedrawer.h"

class Game {

	public:
		int execute();

	private:
		bool running;

		int init();
		void shutdown();

		void handleEvents();
		void update();
		void render();

		void onEvent(SDL_Event * event);

		
		SDL_Surface * screen;

		SDL_Surface * mouse;

	// Dependencies
		SurfaceDao surfaceDao;
		SurfaceDrawer surfaceDrawer;

};

#endif
