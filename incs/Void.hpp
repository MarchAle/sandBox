#ifndef VOID_HPP
# define VOID_HPP

#include "../incs/Element.hpp"

class Void : public AElement
{
    private:
        /* data */
    public:
        Void();
        ~Void();
        void moveElement(std::vector<std::vector<std::unique_ptr<AElement> > > &map, int x, int y);
};

#endif