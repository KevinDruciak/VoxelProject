#include "chunk_shader.h"

ChunkShader::ChunkShader(const std::string& vertexShader, const std::string& fragmentShader) {
    Shader(vertexShader.c_str(), fragmentShader.c_str());
    use();
}

void ChunkShader::setModelLocation(const glm::mat4& model) {
    setMat4(modelLocation, model);
}

void ChunkShader::setViewLocation(const glm::mat4& view) {
    setMat4(viewLocation, view);
}

void ChunkShader::setProjectionLocation(const glm::mat4& projection) {
    setMat4(projectionLocation, projection);
}
