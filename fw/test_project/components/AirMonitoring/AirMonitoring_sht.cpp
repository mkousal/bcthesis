#include "AirMonitoring_sht.hpp"

#include "AirMonitoring_i2c.hpp"
#include "AirMonitoring_pinout.hpp"

namespace Am {

SHT::SHT(int addr, gpio_num_t SDA, gpio_num_t SCL){
    sht_addr = addr;
    sda = SDA;
    scl = SCL;
}

SHT::~SHT() {}

void SHT::init(){
    I2C::master_init(sda, scl);
}

void SHT::sendRequestToRead() {
    I2C::writeByte(sht_addr, readCommand);
}

void SHT::read() {
    I2C::readBytes(sht_addr, data_rd, 6);
}

float SHT::getTemp() {
    return (-45+175*(((data_rd[0]<<8) | data_rd[1])*1.0/65535));
}

float SHT::getHum() {
    return (-6+125*(((data_rd[3]<<8) | data_rd[4])*1.0/65535));
}

} // namespace Am