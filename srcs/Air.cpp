#include "../incs/Air.hpp"

Air::Air(/* args */) : ALiquid(AIR, AIR_DENSITY)
{
    color = generateColor(0, 0, 0, 0, 0, 0);

}

Air::~Air()
{
    delete[] color;
}

void    Air::moveElement(std::vector<std::vector<std::unique_ptr<AElement> > > &map, int x, int y)
{
    (void)map;
    (void)x;
    (void)y;
}
