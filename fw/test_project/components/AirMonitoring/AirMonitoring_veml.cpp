#include "AirMonitoring_veml.hpp"

#include "AirMonitoring_i2c.hpp"
#include "AirMonitoring_pinout.hpp"

namespace Am{

VEML7700::VEML7700(int addr) {
    veml_addr = addr;
}

VEML7700::~VEML7700() {}

void VEML7700::init(powerState_t pow, integrationTime_t time, gain_t gain) {
    uint16_t d = pow;
    d |= (time << 6);
    d |= (gain << 11);

    I2C::writeBytes(veml_addr, 0, d, size_t(2));
    vTaskDelay(5 / portTICK_RATE_MS);
}

void VEML7700::read() {
    I2C::readBytes(veml_addr, uint8_t(readCMD), data_rd, 2);
}

int VEML7700::getValue() {
    return (data_rd[0]<<8) | data_rd[1];
}

}   // namespace Am