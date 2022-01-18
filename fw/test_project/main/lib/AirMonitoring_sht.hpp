#pragma once

#include "lib/AirMonitoring_i2c.hpp"
#include "lib/AirMonitoring_pinout.hpp"

namespace Am {
class SHT : public I2C {
private: 
    int sht_addr;
    gpio_num_t sda;
    gpio_num_t scl;
    const int readCommand = 0xFD;
    uint8_t *data_rd = (uint8_t *) malloc(6);

public:
    SHT(int addr, gpio_num_t SDA, gpio_num_t SCL){
        sht_addr = addr;
        sda = SDA;
        scl = SCL;
    }

    void init(){
        I2C::master_init(sda, scl);
    }

    void sendRequestToRead() {
        I2C::writeByte(sht_addr, readCommand);
    }

    void read() {
        I2C::readBytes(sht_addr, data_rd, 6);
    }

    float getTemp() {
        return (-45+175*(((data_rd[0]<<8) | data_rd[1])*1.0/65535));
    }

    float getHum() {
        return (-6+125*(((data_rd[3]<<8) | data_rd[4])*1.0/65535));
    }


};  // class SHT

} // namespace Am