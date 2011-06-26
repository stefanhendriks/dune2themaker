/*
 *  SDLAudioManager class implementation, based on SDL_Mixer library.
 *  created by: Peter Gaal, 2011
 *
 *  This class has a full support of music player + sound effects.
 *  MP3 and midi formats are tested and other formats are probably
 *  fine too (ogg, ...). 
 * 
 */


#include "SDLMixerAudioManager.h"
#include "assert.h"

SDLMixerAudioManager::SDLMixerAudioManager()
{
	// audio system not initialized
	m_AudioSystemInitialized = false;
	// clear samples table
	for (int i=0; i<SND_END; i++)
	{
		m_SamplesTable[i] = 0;
		m_PlayTimeTable[i] = -999999;
	}
	// clear music table
	for (int i=0; i<MUS_END; i++)
	{
		m_MusicTable[i] = 0;
	}
	// set volumes to maximum
	// the volumes are in native SDL range
	m_SoundFXVolume = SDL_MIX_MAXVOLUME;
	m_MusicVolume = SDL_MIX_MAXVOLUME;
}

SDLMixerAudioManager::~SDLMixerAudioManager()
{
	// if the sound system is not stopped, stop it
	if (m_AudioSystemInitialized)
		StopSoundSystem();

	// free all memory which was allocated for samples
	for (int i=0; i<SND_END; i++)
		if (!m_SamplesTable[i])
		{
			Mix_FreeChunk(m_SamplesTable[i]);
			m_SamplesTable[i] = 0;
		}
	// free all memory which was allocated for music
	for (int i=0; i<MUS_END; i++)
		if (!m_MusicTable[i])
		{
			Mix_FreeMusic(m_MusicTable[i]);
			m_MusicTable[i] = 0;
		}
}

void SDLMixerAudioManager::StartSoundSystem()
{
	// shouldn't be true here
	assert(!m_AudioSystemInitialized);
	// if the system was initialized, not initialize again
	if (m_AudioSystemInitialized)
		return;
	// open mixer audio 
	if (Mix_OpenAudio(44100, AUDIO_S16, 2, 1024) == -1)
	{
		fprintf(stderr, "Mix_OpenAudio: %s\n", Mix_GetError());
		return;
	}
	// allocate sound channels
	Mix_AllocateChannels(MAX_SOUND_CHANNELS);
	// audio system initialized
	m_AudioSystemInitialized = true;
	// set 100 ms as a dead time
	m_Time100ms = 100;
}

void SDLMixerAudioManager::StopSoundSystem()
{
	// shouldn't be false here
	assert(m_AudioSystemInitialized);
	if (!m_AudioSystemInitialized)
		return;
	Mix_CloseAudio();
	m_AudioSystemInitialized = false;
}

void SDLMixerAudioManager::LoadSound(int Index, char *filename)
{
	// check boundaries
	assert( (Index>=SND_BEGIN) && (Index<SND_END) );
	if ( (Index<SND_BEGIN) || (Index>=SND_END) )
		return;

	// audio system should be initialized
	assert(m_AudioSystemInitialized);
	if (!m_AudioSystemInitialized)
		return;

	// the table should be empty
	assert(!m_SamplesTable[Index]);
	if (m_SamplesTable[Index])
		return;

	// load sample from WAV file
	m_SamplesTable[Index] = Mix_LoadWAV(filename);

	if(!m_SamplesTable[Index])
	{
		fprintf(stderr, "Mix_LoadWAV: %s\n", Mix_GetError());
	}

}

void SDLMixerAudioManager::PlaySound(int Index)
{
	// check boundaries
	assert( (Index>=SND_BEGIN) && (Index<SND_END) );
	if ( (Index<SND_BEGIN) || (Index>=SND_END) )
		return;

	// audio system should be initialized
	assert(m_AudioSystemInitialized);
	if (!m_AudioSystemInitialized)
		return;

	// don't play the same sound same time
	int CurrentTime = SDL_GetTicks();
	if (m_PlayTimeTable[Index] + m_Time100ms >= CurrentTime)
		return;

	// find free sound channel
	int ChannelFound;
	ChannelFound = -1;
	for (int i=0; i<MAX_SOUND_CHANNELS; i++)
	{
		if (!Mix_Playing(i))
		{
			ChannelFound = i;
			break;
		}
	}

	// if we didn't found a free channel
	if ( ChannelFound == -1 )
	{
		fprintf(stderr, "unable to play sound, no free entry in sound table\n");
		return;
	}

	Mix_PlayChannel(ChannelFound, m_SamplesTable[Index], 0);
	m_PlayTimeTable[Index] = SDL_GetTicks();
}

int SDLMixerAudioManager::CalcSDLVolume(int Volume)
{
	if ( (MAX_VOLUME==1024) && (SDL_MIX_MAXVOLUME == 128))
	{
		// divide by 8 - shift right 3x
		return (Volume >> 3);
	}
	else
	{
		// throw assert, we need to rewrite the optimization formula
		assert(0);
		// but anyway calculate the new value
		return (Volume * SDL_MIX_MAXVOLUME / MAX_VOLUME);
	}
}

// set sound effects main volume
// bear in mind that the input range is 0..1024 (MAX_VOLUME) so we need to convert it
void SDLMixerAudioManager::SetSoundVolume(int Volume)
{
	// store volume - to be able get the correct volume by GetSoundVolume()
	m_SoundFXVolume = Volume;
	// store also the calculated volume
	m_SoundFXVolumeSDL = CalcSDLVolume(Volume);

}

// set music main volume
// bear in mind that the input range is 0..1024 (MAX_VOLUME) so we need to convert it
void SDLMixerAudioManager::SetMusicVolume(int Volume)
{
	// store volume - to be able get the correct volume by GetMusicVolume()
	m_MusicVolume = Volume;
	// store also the calculated volume
	m_MusicVolumeSDL = CalcSDLVolume(Volume);

}


// Load music from file (for example mp3 format)
void SDLMixerAudioManager::LoadMusic(int Index, char *filename)
{
	// check boundaries
	assert( (Index>=MUS_BEGIN) && (Index<MUS_END) );
	if ( (Index<MUS_BEGIN) || (Index>=MUS_END) )
		return;

	// audio system should be initialized
	assert(m_AudioSystemInitialized);
	if (!m_AudioSystemInitialized)
		return;

	// the table should be empty
	assert(!m_MusicTable[Index]);
	if (m_MusicTable[Index])
		return;

	// load sample from WAV file
	m_MusicTable[Index] = Mix_LoadMUS(filename);

	if(!m_MusicTable[Index])
	{
		fprintf(stderr, "Mix_LoadMUS: %s\n", Mix_GetError());
	}

}

// play music by selected index
void SDLMixerAudioManager::PlayMusic(int Index)
{
	// check boundaries
	assert( (Index>=MUS_BEGIN) && (Index<MUS_END) );
	if ( (Index<MUS_BEGIN) || (Index>=MUS_END) )
		return;

	// audio system should be initialized
	assert(m_AudioSystemInitialized);
	if (!m_AudioSystemInitialized)
		return;

	// the table shouldn't be empty
	assert(m_MusicTable[Index]);
	if (!m_MusicTable[Index])
		return;

	Mix_PlayMusic(m_MusicTable[Index],1);
}

// this function is not implemented yet
void SDLMixerAudioManager::StopMusic()
{
	// audio system should be initialized
	assert(m_AudioSystemInitialized);
	if (!m_AudioSystemInitialized)
		return;
	Mix_HaltMusic();
}

