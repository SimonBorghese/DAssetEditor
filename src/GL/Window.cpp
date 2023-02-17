#include "Window.hpp"

Window::Window(uint32_t width, uint32_t height) : _width(width), _height(height){}

void Window::createWindow(){
	SDL_Init(SDL_INIT_EVERYTHING);

	_window = SDL_CreateWindow("DAsset Editor", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, _width, _height, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);

	_context = SDL_GL_CreateContext(_window);
	SDL_GL_MakeCurrent(_window, _context);
	gladLoadGLLoader((GLADloadproc) SDL_GL_GetProcAddress);
	glViewport(0,0,_width,_height);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);
	
}
void Window::flipWindow(){
	SDL_GL_SwapWindow(_window);
	SDL_UpdateWindowSurface(_window);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
void Window::destroyWindow(){
	SDL_GL_DeleteContext(_context);
	SDL_DestroyWindow(_window);
	SDL_Quit();
}