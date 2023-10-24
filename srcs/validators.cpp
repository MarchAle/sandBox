#include "../incs/sandbox.hpp"

bool    isValidCoordonate(std::vector<std::vector<std::unique_ptr<AElement> > > &map, int x, int y)
{
    if (x < 0 || x >= (int)map.size() || y < 0 || y >= (int)map[0].size())
        return (false);
    return (true);
}