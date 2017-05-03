#include "MainActor.h"

MainActor::MainActor(): _world(0)
{
    
    setSize(oxygine::getStage()->getSize());
    
    _world = new b2World(b2Vec2(0, 10));
    
}
