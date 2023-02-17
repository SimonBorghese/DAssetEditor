#include "Shader.hpp"

Shader::Shader(const char *vertex, const char *fragment) :
_vertexShader(vertex), _fragmentShader(fragment) {}
Shader::Shader(std::string vertex, std::string fragment) : 
_vertexShader(vertex), _fragmentShader(fragment) {}

void Shader::createShader(){
	uint32_t vertexLength = 0, fragmentLength = 0;
	char *vertexShader = nullptr, *fragmentShader = nullptr;
	FILE *file = fopen(_vertexShader.c_str(), "r");
	fseek(file, 0, SEEK_END);
	vertexLength = ftell(file);
	fseek(file, 0, SEEK_SET);
	vertexShader = (char*) malloc(sizeof(char) * (vertexLength + 1));
	fread(vertexShader, sizeof(char), vertexLength, file);
	fclose(file);
	vertexShader[vertexLength] = '\0';

	file = fopen(_fragmentShader.c_str(), "r");
	fseek(file, 0, SEEK_END);
	fragmentLength = ftell(file);
	fseek(file, 0, SEEK_SET);
	fragmentShader = (char*) malloc(sizeof(char) * (fragmentLength + 1));
	fread(fragmentShader, sizeof(char), fragmentLength, file);
	fclose(file);
	fragmentShader[fragmentLength] = '\0';

	GLuint gVertexShader, gFragmentShader;
	gVertexShader = glCreateShader(GL_VERTEX_SHADER);
	gFragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	_shaderProgram = glCreateProgram();
	glShaderSource(gVertexShader, 1, &vertexShader, nullptr);
	glShaderSource(gFragmentShader, 1, &fragmentShader, nullptr);
	glCompileShader(gVertexShader);
	glCompileShader(gFragmentShader);
	int success;
  char infoLog[512];

  glGetShaderiv(gVertexShader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(gVertexShader, 512, nullptr, infoLog);
		printf("FAILED TO BUILD VERTEX SHADER: %s\n", infoLog);
  }

	glGetShaderiv(gFragmentShader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(gFragmentShader, 512, nullptr, infoLog);
		printf("FAILED TO BUILD FRAGMENT SHADER: %s\n", infoLog);
  }

	glAttachShader(_shaderProgram, gVertexShader);
	glAttachShader(_shaderProgram, gFragmentShader);
	glLinkProgram(_shaderProgram);

	glGetProgramiv(_shaderProgram, GL_LINK_STATUS, &success);
  if (!success) {
    glGetProgramInfoLog(_shaderProgram, 512, nullptr, infoLog);
		printf("FAILED TO LINK SHADER: %s\n", infoLog);
  }
	glDeleteShader(gVertexShader);
	glDeleteShader(gFragmentShader);
	free(vertexShader);
	free(fragmentShader);
}
void Shader::useShader(){
	glUseProgram(_shaderProgram);
}
void Shader::deleteShader(){
	glDeleteProgram(_shaderProgram);
}