#ifndef SAND_HPP
# define SAND_HPP

#include "../incs/Solid.hpp"

class Sand : public ASolid
{
    private:

    public:
        Sand(std::vector<std::vector<std::unique_ptr<AElement> > > *mapAddr);
        ~Sand();
        void    moveElement(int x, int y);
        void    fallDown(int x, int y, int i);
        void    fallOnSide(int x, int y, int i);
        // float*  generateColor(int minRed, int maxRed, int minGreen, int maxGreen, int minBlue, int maxBlue);
        
};

#endif

