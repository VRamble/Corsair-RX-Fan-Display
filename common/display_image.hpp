#pragma once

#include "display.hpp"

#include <cstdint>

typedef struct DisplayImage {
    uint8_t *r;
    uint8_t *g;
    uint8_t *b;
    uint16_t pixel_count;

} DisplayImage;
