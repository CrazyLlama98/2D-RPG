#pragma once
#include "Entity.h"
#define ENV_CONSTRUCT const oxygine::ResAnim *_res, b2World *_world, const oxygine::Vector2 &_pos, const float _scale = 1.0f
#define ENV_PARAMS const oxygine::ResAnim *_res, b2World *_world, const oxygine::Vector2 &_pos, const float _scale

class Environment : public Entity
{
public:
	Environment(ENV_CONSTRUCT);
};