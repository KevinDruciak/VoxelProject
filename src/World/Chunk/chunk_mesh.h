#ifndef CHUNK_MESH_H
#define CHUNK_MESH_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>

#include "World/Model/model_face.h"
#include "Renderer/render_data.h"
#include "World/Model/model.h" 

class ChunkMesh {
public:
	ChunkMesh() = default;
	ChunkMesh(std::vector<ModelFace>& faces);

	void addFace(std::vector<ModelFace>& faces);
	void loadModel();

	const Model &getModel();
	void deleteData();
	unsigned getNumFaces();

private:
	Model model;
	unsigned numFaces;
	unsigned indexCount{ 0 };

	std::vector<GLfloat> vertexPositions;
	std::vector<GLfloat> textureCoordinates;
	std::vector<GLuint> indices;
};

#endif

