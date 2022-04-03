#pragma once

#include "AirMonitoring_i2c.hpp"
#include "AirMonitoring_pinout.hpp"

namespace Am {
class SGP : public I2C {
private:
    int sgp_addr;
    uint8_t *data_rd = (uint8_t *) malloc(6);
    uint8_t *id = (uint8_t *) malloc(9);
public:
    SGP(int addr);

    ~SGP();

    void init();

    void measure();

    uint16_t getTVOC();

    uint16_t getCO2();

    void printRAW();

    void getSerialID();

    void printID();

    void setHumidity(float humidity, float temperature);

};  // class SGP

}   // namespace Am