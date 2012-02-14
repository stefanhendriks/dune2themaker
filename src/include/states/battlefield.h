#ifndef GAMESTATE_BATTLEFIELD_H
#define GAMESTATE_BATTLEFIELD_H

#include "game.h"

#include "gamestate.h"
#include "tileset.h"
#include "map.h"

#include "mapcamera.h"
#include "mapdrawer.h"

class BattleField : public GameState {
	
	public:
		BattleField();

		int init();

		void handleEvents();
		void update();
		void render();

		void onKeyboardEvent(SDL_KeyboardEvent * key);
		void onMouseEvent(SDL_MouseButtonEvent * mouse);

		void shutdown();

		// setters
		void setMapDrawer(MapDrawer * mapDrawer) {
			this->mapDrawer = mapDrawer;
		}

		void setMapCamera(MapCamera * mapCamera) {
			this->mapCamera = mapCamera;
		}

		void setMap(Map * map) {
			this->map = map;
		}

		void setScreen(SDL_Surface * screen) {
			this->screen = screen;
		}

		void setGame(Game * game) {
			this->game = game;
		}

	private:
		// resources
		Tileset * tileset;

		// state
		Map * map;
		MapCamera * mapCamera;
		Game * game;

		// dependencies
		MapDrawer * mapDrawer;

		// screen to draw to
		SDL_Surface * screen;

};


#endif