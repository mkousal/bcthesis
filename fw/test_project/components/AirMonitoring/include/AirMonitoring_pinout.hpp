/**
 * @file AirMonitoring_pinout.hpp
 * @author Martin Kousal ()
 * @brief Pinout defines for Air monitoring main board
 * @version 0.1
 * @date 2022-04-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once

#include <driver/gpio.h>
#include <driver/adc.h>

namespace Am {

static const gpio_num_t IO0 = GPIO_NUM_0;
static const gpio_num_t IO2 = GPIO_NUM_2;
static const gpio_num_t IO12 = GPIO_NUM_12;
static const gpio_num_t IO4 = GPIO_NUM_4;
static const gpio_num_t IO5 = GPIO_NUM_5;
static const gpio_num_t IO13 = GPIO_NUM_13;
static const gpio_num_t IO14 = GPIO_NUM_14;
static const gpio_num_t IO15 = GPIO_NUM_15;
static const gpio_num_t IO16 = GPIO_NUM_16;
static const gpio_num_t IO17 = GPIO_NUM_17;
static const gpio_num_t IO18 = GPIO_NUM_18;
static const gpio_num_t IO19 = GPIO_NUM_19;
static const gpio_num_t IO21 = GPIO_NUM_21;
static const gpio_num_t IO25 = GPIO_NUM_25;
static const gpio_num_t IO26 = GPIO_NUM_26;
static const gpio_num_t IO27 = GPIO_NUM_27;
static const gpio_num_t IO32 = GPIO_NUM_32;
static const gpio_num_t IO33 = GPIO_NUM_33;
static const gpio_num_t IO34 = GPIO_NUM_34;
static const gpio_num_t IO35 = GPIO_NUM_35;
static const gpio_num_t IO23 = GPIO_NUM_23;

static const gpio_num_t PMS_EN = IO4;
static const gpio_num_t CS = IO5;
static const gpio_num_t CS_LORA = IO12;
static const gpio_num_t LDO_EN = IO13;
static const gpio_num_t LORA_EN = IO14;
static const gpio_num_t LED = IO15;
static const gpio_num_t RX1 = IO16;
static const gpio_num_t TX1 = IO17;
static const gpio_num_t SCLK = IO18;
static const gpio_num_t MISO = IO19;
static const gpio_num_t MOSI = IO23;
static const gpio_num_t SEN_VDD_EN = IO25;
static const gpio_num_t SGP_EN = IO26;
static const gpio_num_t POWER_OFF = IO27;
static const gpio_num_t LORA_RST = IO32;
static const gpio_num_t DIO0 = IO33;
// static const gpio_num_t IO34 = ADC_VIN;
static const gpio_num_t SWITCH = IO35;

static const gpio_num_t I2C_MASTER_SDA = GPIO_NUM_21;
static const gpio_num_t I2C_MASTER_SCL = GPIO_NUM_22;

static const adc_unit_t BATT_ADC_UNIT = ADC_UNIT_1;
static const adc1_channel_t BATT_ADC_CHANNEL = ADC1_CHANNEL_6;

} // namespace Am