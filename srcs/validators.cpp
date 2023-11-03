#include "../incs/sandbox.hpp"

bool    isValidCoordonate(std::vector<std::vector<std::unique_ptr<AElement> > > &map, int x, int y)
{
    // std::cout << "y : " << y << " size : " << (int)map[0].size() << std::endl;
    if (x < 0 || x >= (int)map.size() || y < 0 || y >= (int)map[0].size())
        return (false);
    return (true);
}