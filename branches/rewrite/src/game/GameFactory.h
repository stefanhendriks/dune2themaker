/**
 * Following the Factory Pattern. Creating a game object, initialized for usage.
 *
 * NOTE: The environment must be set up (ie, SDL must be initialized) before
 * calling the createGame() function!
 */

#ifndef GAMEFACTORY_H_
#define GAMEFACTORY_H_

#include "GameConfiguration.h"
#include "Game.h"
#include "D2TMGame.h"

class GameFactory {
	public:
		D2TMGame * createGame(GameConfiguration * gameConfiguration);
};

#endif /* GAMEFACTORY_H_ */
