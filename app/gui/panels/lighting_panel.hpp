#pragma once

#include <string>
#include <vector>

#include "panel.hpp"

class LightingPanel : public Panel {
  public:
    LightingPanel(int x, int y, int w, int h,
                  const std::string &executablePath);

  private:
    std::vector<Widget *> children;
    std::string executablePath;
};
