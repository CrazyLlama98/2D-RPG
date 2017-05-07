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
	{
		hero->addTween(createTween(Actor::TweenPosition(tev->localPosition), 1500));
		int x = hero->getPosition().x, y = hero->getPosition().y;
		int xTarget = tev->localPosition.x, yTarget = tev->localPosition.y;
		double tg = (x - xTarget != 0) ? (double)(yTarget - y) / (x - xTarget) : Utils::inf * ((yTarget - y) < 0 ? (-1) : 1);
		if (tg < 0)
		{
			if (yTarget - y <= 0)
			{
				if (tg <= -1)
					hero->addTween(TweenQueue::create(
						createTween(Sprite::TweenAnim(res::resources.getResAnim("hero_walk_left")), 1500, 1),
						createTween(Sprite::TweenAnim(res::resources.getResAnim("hero_idle_left")), 500, 1)));
				else 
					hero->addTween(TweenQueue::create(
						createTween(Sprite::TweenAnim(res::resources.getResAnim("hero_walk_up")), 1500, 1),
						createTween(Sprite::TweenAnim(res::resources.getResAnim("hero_idle_up")), 500, 1)));
			}
			else if (x - xTarget <= 0)
			{
				if (tg <= -1)
					hero->addTween(TweenQueue::create(
						createTween(Sprite::TweenAnim(res::resources.getResAnim("hero_walk_right")), 1500, 1),
						createTween(Sprite::TweenAnim(res::resources.getResAnim("hero_idle_right")), 500, 1)));
				else
					hero->addTween(TweenQueue::create(
						createTween(Sprite::TweenAnim(res::resources.getResAnim("hero_walk_down")), 1500, 1),
						createTween(Sprite::TweenAnim(res::resources.getResAnim("hero_idle_down")), 500, 1)));
			}
		}
		else
		{
			if (x - xTarget >= 0 && yTarget - y >= 0)
			{
				if (tg < 1)
					hero->addTween(TweenQueue::create(
						createTween(Sprite::TweenAnim(res::resources.getResAnim("hero_walk_left")), 1500, 1),
						createTween(Sprite::TweenAnim(res::resources.getResAnim("hero_idle_left")), 500, 1)));
				else
					hero->addTween(TweenQueue::create(
						createTween(Sprite::TweenAnim(res::resources.getResAnim("hero_walk_down")), 1500, 1),
						createTween(Sprite::TweenAnim(res::resources.getResAnim("hero_idle_down")), 500, 1)));
			}
			else
			{
				if (tg < 1)
					hero->addTween(TweenQueue::create(
						createTween(Sprite::TweenAnim(res::resources.getResAnim("hero_walk_right")), 1500, 1),
						createTween(Sprite::TweenAnim(res::resources.getResAnim("hero_idle_right")), 500, 1)));
				else
					hero->addTween(TweenQueue::create(
						createTween(Sprite::TweenAnim(res::resources.getResAnim("hero_walk_up")), 1500, 1),
						createTween(Sprite::TweenAnim(res::resources.getResAnim("hero_idle_up")), 500, 1)));
			}
		}
	}
}
