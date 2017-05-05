#pragma once
#include "oxygine-framework.h"
#include "Map.h"
#include "Hero.h"
#include "Box2D/Box2D.h"
#include "Entity.h"
#include <list>

class MainActor : public oxygine::Actor
{
public:
    MainActor();

private:
    
    std::list<Entity*> _entities;
	b2World* _world;
	Hero *hero;
	spMap map;

	// Spawns enough Characters until there are ten of them
	void RandomSpawn();
	// Moves the hero around the map
    void MoveHero(oxygine::Event* ev);
    // Responds to clicks made on Characters (mobs)
    void ClickCharacter(oxygine::Event* _event);
    // Checks if two sprites are too close from each other
    bool Overlaps(const oxygine::Vector2 _pos);
};
