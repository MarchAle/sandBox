#include "../incs/sandbox.hpp"
#include "../incs/particule.hpp"

void render(float &glParticuleWidth, float &glParticuleHeight)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBindVertexArray(VAO);
    std::vector<GLfloat>    allVertices;  // Store all vertices for all squares
    std::vector<GLuint>     indices;      // Indices for drawing
    for (auto& particule : particules) {
        GLfloat particuleVertices[] = {
            particule.getX(), particule.getY() - 2 * glParticuleHeight,
            particule.getX() + 2 * glParticuleWidth, particule.getY() - 2 * glParticuleHeight,
            particule.getX() + 2 * glParticuleWidth, particule.getY(),
            particule.getX(), particule.getY()
        };
        // Append square vertices to the allVertices vector
        allVertices.insert(allVertices.end(), particuleVertices, particuleVertices + 8);

        // Define indices for drawing the square
        GLuint baseIndex = (GLuint)allVertices.size() / 2 - 4;
        GLuint squareIndices[] = {
            baseIndex, baseIndex + 1, baseIndex + 2,
            baseIndex, baseIndex + 2, baseIndex + 3
        };
        indices.insert(indices.end(), squareIndices, squareIndices + 6);
    }
    // std::cout << "particules :\t" << particules.size() << std::endl;
    // std::cout << "allVertices :\t" << allVertices.size() << std::endl;
    // std::cout << "indices :\t" << indices.size() << std::endl;
    // std::cout << "colors :\t" << colors.size() << std::endl << std::endl;
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, allVertices.size() * sizeof(GLfloat), allVertices.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), indices.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), (void*)0);
    glEnableVertexAttribArray(0);
    // Specify color attribute
        //Buffer for color
    glGenBuffers(1, &VBO_colors);
    glBindBuffer(GL_ARRAY_BUFFER, VBO_colors);
    glEnableVertexAttribArray(1);

    glBufferData(GL_ARRAY_BUFFER, (colors.size())*sizeof(float), colors.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0); //size = 3 (R,G,B)

    // GLuint colorLocation = 1;  // Location of the color attribute in the vertex shader
    // glVertexAttribPointer(colorLocation, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)(particules.size() * 8 * sizeof(GLfloat)));
    // glEnableVertexAttribArray(1);
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
    glfwSwapBuffers(window);
}