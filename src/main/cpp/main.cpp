#include <fstream>
#include <iostream>
#include "gamefactory.h"

using namespace std;

int main(int argc, char **argv) {
	GameFactory gameFactory;
	Game game = gameFactory.create();
	return game.execute();
}
