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
    if (isFalling() == true)
    {
        int i = 0;

        while (i < abs(y_velocity) && isValidCoordonate(map, x, y + i + 1)) 
        {
            if ((*map[x][y + i + 1]).get_particule_state() == LIQUID)
            {
                std::swap(map[x][y + i], map[x][y + i + 1]);
                if (isValidCoordonate(map, x - 1, y + i) && (*map[x - 1][y + i]).get_particule_state() == SOLID)
                {
                    (*map[x - 1][y + i]).setFallingAs(true);
                    (*map[x - 1][y + i]).y_velocity = 1;
                }
                if (isValidCoordonate(map, x + 1, y + i) && (*map[x + 1][y + i]).get_particule_state() == SOLID)
                {
                    (*map[x + 1][y + i]).setFallingAs(true);
                    (*map[x + 1][y + i]).y_velocity = 1;
                }
            }
            else
            {
                if (shouldFall() == true)
                {
                    std::uniform_int_distribution<int> dist(-1, 1);
                    int randomValue = dist(gen);
                    if (isValidCoordonate(map, x + randomValue, y + i + 1) && (*map[x + randomValue][y + i + 1]).get_particule_state() == LIQUID && (*map[x + randomValue][y + i]).get_particule_state() == LIQUID)
                    {
                        std::swap(map[x + randomValue][y + i + 1], map[x][y + i]);
                        // if (isValidCoordonate(map, x + randomValue, y + i + 2) && (*map[x + randomValue][y + i + 1]).get_particule_state() == SOLID)
                        //     setFallingAs(false);
                    }
                    else if (isValidCoordonate(map, x - randomValue, y + i + 1) && (*map[x - randomValue][y + i + 1]).get_particule_state() == LIQUID && (*map[x - randomValue][y + i]).get_particule_state() == LIQUID)
                    {
                        std::swap(map[x - randomValue][y + i + 1], map[x][y + i]);
                        // if (isValidCoordonate(map, x - randomValue, y + i + 2) && (*map[x - randomValue][y + i + 1]).get_particule_state() == SOLID)
                        //     setFallingAs(false);
                    }
                    // else
                    // {
                    //     setFallingAs(false);
                    //     y_velocity = 1;
                    // }
                }
                else
                {
                    setFallingAs(false);
                    y_velocity = 1;
                }
                break;
            }
            i++;
        }
    }

}

// float*    Sand::generateColor(int minRed, int maxRed, int minGreen, int maxGreen, int minBlue, int maxBlue)
// {
//     int redInterval = maxRed - minRed;
//     int redOffset = static_cast<float> (rand() / static_cast<float> (RAND_MAX)) * redInterval;
//     float   redValue = static_cast<float> (static_cast<float> (minRed + redOffset) / 255);
//     int greenInterval = maxGreen - minGreen;
//     int greenOffset = static_cast<float> (rand() / static_cast<float> (RAND_MAX)) * greenInterval;
//     float   greenValue = static_cast<float> (static_cast<float> (minGreen + greenOffset) / 255);
//     int blueInterval = maxBlue - minBlue;
//     int blueOffset = static_cast<float> (rand() / static_cast<float> (RAND_MAX)) * blueInterval;
//     float   blueValue = static_cast<float> (static_cast<float> (minBlue + blueOffset) / 255);

//     float *colorArray = new float[3]{redValue, greenValue, blueValue};
//     return (colorArray);
// }
