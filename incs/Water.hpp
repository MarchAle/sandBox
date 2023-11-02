#ifndef WATER_HPP
# define WATER_HPP

# include "./Liquid.hpp"

class Water : public ALiquid
{
    private:
        /* data */
    public:
        Water(std::vector<std::vector<std::unique_ptr<AElement> > > *mapAddr);
        ~Water();
        void    moveElement(int x, int y);

        bool    isWet();
        void    setWetAs(bool value);

};


#endif