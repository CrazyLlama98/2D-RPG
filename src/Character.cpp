#include "Character.h"

Character::Character(const int _health, const int _damage, const int _xp, const std::string _type, ENTITY_PARAMS) :
	Entity(_res, _world, _pos, _def, _scale)
{
	health = _health;
	damage = _damage;
	xp = _xp;
<<<<<<< HEAD
	type = _type;
}
=======
}

int Character::DealDamage() { return 1; }
void Character::Die() { }
>>>>>>> ClickCharacter
