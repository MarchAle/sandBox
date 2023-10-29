#include "../incs/Solid.hpp"
#include "../incs/Water.hpp"

ASolid::ASolid(int type, float granularFlow) : AElement(SOLID, type, 1), granularFlow(granularFlow)
{
    wet = false;
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

bool    ASolid::isWet()
{
    return (wet);
}

void    ASolid::setWetAs(bool value)
{
    wet = value;
}

void    ASolid::moveHumidity(std::vector<std::vector<std::unique_ptr<AElement> > > &map, int x, int y)
{
    if (isFalling() == true || isWet() == false)
        return ;
    if (rand() / static_cast<float> (RAND_MAX) < 0.3)
    {
        if (isValidCoordonate(map, x, y + 1) && (*map[x][y + 1]).get_particule_type() == SAND && (*map[x][y + 1]).isWet() == false)
        {
            (*map[x][y + 1]).setWetAs(true);
            setWetAs(false);
        }
        else
        {
            std::uniform_int_distribution<int> dist(-1, 1);
            int randomValue = dist(gen);
            if (isValidCoordonate(map, x + randomValue, y))
            {
                if ((*map[x + randomValue][y]).get_particule_type() == SAND && (*map[x + randomValue][y]).isWet() == false)
                {
                    (*map[x + randomValue][y]).setWetAs(true);
                    setWetAs(false);
                }
                else if ((*map[x + randomValue][y]).get_particule_type() == AIR)
                {
                    map[x + randomValue][y] = std::make_unique<Water>();
                    setWetAs(false);
                }
            }
            else if (isValidCoordonate(map, x - randomValue, y))
            {
                if ((*map[x - randomValue][y]).get_particule_type() == SAND && (*map[x - randomValue][y]).isWet() == false)
                {
                    (*map[x - randomValue][y]).setWetAs(true);
                    setWetAs(false);
                }
                else if ((*map[x - randomValue][y]).get_particule_type() == AIR)
                {
                    map[x - randomValue][y] = std::make_unique<Water>();
                    setWetAs(false);
                }
            }

        }
    }
}
