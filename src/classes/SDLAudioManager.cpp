/*
 *  SDLAudioManager class implementation
 *  created by: Peter Gaal, 2011
 *
 *  This library doesn't support music now. It will be implemented 
 *  in different class, based on SDL_Mixer library
 * 
 */


#include "SDLAudioManager.h"
#include "assert.h"


// pure mixer function, defined as friend function from a class
void SDLMixCallBack(void *userdata, Uint8 *stream, int len)
{
	SDLAudioManager *SoundManager = (SDLAudioManager *) userdata;
	SoundManager->CallBack(stream, len);
}

SDLAudioManager::SDLAudioManager()
{
	// audio system not initialized
	m_AudioSystemInitialized = false;

	// clear sample array
	for (int i=0; i<MAX_SOUND_CHANNELS; i++)
	{
		m_Samples[i].data = 0;
		m_Samples[i].dlen = 0;
		m_Samples[i].dpos = 0;
	}

	// clear CVT table
	for (int i=0; i<SND_END; i++)
	{
		m_CVT_table[i].buf=0;
		m_CVT_table[i].len=0;
		m_CVT_table[i].len_cvt=0;
	}
	// set volumes to maximum
	// the volumes are in native SDL range
	m_SoundFXVolume = SDL_MIX_MAXVOLUME;
	m_MusicVolume = SDL_MIX_MAXVOLUME;
	// size of 100ms time is zero now
	m_Size100ms = 0;
}

SDLAudioManager::~SDLAudioManager()
{
	// if the sound system is not stopped, stop it
	if (m_AudioSystemInitialized)
		StopSoundSystem();

	// free all memory which was allocated
	for (int i=0; i<SND_END; i++)
		if (!m_CVT_table[i].buf)
		{
			free(m_CVT_table[i].buf);
			m_CVT_table[i].buf=0;
			m_CVT_table[i].len=0;
			m_CVT_table[i].len_cvt=0;
		}
}

void SDLAudioManager::StartSoundSystem()
{
	// shouldn't be true here
	assert(!m_AudioSystemInitialized);
	// if the system was initialized, not initialize again
	if (m_AudioSystemInitialized)
		return;
	/* Set 16-bit stereo audio at 22Khz */
	SDL_AudioSpec fmt;
	fmt.freq = 44100;
	fmt.format = AUDIO_S16;
	fmt.channels = 2;
	fmt.samples = 1024;        /* A good value for games */
	fmt.callback = SDLMixCallBack;
	fmt.userdata = (void *) this;
	if ( SDL_OpenAudio(&fmt, &m_AudioFormat) < 0 ) {
		fprintf(stderr, "Unable to open audio: %s\n", SDL_GetError());
		return;
	}
	m_AudioSystemInitialized = true;
	
	if (m_AudioFormat.format == AUDIO_S16)
	{
		// calculcate the interval of 100 ms 
		m_Size100ms = (m_AudioFormat.freq * m_AudioFormat.channels * 2 / 10);
	}
	SDL_PauseAudio(0);
}

void SDLAudioManager::StopSoundSystem()
{
	// shouldn't be false here
	assert(m_AudioSystemInitialized);
	if (!m_AudioSystemInitialized)
		return;
	SDL_CloseAudio();
	m_AudioSystemInitialized = false;
}

void SDLAudioManager::LoadSound(int Index, char *filename)
{
	SDL_AudioSpec wave;
	Uint8 *data;
	Uint32 dlen;
	SDL_AudioCVT* cvt;

	// pointer to cvt table
	cvt = & m_CVT_table[Index];
	// the buffer should be empty
	assert(!cvt->buf);
	if (cvt->buf)
		return;

	/* Load the sound file and convert it to our sound format */
	if ( SDL_LoadWAV(filename, &wave, &data, &dlen) == NULL ) {
		fprintf(stderr, "Couldn't load %s: %s\n", filename, SDL_GetError());
		return;
	}

	// convert audio to proper format
	SDL_BuildAudioCVT(cvt, wave.format, wave.channels, wave.freq,
		m_AudioFormat.format, m_AudioFormat.channels, m_AudioFormat.freq);

	cvt->buf = (Uint8*) malloc(dlen*cvt->len_mult);
	memcpy(cvt->buf, data, dlen);
	cvt->len = dlen;
	SDL_ConvertAudio(cvt);
	SDL_FreeWAV(data);
}

// Play sound by index
void SDLAudioManager::PlaySound(int Index)
{	
	int i, ChannelFound, SampleFound;
	ChannelFound = -1;
	SampleFound = -1;
	// find a free buffer to play
	for ( i=0; i<MAX_SOUND_CHANNELS; ++i )
	{
		// if there is a free channel
		if ( (ChannelFound ==-1) && (m_Samples[i].dpos == m_Samples[i].dlen) )
			ChannelFound = i;
		// if the current sound is playing in audio table less than nearly 100 ms ago
		if ( (SampleFound == -1) && (m_Samples[i].data == m_CVT_table[Index].buf) && (m_Samples[i].dpos <= m_Size100ms) )
			SampleFound = i;
		/* // next code is for testing and debugging purposes:
		if ( (m_Samples[i].data == m_CVT_table[Index].buf) && (m_Samples[i].dpos != m_Samples[i].dlen) )
			printf("found on channel %d sound %d, dlen: %d, dpos: %d\n", i, Index, m_Samples[i].dlen, m_Samples[i].dpos);
		*/
	}

	// if we didn't found a free channel
	if ( ChannelFound == -1 )
	{
		fprintf(stderr, "unable to play sound, no free entry in sound table\n");
		return;
	}

	// if we found the sample is playing somewhere, don't play the sound then
	// this is an optimization if other classes try to play the same sound multiply times
	if ( SampleFound != -1)
		return;
	
	// Put the sound data in the slot (it starts playing immediately)
	SDL_LockAudio();
	m_Samples[ChannelFound].data = m_CVT_table[Index].buf;
	m_Samples[ChannelFound].dlen = m_CVT_table[Index].len_cvt;
	m_Samples[ChannelFound].dpos = 0;
	SDL_UnlockAudio();

	// for debugging only
	// printf("Playing index %d on channel %d\n", Index, ChannelFound);
}


// callback function in class
void SDLAudioManager::CallBack(Uint8 *stream, int len)
{
	int i;
	int amount;

	// mix all sounds
	for ( i=0; i<MAX_SOUND_CHANNELS; ++i )
	{
		amount = (m_Samples[i].dlen-m_Samples[i].dpos);
		if ( amount > len ) 
		{
			amount = len;
		}
		SDL_MixAudio(stream, &m_Samples[i].data[m_Samples[i].dpos], amount, SDL_MIX_MAXVOLUME);
		m_Samples[i].dpos += amount;
	}
	//printf("%6.6d callback: len=%d\n",SDL_GetTicks(), len);
}

int SDLAudioManager::CalcSDLVolume(int Volume)
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
void SDLAudioManager::SetSoundVolume(int Volume)
{
	// store volume - to be able get the correct volume by GetSoundVolume()
	m_SoundFXVolume = Volume;
	// store also the calculated volume
	m_SoundFXVolumeSDL = CalcSDLVolume(Volume);

}

// set music main volume
// bear in mind that the input range is 0..1024 (MAX_VOLUME) so we need to convert it
void SDLAudioManager::SetMusicVolume(int Volume)
{
	// store volume - to be able get the correct volume by GetMusicVolume()
	m_MusicVolume = Volume;
	// store also the calculated volume
	m_MusicVolumeSDL = CalcSDLVolume(Volume);

}


// this function is not implemented yet
void SDLAudioManager::LoadMusic(int Index, char *filename)
{
}

// this function is not implemented yet
void SDLAudioManager::PlayMusic(int Index)
{
}

// this function is not implemented yet
void SDLAudioManager::StopMusic()
{
}

