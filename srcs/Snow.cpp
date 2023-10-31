#include "../incs/Snow.hpp"

Snow::Snow(/* args */) : ASolid(SNOW, SNOW_GRANULAR_FLOW, true), flyingTime(30), flying(true)
{
    std::uniform_int_distribution<int> dist(100, 200);
    int randomValue = dist(gen);
    lifeTime = randomValue;
    color = generateColor(230, 255);
}

Snow::~Snow()
{
    delete[] color;
}

void    Snow::moveElement(std::vector<std::vector<std::unique_ptr<AElement> > > &map, int x, int y)
{
    // if (isFalling() == false)
    //     setFlyingAs(false);
    if (isFalling() == false || (isFlying() == true && rand() / static_cast<float> (RAND_MAX) < 0.7))
        return;
    std::uniform_int_distribution<int> dist(-1, 1);
    int randomValue = dist(gen);

    if (isFlying() == true)
    {
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
        else if (isValidCoordonate(map, x, y + 1) && (*map[x][y + 1]).isFalling() == false)
        {
            // if (isValidCoordonate(map, x + randomValue, y + 1) && (*map[x + randomValue][y]).get_particule_type() == AIR && (*map[x + randomValue][y + 1]).get_particule_type() == AIR)
            // {
            //     std::swap(map[x][y], map[x + randomValue][y + 1]);
            // }
            // else if (isValidCoordonate(map, x - randomValue, y + 1) && (*map[x - randomValue][y]).get_particule_type() == AIR && (*map[x - randomValue][y + 1]).get_particule_type() == AIR)
            // {
            //     std::swap(map[x][y], map[x - randomValue][y + 1]);
            // }
            // else
            // {
                // setFallingAs(false);
                setFlyingAs(false);
            // }
        }
        else
        {
            setFallingAs(false);

        }
    }
    else if (isFalling() == true)
    {
        if (isValidCoordonate(map, x, y + 1) && (*map[x][y + 1]).get_particule_type() == AIR)
        {
            std::swap(map[x][y], map[x][y + 1]);
            if (isValidCoordonate(map, x - 1, y) && (*map[x - 1][y]).get_particule_state() == SOLID && (*map[x - 1][y]).isFalling() == false)
            {
                (*map[x - 1][y]).setFallingAs(true);
                (*map[x - 1][y]).y_velocity = 1;
            }
            if (isValidCoordonate(map, x + 1, y) && (*map[x + 1][y]).get_particule_state() == SOLID && (*map[x + 1][y]).isFalling() == false)
            {
                (*map[x + 1][y]).setFallingAs(true);
                (*map[x + 1][y]).y_velocity = 1;
            }
        }
        else if (shouldFall() == true)
        {
            if (isValidCoordonate(map, x + randomValue, y + 1) && (*map[x + randomValue][y]).get_particule_type() == AIR && (*map[x + randomValue][y + 1]).get_particule_type() == AIR)
            {
                std::swap(map[x][y], map[x + randomValue][y + 1]);
            }
            else if (isValidCoordonate(map, x - randomValue, y + 1) && (*map[x - randomValue][y]).get_particule_type() == AIR && (*map[x - randomValue][y + 1]).get_particule_type() == AIR)
            {
                std::swap(map[x][y], map[x - randomValue][y + 1]);
            }

        }
        else
        {
            setFallingAs(false);
        }

    }
}

bool    Snow::isFlying()
{
    return (flying);
}

void    Snow::setFlyingAs(bool value)
{
    if (value == true)
    {
        flying = value;
        return;
    }
    else
    {
        flyingTime--;
        if (flyingTime <= 0)
        {
            flying = value;
            setFallingAs(true);
            flyingTime = 0;
        }
    }
}

void    Snow::decreaseLifeTime()
{
    lifeTime--;
    if (isWet() == true)
        lifeTime--;
}

int     Snow::getLifeTime()
{
    return (lifeTime);
}