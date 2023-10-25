#include "../incs/Liquid.hpp"

ALiquid::ALiquid(int type, float density) : AElement(LIQUID, type, density)
{
}

ALiquid::~ALiquid()
{
}

// float   ALiquid::get_density()
// {
//     return (density);
// }