#include "chunk_mesh.h"


ChunkMesh::ChunkMesh(std::vector<ModelFace>& faces) {
	addFace(faces);
}

unsigned ChunkMesh::getNumFaces() {
	return numFaces;
}

//TODO: make global constant for the CHUNK_SIZE
void ChunkMesh::addFace(std::vector<ModelFace>& faces) {
	numFaces++;
	for (auto& face : faces) {
		textureCoordinates.insert(textureCoordinates.end(), face.texCoords.begin(), face.texCoords.end());
		for (int i = 0, index = 0; i < 4; ++i) {
			vertexPositions.push_back(face.blockFace[index++] + face.chunkPosition.x * 16 +
				face.blockPosition.x);
			vertexPositions.push_back(face.blockFace[index++] + face.chunkPosition.y * 16 +
				face.blockPosition.y);
			vertexPositions.push_back(face.blockFace[index++] + face.chunkPosition.z * 16 +
				face.blockPosition.z);
		}
		indices.insert(indices.end(),
			{ indexCount, indexCount + 1, indexCount + 2,

			 indexCount + 2, indexCount + 3, indexCount });
		indexCount += 4;
	}
}

void ChunkMesh::loadModel() {
	model.addData(vertexPositions, textureCoordinates, indices);

	vertexPositions.clear();
	textureCoordinates.clear();
	indices.clear();
	vertexPositions.shrink_to_fit();
	textureCoordinates.shrink_to_fit();
	indices.shrink_to_fit();
	indexCount = 0;
}

const Model &ChunkMesh::getModel() {
	return model;
}

void ChunkMesh::deleteData() {
	model.deleteData();
}
