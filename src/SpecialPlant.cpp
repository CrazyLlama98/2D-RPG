#include "SpecialPlant.h"

SpecialPlant::SpecialPlant(b2World *_world, const oxygine::Vector2 &_pos, 
						   const float _scale) : Plant(_world, _pos, _scale) { }

void SpecialPlant::Respawn(int (*_get[4])(), void (*_set[4])()) { return; }