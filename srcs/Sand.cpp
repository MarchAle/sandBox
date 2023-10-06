#include "../incs/Sand.hpp"

Sand::Sand(/* args */) : ASolid(SAND)
{
    this->color[0] = 0.8f;
    this->color[1] = 0.1f;
    this->color[2] = 0.1f;
}

Sand::~Sand()
{
}

void    Sand::moveElement(std::vector<std::vector<std::unique_ptr<AElement> > > &map, int x, int y)
{
    if ((*map[x][y + 1]).get_particule_state() == LIQUID)
    {
        // std::cout << "map[x][y] color[0] " << (*map[x][y]).get_color()[0] << std::endl;
        // std::cout << "map[x][y + 1] color[0] " << (*map[x][y + 1]).get_color()[0] << std::endl;
        std::swap(map[x][y], map[x][y + 1]);
        // std::cout << "map[x][y] color[0] " << (*map[x][y]).get_color()[0] << std::endl;
        // std::cout << "map[x][y + 1] color[0] " << (*map[x][y + 1]).get_color()[0] << std::endl;
        // swapElement(map[x][y], map[x][y + 1]);
        // map[x][y + 1].set_free_as(false);
        // map[x][y + 1].set_particule_type(map[x][y].get_particule_type());
        // map[x][y].set_free_as(true);
        // map[x][y].set_particule_type(AIR);
    }
    else
    {
        std::uniform_int_distribution<int> dist(-1, 1);
        int randomValue = dist(gen);
        if (isValidCoordonate(map, x + randomValue, y + 1) && (*map[x + randomValue][y + 1]).get_particule_state() == LIQUID && (*map[x + randomValue][y]).get_particule_state() == LIQUID)
        {
            std::swap(map[x + randomValue][y + 1], map[x][y]);
            // swapElement(map[x + randomValue][y + 1], map[x][y]);
            // map[x + randomValue][y + 1].set_free_as(false);
            // map[x + randomValue][y + 1].set_particule_type(map[x][y].get_particule_type());
            // map[x][y].set_free_as(true);
            // map[x][y].set_particule_type(AIR);
        }
        else if (isValidCoordonate(map, x - randomValue, y + 1) && (*map[x - randomValue][y + 1]).get_particule_state() == LIQUID && (*map[x - randomValue][y]).get_particule_state() == LIQUID)
        {
            std::swap(map[x - randomValue][y + 1], map[x][y]);
            // swapElement(map[x - randomValue][y + 1], map[x][y]);
            // map[x - randomValue][y + 1].set_free_as(false);
            // map[x - randomValue][y + 1].set_particule_type(map[x][y].get_particule_type());
            // map[x][y].set_free_as(true);
            // map[x][y].set_particule_type(AIR);
        }
    }
}
