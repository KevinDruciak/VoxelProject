#include "voxel_shader.h"

VoxelShader::VoxelShader(const std::string& vertexShader, const std::string& fragmentShader) {
    Shader(vertexShader.c_str(), fragmentShader.c_str());
    use();
}

void VoxelShader::setModelLocation(const glm::mat4& model) {
    setMat4(modelLocation, model);
}

void VoxelShader::setViewLocation(const glm::mat4& view) {
    setMat4(viewLocation, view);
}

void VoxelShader::setProjectionLocation(const glm::mat4& projection) {
    setMat4(projectionLocation, projection);
}
