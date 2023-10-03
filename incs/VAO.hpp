#ifndef VAO_HPP
# define VAO_HPP

# include <GLES2/gl2.h>
# include <EGL/egl.h>
# include "VBO.hpp"

class VAO
{
    public:
        GLuint ID;
        VAO();

        void LinkBVO(VBO VBO, GLuint layout);
        void Bind();
        void Unbind();
        void Delete();
};

#endif