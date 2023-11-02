#ifndef LIQUID_HPP
# define LIQUID_HPP

#include "./Element.hpp"

class ALiquid : public AElement
{
    private:
        // float density;
    public:
        ALiquid(int type, float density, bool isFalling, std::vector<std::vector<std::unique_ptr<AElement> > > *mapAddr);
        ~ALiquid();
        // float   get_density();
        void    moveHumidity(int x, int y);

};


#endif