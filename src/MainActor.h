#pragma once
#include "oxygine-framework.h"
#include "Map.h"
#include "Hero.h"
#include "Box2D/Box2D.h"

class MainActor : public oxygine::Actor
{
public:
    MainActor();
    void MoveHero(oxygine::Event* ev);

private:
	b2World* _world;
	spHero hero;
	spMap map;
<<<<<<< Updated upstream
=======
    MainActor();
    void MoveHero(oxygine::Event* ev);
    void ClickCharacter(oxygine::Event* _event);
>>>>>>> Stashed changes
};
