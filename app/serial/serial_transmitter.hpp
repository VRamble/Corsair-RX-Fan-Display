#pragma once

#include "display_image.hpp"

#include <boost/asio.hpp>
#include <boost/asio/io_context.hpp>
#include <cstdint>
#include <string>

class SerialTransmitter {
  public:
    SerialTransmitter(const std::string &portName, uint16_t baudRate);
    ~SerialTransmitter();

    void configureSerialPort();
    void writeToSerialPort(DisplayImage &displayImage);

  private:
    boost::asio::serial_port serial;
    boost::asio::io_context ioContext;
    std::string portName;
    uint16_t baudRate;
};
