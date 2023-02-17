#include "GL/Window.hpp"
#include "GL/Shader.hpp"
#include "GL/Mesh.hpp"

int main(){
	Mesh::vertex_t vertexArray[3] = {
		glm::vec3(-1.0f, -1.0f, 0.0f),
		glm::vec3(1.0f, -1.0f, 0.0f),
		glm::vec3(0.0f, 1.0f, 0.0f)
	};
	uint32_t indices[3] = {0,1,2};
	Window *coolWin = new Window(250,250);
	coolWin->createWindow();

	Mesh *triangle = new Mesh(vertexArray, 3, indices, 3);
	triangle->createMesh();

	Shader *shader = new Shader("Shaders/debugV.glsl", "Shaders/debugF.glsl");
	shader->createShader();
	while (1){
		shader->useShader();
		triangle->renderMesh();
		coolWin->flipWindow();
	}
	coolWin->destroyWindow();
	return 0;
}