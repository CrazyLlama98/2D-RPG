#include "Game.h"
#include "oxygine-framework.h"

using namespace oxygine;

Resources gameResources;

game_preinit() { }

game_init() {
	gameResources.loadXML("res.xml");

}

game_update() { }

game_destroy() {
	gameResources.free();
}