#ifndef WATER_HPP
# define WATER_HPP

# include "./Liquid.hpp"

class Water : public ALiquid
{
    private:
        /* data */
    public:
        Water();
        ~Water();
        void    moveElement(std::vector<std::vector<std::unique_ptr<AElement> > > &map, int x, int y);

};


#endif