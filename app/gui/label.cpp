
#include "label.hpp"

Label::Label(int x, int y, const std::string &text)
    : Widget(x, y, 0, 0), text(text) {}

void Label::render() {}
