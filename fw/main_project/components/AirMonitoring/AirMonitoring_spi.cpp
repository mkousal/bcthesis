#include "AirMonitoring_spi.hpp"

#include "AirMonitoring_pinout.hpp"
#include "driver/spi_common.h"
#include "driver/spi_master.h"
#include "esp_log.h"
#include "esp_err.h"
#include <cstring>

namespace Am {

SPI::SPI() {}

SPI::~SPI() {}

esp_err_t SPI::begin(gpio_num_t mosi, gpio_num_t miso, gpio_num_t sclk) {
    spi_bus_config_t cfg;
    memset(&cfg, 0, sizeof(spi_bus_config_t));
    cfg.mosi_io_num = mosi;
    cfg.miso_io_num = miso;
    cfg.sclk_io_num = sclk;
    cfg.quadhd_io_num = -1; // not used
    cfg.quadwp_io_num = -1; // not used
    cfg.max_transfer_sz = 0;    // -> 4092
    return spi_bus_initialize(host, &cfg, SPI_DMA_CH_AUTO);
}

esp_err_t SPI::addDevice(uint8_t mode, uint32_t clock_speed_hz, gpio_num_t cs_pin, spi_device_handle_t *handle) {
    spi_device_interface_config_t cfg;
    cfg.command_bits = 0;
    cfg.address_bits = 8;
    cfg.dummy_bits = 0;
    cfg.mode = mode;
    cfg.duty_cycle_pos = 0; // 0 = 128 -> 50%
    cfg.cs_ena_pretrans = 0;
    cfg.cs_ena_posttrans = 0;
    cfg.clock_speed_hz = clock_speed_hz;
    cfg.spics_io_num = cs_pin;
    cfg.flags = 0;
    cfg.queue_size = 1;
    cfg.pre_cb = NULL;
    cfg.post_cb = NULL;
    return spi_bus_add_device(host, &cfg, handle);
}

esp_err_t SPI::removeDevice(spi_device_handle_t handle) {
    return spi_bus_remove_device(handle);
}

esp_err_t SPI::writeReadBytes(spi_device_handle_t handle, uint8_t *data_tx, uint8_t length_rx, uint8_t *data_rx) {
    spi_transaction_t cmd;
    cmd.flags = 0;
    cmd.cmd = 0;
    cmd.addr = 0;
    cmd.length = length_rx * 8;
    cmd.rxlength = 0;
    cmd.user = NULL;
    cmd.tx_buffer = data_tx;
    cmd.rx_buffer = data_rx;
    return spi_device_transmit(handle, &cmd);
}

}   // namespace Am