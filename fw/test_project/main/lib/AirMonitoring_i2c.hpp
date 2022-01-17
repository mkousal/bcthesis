#pragma once

#include "lib/AirMonitoring_pinout.hpp"
#include "driver/i2c.h"
#include "esp_log.h"

namespace Am {

class I2C
{
protected:
    const int i2c_master_port = 0;
public:
    I2C(){}
    ~I2C(){}

    esp_err_t master_init(gpio_num_t SDA, gpio_num_t SCL){
        i2c_config_t conf = {
            .mode = I2C_MODE_MASTER,
            .sda_io_num = SDA,
            .scl_io_num = SCL,
            .sda_pullup_en = GPIO_PULLUP_DISABLE,
            .scl_pullup_en = GPIO_PULLUP_DISABLE,
            .master = {.clk_speed = 400000},
            .clk_flags = 0,
        };
        
        i2c_param_config(i2c_master_port, &conf);

        return i2c_driver_install(i2c_master_port, conf.mode, 0, 0, 0);
    }

    esp_err_t master_deinit(int num = 0){
        return(i2c_driver_delete(num));
    }

};  // class I2C


} // namespace Am