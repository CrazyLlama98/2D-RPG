#pragma once
#include "Entity.h"
#define ENTITY_CONSTRUCT const oxygine::ResAnim *_res, b2World *_world, const oxygine::Vector2 &_pos, const float _scale = 1.0f
#define ENTITY_PARAMS const oxygine::ResAnim *_res, b2World *_world, const oxygine::Vector2 &_pos, const float _scale

class Environment : public Entity
{
public:
	Environment(ENTITY_CONSTRUCT);

	void Click(oxygine::Event *_event);
};