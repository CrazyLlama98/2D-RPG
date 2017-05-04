#include "MainActor.h"
#include "Utils.h"
#include "Map.h"
#include "Hero.h"
#include "res.h"
#include <iostream>

using namespace oxygine;

MainActor::MainActor(): _world(0)
{
    
    setSize(getStage()->getSize());
    
	map = new Map("map.xml", "Sprites.png");
	addChild(map);
    _world = new b2World(b2Vec2(0, 10));   

	hero = new Hero(100, 10, 0, 100, res::resources.getResAnim("hero_idle_up"), _world, getSize() / 2, 0.6);
	addChild(hero);
	this->addEventListener(TouchEvent::CLICK, CLOSURE(this, &MainActor::MoveHero));
}

void MainActor::MoveHero(Event* ev)
{
	TouchEvent* tev = safeCast<TouchEvent*>(ev);
	if (tev->localPosition.x > 64 && tev->localPosition.y > 64 && tev->localPosition.y < 630 && tev->localPosition.x < 1080)
		hero->addTween(createTween(Actor::TweenPosition(tev->localPosition), 1500));
}
