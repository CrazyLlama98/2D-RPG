#include "Character.h"
#include "res.h"
#include <cstdlib>
#include <ctime>

Character::Character(const int _health, const int _damage, const int _xp, const std::string _type, ENTITY_PARAMS) :
	Entity(_res, _world, _pos, _def, _scale)
{
	health = _health;
	damage = _damage;
	xp = _xp;
	type = _type;
}


int Character::DealDamage()
{ 
	srand(time(0));
	if (!getFirstTween())
		addTween(TweenAnim(res::resources.getResAnim(type + "_attack")), 500)->setDoneCallback(CLOSURE(this, &Character::GoIdle));
	return rand() % damage + 1;
}
void Character::Die() { } 

void Character::GoIdle(oxygine::Event *_event)
{
	addTween(TweenAnim(res::resources.getResAnim(type + "_idle")), 10);
}