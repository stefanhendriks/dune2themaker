#include <SDL/SDL.h>   /* All SDL App's need this */

#include "gamerules.h"
#include "game.h"

#include <iostream>

using namespace std;

void Game::evaluateGameOfLifeRulesWithNeighbourCount(int neighbours) {
	GameRules gamerules;
	cout << "Evaluating rules with [" << neighbours << "] neighbours -- Start" << endl;
	cout << "With " << neighbours << " shouldRemainAlive returns " << gamerules.shouldRemainAlive(neighbours) << endl;
	cout << "With " << neighbours << " shouldRevive returns " << gamerules.shouldRevive(neighbours) << endl;
	cout << "With " << neighbours << " shouldDie returns " << gamerules.shouldDie(neighbours) << endl;
	cout << "DONE Evaluating rules with [" << neighbours << "] neighbours" << endl;
}


int Game::execute() {
	if((SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO)==-1)) { 
        	printf("Could not initialize SDL: %s.\n", SDL_GetError());
	        exit(-1);
	}

	cout << "Conway's Game Of Life" << endl;
	evaluateGameOfLifeRulesWithNeighbourCount(1);
	evaluateGameOfLifeRulesWithNeighbourCount(2);
	evaluateGameOfLifeRulesWithNeighbourCount(3);
	evaluateGameOfLifeRulesWithNeighbourCount(4);
	evaluateGameOfLifeRulesWithNeighbourCount(5);
	return 0;

}
