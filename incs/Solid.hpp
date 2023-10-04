#ifndef SOLID_HPP
# define SOLID_HPP

#include "../incs/Element.hpp"

class ASolid : public AElement
{
    private:

    protected:
        bool    freeFalling;
        virtual void moveElement(std::vector<std::vector<std::unique_ptr<AElement> > > &map, int x, int y) = 0;

    public:
        ASolid(int type);
        ~ASolid();
};


#endif