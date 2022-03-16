#pragma once

#include "AirMonitoring_pinout.hpp"
#include "driver/uart.h"
#include <algorithm>
#include "esp_log.h"

namespace Am {
class PMS {
private:
    #pragma pack(push, 1)
    typedef struct {
        uint16_t framelen;
        uint16_t pm10_standard, pm25_standard, pm100_standard;
        uint16_t pm10_env, pm25_env, pm100_env;
        uint16_t particles_03um, particles_05um, particles_10um, particles_25um, particles_50um, particles_100um;
        uint16_t unused;
        uint16_t checksum;
    }pms5003_data_t, *Ppms5003_data_t;
    #pragma pack(pop)

    Ppms5003_data_t receivedData;
    uint8_t data_rx[30];

public:
    PMS();

    ~PMS();

    void init();

    int readPMS();

    void printData();

    void printPM();

    int getPM1();

    int getPM25();

    int getPM10();

};  // class PMS

}   // namespace Am