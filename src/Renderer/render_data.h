#ifndef RENDER_DATA_H
#define RENDER_DATA_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class RenderData {
public:
    RenderData();
    GLuint* getVAO();
    GLuint* getIndices();
    void resetData();
    bool hasVAO();
    bool hasIndices();
private:
    GLuint VAO;
    GLuint indices;
};


#endif
