#version 330 core

in vec3 vertex;
out vec4 FragColor;

void main(){
	FragColor = vec4(vertex, 1.0f);
} 