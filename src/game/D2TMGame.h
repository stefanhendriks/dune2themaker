#ifndef D2TMGAME_H_
#define D2TMGAME_H_

#include <SDL/SDL.h>

#include "Game.h"
#include "GameConfiguration.h"
#include "../timer/Timer.h"

class D2TMGame : public Game {
	public:
		D2TMGame(GameConfiguration const * startingGameConfiguration);
		virtual ~D2TMGame();

		void run();

		// get/set
		GameConfiguration const * getGameConfiguration() { return gameConfiguration; }
		void setTimer(Timer const * newTimer);
		bool isPlaying() { return playing; }

	protected:
		// after each run in the game loop, handle the passed time by updating states of
		// kinds of objects.
		void handlePassedTime();

		// React upon events (keyboard, mouse, etc), and update state.
		void handleEvents();

		// render the game state
		void render();

	private:
		GameConfiguration const * gameConfiguration;
		Timer const * timer;
		SDL_Surface *screen;
		bool playing;
};

#endif /* D2TMGAME_H_ */
