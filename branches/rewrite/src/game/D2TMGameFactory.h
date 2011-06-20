/**
 * Following the Factory Pattern. Creating a game object, initialized for usage.
 *
 * NOTE: The environment must be set up (ie, SDL must be initialized) before
 * calling the createGame() function!
 */

#ifndef D2TM_GAMEFACTORY_H_
#define D2TM_GAMEFACTORY_H_

#include "GameConfiguration.h"
#include "Game.h"
#include "D2TMGame.h"

class D2TMGameFactory {
	public:
		D2TMGame * createGame(GameConfiguration * gameConfiguration);
};

#endif
