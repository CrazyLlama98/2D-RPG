#pragma once
#include "oxygine-framework.h"
#include "Box2D/Box2D.h"

class Entity : public oxygine::Sprite 
{
public:
	Entity(b2World *_world, b2BodyType _def, const oxygine::Vector2 &_pos, 
		   const float _scale = 1.0f);

	virtual void DealDamage() = 0;
	virtual void Respawn() = 0;
	virtual void Die() = 0;
	virtual void Click(oxygine::Event *_event) = 0;
	
	int GetHealth() const { return health; };
	void SetHealth(const int _health) { health = _health; };

	int GetDamage() const { return damage; };
	void SetDamage(const int _damage) { damage = _damage; };

	int GetXp() const { return xp; };
	void SetXp(const int _xp) { xp = _xp; };

private:
	int xp, health, damage;
};
