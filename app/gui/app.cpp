#include "app.hpp"
#include "button.hpp"
#include "event_loop.hpp"
#include "gui_manager.hpp"
#include "label.hpp"
#include "panels/panel.hpp"
#include "window.hpp"
#include <limits.h>
#include <unistd.h>

#include "panels/lighting_panel.hpp"

namespace gui {
App::App() : window("App", 960, 720) {
    // init logic
    if (!window.isInitialized()) {
        isRunning = false;
        return;
    }
}

App::~App() {
    // destructor logic
}

Window App::getWindow() { return window; }

std::string App::getExecutablePath() {
    char result[PATH_MAX];
    ssize_t size = readlink("/proc/self/exe", result, PATH_MAX - 1);
    if (size <= 0) {
        return "";
    }
    result[size] = '\0';
    std::string path(result);
    size_t lastSlash = path.find_last_of('/');
    if (lastSlash == std::string::npos) {
        return path;
    }
    return path.substr(0, lastSlash);
}

int App::run() {

    const std::string executablePath = getExecutablePath();
    GuiManager gui;
    auto lightingPanel = new LightingPanel(0, 0, 240, 360, executablePath);
    gui.add(lightingPanel);

    bool running = true;
    EventLoop event_loop = EventLoop();
    while (running) {

        SDL_Event e;
        // running = event_loop.pollEvents();
        while (SDL_PollEvent(&e)) {
            event_loop.handleEvent(e); // global window events like quit
            gui.handleEvent(e);
        }

        if (event_loop.shouldQuit()) {
            running = false;
            continue;
        }

        window.clear();
        gui.render();
        window.swap_buffers();
    }
    return 0;
}

} // namespace gui
