
#pragma once

#include "widget.hpp"

#include <SDL2/SDL_opengl.h>
#include <functional>
#include <string>

class Button : public Widget {

  public:
    std::string text;
    std::function<void()> onClick;
    Button(int x, int y, int w, int h, const std::string &text);
    Button(int x, int y, int w, int h, const std::string &text, float red,
           float green, float blue);
    Button(int x, int y, int w, int h, const std::string &text,
           const std::string &iconPath, int iconWidth, int iconHeight);
    void render() override;
    void handleEvent(const SDL_Event &e) override;

    void loadIcon(const std::string &iconPath);

  private:
    float red = 0.96;
    float green = 0.95;
    float blue = 0.13;
    GLuint iconTexture = 0;
    int iconWidth = 0, iconHeight = 0;
};
