#ifndef VBO_HPP
# define VBO_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class VBO
{
    public:
        GLuint ID;
        VBO(GLfloat *vertices, GLsizeiptr size);

        void Bind();
        void Unbind();
        void Delete();
};

#endif