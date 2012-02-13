#ifndef GAMESTATE_BATTLEFIELD_H
#define GAMESTATE_BATTLEFIELD_H

#include "gamestate.h"
#include "tileset.h"
#include "map.h"

class BattleField : public GameState {
	
	public:
		BattleField();

		int init();

		void handleEvents();
		void update();
		void render();

		void onEvent(SDL_Event * event);

		void shutdown();

	private:
		SDL_Surface * test;
		Tileset * tileset;
		Map * map;
};


#endif