#pragma once
#include "oxygine-framework.h"
#include "Box2D/Box2D.h"

DECLARE_SMART(Entity, spEntity);
class Entity : public oxygine::Sprite 
{
public:
	Entity(const oxygine::ResAnim *_res, b2World *_world, const oxygine::Vector2 &_pos, 
		const b2BodyType _def, const float _scale = 1.0f);
	~Entity();
};
