#pragma once

#include <SDL2/SDL.h>

class EventLoop {
  public:
    EventLoop();
    ~EventLoop();

    bool pollEvents();
    bool shouldQuit() const;

  private:
    bool quit = false;

    void handleEvent(SDL_Event &e);
};
