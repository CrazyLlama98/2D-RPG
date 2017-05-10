#pragma once
#include "oxygine-framework.h"
#include "Map.h"
#include "Hero.h"
#include "Box2D/Box2D.h"
#include "Entity.h"
#include "Box2DDebugDraw.h"
#include "CharactersContactListener.h"
#include "Environment.h"
#include <list>

class MainActor : public oxygine::Actor
{
public:
    MainActor();

private:
    
    std::list<Character*> _mobs;
    std::list<Environment*> _plants;
	b2World* _world;
	Hero *hero;
	spMap map;
	CharactersContactListener contactListener;
	spBox2DDraw _debugDraw;
	// Spawns enough Characters until there are ten of them
	void RandomSpawn();
	// Moves the hero around the map
    void MoveHero(oxygine::Event* ev);
    // Responds to clicks made on Characters (mobs)
    void ClickCharacter(oxygine::Event* _event);
    // Resspond to clicks made on Special Enviorment(Special Plants)
    void ClickSpecialEnvironment(oxygine::Event* _event);
    // Checks if two sprites are too close from each other
    bool Overlaps(const oxygine::Vector2 _pos);
	// Toggle the debug view for box2d
	void ShowHideDebug(Event* ev);
	// Responds to clicks made on Hero
	void ClickOnHero(Event* ev);
	// Updates box2d body's position to follow character
	void doUpdate(const UpdateState& us);

	void RemoveActor(Actor* _act);
};
