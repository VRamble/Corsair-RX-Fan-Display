#pragma once

#include <vector>

#include "panel.hpp"

class LightingPanel : public Panel {
  public:
    LightingPanel(int x, int y, int w, int h);

  private:
    std::vector<Widget *> children;
};
