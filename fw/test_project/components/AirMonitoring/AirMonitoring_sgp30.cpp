#include "AirMonitoring_sgp30.hpp"

#include "esp_log.h"
#include "math.h"

namespace Am {

SGP::SGP(int addr) {
    sgp_addr = addr;
}

SGP::~SGP() {}

void SGP::init() {
    I2C::writeBytes(sgp_addr, 0x0320);
}

void SGP::measure() {
    I2C::writeBytes(sgp_addr, 0x0820);
    vTaskDelay(12 / portTICK_RATE_MS);
    I2C::readBytes(sgp_addr, data_rd, 6);
}

uint16_t SGP::getTVOC() {
    uint16_t tvoc = 0;
    tvoc |= data_rd[3] << 8;
    tvoc |= data_rd[4];
    return tvoc;
}

uint16_t SGP::getCO2() {
    uint16_t co2 = 0;
    co2 |= data_rd[0] << 8;
    co2 |= data_rd[1];
    return co2;
}

void SGP::printRAW() {
    ESP_LOGI("SGP_dev", "%d %d %d %d %d %d", data_rd[0], data_rd[1], data_rd[2], data_rd[3], data_rd[4], data_rd[5]);
}

void SGP::getSerialID() {
    I2C::writeBytes(sgp_addr, 0x8236);
    I2C::readBytes(sgp_addr, id, 9);
}

void SGP::printID() {
    ESP_LOGI("SGP_DEVID", "%x %x %x %x %x %x %x %x %x", id[0], id[1], id[2], id[3], id[4], id[5], id[6], id[7], id[8]);
}

void SGP::setHumidity(float humidity, float temperature) {
    float absHumidity = 216.7 * (((humidity/100) * 6.112 * exp((17.62 * temperature) / (243.12 * temperature))) / (273.15 + temperature));
    absHumidity = absHumidity * 100;
}

}   // namespace Am