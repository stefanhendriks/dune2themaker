#include "gamefactory.h"

int main(int argc, char **argv) {
	GameFactory gameFactory;
	Game game = gameFactory.create();
	return game.execute();
}
