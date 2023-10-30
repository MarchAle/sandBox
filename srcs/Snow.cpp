#include "../incs/Snow.hpp"

Snow::Snow(/* args */) : ASolid(SNOW, SNOW_GRANULAR_FLOW)
{
    color = generateColor(230, 255);
}

Snow::~Snow()
{
    delete[] color;
}

void    Snow::moveElement(std::vector<std::vector<std::unique_ptr<AElement> > > &map, int x, int y)
{
    if (isFalling() == false || rand() / static_cast<float> (RAND_MAX) < 0.7)
        return;
    std::uniform_int_distribution<int> dist(-1, 1);
    int randomValue = dist(gen);

    if (isValidCoordonate(map, x, y + 1) && (*map[x][y + 1]).get_particule_type() == AIR)
    {
        if (isValidCoordonate(map, x + randomValue, y + 1) && (*map[x + randomValue][y]).get_particule_type() == AIR && (*map[x + randomValue][y + 1]).get_particule_type() == AIR)
        {
            std::swap(map[x][y], map[x + randomValue][y + 1]);
        }
        else if (isValidCoordonate(map, x - randomValue, y + 1) && (*map[x - randomValue][y]).get_particule_type() == AIR && (*map[x - randomValue][y + 1]).get_particule_type() == AIR)
        {
            std::swap(map[x][y], map[x - randomValue][y + 1]);
        }
        else
        {
            std::swap(map[x][y], map[x][y + 1]);
        }
    }
    else
    {
        if (isValidCoordonate(map, x + randomValue, y + 1) && (*map[x + randomValue][y]).get_particule_type() == AIR && (*map[x + randomValue][y + 1]).get_particule_type() == AIR)
        {
            std::swap(map[x][y], map[x + randomValue][y + 1]);
        }
        else if (isValidCoordonate(map, x - randomValue, y + 1) && (*map[x - randomValue][y]).get_particule_type() == AIR && (*map[x - randomValue][y + 1]).get_particule_type() == AIR)
        {
            std::swap(map[x][y], map[x - randomValue][y + 1]);
        }
        else
        {
            setFallingAs(false);
        }
    }

    (void)map;
    (void)x;
    (void)y;
}