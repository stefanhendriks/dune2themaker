#ifndef GAME_H
#define GAME_H

#include <SDL/SDL.h>

#include "surfacedao.h"
#include "surfacedrawer.h"
#include "mapdrawer.h"

#include "states/gamestate.h"

class Game {

	public:
		Game();
		~Game();

		int execute();
		int init();

		// setters
		void setGameState(GameState * gameState) {
			this->gameState = gameState;
		};

		void setScreen(SDL_Surface * screen) {
			this->screen = screen;
		}

	private:
		bool running;


		void shutdown();

		void handleEvents();
		void update();
		void render();

		void onEvent(SDL_Event * event);
		
		// resources
		SDL_Surface * screen;
		SDL_Surface * mouse;

		// dependencies
		SurfaceDao surfaceDao;
		SurfaceDrawer surfaceDrawer;
		
		GameState * gameState;
};

#endif
