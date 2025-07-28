#include "display.hpp"

#include <cstdint>
#include <string>

Display::Display(const uint8_t width, const uint8_t height) {
    this->width = width;
    this->height = height;
    this->calcPixelCount();
}

Display::Display(const uint8_t width, const uint8_t height, const bool isRGB) {
    this->width = width;
    this->height = height;
    this->isRGB = isRGB;
    this->calcPixelCount();
}

Display::Display(const std::string &name, const uint8_t width,
                 const uint8_t height) {
    this->name = name;
    this->width = width;
    this->height = height;
    this->calcPixelCount();
}

Display::Display(const std::string &name, const uint8_t width,
                 const uint8_t height, const bool isRGB) {
    this->name = name;
    this->width = width;
    this->height = height;
    this->isRGB = isRGB;
    this->calcPixelCount();
}
