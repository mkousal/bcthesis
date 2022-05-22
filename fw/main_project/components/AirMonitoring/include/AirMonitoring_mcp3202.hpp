/**
 * @file AirMonitoring_mcp3202.hpp
 * @author Martin Kousal ()
 * @brief Simple library to use ADC MCP3202 via SPI bus
 * @version 0.1
 * @date 2022-04-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once

#include "AirMonitoring_pinout.hpp"
#include "AirMonitoring_spi.hpp"

namespace Am {

class MCP3202 : public SPI{
private:
    /**
     * @brief SPI device handle variable to store created SPI object
     * 
     */
    spi_device_handle_t device;
    /**
     * @brief Variable to store received data
     * 
     */
    uint8_t *data = (uint8_t *) malloc(3);
public:
    /**
     * @brief Construct a new MCP3202 object
     * 
     */
    MCP3202();

    /**
     * @brief Destroy the MCP3202 object
     * 
     */
    ~MCP3202();

    /**
     * @brief Initialize MCP3202 at SPI bus, select CS pin and communicating frequency
     * 
     * @return esp_err_t Returns status of adding SPI device
     */
    esp_err_t init();

    /**
     * @brief Send command to read ADC data from given channel (0 or 1)
     * 
     * @param channel Channel to read (0/1)
     */
    void read(uint8_t channel);

    /**
     * @brief Read measured analog value
     * 
     * @return uint16_t Measured value
     */
    uint16_t getData();

    /**
     * @brief Calculate value UV/mW with measured AD value
     * 
     * @return float Calculated UV value
     */
    float getUVmW();

}; // class MCP3202

}   // namespace Am