#include "../incs/sandbox.hpp"
#include "../incs/Element.hpp"
#include "../incs/Void.hpp"
#include "../incs/Air.hpp"
#include "../incs/Sand.hpp"
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
                map[xpos + i][ypos + j] = std::make_unique<Air>();
            }
        }
    }
}

void    addParticules(std::vector<std::vector<std::unique_ptr<AElement> > > &map, double xpos, double ypos)
{
    for (int i = -spread / 2; i < spread / 2; i++)
    {
        for (int j = -spread / 2; j < spread / 2; j++)
        {
            if (isValidCoordonate(map, xpos + i, ypos + j))
            {
                switch (currentParticuleType)
                {
                case SAND:
                    map[xpos + i][ypos + j] = std::make_unique<Sand>();
                    break;
                case STONE:
                    map[xpos + i][ypos + j] = std::make_unique<Stone>();
                    break;
                case AIR:
                    map[xpos + i][ypos + j] = std::make_unique<Air>();
                    break;
                case WATER:
                    map[xpos + i][ypos + j] = std::make_unique<Water>();
                    break;
                
                default:
                    break;
                }
            }
        }
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
