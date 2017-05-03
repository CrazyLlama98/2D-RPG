#include "Hero.h"

Hero::Hero(const int _health, const int _damage, const int _xp, const int _armor, CHARACTER_PARAMS) : 
	Character(_health, _damage, _xp, _res, _world, _pos, b2_dynamicBody, _scale)
{
    armor = _armor;
}

void Hero::DealDamage(){ };
void Hero::Respawn(){ };
void Hero::Die(){ };
void Hero::Click(oxygine::Event *_event){ };
