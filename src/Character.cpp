#include "Character.h"

Character::Character(int _health, int _damage, int _xp, ENTITY_PARAMS) :
	Entity(_res, _world, _pos, _def, _scale)
{
	health = _health;
	damage = _damage;
	xp = _xp;
}

void Character::Click(oxygine::Event *_event)
{
	return;
}