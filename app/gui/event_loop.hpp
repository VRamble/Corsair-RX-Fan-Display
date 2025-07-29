#pragma once

#include <SDL2/SDL.h>

class EventLoop {
  public:
    EventLoop();
    ~EventLoop();

    bool pollEvents();
    bool shouldQuit() const;
    void handleEvent(SDL_Event &e);

  private:
    bool quit = false;
};
