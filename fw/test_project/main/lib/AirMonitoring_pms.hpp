#pragma once

#include "lib/AirMonitoring_pinout.hpp"
#include "driver/uart.h"
#include <algorithm>

namespace Am {
class PMS {
private:
    #pragma pack(push, 1)
    typedef struct {
        uint16_t framelen;
        uint16_t pm10_standard, pm25_standard, pm100_standard;
        uint16_t pm10_env, pm25_env, pm100_env;
        uint16_t particles_03um, particles_05um, particles_10um, particles_25um, particles_50um, particles_100um;
        uint16_t unused;
        uint16_t checksum;
    }pms5003_data_t, *Ppms5003_data_t;
    #pragma pack(pop)

    Ppms5003_data_t receivedData;
    uint8_t data_rx[30];


public:
    PMS() { }

    void init(){
        const uart_port_t uart_num = UART_NUM_1;
        uart_config_t uart_config = {
        .baud_rate = 9600,
        .data_bits = UART_DATA_8_BITS,
        .parity = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
        .rx_flow_ctrl_thresh = 122,
        };
        // Configure UART parameters
        ESP_ERROR_CHECK(uart_param_config(uart_num, &uart_config));
        ESP_ERROR_CHECK(uart_set_pin(uart_num, TX1, RX1, NULL, NULL));
        const int uart_buffer_size = (1024 * 2);
        QueueHandle_t uart_queue;
        ESP_ERROR_CHECK(uart_driver_install(uart_num, uart_buffer_size, uart_buffer_size, 10, &uart_queue, 0));
    }

    int readPMS() {
        const uart_port_t uart_num = UART_NUM_1;
        uint8_t data_receive[32];
        int length = 0;
        ESP_ERROR_CHECK(uart_get_buffered_data_len(uart_num, (size_t*)&length));
        length = uart_read_bytes(uart_num, data_receive, length, 100);
        if (length == 32 && data_receive[0] == 0x42 && data_receive[1] == 0x4d) {
            uint8_t temp;
            for (uint8_t i = 2; i != 32; i += 2) {
                temp = data_receive[i];
                data_receive[i] = data_receive[i+1];
                data_receive[i+1] = temp;
            }
            std::copy(data_receive + 2, data_receive + 31, data_rx);
        }
        uart_flush(uart_num);
        receivedData = (Ppms5003_data_t)data_rx;
        return length;
    }

    void printData() {
        for (uint8_t i = 0; i != 128; i++)
            printf("%#x ", data_rx[i]);
        printf("\r\n");
    }

    void printPM() {
        ESP_LOGI("PMS", "PM1.0: %d  PM2.5: %d   PM10: %d", receivedData->particles_10um, receivedData->particles_25um, receivedData->particles_100um);
    }

};  // class PMS

}   // namespace Am