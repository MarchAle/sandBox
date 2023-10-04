#include "../incs/sandbox.hpp"
#include "../incs/Element.hpp"
#include "../incs/Void.hpp"
#include "../incs/Sand.hpp"

void    deleteParticule(std::vector<std::vector<std::unique_ptr<AElement> > > &map, double xpos, double ypos)
{
    if (xpos >= 0 && xpos <= WIN_WIDTH && ypos > 0 && ypos <= WIN_HEIGHT)
    {
        map[xpos][ypos] = std::make_unique<Void>();
        // map[xpos][ypos].set_free_as(true);
        // map[xpos][ypos].set_particule_type(-1);
    }
}

void    addParticules(std::vector<std::vector<std::unique_ptr<AElement> > > &map, double xpos, double ypos)
{
    if ((xpos >= 0 && xpos <= WIN_WIDTH / PARTICULE_SIZE && ypos > 0 && ypos <= WIN_HEIGHT / PARTICULE_SIZE))
    {
        switch (currentParticuleType)
        {
        case SAND:
            map[xpos][ypos] = std::make_unique<Sand>();
            break;
        case AIR:
            map[xpos][ypos] = std::make_unique<Void>();   /////////////// TO CHANGE TO AIR
            break;
        
        default:
            break;
        }
    }
    // for (int i = -spread / 2; i < spread / 2; i++)
    // {
    //     for (int j = -spread / 2; j < spread / 2; j++)
    //     {
    //         if ((i + j) % 2 && (xpos + i >= 0 && xpos + i <= WIN_WIDTH / PARTICULE_SIZE && ypos + j > 0 && ypos + j <= WIN_HEIGHT / PARTICULE_SIZE))
    //         {
    //             switch (currentParticuleType)
    //             {
    //             case SAND:
    //                 map[xpos + i][ypos + j] = std::make_unique<Sand>();
    //                 break;
    //             case AIR:
    //                 map[xpos + i][ypos + j] = std::make_unique<Void>();   /////////////// TO CHANGE TO AIR
    //                 break;
                
    //             default:
    //                 break;
    //             }
    //             // map[xpos + i][ypos + j].set_free_as(false);
    //             // map[xpos + i][ypos + j].set_particule_type(currentParticuleType);
    //         }
    //     }
    // }
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
