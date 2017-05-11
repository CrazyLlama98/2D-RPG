#pragma once
#include "oxygine-framework.h"
#include "oxygine-sound.h"

namespace snd
{
	extern oxygine::Resources resources;
	extern oxygine::SoundPlayer sfxPlayer;
	extern oxygine::SoundPlayer musicPlayer;
	void load();
	void free();
}