#pragma once
#include "oxygine-framework.h"

class SpecialEnvironment : public oxygine::Sprite
{
public:
	SpecialEnvironment(oxygine::ResAnim* _res, oxygine::Vector2 _pos, const float scale = 1.0f);
	/* RandomDrop *
	 **************
	 * "Drops" randomly one of the following: Health(0), Damage(1), Armor(2), Xp(3).
	*/
	std::pair<int, int> RandomDrop();
};
