/**
 * @file AirMonitoring_i2c.hpp
 * @author Martin Kousal ()
 * @brief Simplified library to use I2C bus with ESP-IDF
 * @version 0.1
 * @date 2022-04-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once

#include "AirMonitoring_pinout.hpp"
#include "driver/i2c.h"
#include "esp_log.h"
#include "esp_err.h"

namespace Am {

class I2C
{
protected:
    /**
     * @brief Variable to store I2C port number
     * 
     */
    uint8_t i2c_master_port;
public:
    /**
     * @brief Construct a new I2C object
     * 
     * @param port Port number of initialized I2C
     */
    I2C(uint8_t port = 0);
    
    /**
     * @brief Destroy the I2C object
     * 
     */
    ~I2C();

    /**
     * @brief Initialize I2C as master
     * 
     * @param SDA SDA pin number
     * @param SCL SCL pin number
     * @return esp_err_t Returns initialization state
     */
    esp_err_t master_init(gpio_num_t SDA, gpio_num_t SCL);

    /**
     * @brief Deinitialize I2C master
     * 
     * @param num I2C port number
     * @return esp_err_t Returns deinitialization state
     */
    esp_err_t master_deinit(int num);

    /**
     * @brief Writes one byte of data to given device
     * 
     * @param addr Address of I2C device
     * @param msg One byte message to send
     * @return esp_err_t Return status of sending
     */
    esp_err_t writeByte(int addr, uint8_t msg);

    /**
     * @brief Write two bytes of data to given device and register
     * 
     * @param addr Address of I2C device
     * @param reg 8 bit register address
     * @param data 16 bit data to send
     * @param len Length of given data in number of bytes
     * @return esp_err_t Return status of sending
     */
    esp_err_t writeBytes(int addr, uint8_t reg, uint16_t data, size_t len);

    /**
     * @brief Write two bytes of data to given device
     * 
     * @param addr Address of I2C device
     * @param data 16 bit data to send
     * @return esp_err_t Return status of sending
     */
    esp_err_t writeBytes(int addr, uint16_t data);

    /**
     * @brief Write byte of data to given registr and device
     * 
     * @param addr Address of I2C device
     * @param reg 8 bit register address
     * @param data 8 bit data to send
     * @return esp_err_t Return status of sending
     */
    esp_err_t writeByteToReg(int addr, uint8_t reg, uint8_t data);

    /**
     * @brief Read given amount of bytes from device
     * 
     * @param addr Address of I2C device
     * @param data Pointer to space where to store received data
     * @param data_len Length of data to receive
     * @return esp_err_t Return status of receiving
     */
    esp_err_t readBytes(int addr, uint8_t *data, int data_len);

    /**
     * @brief Read given amount of bytes from given register and device
     * 
     * @param addr Address of I2C device
     * @param reg 8 bit register address
     * @param data Pointer to space where to store received data
     * @param data_len Length of data to receive
     * @return esp_err_t Return status of receiving
     */
    esp_err_t readBytes(int addr, uint8_t reg, uint8_t *data, int data_len);

    /**
     * @brief Read given amount of bytes from 16 bit register
     * 
     * @param addr Address of I2C device
     * @param reg 16 bit register address
     * @param data Pointer to space where to store received data
     * @param data_len Length of data to receive
     * @return esp_err_t Return status of receiving
     */
    esp_err_t readBytes16reg(int addr, uint16_t reg, uint8_t *data, int data_len);

    /**
     * @brief Write 16 bit command to 8 bit register
     * 
     * @param addr Address of I2C device
     * @param cmdCode 8 bit command value
     * @param msg 16 bit message value
     * @return esp_err_t Return status of sending
     */
    esp_err_t writeCommand(int addr, uint8_t cmdCode, uint16_t msg);    

};  // class I2C


} // namespace Am