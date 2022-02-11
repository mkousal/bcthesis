#pragma once

#include "AirMonitoring_i2c.hpp"
#include "AirMonitoring_pinout.hpp"

namespace Am {
class SHT : public I2C {
private: 
    int sht_addr;
    gpio_num_t sda;
    gpio_num_t scl;
    const int readCommand = 0xFD;
    uint8_t *data_rd = (uint8_t *) malloc(6);

public:
    SHT(int addr, gpio_num_t SDA, gpio_num_t SCL);

    ~SHT();

    void init();

    void sendRequestToRead();

    void read();

    float getTemp();

    float getHum();

};  // class SHT

} // namespace Am