#include "../incs/Liquid.hpp"

ALiquid::ALiquid(int type, float density, bool isFalling) : AElement(LIQUID, type, density, isFalling)
{
}

ALiquid::~ALiquid()
{
}

void    ALiquid::moveHumidity(std::vector<std::vector<std::unique_ptr<AElement> > > &map, int x, int y)
{
    (void)map,
    (void)x;
    (void)y;
}


// float   ALiquid::get_density()
// {
//     return (density);
// }