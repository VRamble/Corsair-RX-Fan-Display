
#include "gui_manager.hpp"
#include <SDL2/SDL_opengl.h>

void GuiManager::add(Widget *w) { widgets.push_back(w); }

void GuiManager::render() {
    for (auto *w : widgets) {
        if (w->visible)
            w->render();
    }
}

void GuiManager::handleEvent(const SDL_Event &e) {
    for (auto *w : widgets) {
        if (w->visible)
            w->handleEvent(e);
    }
}
