#include "model.h"
#include <iostream>

Model::Model(const std::vector<GLfloat> vertexPositions, const std::vector<GLfloat> textureCoordinates, const std::vector<GLuint> indices) {
    //addData(vertexPositions, textureCoordinates, indices);
}

Model::~Model() {
    deleteData();
}

RenderData* Model::getRenderData() {
    return &renderData;
}

void Model::addData(const std::vector<GLfloat> vertexPositions, const std::vector<GLfloat> textureCoordinates, const std::vector<GLuint> indices) {
    genVAO();
    addVBO(3, vertexPositions);
    addVBO(2, textureCoordinates);
    addEBO(indices);
}

void Model::deleteData() {
    if (renderData.hasVAO()) {
        glDeleteVertexArrays(1, renderData.getVAO());
    }
    if (VBOs.size() > 0) {
        glDeleteBuffers(static_cast<GLsizei>(VBOs.size()),
        VBOs.data());
    }
    VBOs.clear();
    numVBOs = 0;
    renderData.resetData();
}

void Model::genVAO() {
    //deleteData();

    if (renderData.hasVAO()) {
        //std::cout << "called" << std::endl;
        deleteData();
    }
    glGenVertexArrays(1, renderData.getVAO());
    glBindVertexArray(*renderData.getVAO());
    //std::cout << glGetError() << " 8" << std::endl;

}

void Model::bindVAO() {
    glBindVertexArray(*renderData.getVAO());
    //std::cout << glGetError() << " 7" << std::endl;

}

void Model::addVBO(int size, const std::vector<GLfloat> &data) {
    GLuint VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(GLfloat), data.data(),
                 GL_STATIC_DRAW);
    glVertexAttribPointer(static_cast<GLuint>(numVBOs), size, GL_FLOAT,
                          GL_FALSE, 0, (GLvoid *)0);
    glEnableVertexAttribArray(static_cast<GLuint>(numVBOs++));
    VBOs.push_back(VBO);
    //std::cout << glGetError() << " 6" << std::endl;

}

void Model::addEBO(const std::vector<GLuint> &indices) {
    *renderData.getIndices() = static_cast<GLuint>(indices.size());
    //std::cout << glGetError() << " 1" << std::endl;
    GLuint EBO;
    //std::cout << glGetError() << " 2" << std::endl;

    glGenBuffers(1, &EBO);
    //std::cout << glGetError() << " 3" << std::endl;


    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    //std::cout << glGetError() << " 4" << std::endl;

    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint),
                 indices.data(), GL_STATIC_DRAW);

    //std::cout << glGetError() << " 5" << std::endl;

}


