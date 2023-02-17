#include "Mesh.hpp"

Mesh::Mesh(vertex_t *vertices, uint32_t numVertices,
				 uint32_t *indices,	 uint32_t numIndices){
	_vertices = std::vector<vertex_t>(&vertices[0], &vertices[numVertices]);
	_indices = std::vector<uint32_t>(&indices[0], &indices[numIndices]);
}

Mesh::Mesh(std::vector<vertex_t> vertices,
				 std::vector<uint32_t> indices){
	_vertices = std::vector<vertex_t>(vertices);
	_indices = std::vector<uint32_t>(indices);
}


void Mesh::createMesh(){
	glGenVertexArrays(1, &_VAO);
	glGenBuffers(1, &_VBO);
	glGenBuffers(1, &_EBO);
	glBindVertexArray(_VAO);
	glBindBuffer(GL_ARRAY_BUFFER, _VBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _EBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_t) * _vertices.size(), _vertices.data(), GL_STATIC_DRAW);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(uint32_t) * _indices.size(), _indices.data(), GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vertex_t), nullptr);
	glEnableVertexAttribArray(0);
}
void Mesh::renderMesh(){
	glBindVertexArray(_VAO);
	glDrawElements(GL_TRIANGLES, _indices.size(), GL_UNSIGNED_INT, nullptr);
}
void Mesh::destroyMesh(){
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glDeleteBuffers(1, &_EBO);
	glDeleteBuffers(1, &_VBO);
	glDeleteVertexArrays(1, &_VAO);
}