#include "../incs/Sand.hpp"

Sand::Sand() : ASolid(SAND, SAND_GRANULAR_FLOW)
{
    color = generateColor(185, 210, 181, 206, 49, 76);
}

Sand::~Sand()
{
    delete[] color;
}

void    Sand::moveElement(std::vector<std::vector<std::unique_ptr<AElement> > > &map, int x, int y)
{
    if ((*map[x][y + 1]).get_particule_state() == LIQUID)
    {
        (*map[x + 1][y]).setFallingAs(true);
        (*map[x - 1][y]).setFallingAs(true);
        std::swap(map[x][y], map[x][y + 1]);
    }
    else if (isFalling() == true) // && shouldFall() == true
    {
        std::uniform_int_distribution<int> dist(-1, 1);
        int randomValue = dist(gen);
        if (isValidCoordonate(map, x + randomValue, y + 1) && (*map[x + randomValue][y + 1]).get_particule_state() == LIQUID && (*map[x + randomValue][y]).get_particule_state() == LIQUID)
        {
            std::swap(map[x + randomValue][y + 1], map[x][y]);
            // (*map[x + randomValue][y + 1]).setFallingAs(true);
        }
        else if (isValidCoordonate(map, x - randomValue, y + 1) && (*map[x - randomValue][y + 1]).get_particule_state() == LIQUID && (*map[x - randomValue][y]).get_particule_state() == LIQUID)
        {
            std::swap(map[x - randomValue][y + 1], map[x][y]);
            // (*map[x - randomValue][y + 1]).setFallingAs(true);
        }
        else
            setFallingAs(false);
    }
}

float*    Sand::generateColor(int minRed, int maxRed, int minGreen, int maxGreen, int minBlue, int maxBlue)
{
    int redInterval = maxRed - minRed;
    int redOffset = static_cast<float> (rand() / static_cast<float> (RAND_MAX)) * redInterval;
    float   redValue = static_cast<float> (static_cast<float> (minRed + redOffset) / 255);
    int greenInterval = maxGreen - minGreen;
    int greenOffset = static_cast<float> (rand() / static_cast<float> (RAND_MAX)) * greenInterval;
    float   greenValue = static_cast<float> (static_cast<float> (minGreen + greenOffset) / 255);
    int blueInterval = maxBlue - minBlue;
    int blueOffset = static_cast<float> (rand() / static_cast<float> (RAND_MAX)) * blueInterval;
    float   blueValue = static_cast<float> (static_cast<float> (minBlue + blueOffset) / 255);

    float *colorArray = new float[3]{redValue, greenValue, blueValue};
    return (colorArray);
}
