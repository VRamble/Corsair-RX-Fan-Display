#pragma once

#include <boost/asio.hpp>
#include <cstdint>
#include <iostream>

class SerialTransmitter {
  public:
    SerialTransmitter(const std::string &portName, uint8_t baudRate);
    ~SerialTransmitter();

    void writeToSerialPort();

  private:
    boost::asio::serial_port &serial;
};
