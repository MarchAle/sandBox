#ifndef SOLID_HPP
# define SOLID_HPP

#include "../incs/Element.hpp"

class ASolid : public AElement
{
    private:

    protected:
        float   granularFlow;
        virtual void moveElement(std::vector<std::vector<std::unique_ptr<AElement> > > &map, int x, int y) = 0;
        virtual float*  generateColor(int minRed, int maxRed, int minGreen, int maxGreen, int minBlue, int maxBlue) = 0;


    public:
        ASolid(int type, float granularFlow);
        ~ASolid();
        bool    shouldFall();
};


#endif