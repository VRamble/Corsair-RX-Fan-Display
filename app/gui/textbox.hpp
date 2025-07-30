
#pragma once
#include "widget.hpp"

#include <string>

class TextBox : public Widget {
    std::string text;
    bool active = false;

  public:
    TextBox(int x, int y, int w, int h);
    void render() override;
    void handleEvent(const SDL_Event &e) override;
    std::string getText() const { return text; }
};
