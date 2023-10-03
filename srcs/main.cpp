#include "../incs/sandbox.hpp"
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

void    buildParticulesVector(Map &map)
{
    GLfloat r, g, b;
    particules.clear();
    colors.clear();
    for (size_t i = 0; i < map.size(); i++)
    {
        for (size_t j = 0; j < map[0].size(); j++)
        {
            if (map[i][j].is_free() == false)
            {
                particules.emplace_back((((float)i * squareSize) / (WIN_WIDTH / 2) - 1.0), -((float)j * squareSize / (WIN_HEIGHT / 2) - 1.0));
                if (map[i][j].get_particule_type() == SAND)
                {
                    r = 1;
                    g = 0;
                    b = 0;
                }
                else
                {
                    r = 0;
                    g = 1;
                    b = 0;
                }
                for (int i = 0; i < 4; i++)
                    colors.insert(colors.end(), {r, g, b});
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

void    updateMap(Map &map)
{
    for (int y = (int)map[0].size() - 3; y >= 0; y--)
    {
        for (int x = 0; x < (int)map.size() - 1; x++)
        {
            if (map[x][y].get_particule_type() == SAND)
                move_sand(x, y);
        }
    }
}

int main()
{
    Map map;
    map.resize(WIN_WIDTH / squareSize + 1);
    for (size_t i = 0; i < map.size(); i++)
        map[i].resize(WIN_HEIGHT / squareSize + 1);

    float glParticuleWidth = (float)squareSize / WIN_WIDTH;
    float glParticuleHeight = (float)squareSize / WIN_HEIGHT;

    if (initLibraries() == 1)
        return (1);

    setUpOpenGl();

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        if (buttonPress == true)
            processClick();
        buildParticulesVector(map);
        render(glParticuleWidth, glParticuleHeight);
        updateMap(map);
    }
    cleanUp();
    return 0;
}


