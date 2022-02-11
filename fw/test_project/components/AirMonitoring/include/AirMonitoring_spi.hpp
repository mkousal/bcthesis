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
    spi_host_device_t host = VSPI_HOST;

public:
    SPI();

    ~SPI();

    esp_err_t begin(gpio_num_t mosi, gpio_num_t miso, gpio_num_t sclk);

    esp_err_t addDevice(uint8_t mode, uint32_t clock_speed_hz, gpio_num_t cs_pin, spi_device_handle_t *handle);

    esp_err_t removeDevice(spi_device_handle_t handle);

    esp_err_t writeReadBytes(spi_device_handle_t handle, uint8_t *data_tx, uint8_t length_rx, uint8_t *data_rx);

}; // class SPI

}   // namespace Am