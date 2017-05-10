#pragma once
#include "Environment.h"

class SpecialEnvironment : public Environment
{
public:
	SpecialEnvironment(ENV_CONSTRUCT);
	/* RandomDrop *
	 **************
	 * "Drops" randomly one of the following: Health(0), Damage(1), Armor(2), Xp(3).
	*/
	std::pair<int, int> RandomDrop();
};
