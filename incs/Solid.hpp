#ifndef SOLID_HPP
# define SOLID_HPP

#include "../incs/Element.hpp"

class ASolid : public AElement
{
    private:

    protected:
        bool    freeFalling;
        virtual void moveElement() = 0;

    public:
        ASolid(int type);
        ~ASolid();
};


#endif