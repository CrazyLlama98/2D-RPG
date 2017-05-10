#include "SpecialEnvironment.h"
#include <ctime>
#include <cstdlib>

SpecialEnvironment::SpecialEnvironment(ENV_PARAMS) : Environment(_res, _world, _pos, _scale) { }

std::pair<int, int> SpecialEnvironment::RandomDrop()
{
    srand(time(0));
    
    int type = rand() % 4;
    int amount;
    switch(type)
    {
        //health
        case 0: amount = rand() % 30 + 1;
            break;
        //damage
        case 1: amount = rand() % 10 + 1;
            break;
        //armor
        case 2: amount = rand() % 30 + 1;
            break;
        //xp
        case 3: amount = rand() % 50 + 1;
            break;
    }
    
    return std::make_pair(type, amount);
}
