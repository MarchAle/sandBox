#include "../incs/Void.hpp"

Void::Void() : AElement(LIQUID, VOID, 0, false)
{
    // this->color[0] = 0.0f;
    // this->color[1] = 0.0f;
    // this->color[2] = 0.0f;
    color = generateColor(0, 0, 0, 0, 0, 0);
}

Void::~Void()
{
    delete[] color;
}

void  Void::moveElement(std::vector<std::vector<std::unique_ptr<AElement> > > &map, int x, int y)
{
    (void)map;
    (void)x;
    (void)y;
}

float* Void::generateColor(int minRed, int maxRed, int minGreen, int maxGreen, int minBlue, int maxBlue)
{
    (void)minRed;
    (void)maxRed;
    (void)minGreen;
    (void)maxGreen;
    (void)minBlue;
    (void)maxBlue;

    float *colorArray = new float[3]{0.1, 0.1, 0.1};

    return (colorArray);
}

