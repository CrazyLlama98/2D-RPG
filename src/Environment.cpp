#include "Environment.h"

Environment::Environment(ENTITY_PARAMS) : Entity(_res, _world, _pos, b2_staticBody, _scale) { }

void Environment::Click(oxygine::Event *_event) { return; }