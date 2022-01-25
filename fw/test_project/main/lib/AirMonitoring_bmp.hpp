#pragma once

#include "lib/AirMonitoring_i2c.hpp"
#include "lib/AirMonitoring_pinout.hpp"

namespace Am {
class BMP : public I2C {
private:
    int bmp_addr;
    uint8_t pwr_ctrl = 0x33;
    uint8_t *data_rd = (uint8_t *) malloc(6);



public:
    BMP(int addr){
        bmp_addr = addr;
    }

    void forceRead(){
        I2C::writeByteToReg(bmp_addr, 0x1B, pwr_ctrl);
    }

    void readPressure(){
        I2C::readBytes(bmp_addr, 0x04, data_rd, 6);
    }

    void readTemperature() {
        I2C::readBytes(bmp_addr, 0x07, data_rd, 3);
    }

    void print(){
        ESP_LOGI("BMP", "%#x %#x %#x %#x %#x %#x", data_rd[5], data_rd[4], data_rd[3], data_rd[2], data_rd[1], data_rd[0]);
    }

    void readID(){
        uint8_t data = 0;
        I2C::readBytes(bmp_addr, 0x00, &data, 1);
        ESP_LOGI("BMP", "id: %#x", data);
    }

    void checkERR() {
        uint8_t data = 0;
        I2C::readBytes(bmp_addr, 0x02, &data, 1);
        ESP_LOGI("BMP", "err: %#x", data);
    }

    void readStatus() {
        uint8_t data = 0;
        I2C::readBytes(bmp_addr, 0x03, &data, 1);
        ESP_LOGI("BMP", "stat: %#x", data);
    }

    void readPower() {
        uint8_t data = 0;
        I2C::readBytes(bmp_addr, 0x1B, &data, 1);
        ESP_LOGI("BMP", "pwr: %#x", data);
    }

    void softReset() {
        I2C::writeByteToReg(bmp_addr, 0x7E, 0xB6);
    }

};   // class BMP

} // namespace Am