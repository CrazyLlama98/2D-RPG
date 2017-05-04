#include "Hero.h"
#include "res.h"
#include <iostream>

Hero::Hero(const int _health, const int _damage, const int _xp, const int _armor, CHARACTER_PARAMS) : 
	Character(_health, _damage, _xp, _res, _world, _pos, b2_dynamicBody, _scale)
{
    armor = _armor;
}

void Hero::DealDamage(){ };
void Hero::Respawn(){ };
void Hero::Die(){ };
void Hero::Click(oxygine::Event *_event) 
{
	addTween(Sprite::TweenAnim(res::resources.getResAnim("hero_walk_up")), 1000, 1);
	_event->stopImmediatePropagation();
}

void Hero::Move(const oxygine::Vector2 _pos) const { };
void Hero::Move(const float _x, const float _y) const
{
	// oxygine::Resources res;
	// res.loadXML("res.xml");
	// Sprite::addTween(oxygine::Sprite::TweenAnim(res.getResAnim("hero_walk_up")), 1000, 2);
}
