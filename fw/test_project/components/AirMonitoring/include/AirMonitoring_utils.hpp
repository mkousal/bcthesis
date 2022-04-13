#pragma once

#include "AirMonitoring_pinout.hpp"
#include "../../ttn-esp32/include/TheThingsNetwork.h"

namespace Am {

/**
 * @brief Status flags to store current status for process controlling
 * 
 */
#define I2C_CHECKER 0x01
#define SPI_CHECKER 0x02
#define PMS_CHECKER 0x04
#define SGP_CHECKER 0x08
#define MEAS_DONE_CHECKER 0x0F
#define WIFI_CHECKER 0x80
#define TTN_CHECKER 0x40
#define LORAWAN_CHECKER 0x20

static volatile uint8_t taskStatus = 0;

/**
 * @brief Set task checker selected flag to true
 * 
 * @param flag Status flag to be set
 */
void setTaskChecker(uint8_t flag);

/**
 * @brief Get task checker selected flag status
 * 
 * @param flag Status flag to be returned
 * @return bool Return true if given flag is set
 */
bool getTaskChecker(uint8_t flag);

/**
 * @brief Reset task checker selected flag or all flags with second parameter
 * 
 * @param flag Status flag to be resetted
 * @param all Set to true if clearing all flags of task checker is needed
 */
void resetTaskChecker(uint8_t flag, bool all = false);

/**
 * @brief Callback function for LoRaWAN receiving messages
 * 
 * @param message Received message
 * @param length Length of message
 * @param port Port at which message was received
 */
void messageReceived(const uint8_t *message, size_t length, ttn_port_t port);

}   // namespace Am