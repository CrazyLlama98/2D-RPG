#include "Game.h"
#include "oxygine-framework.h"
#include "Utils.h"
#include "Map.h"
#include "Hero.h"
// #include "Character.h"

using namespace oxygine;

Resources gameResources;

void game_preinit() { }

void game_init() {
	gameResources.loadXML("res.xml");
	spStage stage = getStage();
	spMap map = new Map("map.xml", "Sprites.png");
	stage->addChild(map);

	b2World *_world;
	_world = new b2World(b2Vec2(0, 10));

	spHero hero = new Hero(100, 10, 0, 100, gameResources.getResAnim("hero_idle_up"), _world, Vector2(10, 10));
	stage->addChild(hero);
}

void game_update() { }

void game_destroy() {
	gameResources.free();
}
