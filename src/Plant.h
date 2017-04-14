#pragma once
#include "oxygine-framework.h"
#include "Box2D/Box2D.h"

class Plant : public oxygine::Sprite
{
public:
	Plant(b2World *_world, const oxygine::Vector2 &_pos, 
		  const float _scale = 1.0f);

	void Click(oxygine::Event *_event);
};