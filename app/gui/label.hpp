
#pragma once

#include "widget.hpp"

#include <string>

class Label : public Widget {
  public:
    std::string text;

    Label(int x, int y, const std::string &text);
    void render() override;
    void handleEvent(const SDL_Event &e) override {}
};
