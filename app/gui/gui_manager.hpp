
#pragma once

#include "widget.hpp"

#include <vector>

class GuiManager {
  public:
    std::vector<Widget *> widgets;

    void add(Widget *w);
    void render();
    void handleEvent(const SDL_Event &e);
};
