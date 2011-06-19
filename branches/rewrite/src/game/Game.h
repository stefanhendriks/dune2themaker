/*
 * Game.h
 *
 * This is a game interface. It offers three functions:
 *
 * 1. Handle the passed time to update objects and so forth. Usually done by measuring time passed between
 *    frames and acting upon the passed miliseconds.
 * 2. Handle events triggered by the player (keyboard/mouse), and so forth.
 * 3. Render / play sounds
 *
 */

#ifndef GAME_INTERFACE_H_
#define GAME_INTERFACE_H_

class Game {

	public:
		// after each run in the game loop, handle the passed time by updating states of
		// kinds of objects.
		virtual void handlePassedTime() = 0;

		// React upon events (keyboard, mouse, etc), and update state.
		virtual void handleEvents() = 0;

		// render the game state
		virtual void render() = 0;
};


#endif /* GAME_INTERFACE_H_ */
