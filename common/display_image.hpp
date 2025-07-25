#pragma once

#include "display.hpp"

#include <cstdint>
#include <memory>

typedef struct DisplayImage {
    std::unique<uint8_t[]> r;
    std::unique<uint8_t[]> g;
    std::unique<uint8_t[]> b;
    uint8_t lineCount;   // number of lines sent at a time
    uint16_t pixelCount; // total number of pixels

} DisplayImage;
