#ifndef SAND_HPP
# define SAND_HPP

#include "../incs/Solid.hpp"


class Sand : public ASolid
{
    private:
        /* data */
    public:
        Sand();
        ~Sand();
        void    moveElement(Map &map, int x, int y);
};

#endif

