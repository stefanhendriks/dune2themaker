#ifndef GAMESTATE_BATTLEFIELD_H
#define GAMESTATE_BATTLEFIELD_H

#include "gamestate.h"

class BattleField : public GameState {
	
	public:
		void handleEvents();
		void update();
		void render();

		void onEvent(SDL_Event * event);

		void shutdown();
};


#endif