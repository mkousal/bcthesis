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
        i2c_cmd_handle_t cmd = i2c_cmd_link_create();
        i2c_master_start(cmd);
        i2c_master_write_byte(cmd, (sht_addr<<1) | I2C_MASTER_WRITE, I2C_MASTER_ACK);
        i2c_master_write_byte(cmd, readCommand, I2C_MASTER_ACK);
        i2c_master_stop(cmd);
        i2c_master_cmd_begin(i2c_master_port, cmd, 0);
        i2c_cmd_link_delete(cmd);
    }

    void read() {
        i2c_cmd_handle_t cmd = i2c_cmd_link_create();
        i2c_master_start(cmd);
        i2c_master_write_byte(cmd, (sht_addr<<1) | I2C_MASTER_READ, I2C_MASTER_ACK);
        i2c_master_read(cmd, data_rd, 5, I2C_MASTER_ACK);
        i2c_master_read(cmd, data_rd + 5, 1, I2C_MASTER_LAST_NACK);
        i2c_master_stop(cmd);
        i2c_master_cmd_begin(i2c_master_port, cmd, 0);
        i2c_cmd_link_delete(cmd);
    }

    float getTemp() {
        return (-45+175*(((data_rd[0]<<8) | data_rd[1])*1.0/65535));
    }

    float getHum() {
        return (-6+125*(((data_rd[3]<<8) | data_rd[4])*1.0/65535));
    }


};  // class SHT

} // namespace Am