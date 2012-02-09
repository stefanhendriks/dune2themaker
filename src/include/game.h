#ifndef GAME_H
#define GAME_H

#include <SDL/SDL.h>   /* All SDL App's need this */

class Game {

	public:
		int execute();
		void evaluateGameOfLifeRulesWithNeighbourCount(int neighbours);

	private:
		bool running;

		int init();
		void shutdown();

		void handleEvents();
		void update();
		void render();

		void onEvent(SDL_Event * event);

		
		SDL_Surface * screen;

};

#endif
