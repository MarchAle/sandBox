#include "../incs/sandbox.hpp"

void    deleteParticule(double xpos, double ypos)
{
    if (xpos >= 0 && xpos <= WIN_WIDTH && ypos > 0 && ypos <= WIN_HEIGHT)
    {
        map[xpos][ypos].set_free_as(true);
        map[xpos][ypos].set_particule_type(-1);
    }
}

void    addParticules(double xpos, double ypos)
{
    for (int i = -spread / 2; i < spread / 2; i++)
    {
        for (int j = -spread / 2; j < spread / 2; j++)
        {
            if ((i + j) % 2 && (xpos + i >= 0 && xpos + i <= WIN_WIDTH / PARTICULE_SIZE && ypos + j > 0 && ypos + j <= WIN_HEIGHT / PARTICULE_SIZE))
            {
                map[xpos + i][ypos + j].set_free_as(false);
                map[xpos + i][ypos + j].set_particule_type(currentParticuleType);
            }
        }
    }
}

void    processClick()
{
    double xpos;
    double ypos;
    glfwGetCursorPos(window, &xpos, &ypos);
    xpos = (int)xpos / squareSize;
    ypos = (int)ypos /  squareSize;

    if (deleteMode == true)
        deleteParticule(xpos, ypos);
    else
        addParticules(xpos, ypos);
}
