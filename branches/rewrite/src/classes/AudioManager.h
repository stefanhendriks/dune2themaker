/*
 *  abstract AudioManager class
 *  created by: Peter Gaal, 2011
 *  
 *  This is a general audio interface. It can load sound samples and music files.
 *  Then can play sound and/or music. In derived class we will have at least
 *  an implementation of audio manager based on SDL functions.
 *  Other libraries can be also supported in future.
 *  The audio manager class is more abstract then a bitmap list. Here we don't
 *  have any specific library typed
 *
 */


#ifndef AUDIO_MANAGER_H
#define AUDIO_MANAGER_H

#define MAX_SOUNDS 1024
#define MAX_VOLUME 1024

enum Sounds
{
	SND_BEGIN = 0,
	SND_ACKNOWLEDGED = 0,
	SND_AFFIRMATIVE,
	SND_END
};

enum Music
{
	MUS_BEGIN =0,
	MUS_END
};


class AudioManager
{
public:
	// virtual destructor - we need usually to free sound samples from memory
	virtual ~AudioManager(){};
	// this call will set up the sound system
	virtual void StartSoundSystem() = 0;
	// this call will shut down the sound system
	virtual void StopSoundSystem() = 0;
	// Load sound from file
	virtual void LoadSound(int Index, char * filename) = 0;
	// Play sound (by Index)
	virtual void PlaySound(int Index) = 0;
	// Load music from file
	virtual void LoadMusic(int Index, char * filename) = 0;
	// Play music by index
	virtual void PlayMusic(int Index) = 0;
	virtual void StopMusic() = 0;
	// set up sound volume (in range 0-1024 (MAX_VOLUME), if the low level library range
	// is different, then adjust the range to library range
	virtual void SetSoundVolume(int Volume)
	{
		m_SoundFXVolume = Volume;
	}
	// set up music volume (in range 0-1024 (MAX_VOLUME), if the low level library range
	// is different, then adjust the range to library range
	virtual void SetMusicVolume(int Volume)
	{
		m_MusicVolume = Volume;
	}
	// return sound effects volume
	virtual int GetSoundVolume()
	{
		return m_SoundFXVolume;
	}
	// return music volume
	virtual int GetMusicVolume()
	{
		return m_MusicVolume;
	}

protected:
	int m_SoundFXVolume;
	int m_MusicVolume;
};

#endif
