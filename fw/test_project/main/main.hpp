#pragma once

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "cJSON.h"
#include "mqtt_client.h"
#include "esp_sleep.h"

#include "AirMonitoring_pinout.hpp"
#include "AirMonitoring_power.hpp"
#include "AirMonitoring_i2c.hpp"
#include "AirMonitoring_sht.hpp"
#include "AirMonitoring_veml.hpp"
#include "AirMonitoring_bmp388.hpp"
#include "AirMonitoring_pms.hpp"
#include "AirMonitoring_spi.hpp"
#include "AirMonitoring_mcp3202.hpp"
#include "AirMonitoring_wifi.hpp"

using namespace Am;

Power power;
SPI spi;
MCP3202 mcp;
PMS pms;  
SHT sht(0x44, I2C_MASTER_SDA, I2C_MASTER_SCL);      
BMP388 bmp(0x77);
VEML7700 light(0x10);
cJSON *msg;
uint8_t taskChecker = 0;

#define DEBUG