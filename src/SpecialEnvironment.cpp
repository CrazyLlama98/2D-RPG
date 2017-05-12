#include "SpecialEnvironment.h"
#include "snd.h"
#include <ctime>
#include <cstring>
#include <cstdlib>

SpecialEnvironment::SpecialEnvironment(oxygine::ResAnim* _res, oxygine::Vector2 _pos, const float _scale)
{ 
    setResAnim(_res);
    setPosition(_pos);
    setScale(_scale);
}

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

    int nr = 1;
    snd::sfxPlayer.play(snd::resources.get("collect" + std::to_string(rand() % nr + 1)));
    
    return std::make_pair(type, amount);
}
