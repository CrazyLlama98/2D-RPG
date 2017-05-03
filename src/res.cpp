#include "res.h"

namespace res
{
    
    oxygine::Resources resources;
    
    void load()
    {
        resources.loadXML("res.xml");
    }
    
    void free()
    {
        resources.free();
    }

}
