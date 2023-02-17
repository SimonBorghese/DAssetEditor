#ifndef GLSHADER
#define GLSHADER
#include <glad/glad.h>
#include <cstdio> // C file opening lel
#include <string>

class Shader{
	public:
		Shader(const char *vertex, const char *fragment);
		Shader(std::string vertex, std::string fragment);
		virtual ~Shader() = default;

		void createShader();
		void useShader();
		void deleteShader();

	private:
		std::string _vertexShader;
		std::string _fragmentShader;

		GLuint _shaderProgram = 0;
};

#endif