#include "Hero.h"

Hero::Hero(const int _health, const int _damage, const int _xp)
{
    SetHealth(_health);
    SetDamage(_damage);
    SetXp(_xp);
}

void Hero::DealDamage(){ };
void Hero::Respawn(){ };
void Hero::Die(){ };
void Hero::Click(oxygine::Event *_event){ };
