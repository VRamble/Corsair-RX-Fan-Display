#include "panel.hpp"

#include <string>
#include <GL/gl.h>
#include <SDL2/SDL_opengl.h>

Panel::Panel(int x, int y, int w, int h) : Widget(x, y, w, h) {}

Panel::Panel(int x, int y, int w, int h, const std::string &fontPath) : Widget(x, y, w, h), fontPath(fontPath) {}

void Panel::add(Widget *w) { children.push_back(w); }

void Panel::render() {
    glColor3f(0.15f, 0.15f, 0.15f);
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);
    glEnd();

    for (auto *child : children) {
        if (child->visible) {
            child->render();
        }
    }
}

void Panel::handleEvent(const SDL_Event &e) {
    for (auto *child : children) {
        if (child->visible) {
            child->handleEvent(e);
        }
    }
}
