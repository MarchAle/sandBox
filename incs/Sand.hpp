#ifndef SAND_HPP
# define SAND_HPP

#include "../incs/Solid.hpp"


class Sand : public ASolid
{
    private:

    public:
        Sand();
        ~Sand();
        void    moveElement(std::vector<std::vector<std::unique_ptr<AElement> > > &map, int x, int y);
        float*  generateColor(int minRed, int maxRed, int minGreen, int maxGreen, int minBlue, int maxBlue);
        
};

#endif

