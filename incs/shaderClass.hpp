#ifndef SHADERCLASS_HPP
# define SHADERCLASS_HPP

// # include <GLES2/gl2.h>
#include <GL/glew.h>

// # include <EGL/egl.h>
# include <string>
# include <fstream>
# include <sstream>
# include <iostream>
# include <cerrno>

std::string get_file_contents(const char *filename);

class shaderClass
{
    public:
        int     success;
        char    infoLog[512];
        GLuint  ID;
        shaderClass(const char *vertexFile, const char *fragmentFile);

        void Activate();
        void Delete();
};

#endif