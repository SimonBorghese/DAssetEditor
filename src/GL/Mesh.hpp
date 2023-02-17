#ifndef GLMESH
#define GLMESH
#include <glm/glm.hpp>
#include <glad/glad.h>
#include <vector>

class Mesh{
	public:
		typedef struct{
			glm::vec3 position;
		} vertex_t;
		Mesh(vertex_t *vertices, uint32_t numVertices,
				 uint32_t *indices,	 uint32_t numIndices);

		Mesh(std::vector<vertex_t> vertices,
				 std::vector<uint32_t> indices);
		virtual ~Mesh() = default;

		void createMesh();
		void renderMesh();
		void destroyMesh();

	private:
		std::vector<vertex_t> _vertices;
		std::vector<uint32_t> _indices;

		GLuint _VAO = 0;
		GLuint _VBO = 0;
		GLuint _EBO = 0;
};

#endif