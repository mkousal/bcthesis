/**
 * @file AirMonitoring_wifi.hpp
 * @author Martin Kousal ()
 * @brief Simple library to use WiFi peripheral
 * @version 0.1
 * @date 2022-04-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once

#include "esp_system.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_log.h"
#include "freertos/event_groups.h"
#include "freertos/queue.h"
#include "freertos/task.h"
#include "freertos/FreeRTOS.h"
#include "nvs_flash.h"
 

#define WIFI_CONNECTED_BIT  BIT0
#define WIFI_FAIL_BIT       BIT1

namespace Am {

/**
 * @brief Event group handler variable to store WiFi events
 * 
 */
static EventGroupHandle_t s_wifi_event_group;

/**
 * @brief Variable to store number of retries of reconnecting to WiFi AP
 * 
 */
static int s_retry_num = 0;

/**
 * @brief Callback function to solve events from WiFi peripheral, e.g. reconnecting, connect fail and successful connection
 * 
 * @param arg 
 * @param event_base 
 * @param event_id 
 * @param event_data 
 */
static void event_handler(void* arg, esp_event_base_t event_base, int32_t event_id, void* event_data);

/**
 * @brief Function to initialize WiFi peripheral as WIFI_STA and start connecting to AP with given WiFi SSID and password
 * 
 */
void wifi_init_sta(void);

}