#include "MainActor.h"
#include "Utils.h"
#include "Map.h"
#include "Hero.h"
#include "res.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace oxygine;

MainActor::MainActor(): _world(0)
{
    
    setSize(getStage()->getSize());
    
	map = new Map("map.xml", "Sprites.png");
	addChild(map);
    _world = new b2World(b2Vec2(0, 10));   

	hero = new Hero(100, 10, 0, 100, "hero", res::resources.getResAnim("hero_idle_up"), _world, getSize() / 2, 0.6);
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
	std::string mob_types[] = { "dwarf", "troll", "skeleton" };
	srand(time(0));
	for (int i = 0; i < 10; ++i)
	{
		int type = rand() % 3;
		Vector2 pos;
		do {
			pos.x = rand() % (int)getSize().x;
			pos.y = rand() % (int)getSize().y;
		} while (pos.x < 70 || pos.x > getSize().x - 70 || pos.y < 70 || pos.y > getSize().y - 70); //|| overlaps());
		spCharacter mob = new Character(100, 5, 20, mob_types[type], res::resources.getResAnim(mob_types[type] + "_spawn"), _world, pos, b2_staticBody, 1);
		mob->addTween(TweenAnim(res::resources.getResAnim(mob_types[type] + "_spawn")), 700);
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
        	std::cout << "WORKING\n";
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
