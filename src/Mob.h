#pragma once
#include "Entity.h"
#define ENTITY_CONSTRUCT b2World *_world, const oxygine::Vector2 &_pos, const float _scale = 1.0f

class Mob : public Entity 
{
public:
	Mob(const int _health, const int _damage, const int _xp, ENTITY_CONSTRUCT);

	void DealDamage();
	void Respawn();
	void Die();
	void Click(oxygine::Event *_event);
};