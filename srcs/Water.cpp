#include "../incs/Water.hpp"
#include "../incs/Air.hpp"

Water::Water() : ALiquid(WATER, WATER_DENSITY)
{
    color = generateColor(26, 55, 26, 55, 180, 200);
}

Water::~Water()
{
    delete[] color;
}

void    Water::moveElement(std::vector<std::vector<std::unique_ptr<AElement> > > &map, int x, int y)
{
    int i = 0;
    while (i < abs(y_velocity) && isValidCoordonate(map, x, y + i + 1)) 
        {
            if (((*map[x][y + i + 1]).get_particule_state() == LIQUID && density > (*map[x][y + i + 1]).get_density()) || (*map[x][y + i + 1]).get_particule_type() == SNOW)
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
            // wet the particule underneath
            else if (rand() / static_cast<float> (RAND_MAX) < 0.02 && ((*map[x][y + i + 1]).get_particule_type() == SAND || (*map[x][y + i + 1]).get_particule_type() == SNOW) && (*map[x][y + i + 1]).isWet() == false)
            {
                (*map[x][y + i + 1]).setWetAs(true);
                map[x][y + i] = std::make_unique<Air>();
                break;
            }
            // move on side
            else
            {
                std::uniform_int_distribution<int> dist(-1, 1);
                int randomValue = dist(gen);
                for (int j = 0; j < 10; j++)
                {
                    if (isValidCoordonate(map, x + (j * randomValue), y + i) && (*map[x + (j * randomValue)][y + i]).get_particule_state() == LIQUID)
                    {
                        std::swap(map[x + (j * randomValue)][y + i], map[x][y + i]);
                    }
                    else if (isValidCoordonate(map, x + (j * randomValue), y + i) && ((*map[x + (j * randomValue)][y + i]).get_particule_type() == SAND || (*map[x + (j * randomValue)][y + i]).get_particule_type() == SNOW))
                    {
                        // wet particule on side
                        if (rand() / static_cast<float> (RAND_MAX) < 0.5 && (*map[x + (j * randomValue)][y + i]).isWet() == false)
                        {
                            (*map[x + (j * randomValue)][y + i]).setWetAs(true);
                            map[x][y + i] = std::make_unique<Air>();
                        }
                        break;
                    }
                    else
                        break;
                }
                // break;
            }
            i++;
        }
}


bool    Water::isWet()
{
    std::cout << "should not appear (isWet Water)" << std::endl;
    return (false);
}

void    Water::setWetAs(bool value)
{
    std::cout << "should not appear (setWet Water)" << std::endl;
    (void)value;
}