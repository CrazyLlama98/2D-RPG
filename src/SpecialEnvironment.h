#pragma once
#include "Environment.h"

class SpecialEnvironment : public Environment
{
public:
	SpecialEnvironment(ENTITY_CONSTRUCT);

private:
	/* RandomDrop *
	 **************
	 * "Drops" randomly one of the following: Health, Damage, Armor, Xp. Used
	 * internaly in Respawn function.
	 * Params: Two arrays of pointers to functions. One that points to Get
	 * functions and one that points to Set functions of Hero methods.
	*/
	void RandomDrop(int (*_get[4])(), void (*_set[4])());
};