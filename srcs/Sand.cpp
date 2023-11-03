#include "../incs/Sand.hpp"

Sand::Sand(std::vector<std::vector<std::unique_ptr<AElement> > > *mapAddr) : ASolid(SAND, SAND_GRANULAR_FLOW, true, mapAddr)
{
    color = generateColor(185, 210, 181, 206, 49, 76);
}

Sand::~Sand()
{
    delete[] color;
}

void    Sand::fallDown(int x, int y, int i)
{
    std::uniform_int_distribution<int> dist(-1, 1);
    int randomValue = dist(gen);

    if (isValidCoordonate(*map, x + randomValue, y + i + 1) && (*map)[x + randomValue][y + i + 1]->get_particule_state() == LIQUID)
        std::swap((*map)[x][y + i + 1], (*map)[x + randomValue][y + i + 1]);
    else if (isValidCoordonate(*map, x - randomValue, y + i + 1) && (*map)[x - randomValue][y + i + 1]->get_particule_state() == LIQUID)
        std::swap((*map)[x][y + i + 1], (*map)[x - randomValue][y + i + 1]);
    std::swap((*map)[x][y + i], (*map)[x][y + i + 1]);
}

void    Sand::fallOnSide(int x, int y, int i)
{
    std::uniform_int_distribution<int> dist(-1, 1);
    int randomValue = dist(gen);

    if (shouldFall() == true)
    {
        if (isValidCoordonate(*map, x + randomValue, y + i + 1) && (*map)[x + randomValue][y + i + 1]->get_particule_state() == LIQUID && (*map)[x + randomValue][y + i]->get_particule_state() == LIQUID)
            std::swap((*map)[x + randomValue][y + i + 1], (*map)[x][y + i]);
        else if (isValidCoordonate(*map, x - randomValue, y + i + 1) && (*map)[x - randomValue][y + i + 1]->get_particule_state() == LIQUID && (*map)[x - randomValue][y + i]->get_particule_state() == LIQUID)
            std::swap((*map)[x - randomValue][y + i + 1], (*map)[x][y + i]);
    }
    else
    {
        setFallingAs(false);
        y_velocity = 1;
    }
}

void    Sand::moveElement(int x, int y)
{
    if (isFalling() == true)
    {
        int i = 0;

        while (i < static_cast<int>(y_velocity) && isValidCoordonate(*map, x, y + i + 1)) 
        {
            if ((*map)[x][y + i + 1]->get_particule_state() == LIQUID)
            {
                fallDown(x, y, i);
                activateNeighbours(x, y + i);
            }
            else
            {
                fallOnSide(x, y, i);
                break;
            }
            i++;
            if (isValidCoordonate(*map, x, y + i - 1) && (*map)[x][y + i - 1]->get_particule_type() == WATER)
                y_velocity = 1;
        }
    }
}
