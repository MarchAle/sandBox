#include "../incs/Liquid.hpp"

ALiquid::ALiquid(int type, float density, bool isFalling, std::vector<std::vector<std::unique_ptr<AElement> > > *mapAddr) : AElement(LIQUID, type, density, isFalling, mapAddr)
{
}

ALiquid::~ALiquid()
{
}

void    ALiquid::moveHumidity(int x, int y)
{
    (void)map,
    (void)x;
    (void)y;
}


// float   ALiquid::get_density()
// {
//     return (density);
// }