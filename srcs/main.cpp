#include "../incs/sandbox.hpp"
#include "../incs/Void.hpp"
#include "../incs/Sand.hpp"
#include "../incs/particule.hpp"
#include "../incs/shaderClass.hpp"

int squareSize = PARTICULE_SIZE;
int spread = SPREAD_SIZE;
int currentParticuleType = SAND;
bool buttonPress = false;
bool deleteMode = false;
// Map map;
std::vector<Particule>          particules;
std::vector<GLfloat>            colors;
GLuint                          VBO, VAO, EBO, VBO_colors;
GLFWwindow*                     window;

std::random_device rd;  // Initialize a random device to seed the generator
std::mt19937 gen(rd()); // Create a Mersenne Twister pseudo-random generator

void    buildParticulesVector(std::vector<std::vector<std::unique_ptr<AElement> > > &map)
{
    // GLfloat r, g, b;
    particules.clear();
    colors.clear();
    for (size_t i = 0; i < map.size(); i++)
    {
        for (size_t j = 0; j < map[0].size(); j++)
        {
            if ((*map[i][j]).get_particule_type() == 1)
            {
                particules.emplace_back((((float)i * squareSize) / (WIN_WIDTH / 2) - 1.0), -((float)j * squareSize / (WIN_HEIGHT / 2) - 1.0));
                // if ((*map[i][j]).get_particule_type() == SAND)
                // {
                //     r = 1;
                //     g = 0;
                //     b = 0;
                // }
                // else
                // {
                //     r = 0;
                //     g = 1;
                //     b = 0;
                // }
                // if ((*map[i][j]).get_particule_type() == 1)
                if ((*map[i][j]).isFalling() == true)
                {
                    for (int k = 0; k < 4; k++)
                        colors.insert(colors.end(), {1, 0, 0});
                }
                else
                {
                    for (int k = 0; k < 4; k++)
                        colors.insert(colors.end(), {(*map[i][j]).get_color()[0], (*map[i][j]).get_color()[1], (*map[i][j]).get_color()[2]});
                }
                    
                    // colors.insert(colors.end(), {r, g, b});
                    // colors.insert(colors.end(), colorsVector[map[i][j].get_particule_type()].begin(), colorsVector[map[i][j].get_particule_type()].end());
            }
        }
    }
}

// void    move_sand(int &x, int &y)
// {
//     if (map[x][y + 1].is_free() == true)
//     {
//         map[x][y + 1].set_free_as(false);
//         map[x][y + 1].set_particule_type(map[x][y].get_particule_type());
//         map[x][y].set_free_as(true);
//         map[x][y].set_particule_type(AIR);
//     }
//     else
//     {
//         std::uniform_int_distribution<int> dist(-1, 1);
//         int randomValue = dist(gen);
//         if (map[x + randomValue][y + 1].is_free() == true && map[x + randomValue][y].is_free() == true)
//         {
//             map[x + randomValue][y + 1].set_free_as(false);
//             map[x + randomValue][y + 1].set_particule_type(map[x][y].get_particule_type());
//             map[x][y].set_free_as(true);
//             map[x][y].set_particule_type(AIR);
//         }
//         else if (map[x - randomValue][y + 1].is_free() == true && map[x - randomValue][y].is_free() == true)
//         {
//             map[x - randomValue][y + 1].set_free_as(false);
//             map[x - randomValue][y + 1].set_particule_type(map[x][y].get_particule_type());
//             map[x][y].set_free_as(true);
//             map[x][y].set_particule_type(AIR);
//         }
//     }
// }

void    updateMap(std::vector<std::vector<std::unique_ptr<AElement> > > &map)
{
    for (int y = (int)map[0].size() - 3; y >= 0; y--)
    {
        for (int x = 0; x < (int)map.size() - 1; x++)
        {
            // if (map[x][y].get_particule_type() != AIR)
            //     // move_sand(x, y);
            (*map[x][y]).moveElement(map, x, y);
        }
    }
}

int main()
{
    std::vector<std::vector<std::unique_ptr<AElement> > > map;
    map.resize(WIN_WIDTH / squareSize + 1);
    for (size_t i = 0; i < map.size(); i++)
    {
        for (int j = 0; j < WIN_HEIGHT / squareSize + 1; j++)
        {
            map[i].push_back(std::make_unique<Void>());
            // map[i].resize(WIN_HEIGHT / squareSize + 1, std::make_unique<Sand>());

        }
    }

    float glParticuleWidth = (float)squareSize / WIN_WIDTH;
    float glParticuleHeight = (float)squareSize / WIN_HEIGHT;

    if (initLibraries() == 1)
        return (1);

    setUpOpenGl();

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        if (buttonPress == true)
            processClick(map);
        buildParticulesVector(map);
        render(glParticuleWidth, glParticuleHeight);
        updateMap(map);
    }
    cleanUp();
    return 0;
}


