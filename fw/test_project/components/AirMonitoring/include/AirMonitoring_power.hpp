/**
 * @file AirMonitoring_power.hpp
 * @author Martin Kousal ()
 * @brief Library for powering on and off sensors and connected devices
 * @version 0.1
 * @date 2022-04-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once

#include "AirMonitoring_pinout.hpp"

#include <driver/gpio.h>
#include "driver/rtc_io.h"
#include "esp_sleep.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

namespace Am {

/**
 * @brief Class for managing GPIOs for switching on and off sensors and device
 * 
 */
class Power {
private:
    /**
     * @brief Enumeration with power states - ON and OFF for simplify usage
     * 
     */
    enum power_state { OFF, ON };

public:
    /**
     * @brief Construct a new Power object
     * 
     */
    Power();

    /**
     * @brief Destroy the Power object
     * 
     */
    ~Power();

    /**
     * @brief Power on and off LDO for AD converter
     * 
     * @param state State ON and OFF (default - ON)
     */
    void ldo(bool state = ON);

    /**
     * @brief Power on and off I2C sensors and pullup resistors to 3V3 line
     * 
     * @param state State ON and OFF (default - ON)
     */
    void sensors(bool state = ON);

    /**
     * @brief Power on and off LoRa module RF95W
     * 
     * @param state State ON and OFF (default - ON)
     */
    void lora(bool state = ON);

    /**
     * @brief Power on and off SGP30 sensor
     * 
     * @param state State ON and OFF (default - ON)
     */
    void sgp30(bool state = ON);

    /**
     * @brief Power on and off PMS5003 sensor (+5V step up converter)
     * 
     * @param state State ON and OFF (default - ON)
     */
    void pms(bool state = ON);

    /**
     * @brief Shutdown whole device
     * 
     * @param state State ON and OFF (default - ON)
     */
    void device(bool state = ON);

    /**
     * @brief Isolate GPIOs in deep sleep mode to prevent flowing current
     * 
     */
    void isolateGPIO();

    /**
     * @brief Go to deep sleep for given time
     * 
     * @param time Time for deep sleep in minutes
     */
    void goToSleep(int time);
    
};   // class Power

} // namespace Am