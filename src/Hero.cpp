#include "Hero.h"
#define ENTITY_PARAMS b2World *_world, const oxygine::Vector2 &_pos, const float _scale

Hero::Hero(const oxygine::ResAnim *_res, const int _health, const int _damage, const int _xp, const int _armor, ENTITY_PARAMS) : Entity(_res, _health, _damage, _xp, _world, b2_dynamicBody, _pos, _scale)
{
    SetArmor(_armor);
}

void Hero::AddArmor(const int _armor)
{
    SetArmor(GetArmor() + _armor);
}

void Hero::AddDamage(const int _damage)
{
    SetDamage(GetDamage() + _damage);
}

void Hero::AddHealth(const int _health)
{
    Sethealth(GetHealth() + _health);
}

void Hero::AddXp(const int _xp)
{
    SetXp(GetXp() + _xp);
}

void Hero::DealDamage(){ };
void Hero::Respawn(){ };
void Hero::Die(){ };
void Hero::Click(oxygine::Event *_event){ };
