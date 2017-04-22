#include "Mob.h"
#define ENTITY_PARAMS b2World *_world, const oxygine::Vector2 &_pos, const float _scale

Mob::Mob(const oxygine::ResAnim *_res, const int _health, const int _damage, 
		 const int _xp, ENTITY_PARAMS) : Entity(_res, _health, _damage, _xp, 
		 _world, b2_staticBody, _pos, _scale) { }

void Mob::DealDamage() { return; }
void Mob::Respawn() { return; }
void Mob::Die() { return; }
void Mob::Click(oxygine::Event *_event) { return; }