#ifndef MODEL_FACE_H
#define MODEL_FACE_H

#include <glad/glad.h>
#include <glm/glm.hpp>

#include <array>

const struct ModelFace {
	 std::array<GLfloat, 12> &blockFace;
	 std::array<GLfloat, 8> &texCoords;
	 glm::vec3 &chunkPosition;
	 glm::vec3 &blockPosition;
};

#endif