#include "button.hpp"
#include <SDL2/SDL_opengl.h>

Button::Button(int x, int y, int w, int h, const std::string &text)
    : Widget(x, y, w, h), text(text) {}

void Button::render() {
    glColor3f(0.96f, 0.95f, 0.13f);
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);
    glEnd();
}

void Button::handleEvent(const SDL_Event &e) {
    if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT) {
        int mx = e.button.x;
        int my = e.button.y;
        printf("Button clicked at (%d, %d)\n", mx, my);
        if (mx >= x && mx < x + width && my >= y && my < y + height) {
            printf("Button contains click at (%d, %d)\n", mx, my);
            if (onClick) {
                onClick();
            }
        }
    }
}
