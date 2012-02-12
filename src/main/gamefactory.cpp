#include "gamefactory.h"

Game GameFactory::create() {
	Game game;

	GameState * gameState = new BattleField();
	game.setGameState(gameState);

	return game;
}
