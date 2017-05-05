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
	spHero hero;
	spMap map;
<<<<<<< HEAD

	void RandomSpawn();
=======
    void MoveHero(oxygine::Event* ev);
    void ClickCharacter(oxygine::Event* _event);
    
>>>>>>> ClickCharacter
};
