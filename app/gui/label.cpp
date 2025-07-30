
#include "label.hpp"

#include <GL/gl.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_ttf.h>

Label::Label(int x, int y, const std::string &text, int fontSize)
    : Widget(x, y, 0, 0), text(text), fontSize(fontSize) {

    font = TTF_OpenFont(fontPath.c_str(), fontSize);
    if (!font) {
        printf("Failed to load font: %s\n", TTF_GetError());
        return;
    }
    createTexture();
}

Label::~Label() {
    if (texture) {
        glDeleteTextures(1, &texture);
    }
    if (font) {
        TTF_CloseFont(font);
    }
}

void Label::render() {
    if (!texture) {
        return;
    }
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture);
    glColor3f(1.0f, 1.0f, 1.0f);

    float x1 = x, y1 = y;
    float x2 = x + texW, y2 = y + texH;

    glBegin(GL_QUADS);
    glTexCoord2f(0, 0);
    glVertex2f(x1, y1);
    glTexCoord2f(1, 0);
    glVertex2f(x2, y1);
    glTexCoord2f(1, 1);
    glVertex2f(x2, y2);
    glTexCoord2f(0, 1);
    glVertex2f(x1, y2);
    glEnd();

    glDisable(GL_TEXTURE_2D);
    glDisable(GL_BLEND);
}

void Label::createTexture() {
    SDL_Color color = {255, 255, 255, 255};
    SDL_Surface *surface = TTF_RenderUTF8_Blended(font, text.c_str(), color);

    if (!surface) {
        printf("TTF_RenderUTF8_Blended failed: %s\n", TTF_GetError());
        return;
    }

    texW = surface->w;
    texH = surface->h;

    SDL_Surface *converted =
        SDL_ConvertSurfaceFormat(surface, SDL_PIXELFORMAT_RGBA32, 0);
    SDL_FreeSurface(surface);
    if (!converted) {
        printf("SDL_ConvertSurfaceFormat failed: %s\n", SDL_GetError());
        return;
    }

    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    GLenum format =
        (converted->format->Rmask == 0x000000ff) ? GL_RGBA : GL_BGRA;
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texW, texH, 0, format,
                 GL_UNSIGNED_BYTE, converted->pixels);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    SDL_FreeSurface(converted);
}

void Label::handleEvent(const SDL_Event &e) {}
