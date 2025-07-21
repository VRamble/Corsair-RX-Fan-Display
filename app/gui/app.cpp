#include "app.hpp"
#include "event_loop.hpp"
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

    bool running = true;
    EventLoop event_loop = EventLoop();
    while (running) {
        running = event_loop.pollEvents();
        window.clear();
        window.swap_buffers();
    }
    return 0;
}

} // namespace gui
