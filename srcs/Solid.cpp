#include "../incs/Solid.hpp"


ASolid::ASolid(int type, float granularFlow) : AElement(SOLID, type, 1), granularFlow(granularFlow)
{
    // particule_state = SOLID;
}

ASolid::~ASolid()
{
}

bool    ASolid::shouldFall()
{
    if (rand() / static_cast<float> (RAND_MAX) < granularFlow)
        return (true);
    return (false);
}