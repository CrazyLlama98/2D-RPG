#include "Character.h"
#include "res.h"
#include "snd.h"
#include "Text.h"
#include "MainActor.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

Character::Character(const int _health, const int _damage, const int _xp, const int _level, const std::string _type, ENTITY_PARAMS) :
	Entity(_res, _world, _pos, _def, _scale)
{
	health = _health;
	damage = _damage;
	xp = _xp;
	type = _type;
	maxHealth = _health;
	maxDamage = _damage;
	level = _level;
}


int Character::DealDamage()
{ 
	srand(time(0));
	if (!getFirstTween()) {
		addTween(TweenAnim(res::resources.getResAnim(type + "_attack")), 500)->setDoneCallback(CLOSURE(this, &Character::GoIdle));
		int nr;
		if (type == "skeleton")
			nr = 8;
		else if (type == "troll")
			nr = 10;
		else if (type == "dwarf")
			nr = 10;
		snd::sfxPlayer.play(snd::resources.get(type + "_attack" + std::to_string(rand() % nr + 1)));
	}
	return rand() % damage + 1;
}
void Character::Die() {
	addTween(TweenAnim(res::resources.getResAnim(type + "_die")), 500);
	int nr;
	if (type == "skeleton")
		nr = 1;
	else if (type == "troll")
		nr = 1;
	else if (type == "dwarf")
		nr = 5;
	snd::sfxPlayer.play(snd::resources.get(type + "_death" + std::to_string(rand() % nr + 1)));
} 

void Character::GoIdle(oxygine::Event *_event)
{
	addTween(TweenAnim(res::resources.getResAnim(type + "_idle")), 10);
}