#pragma once

#include "widget.hpp"

#include <vector>

class Widget;

class Panel : public Widget {
  public:
    Panel(int x, int y, int w, int h);

    void add(Widget *w);
    void render() override;
    void handleEvent(const SDL_Event &e) override;

  private:
    std::vector<Widget *> children;
};
