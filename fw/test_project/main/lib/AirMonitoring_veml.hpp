#pragma once

#include "lib/AirMonitoring_i2c.hpp"
#include "lib/AirMonitoring_pinout.hpp"

namespace Am{
class VEML7700 : public I2C {
private:
    int veml_addr;
    const int readCMD = 4;
    uint8_t *data_rd = (uint8_t *) malloc(2);
    uint8_t *cmd = (uint8_t *) malloc(3);
    uint16_t data = 0;

public:
    VEML7700(int addr) {
        veml_addr = addr;
    }

    void sendRequestToRead() {
        I2C::writeBytes(veml_addr, 0, &data, size_t(2));
        // I2C::writeCommand(veml_addr, 0, 0);
        I2C::writeByte(veml_addr, readCMD);
    }

    void read() {
        I2C::readBytes(veml_addr, data_rd, 2);
    }

    int getValue() {
        return (data_rd[0]<<8) | data_rd[1];
    }

};  // class VEML7700
}   // namespace Am