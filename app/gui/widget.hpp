#pragma once
#include <SDL2/SDL.h>

class Widget {
  public:
    int x, y, width, height;
    bool visible = true;

    Widget(int x, int y, int w, int h) : x(x), y(y), width(w), height(h) {}
    virtual ~Widget() {}

    virtual void render() = 0;
    virtual void handleEvent(const SDL_Event &e) = 0;

    bool contains(int mx, int my) const {
        return mx >= x && mx <= x + width && my >= y && my <= y + height;
    }
};
