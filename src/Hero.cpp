#include "Hero.h"
#include "res.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Hero::Hero(const int _health, const int _damage, const int _xp, const int _armor, CHARACTER_PARAMS) :
	Character(_health, _damage, _xp, _type, _res, _world, _pos, b2_dynamicBody, _scale), targetPosition(getPosition())
{
    armor = _armor;
}

int Hero::DealDamage()
{
	srand(time(0));
	return rand() % damage + 1;
}

void Hero::Die(){ };
