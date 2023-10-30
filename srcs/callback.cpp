#include "../incs/sandbox.hpp"

void    mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_LEFT) {
        if (action == GLFW_PRESS)
            buttonPress = true;
        else if (action == GLFW_RELEASE)
            buttonPress = false;
    }
    (void)window;
    (void)mods;
    (void)action;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (action == GLFW_PRESS)
    {
        switch (key)
        {
            case 68:
                deleteMode = true;
                break;
            case 78:
                currentParticuleType = SNOW;
                break;
            case 81:
                currentParticuleType = AIR;
                break;
            case 82:
                currentParticuleType = STONE;
                break;
            case 83:
                currentParticuleType = SAND;
                break;
            case 90:
                currentParticuleType = WATER;
                break;
            
            default:
                break;
        }
        if (key != 68)
            deleteMode = false;
    }
    (void)window;
    (void)mods;
    (void)scancode;
}