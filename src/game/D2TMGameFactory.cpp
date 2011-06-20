#include "GameConfiguration.h"
#include "Game.h"
#include "D2TMGameFactory.h"

#include "../timer/SDLTimer.h"

D2TMGame * D2TMGameFactory::createGame(GameConfiguration * gameConfiguration) {
	D2TMGame * d2tmGame = new D2TMGame(gameConfiguration);
	d2tmGame->setTimer(new SDLTimer());
	return d2tmGame;
}
