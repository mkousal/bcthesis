#include "AirMonitoring_mcp3202.hpp"

#include "AirMonitoring_pinout.hpp"

namespace Am {

MCP3202::MCP3202() {}

MCP3202::~MCP3202() {}

esp_err_t MCP3202::init() {
    return SPI::addDevice(0, 1000000, CS, &device);
}

void MCP3202::read(uint8_t channel) {
    uint8_t cmd[3] = {1, 0, 0};
    if (channel == 0)
        cmd[1] |= (1<<7);
    else
        cmd[1] |= (3<<6);
    SPI::writeReadBytes(device, cmd, 3, data);
}

uint16_t MCP3202::getData() {
    uint16_t val = (data[1]<<8) | data[2];
    // ESP_LOGI("MCP3202", "%d", val);
    return val;
}

float MCP3202::getUVmW() {

    float voltage = ((float)getData()/4095) * 3.3f;
    if (voltage < 1.0)
        return 0;
    else {
        voltage -= 1.0; // starting bias
        return voltage * (15.0 / 1.8);
    }
}

}   // namespace Am