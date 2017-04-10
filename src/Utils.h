#pragma once
#include "oxygine-framework.h"
#include "Box2D\Box2D.h"

class Utils
{
public:
	static const float scale;
	static b2Vec2 convert(const oxygine::Vector2& _pos)
	{
		return b2Vec2(_pos.x / scale, _pos.y / scale);
	}

	static oxygine::Vector2 convert(const b2Vec2& _pos)
	{
		return oxygine::Vector2(_pos.x * scale, _pos.y * scale);
	}

};
