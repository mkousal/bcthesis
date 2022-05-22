/**
 * @file AirMonitoring_spi.hpp
 * @author Martin Kousal ()
 * @brief Simple library for use basic sending and receiving through SPI bus
 * @version 0.1
 * @date 2022-04-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once

#include "AirMonitoring_pinout.hpp"
#include "driver/spi_common.h"
#include "driver/spi_master.h"
#include "esp_log.h"
#include "esp_err.h"
#include <cstring>

namespace Am {

class SPI
{
private:
    /**
     * @brief Define of using hardware SPI peripheral with name VSPI_HOST
     * 
     */
    spi_host_device_t host = VSPI_HOST;

public:
    /**
     * @brief Construct a new SPI object
     * 
     */
    SPI();

    /**
     * @brief Destroy the SPI object
     * 
     */
    ~SPI();

    /**
     * @brief Start and set up SPI peripheral with given parameters
     * 
     * @param mosi SPI MOSI pin
     * @param miso SPI MISO pin
     * @param sclk SPI SCLK clock value
     * @return esp_err_t Return status of SPI peripheral initialization
     */
    esp_err_t begin(gpio_num_t mosi, gpio_num_t miso, gpio_num_t sclk);

    /**
     * @brief Register new device to communicate via SPI peripheral
     * 
     * @param mode SPI mode, representing a pair of (CPOL, CPHA) configuration
     * @param clock_speed_hz SPI clock speed in Hz
     * @param cs_pin SPI CS pin for selecting this device to communicate with
     * @param handle Handle for a device on a SPI bus
     * @return esp_err_t Return status of adding new device on a SPI bus
     */
    esp_err_t addDevice(uint8_t mode, uint32_t clock_speed_hz, gpio_num_t cs_pin, spi_device_handle_t *handle);

    /**
     * @brief Remove registered device at SPI bus
     * 
     * @param handle Handle of a device on a SPI bus
     * @return esp_err_t Return status of removing a device from SPI bus
     */
    esp_err_t removeDevice(spi_device_handle_t handle);

    /**
     * @brief Write and read given amount of data to device on a SPI bus
     * 
     * @param handle Handle for a device on a SPI bus
     * @param data_tx Pointer to uint8_t array with data to transmit
     * @param length_rx Length of data to receive
     * @param data_rx Pointer to array for storing received data
     * @return esp_err_t Return status of whole SPI transaction
     */
    esp_err_t writeReadBytes(spi_device_handle_t handle, uint8_t *data_tx, uint8_t length_rx, uint8_t *data_rx);

}; // class SPI

}   // namespace Am