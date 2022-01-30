#pragma once

#include "lib/AirMonitoring_i2c.hpp"
#include "lib/AirMonitoring_pinout.hpp"
#include <cstring>

#define BMP_REG_CHIP_ID 0x00
#define BMP_REG_ERR_REG 0x02
#define BMP_REG_STATUS 0x03
#define BMP_REG_DATA_0 0x04
#define BMP_REG_DATA_1 0x05
#define BMP_REG_DATA_2 0x06
#define BMP_REG_DATA_3 0x07
#define BMP_REG_DATA_4 0x08
#define BMP_REG_DATA_5 0x09
#define BMP_REG_SENSORTIME_0 0x0C
#define BMP_REG_SENSORTIME_1 0x0D
#define BMP_REG_SENSORTIME_2 0x0E
#define BMP_REG_EVENT 0x10
#define BMP_REG_INT_STATUS 0x11
// FIFO registers not included yet
#define BMP_REG_INT_CTRL 0x19
#define BMP_REG_IF_CONF 0x1A
#define BMP_REG_PWR_CTRL 0x1B
#define BMP_REG_OSR 0x1C
#define BMP_REG_ODR 0x1D
#define BMP_REG_CONFIG 0x1F
#define BMP_REG_CMD 0x7E

#define BMP_REG_T1 0x31
#define BMP_REG_T2 0x33
#define BMP_REG_T3 0x35
#define BMP_REG_P1 0x36
#define BMP_REG_P2 0x38
#define BMP_REG_P3 0x3A
#define BMP_REG_P4 0x3B
#define BMP_REG_P5 0x3C
#define BMP_REG_P6 0x3E
#define BMP_REG_P7 0x40
#define BMP_REG_P8 0x41
#define BMP_REG_P9 0x42
#define BMP_REG_P10 0x44
#define BMP_REG_P11 0x45

#define BMP_SOFTRESET_CODE 0xB6
#define BMP_PRESS_EN (1<<0)
#define BMP_TEMP_EN (1<<1)
#define BMP_DRDY_EN (1<<6)


namespace Am {
class BMP388 : public I2C {

private:
    int bmp_addr;
    uint8_t *data_rd = (uint8_t *) malloc(6);
    uint32_t data_pressure = 0;
    uint32_t data_temperature = 0;

    typedef enum {
        BMP_MODE_SLEEP = 0,
        BMP_MODE_FORCED = 1,
        BMP_MODE_NORMAL = 3
    } mode_t;

    typedef enum {
        OVERSAMPLING_1 = 0,
        OVERSAMPLING_2,
        OVERSAMPLING_4,
        OVERSAMPLING_8,
        OVERSAMPLING_16,
        OVERSAMPLING_32
    } oversampling_t;

    typedef enum {
        COEF_0 = 0,
        COEF_1,
        COEF_3,
        COEF_7,
        COEF_15,
        COEF_31,
        COEF_63,
        COEF_127
    } filter_t;

    #pragma pack(push, 1)
    typedef struct {
        uint16_t T1;
        uint16_t T2;
        int8_t T3;
        int16_t P1;
        int16_t P2;
        int8_t P3;
        int8_t P4;
        uint16_t P5;
        uint16_t P6;
        int8_t P7;
        int8_t P8;
        int16_t P9;
        int8_t P10;
        int8_t P11;
    } calib_data_t, *Pcalib_data_t;
    #pragma pack(pop)

    typedef struct {
        double T1;
        double T2;
        double T3;
        double temperature;

        double P1;
        double P2;
        double P3;
        double P4;
        double P5;
        double P6;
        double P7;
        double P8;
        double P9;
        double P10;
        double P11;
        double pressure;
    } coefficients_t;

    Pcalib_data_t calib_data;
    coefficients_t c_data;

    void readReg16(int addr, uint8_t reg, uint16_t *r) {
        uint8_t data[] = {0,0};
        I2C::readBytes(addr, reg, data, 2);
        *r = (data[1]<<8) | data[0];
    }

public:
    BMP388(int addr){
        bmp_addr = addr;
    }

    void init(oversampling_t temp = OVERSAMPLING_1, oversampling_t press = OVERSAMPLING_1, filter_t filt = COEF_0) {
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

    void forceRead(bool press = 1, bool temp = 1){
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

    void read() {
        while (1)
        {
            if ((readStatus() & (1<<5)) != 0)
                break;
        }
        I2C::readBytes(bmp_addr, BMP_REG_DATA_0, data_rd, 6);
        data_pressure = (data_rd[2]<<16) | (data_rd[1]<<8) | data_rd[0];
        data_temperature = (data_rd[5]<<16) | (data_rd[4]<<8) | data_rd[3];
    }

    void readPressure(){
        while (1)
        {
            if ((readStatus() & (1<<5)) != 0)
                break;
        }        
        I2C::readBytes(bmp_addr, BMP_REG_DATA_0, data_rd, 3);
    }

    void readTemperature() {
        I2C::readBytes(bmp_addr, BMP_REG_DATA_3, data_rd+3, 3);
    }

    void print(){
        ESP_LOGI("BMP", "%#x %#x %#x %#x %#x %#x", data_rd[5], data_rd[4], data_rd[3], data_rd[2], data_rd[1], data_rd[0]);
    }

    uint8_t readID(){
        uint8_t data = 0;
        I2C::readBytes(bmp_addr, BMP_REG_CHIP_ID, &data, 1);
        ESP_LOGI("BMP", "id: %#x", data);
        return data;
    }

    void checkERR() {
        uint8_t data = 0;
        I2C::readBytes(bmp_addr, BMP_REG_ERR_REG, &data, 1);
        ESP_LOGI("BMP", "err: %#x", data);
    }

    uint8_t readStatus() {
        uint8_t data = 0;
        I2C::readBytes(bmp_addr, BMP_REG_STATUS, &data, 1);
        // ESP_LOGI("BMP", "stat: %#x", data);
        return data;
    }

    void readPower() {
        uint8_t data = 0;
        I2C::readBytes(bmp_addr, BMP_REG_PWR_CTRL, &data, 1);
        ESP_LOGI("BMP", "pwr: %#x", data);
    }

    void softReset() {
        I2C::writeByteToReg(bmp_addr, BMP_REG_CMD, BMP_SOFTRESET_CODE);
        while(1)
        {
            if ((readStatus() & (1<<4)) != 0)
                break;
            // ESP_LOGI("BMP", "Wait for reset...");
        }
    }

    void readCalibrationData() {
        uint8_t *data_cal = (uint8_t *) malloc(21);
        I2C::readBytes(bmp_addr, BMP_REG_T1, data_cal, 21);
        for (uint8_t i = 0; i != 21; i++)
            ESP_LOGI("cal_data", "%#x", data_cal[i]);
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
        ESP_LOGI("Calib", "%f %f %f %f %f %f %f %f %f %f %f %f %f %.20f %d", c_data.T1, c_data.T2, c_data.T3, c_data.P1, c_data.P2, c_data.P3, c_data.P4, c_data.P5, c_data.P6, c_data.P7, c_data.P8, c_data.P9, c_data.P10, c_data.P11, calib_data->P11);
        ESP_LOGI("Calib", "%d   %d", calib_data->P11, (int8_t)data_cal[20]);
    }

    void compensateTemperature(uint32_t uncomp_temp) {
        double part_data1;
        double part_data2;

        part_data1 = double(uncomp_temp - c_data.T1);
        part_data2 = double(part_data1 * c_data.T2);

        c_data.temperature = part_data2 + (part_data1 * part_data1) * c_data.T3;
    }

    void compensatePressure(uint32_t uncomp_press) {
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

    void compensate() {
        compensateTemperature(data_temperature);
        compensatePressure(data_pressure);
        ESP_LOGI("DEB", "%d   %d", data_temperature, data_pressure);
    }

    double getPressure() {
        return c_data.pressure;
    }

    double getTemp() {
        return c_data.temperature;
    }

};   // class BMP

} // namespace Am