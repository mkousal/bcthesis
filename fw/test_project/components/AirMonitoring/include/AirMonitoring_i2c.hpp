#pragma once

#include "AirMonitoring_pinout.hpp"
#include "driver/i2c.h"
#include "esp_log.h"
#include "esp_err.h"

namespace Am {

class I2C
{
protected:
    uint8_t i2c_master_port;
public:
    I2C(uint8_t port = 0);
    
    ~I2C();

    esp_err_t master_init(gpio_num_t SDA, gpio_num_t SCL);

    esp_err_t master_deinit(int num);

    esp_err_t writeByte(int addr, uint8_t msg);

    esp_err_t writeBytes(int addr, uint8_t reg, uint16_t data, size_t len);

    esp_err_t writeByteToReg(int addr, uint8_t reg, uint8_t data);

    esp_err_t readBytes(int addr, uint8_t *data, int data_len);

    esp_err_t readBytes(int addr, uint8_t reg, uint8_t *data, int data_len);

    esp_err_t writeCommand(int addr, uint8_t cmdCode, uint16_t msg);    

};  // class I2C


} // namespace Am