#ifndef AIR_HPP
# define AIR_HPP

#include "./Liquid.hpp"

class Air : public ALiquid
{
    private:
        /* data */
    public:
        Air(/* args */);
        ~Air();
        void    moveElement(std::vector<std::vector<std::unique_ptr<AElement> > > &map, int x, int y);

        bool    isWet();
        void    setWetAs(bool value);
};


#endif