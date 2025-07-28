#pragma once

#include <cstdint>
#include <memory>

typedef struct DisplayImage {
    std::unique_ptr<uint8_t[]> r;
    std::unique_ptr<uint8_t[]> g;
    std::unique_ptr<uint8_t[]> b;
    uint8_t lineCount;   // number of lines sent at a time
    uint16_t pixelCount; // total number of pixels

} DisplayImage;
