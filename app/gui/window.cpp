#include "window.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>
#include <iostream>

namespace gui {
Window::Window(const char *title, const unsigned int width,
               const unsigned int height) {

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL_Init failed: " << SDL_GetError() << std::endl;
        initialized = false;
        return;
    }

    window =
        SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                         width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

    if (!window) {
        std::cerr << "Failed to create window: " << SDL_GetError() << std::endl;
        return;
    }

    glContext = SDL_GL_CreateContext(window);
    if (!glContext) {
        std::cerr << "Failed to create GL context: " << SDL_GetError()
                  << std::endl;
        return;
    }
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, height, 0, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glDisable(GL_DEPTH_TEST);

    SDL_GL_SetSwapInterval(1); // Enables V-Sync
    initialized = true;
}

Window::~Window() {
    if (glContext)
        SDL_GL_DeleteContext(glContext);
    if (window)
        SDL_DestroyWindow(window);
    SDL_Quit();
}

void Window::clear() {
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}
void Window::swap_buffers() { SDL_GL_SwapWindow(window); }

bool Window::isInitialized() const { return initialized; }
SDL_Window *Window::getSDLWindow() const { return window; }
SDL_GLContext Window::getGLContext() const { return glContext; }
} // namespace gui
