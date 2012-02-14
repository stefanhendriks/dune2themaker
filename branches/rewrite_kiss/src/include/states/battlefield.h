#ifndef GAMESTATE_BATTLEFIELD_H
#define GAMESTATE_BATTLEFIELD_H

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

		void onEvent(SDL_Event * event);

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

	private:

		// resources
		Tileset * tileset;

		// state
		Map * map;
		MapCamera * mapCamera;

		// dependencies
		MapDrawer * mapDrawer;
};


#endif