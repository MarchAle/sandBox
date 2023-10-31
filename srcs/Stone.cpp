#include "../incs/Stone.hpp"

Stone::Stone() : ASolid(STONE, 0, false)
{
    color = generateColor(110, 145);
}

Stone::~Stone()
{
    delete[] color;
}

void    Stone::moveElement(std::vector<std::vector<std::unique_ptr<AElement> > > &map, int x, int y)
{
    (void)map;
    (void)x;
    (void)y;
}


// float*    Stone::generateColor(int minRGB, int maxRGB)
// {
//     int rgbInterval = maxRGB - minRGB;
//     int rgbOffset = static_cast<float> (rand() / static_cast<float> (RAND_MAX)) * rgbInterval;
//     float   redValue = static_cast<float> (static_cast<float> (minRGB + rgbOffset) / 255);
//     float   greenValue = static_cast<float> (static_cast<float> (minRGB + rgbOffset) / 255);
//     float   blueValue = static_cast<float> (static_cast<float> (minRGB + rgbOffset) / 255);

//     float *colorArray = new float[3]{redValue, greenValue, blueValue};
//     return (colorArray);
// }