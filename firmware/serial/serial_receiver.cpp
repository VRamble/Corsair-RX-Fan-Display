#include "serial_receiver.hpp"
#include <cstdint>
#include <memory>

SerialReceiver::SerialReceiver(boost::asio::serial_port &serial)
    : serial(serial) {}

DisplayImage SerialReceiver::readFromSerialPort(const uint16_t pixelsPerLine,
                                                const uint16_t lineCount) {
    DisplayImage img;

    img.pixelCount = pixelsPerLine * lineCount;
    img.r = std::make_unique<uint8_t[]>(img.pixelCount);
    img.g = std::make_unique<uint8_t[]>(img.pixelCount);
    img.b = std::make_unique<uint8_t[]>(img.pixelCount);

    boost::asio::read(serial,
                      boost::asio::mutable_buffer(img.r.get(), img.pixelCount));
    boost::asio::read(serial,
                      boost::asio::mutable_buffer(img.g.get(), img.pixelCount));
    boost::asio::read(serial,
                      boost::asio::mutable_buffer(img.b.get(), img.pixelCount));

    return img;
}
