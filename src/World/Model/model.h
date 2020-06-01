#ifndef MODEL_H
#define MODEL_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>

#include "Renderer/render_data.h"

class Model {
public:
    Model() = default;
    Model(const std::vector<GLfloat> vertexPositions, const std::vector<GLfloat> textureCoordinates, const std::vector<GLuint> indices);
    ~Model();
    
    //copy constructor and equals methods
    //Voxel(Voxel &&other);
    //Voxel &operator=(Voxel &&other);
    
    void addData(const std::vector<GLfloat> vertexPositions, const std::vector<GLfloat> textureCoordinates, const std::vector<GLuint> indices);
    void deleteData();
    void genVAO();
    void addEBO(const std::vector<GLuint> &indices);
    void addVBO(int dimensions, const std::vector<GLfloat> &data);
    void bindVAO();
    RenderData* getRenderData();
private:
    RenderData renderData;
    int numVBOs{0};
    std::vector<GLuint> VBOs;
    
};

#endif

