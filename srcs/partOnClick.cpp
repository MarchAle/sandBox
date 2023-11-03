#include "../incs/sandbox.hpp"
#include "../incs/Element.hpp"
#include "../incs/Void.hpp"
#include "../incs/Air.hpp"
#include "../incs/Sand.hpp"
#include "../incs/Snow.hpp"
#include "../incs/Stone.hpp"
#include "../incs/Water.hpp"

void    deleteParticule(std::vector<std::vector<std::unique_ptr<AElement> > > &map, double xpos, double ypos)
{
    for (int i = -spread; i < spread; i++)
    {
        for (int j = -spread; j < spread; j++)
        {
            if (isValidCoordonate(map, xpos + i, ypos + j))
            {
                map[xpos + i][ypos + j] = std::make_unique<Air>(&map);
            }
        }
    }
}

void    addParticules(std::vector<std::vector<std::unique_ptr<AElement> > > &map, double xpos, double ypos)
{
    if (currentParticuleType == STONE)
    {
        for (int i = -spread / 2; i <= spread / 2; i++)
        {
            for (int j = -spread / 2; j <= spread / 2; j++)
                map[xpos + i][ypos + j] = std::make_unique<Stone>(&map);
        }
        return;
    }

    int loop = currentParticuleType == WATER ? 3 : 1;
    while (loop > 0)
    {
        std::uniform_int_distribution<int> dist(-spread, spread);
        int randomI = dist(gen);
        int randomJ = dist(gen);

        if (isValidCoordonate(map, xpos + randomI, ypos + randomJ))
        {
            switch (currentParticuleType)
            {
                case SAND:
                    map[xpos + randomI][ypos + randomJ] = std::make_unique<Sand>(&map);
                    break;
                case SNOW:
                    map[xpos + randomI][ypos + randomJ] = std::make_unique<Snow>(&map);
                    break;
                case WATER:
                    map[xpos + randomI][ypos + randomJ] = std::make_unique<Water>(&map);
                    break;
                
                default:
                    break;
            }
        }
        loop--;
    }
}

void    processClick(std::vector<std::vector<std::unique_ptr<AElement> > > &map)
{
    double xpos;
    double ypos;
    glfwGetCursorPos(window, &xpos, &ypos);
    xpos = (int)xpos / squareSize;
    ypos = (int)ypos /  squareSize;

    if (deleteMode == true)
        deleteParticule(map, xpos, ypos);
    else
        addParticules(map, xpos, ypos);
}
