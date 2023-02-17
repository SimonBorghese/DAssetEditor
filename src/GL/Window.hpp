#ifndef GLWINDOW
#define GLWINDOW
#include <SDL2/SDL.h>
#include "../../extern/include/glad/glad.h"

class Window{
	public:
		Window(uint32_t width, uint32_t height);
		virtual ~Window() = default;

		void createWindow();
		void flipWindow();
		void destroyWindow();
	private:
		uint32_t _width, _height;
		SDL_Window *_window;
		SDL_GLContext _context;
};

#endif