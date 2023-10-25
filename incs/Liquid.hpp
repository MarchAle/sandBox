#ifndef LIQUID_HPP
# define LIQUID_HPP

#include "./Element.hpp"

class ALiquid : public AElement
{
    private:
        // float density;
    public:
        ALiquid(int type, float density);
        ~ALiquid();
        // float   get_density();
};


#endif