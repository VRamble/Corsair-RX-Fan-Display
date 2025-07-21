#include "event_loop.hpp"
// #include event_loop.hpp>

#include <SDL2/SDL_events.h>
#include <SDL2/SDL_video.h>
// #include <iostream>

EventLoop::EventLoop() {}
EventLoop::~EventLoop() {}

bool EventLoop::pollEvents() {
    SDL_Event e;

    while (SDL_PollEvent(&e)) {
        handleEvent(e);
    }
    return !quit;
}

bool EventLoop::shouldQuit() const { return quit; }

void EventLoop::handleEvent(SDL_Event &e) {

    switch (e.type) {
    case SDL_QUIT:
        quit = true;
        break;
    case SDL_WINDOWEVENT:
        if (e.window.event == SDL_WINDOWEVENT_CLOSE) {
            quit = true;
        }
        break;
    default:
        break;
    }
}
