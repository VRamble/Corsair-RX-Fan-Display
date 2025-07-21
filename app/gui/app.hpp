#include "window.hpp"

#pragma once

namespace gui {
class App {
  public:
    App();
    ~App();
    int run();
    Window getWindow();

  private:
    bool isRunning;
    Window window;
};
} // namespace gui
