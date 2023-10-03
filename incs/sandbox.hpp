#ifndef SANDBOX_HPP
# define SANDBOX_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cerrno>
#include <stdexcept>
#include <string>
#include <vector>
#include <array>
#include <random>
#include <unistd.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "../incs/Sand.hpp"
#include "../incs/particule.hpp"
#include "../incs/shaderClass.hpp"

#define WIN_WIDTH 1000
#define WIN_HEIGHT 800
#define PARTICULE_SIZE 5
#define SPREAD_SIZE 5

typedef std::vector<std::vector<AElement> > Map;

extern int  squareSize;
extern int  spread;
extern int  currentParticuleType;
extern bool buttonPress;
extern bool deleteMode;
// extern Map  map;
extern std::vector<Particule>          particules;
extern std::vector<GLfloat>            colors;
extern GLuint                          VBO, VAO, EBO, VBO_colors;
extern GLFWwindow*                     window;

// std::vector<std::array<float, 3> > colorsVector = {{0.0f, 1.0f, 0.0f} , {1.0f, 0.0f, 0.0f}};
// float   colorsArray[][] = {{1.0f, 0.0f, 0.0f} , {0.0f, 1.0f, 0.0f}};

int     initLibraries();
void    setUpOpenGl();
void    cleanUp();

void    processClick();

void    render(float &glParticuleWidth, float &glParticuleHeight);

void    mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
void    key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);


#endif