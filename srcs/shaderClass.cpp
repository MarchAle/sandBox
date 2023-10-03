#include "../incs/shaderClass.hpp"

std::string get_file_contents(const char *filename)
{
    std::ifstream in(filename, std::ios::binary);
    if (in)
    {
        std::string contents;
        in.seekg(0, std::ios::end);
        contents.resize(in.tellg());
        in.seekg(0, std::ios::beg);
        in.read(&contents[0], contents.size());
        in.close();
        return(contents);
    }
    throw(errno);
}

shaderClass::shaderClass(const char *vertexFile, const char *fragmentFile) : success(0)
{
    std::string vertexCode = get_file_contents(vertexFile);
    std::string fragmentCode = get_file_contents(fragmentFile);

    const char *vertexSource = vertexCode.c_str();
    const char *fragmentSource = fragmentCode.c_str();

    // Compile and link shaders
    // Create Vertex Shader Object and get reference
    GLuint vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    // Attach VertexShader source to the Vertex Shader Object
    glShaderSource(vertexShader, 1, &vertexSource, NULL);
    // Compile the vertex Shader into machine code
    glCompileShader(vertexShader);
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "Vertex shader Compilation Failed : " << infoLog << std::endl;
    }

    // Create Fragment Shader Object and get reference
    GLuint fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    // Attach FragmentShader source to the Fragment Shader Object
    glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
    // Compile the Fragment Shader into machine code
    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "Fragment shader Compilation Failed : " << infoLog << std::endl;
    }

    // Create Shader Program Object and get its reference
    GLuint ID = glCreateProgram();
    // Attach the Vertex and Fragment Shaders to the Shader Program
    glAttachShader(ID, vertexShader);
    glAttachShader(ID, fragmentShader);
    // Wrap-up/link all the shaders together into the Shader Program
    glLinkProgram(ID);
    glGetShaderiv(ID, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(ID, 512, NULL, infoLog);
        std::cout << "Shader Program link Failed : " << infoLog << std::endl;
    }

    // Delete the shaders because now they are in th program
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    glUseProgram(ID);
}

void shaderClass::Activate()
{
    glUseProgram(ID);
}

void shaderClass::Delete()
{
    glDeleteProgram(ID);
}