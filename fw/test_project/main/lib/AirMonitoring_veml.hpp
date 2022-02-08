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

    
public:
    enum gain_t {
        ALS_GAIN_1 = 0,
        ALS_GAIN_2 = 1,
        ALS_GAIN_1_8 = 2,
        ALS_GAIN_1_4 = 3
    };

    enum integrationTime_t {
        ALS_IT_25 = 12,
        ALS_IT_50 = 8,
        ALS_IT_100 = 0,
        ALS_IT_200 = 1,
        ALS_IT_400 = 2,
        ALS_IT_800 = 3
    };

    enum powerState_t {
        ALS_SD_SHUTDOWN = 1,
        ALS_SD_POWER_ON = 0
    };


    VEML7700(int addr) {
        veml_addr = addr;
    }

    void init(powerState_t pow, integrationTime_t time, gain_t gain) {
        uint16_t d = pow;
        d |= (time << 6);
        d |= (gain << 11);

        I2C::writeBytes(veml_addr, 0, d, size_t(2));
        vTaskDelay(5 / portTICK_RATE_MS);
    }

    void read() {
        I2C::readBytes(veml_addr, uint8_t(readCMD), data_rd, 2);
    }

    int getValue() {
        return (data_rd[0]<<8) | data_rd[1];
    }

};  // class VEML7700
}   // namespace Am