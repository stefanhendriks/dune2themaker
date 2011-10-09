/*

 Dune II - The Maker

 Author : Stefan Hendriks
 Contact: stefanhen83@gmail.com
 Website: http://dune2themaker.fundynamic.com

 2001 - 2011 (c) code by Stefan Hendriks

 */
#ifndef GAME_H_H
#define GAME_H_H

#include "movie/cMoviePlayer.h"
#include "utils/cSoundPlayer.h"

#include "gameobjects/ScreenResolution.h"

#include "include/GameState.h"
#include "states/State.h"

class cGame {

	public:

		cGame();
		~cGame();

		std::string game_filename;

		bool windowed;
		char version[15];
		char revision[15];

		// -- fade in/out animation
		int iAlphaScreen;
		int iFadeAction;

		// select your next conquest vars -- begin
		int iRegionState;
		int iRegionScene;
		int iRegionSceneAlpha;
		int iRegionConquer[MAX_REGIONS];
		int iRegionHouse[MAX_REGIONS];
		char cRegionText[MAX_REGIONS][255];
		int iRegion;
		// select your next conquest vars -- end

		// used for the fading/color transitioning when selecting things (units/things from item list)
		int fade_select;
		bool bFadeSelectDir;

		bool soundEnabled;
		bool mp3MusicEnabled;
		bool playing;
		int iMusicVolume;

		// skirmish - start
		bool bSkirmish;
		int iSkirmishStartPoints;
		int iSkirmishMap;
		// skirmish - end

		int screenshot;

		int iMission;
		int iHouse;

		// combat - start
		int selected_structure;
		int paths_created;
		int shake_x;
		int shake_y;
		int TIMER_shake;
		bool bPlaceIt;
		bool bPlacedIt;
		int iWinQuota;
		int iMusicType;
		// combat - end


		// mentat - begin
		char mentat_sentence[10][255];
		int TIMER_mentat_Speaking;
		int iMentatSpeak;
		int iMentatMouth;
		int iMentatEyes;
		int iMentatOther;
		int TIMER_mentat_Mouth;
		int TIMER_mentat_Eyes;
		int TIMER_mentat_Other;
		// mentat - end

		/// functions

		// think functions
		void think_winlose();
		void think_music();
		void think_mentat();

		// init functions
		bool setupGame();
		void init();
		void mission_init();

		// main run function
		void run();

		// mentat functions
		void MENTAT_draw_mouth(int iMentat);
		void MENTAT_draw_eyes(int iMentat);
		void MENTAT_draw_other(int iMentat);
		void preparementat(bool bTellHouse);

		bool isState(GameState theState);
		void setState(GameState theState);
		void FADE_OUT();
		void switchStateTo(GameState state);

		// misc
		int getGroupNumberFromKeyboard();

		void destroyAllUnits(bool);
		void destroyAllStructures(bool);


		// get / set

		int getMaxVolume() {
			return iMaxVolume;
		}

		cSoundPlayer *getSoundPlayer() {
			return soundPlayer;
		}

		cMoviePlayer *getMoviePlayer() {
			return moviePlayer;
		}

		void setMoviePlayer(cMoviePlayer * value) {
			moviePlayer = value;
		}

		ScreenResolution * getScreenResolution() {
			return screenResolution;
		}

		void setScreenResolution(ScreenResolution * newScreenResolution) {
			if (screenResolution) {
				delete screenResolution;
			}
			if (newScreenResolution) {
				screenResolution = newScreenResolution;
			} else {
				screenResolution = NULL;
			}
		}

		ScreenResolution *getScreenResolutionFromIni() {
			return screenResolutionFromIni;
		}

		void setScreenResolutionFromIni(ScreenResolution * newScreenResolution) {
			screenResolutionFromIni = newScreenResolution;
		}

		void shutdown();

		// TODO: split it up in a draw and logic
		void combat_mouse();

		State * getState() { return state; }

	private:
		bool isBusyFadingOut();

		// poll
		void updateState();

		void handleTimeSlicing();

		// state functions
		void menuState();
		void playingState();
		void briefingState(int iType);
		void selectNextConquestState();
		void selectHouseState();
		void selecthouseState();
		void runGameState();
		void setupSkirmishState();
		void winningState();
		void losingState();

		// draw functions
		void drawHousesToSelect(int iType);
		void shakeScreenAndBlitBuffer();
		bool isResolutionInGameINIFoundAndSet();
		void setScreenResolutionFromGameIniSettings();

		bool playerHasAnyStructures(int iPlayerId);
		bool playerHasAnyGroundUnits(int iPlayerId);
		bool isWinQuotaSet();
		bool playerHasMetQuota(int iPlayerId);

		bool isFadingOut();
		bool isDoneFadingOut();

		// variables
		GameState gameStateEnum;
		State * state;

		ScreenResolution * screenResolution;
		ScreenResolution * screenResolutionFromIni;

		int iMaxVolume;

		cSoundPlayer *soundPlayer;
		cMoviePlayer *moviePlayer;

};

#endif