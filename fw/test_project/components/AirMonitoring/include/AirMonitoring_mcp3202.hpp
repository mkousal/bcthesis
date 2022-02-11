#pragma once

#include "AirMonitoring_pinout.hpp"
#include "AirMonitoring_spi.hpp"

namespace Am {

class MCP3202 : public SPI{
private:
    spi_device_handle_t device;
    uint8_t *data = (uint8_t *) malloc(3);
public:
    MCP3202();

    ~MCP3202();

    esp_err_t init();

    void read(uint8_t channel);

    uint16_t getData();

    float getUVmW();

}; // class MCP3202

}   // namespace Am