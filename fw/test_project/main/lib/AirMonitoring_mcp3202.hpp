#pragma once

#include "AirMonitoring_pinout.hpp"
#include "AirMonitoring_spi.hpp"

namespace Am {

class MCP3202 {
private:
    spi_device_handle_t device;
    uint8_t *data = (uint8_t *) malloc(3);
public:
    MCP3202() {}

    esp_err_t init() {
        return spi.addDevice(0, 1000000, CS, &device);
    }

    void read(uint8_t channel) {
        uint8_t cmd[3] = {1, 0, 0};
        if (channel == 0)
            cmd[1] |= (1<<7);
        else
            cmd[1] |= (3<<6);
        spi.writeReadBytes(device, cmd, 3, data);
    }

    uint16_t getData() {
        uint16_t val = (data[1]<<8) | data[2];
        // ESP_LOGI("MCP3202", "%d", val);
        return val;
    }

    float getUV() {

        float voltage = ((float)getData()/4095) * 3.3f;
        if (voltage < 1.0)
            return 0;
        voltage -= 1.0; // starting bias
        return voltage * (15.0 / 1.8);
    }


}; // class MCP3202

MCP3202 mcp;

}   // namespace Am