
#pragma once

#include "widget.hpp"

#include <SDL2/SDL_opengl.h>
#include <SDL2/SDL_ttf.h>

#include <string>

class Label : public Widget {
  public:
    std::string text;
    int fontSize;

    Label(int x, int y, const std::string &text, const std::string fontPath, int fontSize);
    ~Label();
    void render() override;
    void handleEvent(const SDL_Event &e) override;

  private:
    std::string fontPath = "./gui/assets/Saira-VariableFont_wdth,wght.ttf";
    TTF_Font *font = nullptr;
    GLuint texture = 0;
    int texW = 0, texH = 0;
    void createTexture();
};
