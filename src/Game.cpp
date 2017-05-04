#include "Game.h"
#include "oxygine-framework.h"
#include "MainActor.h"
#include "res.h"

// #include "Character.h"

using namespace oxygine;

Resources gameResources;

void game_preinit() { }

void game_init() 
{
	res::load();
	// spStage stage = getStage();
	// spMap map = new Map("map.xml", "Sprites.png");
	// stage->addChild(map);

	// b2World *_world;
	// _world = new b2World(b2Vec2(0, 10));

	// spHero hero = new Hero(100, 10, 0, 100, res::resources.getResAnim("hero_idle_up"), _world, Vector2(10, 10), 0.6);
	// hero->setPosition(stage->getSize() / 2);
	// stage->addChild(hero);

	// hero->addTween(Sprite::TweenAnim(res::resources.getResAnim("hero_walk_up")), 1000);
	MainActor *game = new MainActor();
	getStage()->addChild(game);
}

void game_update() { }

void game_destroy() {
	res::free();
}