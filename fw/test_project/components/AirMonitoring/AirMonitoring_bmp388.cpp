#include "AirMonitoring_bmp388.hpp"

#include "AirMonitoring_i2c.hpp"
#include "AirMonitoring_pinout.hpp"
#include <cstring>
#include <cmath>

namespace Am {

void BMP388::readReg16(int addr, uint8_t reg, uint16_t *r) {
    uint8_t data[] = {0,0};
    I2C::readBytes(addr, reg, data, 2);
    *r = (data[1]<<8) | data[0];
}

BMP388::BMP388(int addr){
    bmp_addr = addr;
}

BMP388::~BMP388(){}

void BMP388::init(oversampling_t temp, oversampling_t press, filter_t filt) {
    uint8_t data = 0;
    I2C::writeByteToReg(bmp_addr, BMP_REG_OSR, uint8_t((temp<<3) | press));
    while(1)
    {
        if ((readStatus() & (1<<4)) != 0)
            break;
    }
    I2C::writeByteToReg(bmp_addr, BMP_REG_CONFIG, uint8_t(filt));
    while(1)
    {
        if ((readStatus() & (1<<4)) != 0)
            break;
    }
    I2C::writeByteToReg(bmp_addr, BMP_REG_INT_CTRL, BMP_DRDY_EN);
    while(1)
    {
        if ((readStatus() & (1<<4)) != 0)
            break;
    }
}

void BMP388::forceRead(bool press, bool temp){
    uint8_t ctrl = 0;
    if (press == 1)
        ctrl |= BMP_PRESS_EN;
    if (temp == 1)
        ctrl |= BMP_TEMP_EN;
    ctrl |= (1<<5); // Force read setup
    I2C::writeByteToReg(bmp_addr, BMP_REG_PWR_CTRL, ctrl);
    while(1)
    {
        if ((readStatus() & (1<<4)) != 0)
            break;
    }
}

void BMP388::read() {
    while (1)
    {
        if ((readStatus() & (1<<5)) != 0)
            break;
    }
    I2C::readBytes(bmp_addr, BMP_REG_DATA_0, data_rd, 6);
    data_pressure = (data_rd[2]<<16) | (data_rd[1]<<8) | data_rd[0];
    data_temperature = (data_rd[5]<<16) | (data_rd[4]<<8) | data_rd[3];
}

void BMP388::readPressure(){
    while (1)
    {
        if ((readStatus() & (1<<5)) != 0)
            break;
    }        
    I2C::readBytes(bmp_addr, BMP_REG_DATA_0, data_rd, 3);
}

void BMP388::readTemperature() {
    I2C::readBytes(bmp_addr, BMP_REG_DATA_3, data_rd+3, 3);
}

void BMP388::print(){
    ESP_LOGI("BMP", "%#x %#x %#x %#x %#x %#x", data_rd[5], data_rd[4], data_rd[3], data_rd[2], data_rd[1], data_rd[0]);
}

uint8_t BMP388::readID(){
    uint8_t data = 0;
    I2C::readBytes(bmp_addr, BMP_REG_CHIP_ID, &data, 1);
    ESP_LOGI("BMP", "id: %#x", data);
    return data;
}

void BMP388::checkERR() {
    uint8_t data = 0;
    I2C::readBytes(bmp_addr, BMP_REG_ERR_REG, &data, 1);
    ESP_LOGI("BMP", "err: %#x", data);
}

uint8_t BMP388::readStatus() {
    uint8_t data = 0;
    I2C::readBytes(bmp_addr, BMP_REG_STATUS, &data, 1);
    // ESP_LOGI("BMP", "stat: %#x", data);
    return data;
}

void BMP388::readPower() {
    uint8_t data = 0;
    I2C::readBytes(bmp_addr, BMP_REG_PWR_CTRL, &data, 1);
    ESP_LOGI("BMP", "pwr: %#x", data);
}

void BMP388::softReset() {
    I2C::writeByteToReg(bmp_addr, BMP_REG_CMD, BMP_SOFTRESET_CODE);
    while(1)
    {
        if ((readStatus() & (1<<4)) != 0)
            break;
        // ESP_LOGI("BMP", "Wait for reset...");
    }
}

void BMP388::readCalibrationData() {
    uint8_t *data_cal = (uint8_t *) malloc(21);
    I2C::readBytes(bmp_addr, BMP_REG_T1, data_cal, 21);
    for (uint8_t i = 0; i != 21; i++)
        // ESP_LOGI("cal_data", "%#x", data_cal[i]);
    // memcpy(&calib_data, data_cal, sizeof(calib_data_t));

    calib_data = (Pcalib_data_t)data_cal;

    // readReg16(bmp_addr, BMP_REG_T1, &calib_data.T1);
    // readReg16(bmp_addr, BMP_REG_T2, &calib_data.T2);
    // I2C::readBytes(bmp_addr, BMP_REG_T3, &calib_data.T3, 1);
    // readReg16(bmp_addr, BMP_REG_P1, &calib_data.P1);
    // readReg16(bmp_addr, BMP_REG_P2, &calib_data.P2);
    // I2C::readBytes(bmp_addr, BMP_REG_P3, &calib_data.P3, 1);
    // I2C::readBytes(bmp_addr, BMP_REG_P4, &calib_data.P4, 1);
    // readReg16(bmp_addr, BMP_REG_P5, &calib_data.P5);
    // readReg16(bmp_addr, BMP_REG_P6, &calib_data.P6);
    // I2C::readBytes(bmp_addr, BMP_REG_P7, &calib_data.P7, 1);
    // I2C::readBytes(bmp_addr, BMP_REG_P8, &calib_data.P8, 1);
    // readReg16(bmp_addr, BMP_REG_P9, &calib_data.P9);
    // I2C::readBytes(bmp_addr, BMP_REG_P10, &calib_data.P10, 1);
    // I2C::readBytes(bmp_addr, BMP_REG_P11, &calib_data.P11, 1);

    c_data.T1 = calib_data->T1 / double(0.00390625f);         // 2^-8
    c_data.T2 = calib_data->T2 / double(1073741824.0f);         // 2^30
    c_data.T3 = calib_data->T3 / double(281474976710656.0f);    // 2^48
    c_data.P1 = (calib_data->P1 - 16384) / double(1048576.0f);  // 2^14  2^20
    c_data.P2 = (calib_data->P2 - 16384) / double(536870912.0f);    // 2^14  2^29
    c_data.P3 = calib_data->P3 / double(4294967296.0f);         // 2^32
    c_data.P4 = calib_data->P4 / double(137438953472.0f);       // 2^37
    c_data.P5 = calib_data->P5 / double(0.125f);              // 2^-3
    c_data.P6 = calib_data->P6 / double(64.0f);                 // 2^6
    c_data.P7 = calib_data->P7 / double(256.0f);                // 2^8
    c_data.P8 = calib_data->P8 / double(32768.0f);              // 2^15
    c_data.P9 = calib_data->P9 / double(281474976710656.0f);    // 2^48
    c_data.P10 = calib_data->P10 / double(281474976710656.0f);  // 2^48
    c_data.P11 = calib_data->P11 / double(36893488147419103232.0f); // 2^65
    // ESP_LOGI("Calib", "%f %f %f %f %f %f %f %f %f %f %f %f %f %.20f %d", c_data.T1, c_data.T2, c_data.T3, c_data.P1, c_data.P2, c_data.P3, c_data.P4, c_data.P5, c_data.P6, c_data.P7, c_data.P8, c_data.P9, c_data.P10, c_data.P11, calib_data->P11);
    // ESP_LOGI("Calib", "%d   %d", calib_data->P11, (int8_t)data_cal[20]);
}

void BMP388::compensateTemperature(uint32_t uncomp_temp) {
    double part_data1;
    double part_data2;

    part_data1 = double(uncomp_temp - c_data.T1);
    part_data2 = double(part_data1 * c_data.T2);

    c_data.temperature = part_data2 + (part_data1 * part_data1) * c_data.T3;
}

void BMP388::compensatePressure(uint32_t uncomp_press) {
    double part_data1;
    double part_data2;
    double part_data3;
    double part_data4;
    double part_out1;
    double part_out2;

    part_data1 = c_data.P6 * c_data.temperature;
    part_data2 = c_data.P7 * (c_data.temperature * c_data.temperature);
    part_data3 = c_data.P8 * (c_data.temperature * c_data.temperature * c_data.temperature);
    part_out1 = c_data.P5 + part_data1 + part_data2 + part_data3;

    part_data1 = c_data.P2 * c_data.temperature;
    part_data2 = c_data.P3 * (c_data.temperature * c_data.temperature);
    part_data3 = c_data.P4 * (c_data.temperature * c_data.temperature * c_data.temperature);
    part_out2 = double(uncomp_press) * (c_data.P1 + part_data1 + part_data2 + part_data3);

    part_data1 = double(uncomp_press) * double(uncomp_press);
    part_data2 = c_data.P9 + c_data.P10 * c_data.temperature;
    part_data3 = part_data1 * part_data2;
    part_data4 = part_data3 + (double(uncomp_press) * double(uncomp_press) * double(uncomp_press)) * c_data.P11;

    c_data.pressure = part_out1 + part_out2 + part_data4;
}

void BMP388::compensate() {
    compensateTemperature(data_temperature);
    compensatePressure(data_pressure);
}

double BMP388::getPressure() {
    return c_data.pressure;
}

double BMP388::getTemp() {
    return c_data.temperature;
}

double BMP388::calcRelativePressure(float temperature, int altitude) {
    double averTemp = temperature + altitude * 0.0025f;
    return (c_data.pressure / exp(-altitude * (9.80665f)/(287.04f * (averTemp + 273.15f))));
}

} // namespace Am