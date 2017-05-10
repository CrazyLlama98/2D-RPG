#pragma once
#include "Box2D/Box2D.h"
#include "Character.h"
#include "oxygine-framework.h"

class CharactersContactListener : public b2ContactListener
{
public:
	//void PreSolve(b2Contact* contact, const b2Manifold* oldManifold);
	void BeginContact(b2Contact* contact);
};