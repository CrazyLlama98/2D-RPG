#include "snd.h"

namespace snd
{
	oxygine::Resources resources;
	oxygine::SoundPlayer sfxPlayer;
	oxygine::SoundPlayer musicPlayer;

	void load()
	{
		oxygine::SoundSystem::create()->init(16);
		oxygine::SoundPlayer::initialize();

		sfxPlayer.setVolume(1.0f);
		musicPlayer.setVolume(0.5f);
	}

	void free()
	{
		musicPlayer.stop();
		sfxPlayer.stop();
		oxygine::SoundPlayer::free();
		oxygine::SoundSystem::free();
	}
}