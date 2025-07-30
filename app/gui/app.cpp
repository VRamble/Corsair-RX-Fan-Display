#include "app.hpp"
#include "button.hpp"
#include "event_loop.hpp"
#include "gui_manager.hpp"
#include "label.hpp"
#include "panels/panel.hpp"
#include "window.hpp"
#include <limits.h>
#include <unistd.h>

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

    std::string executablePath = getExecutablePath();
    GuiManager gui;
    Panel *panel = new Panel(50, 50, 400, 400);
    Label *label = new Label(50, 50, "Test Label",
                             getExecutablePath() +
                                 "/gui/assets/Saira-VariableFont_wdth,wght.ttf",
                             64);
    // gui.add(label);

    Button *button =
        new Button(100, 200, 200, 50, "Test",
                   executablePath + "/gui/assets/waves-24.png", 24, 24);
    button->onClick = []() {
        printf("Button Pressed\n");
        fflush(stdout);
    };
    // gui.add(button);
    panel->add(label);
    panel->add(button);
    gui.add(panel);

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
