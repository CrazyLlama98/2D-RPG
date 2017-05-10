#include "Game.h"
#include "oxygine-framework.h"
#include "MainActor.h"
#include "res.h"

using namespace oxygine;

void game_preinit() { }

void game_init() 
{
	res::load();
	
	MainActor *game = new MainActor();
	getStage()->addChild(game);
}

void game_update() {

}

void game_destroy() {
	res::free();
}