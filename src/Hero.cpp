#include "Hero.h"
#include "res.h"
#include <iostream>

Hero::Hero(const int _health, const int _damage, const int _xp, const int _armor, CHARACTER_PARAMS) : 
	Character(_health, _damage, _xp, _res, _world, _pos, b2_dynamicBody, _scale)
{
    armor = _armor;
}

int Hero::DealDamage(){ return 1; }
void Hero::Die(){ };
