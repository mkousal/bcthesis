/**
 * @file AirMonitoring_veml.hpp
 * @author Martin Kousal ()
 * @brief Simple library to communicate with VEML7700 light sensor via I2C bus
 * @version 0.1
 * @date 2022-04-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once

#include "AirMonitoring_i2c.hpp"
#include "AirMonitoring_pinout.hpp"

namespace Am{
class VEML7700 : public I2C {
private:
    /**
     * @brief Local variable to store sensor I2C address
     * 
     */
    int veml_addr;
    
    /**
     * @brief Local constant with read command value
     * 
     */
    const int readCMD = 4;

    /**
     * @brief Local variable to store received data from the sensor
     * 
     */
    uint8_t *data_rd = (uint8_t *) malloc(2);

    // /**
    //  * @brief Local variable to 
    //  * 
    //  */
    // uint8_t *cmd = (uint8_t *) malloc(3);

    
public:
    /**
     * @brief Construct a new VEML7700 object
     * 
     * @param addr I2C address of sensor
     */
    VEML7700(int addr);

    /**
     * @brief Destroy the VEML7700 object
     * 
     */
    ~VEML7700();

    /**
     * @brief Enumeration with sensor setting of ALS gain
     * 
     */
    enum gain_t {
        ALS_GAIN_1 = 0,
        ALS_GAIN_2 = 1,
        ALS_GAIN_1_8 = 2,
        ALS_GAIN_1_4 = 3
    };

    /**
     * @brief Enumeration with sensor setting of ALS integration time
     * 
     */
    enum integrationTime_t {
        ALS_IT_25 = 12,
        ALS_IT_50 = 8,
        ALS_IT_100 = 0,
        ALS_IT_200 = 1,
        ALS_IT_400 = 2,
        ALS_IT_800 = 3
    };

    /**
     * @brief Enumeration with sensor power states
     * 
     */
    enum powerState_t {
        ALS_SD_SHUTDOWN = 1,
        ALS_SD_POWER_ON = 0
    };    

    /**
     * @brief Initialize sensor and set power state, integration time and gain values
     * 
     * @param pow Power state setting of sensor from powerState_t enumeration
     * @param time Integration time setting of sensor from integrationTime_t enumeration
     * @param gain Gain setting of sensor from gain_t enumeration
     */
    void init(powerState_t pow, integrationTime_t time, gain_t gain);

    /**
     * @brief Read measured values
     * 
     */
    void read();

    /**
     * @brief Get measured light intensity value
     * 
     * @return int Light intensity in lux
     */
    int getValue();

};  // class VEML7700

}   // namespace Am