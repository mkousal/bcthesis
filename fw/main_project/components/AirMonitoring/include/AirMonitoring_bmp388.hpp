/**
 * @file AirMonitoring_bmp388.hpp
 * @author Martin Kousal ()
 * @brief Simple library to communicate with BMP388 absolute barometric pressure sensor via I2C bus
 * @version 0.1
 * @date 2022-04-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once

#include "AirMonitoring_i2c.hpp"
#include "AirMonitoring_pinout.hpp"
#include <cstring>
#include <cmath>

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
    /**
     * @brief Variable to store device address
     * 
     */
    int bmp_addr;

    /**
     * @brief 6 bytes variable to store received data from sensor
     * 
     */
    uint8_t *data_rd = (uint8_t *) malloc(6);

    /**
     * @brief Variable to store measured pressure value
     * 
     */
    uint32_t data_pressure = 0;

    /**
     * @brief Variable to store measured temperature value
     * 
     */
    uint32_t data_temperature = 0;

    /**
     * @brief Enumeration of BMP sensor sleep modes
     * 
     */
    typedef enum {
        BMP_MODE_SLEEP = 0,
        BMP_MODE_FORCED = 1,
        BMP_MODE_NORMAL = 3
    } mode_t;

    /**
     * @brief Enumeration of BMP sensor oversampling options
     * 
     */
    typedef enum {
        OVERSAMPLING_1 = 0,
        OVERSAMPLING_2,
        OVERSAMPLING_4,
        OVERSAMPLING_8,
        OVERSAMPLING_16,
        OVERSAMPLING_32
    } oversampling_t;

    /**
     * @brief Enumeration of BMP sensor coefficient options
     * 
     */
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

    /**
     * @brief Structure of received calibration data values from sensor
     * 
     */
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

    /**
     * @brief Structure of received measured values
     * 
     */
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

    /**
     * @brief Reads 16 bit values from register
     * 
     * @param addr Addres of I2C device
     * @param reg 8 bit register address
     * @param r 16 bit variable to store received data
     */
    void readReg16(int addr, uint8_t reg, uint16_t *r);

public:
    /**
     * @brief Construct a new BMP388 object
     * 
     * @param addr I2C device address
     */
    BMP388(int addr);

    /**
     * @brief Destroy the BMP388 object
     * 
     */
    ~BMP388();

    /**
     * @brief Initialize sensor and set parameters of measuring
     * 
     * @param temp Temperature oversampling value from \p oversampling_t structure
     * @param press Pressure oversampling value from \p oversampling_t structure
     * @param filt IIR filter type from \p filter_t structure
     */
    void init(oversampling_t temp = OVERSAMPLING_1, oversampling_t press = OVERSAMPLING_1, filter_t filt = COEF_0);

    /**
     * @brief Force read pressure or temperature values
     * 
     * @param press Enable pressure measurement (default value - true)
     * @param temp Enable temperature measurement (default value - true)
     */
    void forceRead(bool press = 1, bool temp = 1);

    /**
     * @brief Read measured values
     * 
     */
    void read();

    /**
     * @brief Measure and read pressure value
     * 
     */
    void readPressure();

    /**
     * @brief Measure and read temperature value
     * 
     */
    void readTemperature();

    /**
     * @brief Print raw measured data for debug purposes
     * 
     */
    void print();

    /**
     * @brief Read sensor ID and print to UART
     * 
     * @return uint8_t Received data
     */
    uint8_t readID();

    /**
     * @brief Print to UART error state register of sensor
     * 
     */
    void checkERR();

    /**
     * @brief Read sensor status register
     * 
     * @return uint8_t Stats of sensor
     */
    uint8_t readStatus();

    /**
     * @brief Print to UART power register of sensor
     * 
     */
    void readPower();

    /**
     * @brief Soft reset of sensor
     * 
     */
    void softReset();

    /**
     * @brief Read calibration data, process them and store to the prepared structure
     * 
     */
    void readCalibrationData();

    /**
     * @brief Compensate measured temperature with calibration data
     * 
     * @param uncomp_temp Uncompensated measured temperature
     */
    void compensateTemperature(uint32_t uncomp_temp);

    /**
     * @brief Compensate measured pressure with calibration data
     * 
     * @param uncomp_press Uncompensated measured pressure
     */
    void compensatePressure(uint32_t uncomp_press);

    /**
     * @brief Compensate measured temperature and pressure
     * 
     */
    void compensate();

    /**
     * @brief Get measured pressure from local variable
     * 
     * @return double Measured pressure
     */
    double getPressure();

    /**
     * @brief Get measured temperature from local variable
     * 
     * @return double Measured pressure
     */
    double getTemp();

    /**
     * @brief Calculate relative pressure to the sea level with given temperature and altitude
     * 
     * @param temperature Measured actual temperature
     * @param altitude Altitude in which the sensor is installed
     * @return double Relative pressure to the sea level
     */
    double calcRelativePressure(float temperature, int altitude);

};   // class BMP

} // namespace Am