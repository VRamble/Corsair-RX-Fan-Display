
#pragma once

#include "widget.hpp"

#include <functional>
#include <string>

class Button : public Widget {

  public:
    std::string text;
    std::function<void()> onClick;
    Button(int x, int y, int w, int h, const std::string &text);
    void render() override;
    void handleEvent(const SDL_Event &e) override;
};
