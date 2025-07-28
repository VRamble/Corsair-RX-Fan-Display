#pragma once

#if __has_include(<cstdint>)
#include <cstdint>
#elif __has_include(<stdint.h>)
#include <stdint.h>
#else

typedef unsigned char uint8_t;
typedef signed char int8_t;
typedef unsigned short uint16_t;
typedef signed short int16_t;
#endif
