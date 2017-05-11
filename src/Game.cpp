#include "Game.h"
#include "oxygine-framework.h"
#include "MainActor.h"
#include "res.h"
#include "snd.h"

using namespace oxygine;

void game_preinit() { }

void game_init() 
{
	res::load();
	snd::load();
	
	spMainActor game = MainActor::getMainActor();
	getStage()->addChild(game);
}

void game_update() {

}

void game_destroy() {
	res::free();
}