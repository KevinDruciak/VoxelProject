#ifndef CHUNK_SHADER_H
#define CHUNK_SHADER_H

#include "shader.h"

class ChunkShader : public Shader {
public:
    ChunkShader(const std::string& vertexShader = "C:/Users/bakad/Desktop/VoxelProject/VoxelProject/VoxelProject/Shaders/shader.vs", const std::string& fragmentShader = "C:/Users/bakad/Desktop/VoxelProject/VoxelProject/VoxelProject/Shaders/shader.fs");
    
    void setModelLocation(const glm::mat4& model);
    void setViewLocation(const glm::mat4& view);
    void setProjectionLocation(const glm::mat4& projection);
    //void getUniforms();

private:
    const std::string modelLocation = "model";
    const std::string viewLocation = "view";
    const std::string projectionLocation = "projection";
};
#endif
