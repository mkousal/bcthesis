/**
 * @file AirMonitoring_sgp30.hpp
 * @author Martin Kousal ()
 * @brief Simple library for communicating with SGP30 sensor via I2C bus
 * @version 0.1
 * @date 2022-04-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once

#include "AirMonitoring_i2c.hpp"
#include "AirMonitoring_pinout.hpp"

namespace Am {
class SGP : public I2C {
private:
    /**
     * @brief Local variable to store SGP30 address
     * 
     */
    int sgp_addr;

    /**
     * @brief Local variable array to store received data from sensor
     * 
     */
    uint8_t *data_rd = (uint8_t *) malloc(6);

    /**
     * @brief Local variable to store received ID from sensor
     * 
     */
    uint8_t *id = (uint8_t *) malloc(9);
public:
    /**
     * @brief Construct a new SGP object
     * 
     * @param addr I2C address of SGP30 device
     */
    SGP(int addr);

    /**
     * @brief Destroy the SGP object
     * 
     */
    ~SGP();

    /**
     * @brief Send command to initialize SGP30 device
     * 
     */
    void init();

    /**
     * @brief Send command to begin measurement and then read meausured data
     * 
     */
    void measure();

    /**
     * @brief Get measured TVOC value
     * 
     * @return uint16_t TVOC value
     */
    uint16_t getTVOC();

    /**
     * @brief Get measured equivalent CO2 value
     * 
     * @return uint16_t eCO2 value
     */
    uint16_t getCO2();

    /**
     * @brief Print raw measured data, only for debug purposes
     * 
     */
    void printRAW();

    /**
     * @brief Get serial ID of the sensor
     * 
     */
    void getSerialID();

    /**
     * @brief Print received serial ID of the sensor
     * 
     */
    void printID();

    /**
     * @brief Set absolute humidity to the compensation procedure - not included yet!
     * 
     * @param humidity Relative humidity value
     * @param temperature Temperature value
     */
    void setHumidity(float humidity, float temperature);

};  // class SGP

}   // namespace Am