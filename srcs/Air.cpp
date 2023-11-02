#include "../incs/Air.hpp"

Air::Air(std::vector<std::vector<std::unique_ptr<AElement> > > *mapAddr) : ALiquid(AIR, AIR_DENSITY, false, mapAddr)
{
    color = generateColor(0, 0, 0, 0, 0, 0);

}

Air::~Air()
{
    delete[] color;
}

void    Air::moveElement(int x, int y)
{
    (void)map;
    (void)x;
    (void)y;
}

bool    Air::isWet()
{
    std::cout << "should not appear (isWet AIR)" << std::endl;
    return (false);
}

void    Air::setWetAs(bool value)
{
    std::cout << "should not appear (setWet Air)" << std::endl;
    (void)value;
}