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
        float*  generateColor(int minRed, int maxRed, int minGreen, int maxGreen, int minBlue, int maxBlue);

};

#endif