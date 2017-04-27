#include "SpecialEnvironment.h"

SpecialEnvironment::SpecialEnvironment(ENTITY_PARAMS) : Environment(_res, _world, _pos, _scale) { }

void SpecialEnvironment::Respawn(int (*_get[4])(), void (*_set[4])()) { return; }

void SpecialEnvironment::Click(oxygine::Event *_event) { return; }