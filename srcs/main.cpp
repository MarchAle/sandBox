#include "../incs/sandbox.hpp"
#include "../incs/Air.hpp"
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
            if ((*map[i][j]).get_particule_type() != AIR)
            {
                particules.emplace_back((((float)i * squareSize) / (WIN_WIDTH / 2) - 1.0), -((float)j * squareSize / (WIN_HEIGHT / 2) - 1.0));
                // if ((*map[i][j]).isFalling() == true)
                // {
                //     for (int k = 0; k < 4; k++)
                //         colors.insert(colors.end(), {1, 0, 0});
                // }
                // else
                // {
                    for (int k = 0; k < 4; k++)
                        colors.insert(colors.end(), {(*map[i][j]).get_color()[0], (*map[i][j]).get_color()[1], (*map[i][j]).get_color()[2]});
                // }
            }
        }
    }
}

void    updateMap(std::vector<std::vector<std::unique_ptr<AElement> > > &map)
{
    for (int y = (int)map[0].size() - 1; y >= 0; y--)
    {
        for (int x = 0; x < (int)map.size() - 1; x++)
        {
            (*map[x][y]).moveElement(map, x, y);
            ///// correctif pour les cas ou des particules restaient bloquées en not falling au dessus d'un vide
            if (isValidCoordonate(map, x, y + 1) && (*map[x][y]).isFalling() == false && (*map[x][y + 1]).get_particule_state() == LIQUID)
            {
                (*map[x][y]).setFallingAs(true);
                (*map[x][y]).y_velocity = 1;
            }
        }
    }
}

void    updateVelocity(std::vector<std::vector<std::unique_ptr<AElement> > > &map)
{
    for (int y = (int)map[0].size() - 1; y >= 0; y--)
    {
        for (int x = 0; x < (int)map.size() - 1; x++)
        {
            if ((*map[x][y]).get_particule_state() == SOLID)
            {
                (*map[x][y]).y_velocity *= GRAVITY;
                // std::cout << (*map[x][y]).y_velocity << std::endl;
            }
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
            map[i].push_back(std::make_unique<Air>());
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
        updateVelocity(map);
    }
    cleanUp();
    return 0;
}


