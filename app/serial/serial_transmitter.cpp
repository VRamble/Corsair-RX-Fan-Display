
#include "serial_transmitter.hpp"

#include <boost/asio.hpp>

#include <boost/asio/serial_port.hpp>
#include <cstdint>
#include <exception>
#include <iostream>
#include <string>

SerialTransmitter::SerialTransmitter(const std::string &portName,
                                     const uint16_t baudRate)
    : ioContext(), serial(ioContext), portName(portName), baudRate(baudRate) {
    this->portName = portName;
    this->baudRate = baudRate;

    boost::asio::io_context ioContext;
    boost::asio::serial_port serial_p(ioContext, portName);

    this->serial = std::move(serial_p);

    try {
        this->configureSerialPort();
    } catch (const std::exception &e) {
        std::cerr << "Error configuring serial port: " << e.what() << std::endl;
        return;
    }
};

void SerialTransmitter::configureSerialPort() {
    this->serial.open(this->portName);
    this->serial.set_option(
        boost::asio::serial_port_base::baud_rate(this->baudRate));
};
