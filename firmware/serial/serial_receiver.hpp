#pragma once

#include "display_image.hpp"

#include <boost/asio.hpp>

#include <cstdint>

class SerialReceiver {
  public:
    SerialReceiver(boost::asio::serial_port &serial);
    ~SerialReceiver();

    DisplayImage readFromSerialPort(const uint16_t pixelsPerLine,
                                    const uint16_t lineCount);

  private:
    boost::asio::serial_port &serial;
};
