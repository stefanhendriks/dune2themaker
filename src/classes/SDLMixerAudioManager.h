/*
 *  SDLMixerAudioManager class
 *  created by: Peter Gaal, 2011
 *  
 *  This is a SDL Mixer audio interface.
 *
 */


#ifndef SDL_MIXER_AUDIO_MANAGER_H
#define SDL_MIXER_AUDIO_MANAGER_H

#include "AudioManager.h"
#include <SDL/SDL.h>
#include <SDL/SDL_Mixer.h>

#define MAX_SOUND_CHANNELS 32

class SDLMixerAudioManager: public AudioManager
{
public:
	// constructor
				  SDLMixerAudioManager();
	// destructor
	/* virtual */ ~SDLMixerAudioManager();
	// this call will set up the sound system
	/* virtual */ void StartSoundSystem();
	// this call will shut down the sound system
	/* virtual */ void StopSoundSystem();
	// load sound sample from file (WAV)
	/* virtual */ void LoadSound(int Index, char * filename);
	// play sound sample
	/* virtual */ void PlaySound(int Index);
	// load music file
	/* virtual */ void LoadMusic(int Index, char * filename);
	// start playing music
	/* virtual */ void PlayMusic(int Index);
	// stop playing music
	/* virtual */ void StopMusic();
	// set up the sound effects volume
	/* virtual */ void SetSoundVolume(int Volume);
	// set up the music volume
	/* virtual */ void SetMusicVolume(int Volume);

protected:
	// sound effects main volume
	int m_SoundFXVolumeSDL;
	// music main volume
	int m_MusicVolumeSDL;
	// time value for 100 ms - for optimization
	int m_Time100ms;
	// audio system initialized flag
	int m_AudioSystemInitialized;
	// sound sample array
	Mix_Chunk* m_SamplesTable[SND_END];
	// music table array
	Mix_Music* m_MusicTable[MUS_END];
	// table, when sound was playing last time
	int m_PlayTimeTable[SND_END];
	// calculate SDL volume value from AudioManager interface volume range
	int CalcSDLVolume(int Volume);
};

#endif
