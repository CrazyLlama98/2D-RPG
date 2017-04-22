#include "SpecialPlant.h"

SpecialPlant::SpecialPlant(oxygine::ResAnim *_res, b2World *_world, const oxygine::Vector2 &_pos, 
						   const float _scale) : Plant(_res, _world, _pos, _scale) { }

void SpecialPlant::Respawn(int (*_get[4])(), void (*_set[4])()) { return; }