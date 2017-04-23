#include "Game.h"
#include "oxygine-framework.h"
#include "Utils.h"
#include "Map.h"

using namespace oxygine;

//Resources gameResources;

void game_preinit() { }

void game_init() {
	//gameResources.loadXML("res.xml");
	spStage stage = getStage();
	spMap map = new Map("map.xml", "Sprites.png");
	stage->addChild(map);
}

void game_update() { }

void game_destroy() {
	//gameResources.free();
}
