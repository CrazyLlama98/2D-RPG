#pragma once
#include "oxygine-framework.h"
#include "Box2D/Box2D.h"

class Utils
{
public:
	static const float scale;
	static const unsigned int FLIPPED_HORIZONTALLY_FLAG, FLIPPED_VERTICALLY_FLAG, FLIPPED_DIAGONALLY_FLAG;
	static const int inf;

	static b2Vec2 convert(const oxygine::Vector2& _pos)
	{
		return b2Vec2(_pos.x / scale, _pos.y / scale);
	}

	static oxygine::Vector2 convert(const b2Vec2& _pos)
	{
		return oxygine::Vector2(_pos.x * scale, _pos.y * scale);
	}

	static float distance(const oxygine::Vector2& A, const oxygine::Vector2& B)
	{
		return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
	};
};
