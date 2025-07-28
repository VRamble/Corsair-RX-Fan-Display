#pragma once

#include <cstdint>
#include <string>

class Display {
  public:
    Display(const uint8_t width, const uint8_t height);
    Display(const uint8_t width, const uint8_t height, bool isRGB);
    Display(const std::string &name, const uint8_t width, const uint8_t height);
    Display(const std::string &name, const uint8_t width, const uint8_t height,
            bool isRGB);
    ~Display();

    inline std::string getName() const { return name; }
    inline uint8_t getWidth() const { return width; }
    inline uint8_t getHeight() const { return height; }
    inline uint16_t getPixelCount() const { return pixel_count; }
    inline bool getIsRGB() const { return isRGB; }

    inline void setName(std::string name) { this->name = name; }
    inline void setIsRGB(const bool isRGB) { this->isRGB = isRGB; }

  private:
    std::string name = "Not set";
    uint8_t width;
    uint8_t height;
    static uint16_t pixel_count;
    bool isRGB = true;

    inline void calcPixelCount() { pixel_count = width * height; }
};
