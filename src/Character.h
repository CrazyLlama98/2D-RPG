#pragma once
#include "Entity.h"
#include <cstring>
#define ENTITY_CONSTRUCT const oxygine::ResAnim *_res, b2World *_world, const oxygine::Vector2 &_pos, const b2BodyType _def = b2_staticBody, const float _scale = 1.0f
#define ENTITY_PARAMS const oxygine::ResAnim *_res, b2World *_world, const oxygine::Vector2 &_pos, const b2BodyType _def, const float _scale

class Character : public Entity {
public:
	Character(const int _health, const int _damage, const int _xp, const std::string _type, ENTITY_CONSTRUCT);

	// Anims the character when attacking and returns a random value between
	// 1 and 'damage'
	int DealDamage();
	void Die();

	int GetHealth() const { return health; };
	void SetHealth(const int _health) { health = _health; };

	int GetDamage() const { return damage; };
	void SetDamage(const int _damage) { damage = _damage; };

	int GetXp() const { return xp; };
	void SetXp(const int _xp) { xp = _xp; };

	// Resets the sprite to idle state
	void GoIdle(oxygine::Event *_event);

protected:
	int xp, health, damage;
	std::string type;
};