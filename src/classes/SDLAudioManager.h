/*
 *  SDLAudioManager class
 *  created by: Peter Gaal, 2011
 *  
 *  This is a SDL audio interface.
 *
 */


#ifndef SDL_AUDIO_MANAGER_H
#define SDL_AUDIO_MANAGER_H

#include "AudioManager.h"
#include "SDL/SDL.h"
#include "SDL/SDL_audio.h"

#define MAX_SOUND_CHANNELS 32

class SDLAudioManager: public AudioManager
{
public:
	// constructor
				  SDLAudioManager();
	// destructor
	/* virtual */ ~SDLAudioManager();
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
	// data size for 100 ms - for optimization
	unsigned int m_Size100ms;
	// Audio format
	SDL_AudioSpec m_AudioFormat;
	int m_AudioSystemInitialized;
	// audio sample structure, audio data for each channel
	struct AudioSample 
	{
		Uint8 *data;
		Uint32 dpos;
		Uint32 dlen;
	} m_Samples[MAX_SOUND_CHANNELS];
	// cvt structures, for each sound
	SDL_AudioCVT m_CVT_table[SND_END];
	// pure callback function for SDL mix audio, defined as friend function
	friend void SDLMixCallBack(void *userdata, Uint8 *stream, int len);
	// callback fuction in class
	void CallBack(Uint8 *stream, int len);
	// calculate SDL volume value from AudioManager interface volume range
	int CalcSDLVolume(int Volume);
};

#endif
