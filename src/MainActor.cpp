#include "MainActor.h"
#include "Utils.h"
#include "Map.h"
#include "Hero.h"
#include "res.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cmath>

using namespace oxygine;

MainActor::MainActor(): _world(0)
{
    
    setSize(getStage()->getSize());
    
	map = new Map("map.xml", "Sprites.png");
	addChild(map);
    _world = new b2World(b2Vec2(0, 10));   

	hero = new Hero(100, 10, 0, 100, "hero", res::resources.getResAnim("hero_idle_up"), _world, getSize() / 2, 0.6);
	_entities.push_back(hero);
	addChild(hero);
	this->addEventListener(TouchEvent::CLICK, CLOSURE(this, &MainActor::MoveHero));
	RandomSpawn();
}

void MainActor::MoveHero(Event* ev)
{
	TouchEvent* tev = safeCast<TouchEvent*>(ev);
	if (tev->localPosition.x > 64 && tev->localPosition.y > 64 && tev->localPosition.y < 630 && tev->localPosition.x < 1080)
		hero->addTween(createTween(Actor::TweenPosition(tev->localPosition), 1500));
}

void MainActor::RandomSpawn()
{
	std::string mob_types[] = { "skeleton", "dwarf", "troll" };
	srand(time(0));
	for (int i = _entities.size(); i < 11; ++i)
	{
		int type = rand() % 3;
		Vector2 pos;
		do {
			pos.x = rand() % (int)getSize().x;
			pos.y = rand() % (int)getSize().y;
		} while (pos.x < 64 || pos.x > 1080 || pos.y < 64 || pos.y > 630 || Overlaps(pos));
		Character *mob = new Character(100, 5, 20, mob_types[type], res::resources.getResAnim(mob_types[type] + "_idle"),
						 _world, pos, b2_staticBody, 1);
		_entities.push_back(mob);
		mob->addTween(TweenAnim(res::resources.getResAnim(mob_types[type] + "_spawn")), 700);
		mob->addEventListener(TouchEvent::CLICK, CLOSURE(this, &MainActor::ClickCharacter));
		addChild(mob);
	}
}

void MainActor::ClickCharacter(Event* _event)
{
    TouchEvent* _tevent = safeCast<TouchEvent*>(_event);
    
    MoveHero(_event);
    
    for(auto it : _entities)
    {
        if(it == (Character*)_event->target.get())
        {
        	std::cout << "APP_LOG: CHARACTER CLICKED\n";
        	Character *mob = (Character*)it;
            int heroArmor = hero->GetArmor();
            int heroHealth = hero->GetHealth();
            int heroDamage = hero->DealDamage();
            int mobHealth = mob->GetHealth();
            int mobDamage = mob->DealDamage();
            
            if(heroArmor >= mobDamage)
            {
                hero->SetArmor(heroArmor - mobDamage);
            }
            else
            {
                hero->SetArmor(0);
                hero->SetHealth(heroHealth + heroArmor - mobDamage);
            }
            mob->SetHealth(mobHealth - heroDamage);
            if(hero->GetHealth() <= 0)
            {
                hero->Die();
                return;
            }
            if(mob->GetHealth() <= 0)
            {
                mob->Die();
                return;
            }
        }
    }
}

bool MainActor::Overlaps(const Vector2 _pos)
{
	for (auto it = _entities.begin(); it != _entities.end(); ++it)
	{
		Vector2 mob_pos = (*it)->getPosition();
		if (sqrt((mob_pos.x - _pos.x) * (mob_pos.x - _pos.x) + (mob_pos.y - _pos.y) * (mob_pos.y - _pos.y)) < 200)
			return true;
	}
	return false;
}