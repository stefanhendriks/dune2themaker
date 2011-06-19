/*
 * GameConfiguration.h
 *
 * This object holds all configuration needed to create a game. These configurations are usually
 * saved in a file, like a game.cfg or something.
 *
 * Information like screen resolution, the usage of music and sounds, pointing to folders, etc.
 *
 *
 */

#ifndef GAMECONFIGURATION_H_
#define GAMECONFIGURATION_H_

class GameConfiguration {
	public:
		GameConfiguration();
		virtual ~GameConfiguration();

		int getScreenWidth() { return screenWidth; }
		int getScreenHeight() { return screenHeight; }
		int getScreenBithDepth() { return screenBitDepth; }

	private:
		int screenWidth;
		int screenHeight;
		int screenBitDepth;
};

#endif /* GAMECONFIGURATION_H_ */
