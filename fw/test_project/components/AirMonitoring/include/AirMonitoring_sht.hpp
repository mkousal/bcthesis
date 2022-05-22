/**
 * @file AirMonitoring_sht.hpp
 * @author Martin Kousal ()
 * @brief Simple library for communicating with SHT40 temperature and humidity sensor
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
class SHT : public I2C {
private: 
    /**
     * @brief Local variable to store sensor address
     * 
     */
    int sht_addr;

    /**
     * @brief Local variable to store SDA pin from I2C bus
     * 
     */
    gpio_num_t sda;

    /**
     * @brief Local variable to store SCL pin from I2C bus
     * 
     */
    gpio_num_t scl;
    
    /**
     * @brief Local constant with read command
     * 
     */
    const int readCommand = 0xFD;

    /**
     * @brief Local variable to store received data from sensor
     * 
     */
    uint8_t *data_rd = (uint8_t *) malloc(6);

public:
    /**
     * @brief Construct a new SHT object
     * 
     * @param addr I2C addres of sensor
     * @param SDA SDA pin from I2C bus
     * @param SCL SCL pin from I2C bus
     */
    SHT(int addr, gpio_num_t SDA, gpio_num_t SCL);

    /**
     * @brief Destroy the SHT object
     * 
     */
    ~SHT();

    /**
     * @brief Initialize I2C bus, must be called before first usage of I2C peripheral
     * 
     */
    void init();

    /**
     * @brief Send request command to start measuring
     * 
     */
    void sendRequestToRead();

    /**
     * @brief Read 6 bytes of measured data from device
     * 
     */
    void read();

    /**
     * @brief Calculate temperature from measured data
     * 
     * @return float Measured temperature in degrees celsius
     */
    float getTemp();

    /**
     * @brief Calculate relative humidity from measured data
     * 
     * @return float Measured relative humidity
     */
    float getHum();

};  // class SHT

} // namespace Am