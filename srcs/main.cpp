#include "../incs/sandbox.hpp"
#include "../incs/Air.hpp"
#include "../incs/Void.hpp"
#include "../incs/Sand.hpp"
#include "../incs/Water.hpp"
#include "../incs/particule.hpp"
#include "../incs/shaderClass.hpp"

int squareSize = PARTICULE_SIZE;
int spread = SPREAD_SIZE;
int currentParticuleType = SAND;
bool buttonPress = false;
bool deleteMode = false;
bool shake = false;
// Map map;
std::vector<Particule>          particules;
std::vector<GLfloat>            colors;
GLuint                          VBO, VAO, EBO, VBO_colors;
GLFWwindow*                     window;

std::random_device rd;  // Initialize a random device to seed the generator
std::mt19937 gen(rd()); // Create a Mersenne Twister pseudo-random generator

void    buildParticulesVector(std::vector<std::vector<std::unique_ptr<AElement> > > &map)
{
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
                    {
                        if ((*map[i][j]).get_particule_state() == SOLID && (*map[i][j]).isWet() == true)
                            colors.insert(colors.end(), {(*map[i][j]).get_color()[0] * 0.9f, (*map[i][j]).get_color()[1] * 0.9f, (*map[i][j]).get_color()[2] * 0.9f});
                        else
                            colors.insert(colors.end(), {(*map[i][j]).get_color()[0], (*map[i][j]).get_color()[1], (*map[i][j]).get_color()[2]});
                    }
                // }
            }
        }
    }
}

void    wetSurrounding(std::vector<std::vector<std::unique_ptr<AElement> > > &map, int x, int y)
{
    if (isValidCoordonate(map, x, y + 1) && ((*map[x][y + 1]).get_particule_type() == SAND || (*map[x][y + 1]).get_particule_type() == SNOW) && (*map[x][y + 1]).isWet() == false)
        (*map[x][y + 1]).setWetAs(true);
    else if (isValidCoordonate(map, x + 1, y) && ((*map[x + 1][y]).get_particule_type() == SAND || (*map[x + 1][y]).get_particule_type() == SNOW) && (*map[x + 1][y]).isWet() == false)
        (*map[x + 1][y]).setWetAs(true);
    else if (isValidCoordonate(map, x - 1, y) && ((*map[x - 1][y]).get_particule_type() == SAND || (*map[x - 1][y]).get_particule_type() == SNOW) && (*map[x - 1][y]).isWet() == false)
        (*map[x - 1][y]).setWetAs(true);
    else if (isValidCoordonate(map, x, y - 1) && ((*map[x][y - 1]).get_particule_type() == SAND || (*map[x][y - 1]).get_particule_type() == SNOW) && (*map[x][y - 1]).isWet() == false)
        (*map[x][y - 1]).setWetAs(true);
}

void    meltSnow(std::vector<std::vector<std::unique_ptr<AElement> > > &map, int x, int y)
{
    if ((*map[x][y]).isFalling() == false && rand() / static_cast<float> (RAND_MAX) < 0.1)
        (*map[x][y]).decreaseLifeTime();
    if ((*map[x][y]).getLifeTime() <= 0)
    {
        if ((*map[x][y]).isWet() == true)
            wetSurrounding(map, x, y);
        map[x][y] = std::make_unique<Water>(&map);
    }
}

void    updateMap(std::vector<std::vector<std::unique_ptr<AElement> > > &map, int start, int end)
{
    // std::cout << "end : " << end << " " << map[0].size() << std::endl;
    for (int y = (int)map[0].size() - 1; y >= 0; y--)
    {
        for (int x = start; (x < end && x < (int)map.size()); x++)
        {
            (*map[x][y]).moveElement(x, y);
            (*map[x][y]).moveHumidity(x, y);
            if ((*map[x][y]).get_particule_type() == SNOW)
                meltSnow(map, x, y);
            ///// correctif pour les cas ou des particules restaient bloquées en not falling au dessus d'un vide
            if ((*map[x][y]).isFalling() == false && isValidCoordonate(map, x, y + 1) && (*map[x][y + 1]).get_particule_state() == LIQUID)
            {
                (*map[x][y]).setFallingAs(true);
                (*map[x][y]).y_velocity = 1;
            }
        }
    }
}

void    updateVelocity(std::vector<std::vector<std::unique_ptr<AElement> > > &map, int start, int end)
{
    for (int y = (int)map[0].size() - 1; y >= 0; y--)
    {
        for (int x = start; (x < end && x < (int)map.size()); x++)
        {
            if ((*map[x][y]).get_particule_state() == SOLID)
                (*map[x][y]).y_velocity *= GRAVITY;
        }
    }
}

void    shakeMap(std::vector<std::vector<std::unique_ptr<AElement> > > &map)
{
    for (int y = (int)map[0].size() - 1; y >= 0; y--)
    {
        for (int x = 0; x < (int)map.size() - 1; x++)
        {
            if ((*map[x][y]).get_particule_type() != STONE)
            {
                (*map[x][y]).setFallingAs(true);
                (*map[x][y]).y_velocity = 1;
            }
        }
    }
}

void    initMap(std::vector<std::vector<std::unique_ptr<AElement> > > &map)
{
    map.resize(WIN_WIDTH / squareSize + 1);
    for (size_t i = 0; i < map.size(); i++)
    {
        for (int j = 0; j < WIN_HEIGHT / squareSize + 1; j++)
            map[i].push_back(std::make_unique<Air>(&map));
    }
}

int main()
{
    float glParticuleWidth = (float)squareSize / WIN_WIDTH;
    float glParticuleHeight = (float)squareSize / WIN_HEIGHT;
    std::vector<std::vector<std::unique_ptr<AElement> > > map;
    initMap(map);

    int colWidth = map.size() / 12;
    std::vector<std::thread> threads;

    if (initLibraries() == 1)
        return (1);
    setUpOpenGl();

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        if (buttonPress == true)
            processClick(map);
        buildParticulesVector(map);
        render(glParticuleWidth, glParticuleHeight);
        // updateMap(map);
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j <= 12; j += 2)
                threads.push_back(std::thread(updateMap, std::ref(map), (j + i) * colWidth, (j + i) * colWidth + colWidth));
            for (size_t j = 0; j < threads.size(); j++)
                threads[j].join();
            threads.clear();
        }
        // updateVelocity(map);
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j <= 12; j += 2)
                threads.push_back(std::thread(updateVelocity, std::ref(map), (j + i) * colWidth, (j + i) * colWidth + colWidth));
            for (size_t j = 0; j < threads.size(); j++)
                threads[j].join();
            threads.clear();
        }
        if (shake == true)
        {
            shake = false;
            // std::cout << "Shake is disable" << std::endl;
            shakeMap(map);
        }
    }
    cleanUp();
    return 0;
}


