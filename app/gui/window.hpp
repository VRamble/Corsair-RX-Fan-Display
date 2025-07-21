#pragma once

#include <GL/gl.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>

namespace gui {
class Window {
  public:
    Window(const char *title, const unsigned int width,
           const unsigned int height);
    ~Window();
    bool isInitialized() const;
    SDL_Window *getSDLWindow() const;
    SDL_GLContext getGLContext() const;
    void clear();
    void swap_buffers();

  private:
    SDL_Window *window;
    SDL_GLContext glContext;
    bool initialized;
};
} // namespace gui
