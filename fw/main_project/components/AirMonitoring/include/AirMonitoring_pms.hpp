/**
 * @file AirMonitoring_pms.hpp
 * @author Martin Kousal (you@domain.com)
 * @brief Simple library to communicate via UART with PMS5003 dust particle sensor
 * @version 0.1
 * @date 2022-04-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once

#include "AirMonitoring_pinout.hpp"
#include "driver/uart.h"
#include <algorithm>
#include "esp_log.h"

namespace Am {
class PMS {
private:
    /**
     * @brief Data structure to store all received data from sensor
     * 
     */
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
    /**
     * @brief Construct a new PMS object
     * 
     */
    PMS();

    /**
     * @brief Destroy the PMS object
     * 
     */
    ~PMS();

    /**
     * @brief Initialize UART bus to communicate with sensor
     * 
     */
    void init();

    /**
     * @brief Read all data from sensor and store them to the prepared data structure
     * 
     * @return int Returns length of received data
     */
    int readPMS();

    /**
     * @brief Print raw received data from UART buffer (for debug purposes only)
     * 
     */
    void printData();

    /**
     * @brief Print all measured particulate matter values
     * 
     */
    void printPM();

    /**
     * @brief Get PM1 measured value
     * 
     * @return int Measured PM1 value
     */
    int getPM1();

    /**
     * @brief Get PM2.5 measured value
     * 
     * @return int Measured PM2.5 value
     */
    int getPM25();

    /**
     * @brief Get PM10 measured value
     * 
     * @return int Measured PM10 value
     */
    int getPM10();

};  // class PMS

}   // namespace Am