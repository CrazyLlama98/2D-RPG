#pragma once
#include "oxygine-framework.h"
#include "Box2D/Box2D.h"

class MainActor : public oxygine::Actor
{
public:

    b2World* _world;
    
    MainActor();
};
