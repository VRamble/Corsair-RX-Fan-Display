#include "window.hpp"

#include <string>

#pragma once

namespace gui {
class App {
  public:
    App();
    ~App();
    int run();
    Window getWindow();

    static std::string getExecutablePath();

  private:
    bool isRunning;
    Window window;
    std::string executablePath;
};
} // namespace gui
