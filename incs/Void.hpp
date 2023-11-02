#ifndef VOID_HPP
# define VOID_HPP

#include "../incs/Element.hpp"

class Void : public AElement
{
    private:
        /* data */
    public:
        Void(std::vector<std::vector<std::unique_ptr<AElement> > > *mapAddr);
        ~Void();
        void moveElement(int x, int y);
        float*  generateColor(int minRed, int maxRed, int minGreen, int maxGreen, int minBlue, int maxBlue);

};

#endif