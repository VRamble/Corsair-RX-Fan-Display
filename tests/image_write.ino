#include <TFT_eSPI.h> //update your user config file to fix color inversion, etc
#include <SPI.h>

TFT_eSPI tft = TFT_eSPI();
const int width = 160; //will want this info in a config file in future, not baked in
const int height = 80;

void setup() {
  Serial.begin(115200);
  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);
  Serial.println("READY");  // handshake
}

void loop() {
  if (Serial.available() >= 5) {
    uint8_t x = Serial.read();
    uint8_t y = Serial.read();
    uint8_t r = Serial.read();
    uint8_t g = Serial.read();
    uint8_t b = Serial.read();

    uint16_t color = tft.color565(r, g, b);
    tft.drawPixel(x, y, color);

    Serial.println("OK");  // handshake back
  }
}
