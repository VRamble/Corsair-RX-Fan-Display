#include "app.hpp"
#include "button.hpp"
#include "event_loop.hpp"
#include "gui_manager.hpp"
#include "window.hpp"

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

int App::run() {

    GuiManager gui;
    Button *button = new Button(100, 100, 200, 50, "Test");
    button->onClick = []() {
        printf("Button Pressed\n");
        fflush(stdout);
    };
    gui.add(button);

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
