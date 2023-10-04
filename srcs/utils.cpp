#include "../incs/sandbox.hpp"
#include "../incs/shaderClass.hpp"

int    initLibraries()
{
    // Initialize GLFW
    if (!glfwInit())
    {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return (1);
    }
    // Create a GLFW window
    window = glfwCreateWindow(WIN_WIDTH, WIN_HEIGHT, "SandBox", nullptr, nullptr);
    if (!window)
    {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return (1);
    }
    glfwMakeContextCurrent(window);
    // Initialize GLEW
    if (glewInit() != GLEW_OK)
    {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        return (1);
    }
    return (0);
}

void    setUpOpenGl()
{
    // Set up VBO, VAO, and EBO
    glGenBuffers(1, &VBO);
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &EBO);
    glBindVertexArray(VAO);

    // Create and Use shaderProgram
    shaderClass shaderProgram("srcs/shaders/default.vert", "srcs/shaders/default.frag");

    // Set up OpenGL options
    glClearColor(0.2f, 0.2f, 0.3f, 1.0f);
    // Register mouse button callback
    glfwSetMouseButtonCallback(window, mouse_button_callback);
    // Register keyboard key callback
    glfwSetKeyCallback(window, key_callback);
}

void    cleanUp()
{
    // Cleanup
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    glfwTerminate();
}