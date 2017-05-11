#include "Hero.h"
#include "res.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

spHero Hero::hero = 0;

Hero::Hero(const int _health, const int _damage, const int _xp, const int _armor, CHARACTER_PARAMS) :
	Character(_health, _damage, _xp, _type, _res, _world, _pos, b2_dynamicBody, _scale), targetPosition(getPosition())
{
    armor = _armor;
    level = 1;
    quest = 100;
    maxHealth = 100;
    maxDamage = 15;
    maxArmor = 100;
}

spHero Hero::getHero(b2World* _world, oxygine::Vector2 size)
{
	if (hero == 0)
		hero = new Hero(100, 15, 0, 100, "hero", res::resources.getResAnim("hero_idle_up"), _world, size, 0.6f);
	return hero;
}

int Hero::DealDamage()
{
	srand(time(0));
	return rand() % damage + 1;
}

void Hero::IncreaseLevel()
{
    ++level;
    //Update maxHealth, maxDamage, maxArmor at each level
    maxArmor += (1 / 4) * maxArmor;
    maxDamage += (1 / 4) * maxDamage;
    maxHealth += (1 / 4) * maxHealth;
    quest *= 2;
}

void Hero::Die(){
	addTween(createTween(TweenRotation(getRotation() + (float)MATH_PI / 2), 2000, 1));
	addTween(TweenAnim(res::resources.getResAnim("hero_idle_down")), 500, 1);
}
