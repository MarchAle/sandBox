#ifndef STONE_HPP
# define STONE_HPP

#include "../incs/Solid.hpp"

class Stone : public ASolid
{
    private:
    
    public:
        Stone(std::vector<std::vector<std::unique_ptr<AElement> > > *mapAddr);
        ~Stone();
        void    moveElement(int x, int y);
        // float*  generateColor(int minRGB, int maxRGB);

};

#endif