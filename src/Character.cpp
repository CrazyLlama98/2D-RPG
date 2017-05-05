#include "Character.h"

Character::Character(const int _health, const int _damage, const int _xp, ENTITY_PARAMS) :
	Entity(_res, _world, _pos, _def, _scale)
{
	health = _health;
	damage = _damage;
	xp = _xp;
}