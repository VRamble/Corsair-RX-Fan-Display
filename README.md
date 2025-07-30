# Corsair RX Fan Display

This application is to support the entry into the Corsair Printables contest. This application will allow you to interact with the display.

**THIS APP IS A WIP**

## Building

As of 7/30/2025, the only supported way to show images is through the python script/ arduino code found in the test directory. Edit the IMG_PATH line to change the image on the board. Ensure the arduino is flashed with the image_write.ino program.

Current Display -> Arduino Nano Pinout:

GND -> GND
VCC + BLK -> 3.3V
SCL -> D13
SDA -> D11
RES -> D8
DC -> D9
CS -> D10

This software is in active development, and will change rapidly.
