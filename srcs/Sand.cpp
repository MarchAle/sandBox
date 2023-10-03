#include "../incs/Sand.hpp"

Sand::Sand(/* args */) : ASolid(SAND)
{
}

Sand::~Sand()
{
}

void    Sand::moveElement(Map &map, int x, int y)
{
    if (map[x][y + 1]. == true)
    {
        map[x][y + 1].set_free_as(false);
        map[x][y + 1].set_particule_type(map[x][y].get_particule_type());
        map[x][y].set_free_as(true);
        map[x][y].set_particule_type(AIR);
    }
    else
    {
        std::uniform_int_distribution<int> dist(-1, 1);
        int randomValue = dist(gen);
        if (map[x + randomValue][y + 1].is_free() == true && map[x + randomValue][y].is_free() == true)
        {
            map[x + randomValue][y + 1].set_free_as(false);
            map[x + randomValue][y + 1].set_particule_type(map[x][y].get_particule_type());
            map[x][y].set_free_as(true);
            map[x][y].set_particule_type(AIR);
        }
        else if (map[x - randomValue][y + 1].is_free() == true && map[x - randomValue][y].is_free() == true)
        {
            map[x - randomValue][y + 1].set_free_as(false);
            map[x - randomValue][y + 1].set_particule_type(map[x][y].get_particule_type());
            map[x][y].set_free_as(true);
            map[x][y].set_particule_type(AIR);
        }
    }
}
