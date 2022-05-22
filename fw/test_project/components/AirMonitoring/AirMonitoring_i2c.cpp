#include "AirMonitoring_i2c.hpp"

#include "AirMonitoring_pinout.hpp"
#include "driver/i2c.h"
#include "esp_log.h"
#include "esp_err.h"

namespace Am {

I2C::I2C(uint8_t port){
    i2c_master_port = port;
}

I2C::~I2C(){}

esp_err_t I2C::master_init(gpio_num_t SDA, gpio_num_t SCL){
    i2c_config_t conf = {
        .mode = I2C_MODE_MASTER,
        .sda_io_num = SDA,
        .scl_io_num = SCL,
        .sda_pullup_en = GPIO_PULLUP_DISABLE,
        .scl_pullup_en = GPIO_PULLUP_DISABLE,
        .master = {.clk_speed = 400000},
        .clk_flags = 0,
    };
    
    i2c_param_config(i2c_master_port, &conf);

    return i2c_driver_install(i2c_master_port, conf.mode, 0, 0, 0);
}

esp_err_t I2C::master_deinit(int num = 0){
    return(i2c_driver_delete(num));
}

esp_err_t I2C::writeByte(int addr, uint8_t msg) {
    i2c_cmd_handle_t cmd = i2c_cmd_link_create();
    i2c_master_start(cmd);
    i2c_master_write_byte(cmd, (addr<<1) | I2C_MASTER_WRITE, I2C_MASTER_ACK);
    i2c_master_write_byte(cmd, msg, I2C_MASTER_ACK);
    i2c_master_stop(cmd);
    esp_err_t stat = i2c_master_cmd_begin(i2c_master_port, cmd, 0);
    i2c_cmd_link_delete(cmd);
    return stat;
}

esp_err_t I2C::writeBytes(int addr, uint8_t reg, uint16_t data, size_t len) {
    uint8_t *data_wr = (uint8_t *)malloc(sizeof(data));
    data_wr[0] = uint8_t(data & 0xFF);
    data_wr[1] = uint8_t(data >> 8);
    i2c_cmd_handle_t cmd = i2c_cmd_link_create();
    i2c_master_start(cmd);
    i2c_master_write_byte(cmd, (addr<<1) | I2C_MASTER_WRITE, I2C_MASTER_ACK);
    i2c_master_write_byte(cmd, reg, I2C_MASTER_ACK);
    i2c_master_write(cmd, data_wr, len, I2C_MASTER_ACK);
    i2c_master_stop(cmd);
    esp_err_t stat = i2c_master_cmd_begin(i2c_master_port, cmd, 0);
    i2c_cmd_link_delete(cmd);
    free(data_wr);
    return stat;
}

esp_err_t I2C::writeBytes(int addr, uint16_t data) {
    uint8_t *data_wr = (uint8_t *)malloc(sizeof(data));
    data_wr[0] = uint8_t(data & 0xFF);
    data_wr[1] = uint8_t(data >> 8);
    i2c_cmd_handle_t cmd = i2c_cmd_link_create();
    i2c_master_start(cmd);
    i2c_master_write_byte(cmd, (addr<<1) | I2C_MASTER_WRITE, I2C_MASTER_ACK);
    i2c_master_write(cmd, data_wr, 2, I2C_MASTER_ACK);
    i2c_master_stop(cmd);
    esp_err_t stat = i2c_master_cmd_begin(i2c_master_port, cmd, 0);
    i2c_cmd_link_delete(cmd);
    free(data_wr);
    return stat;
}

esp_err_t I2C::writeByteToReg(int addr, uint8_t reg, uint8_t data) {
    i2c_cmd_handle_t cmd = i2c_cmd_link_create();
    ESP_ERROR_CHECK_WITHOUT_ABORT(i2c_master_start(cmd));
    ESP_ERROR_CHECK_WITHOUT_ABORT(i2c_master_write_byte(cmd, (addr << 1) | I2C_MASTER_WRITE, I2C_MASTER_ACK));
    ESP_ERROR_CHECK_WITHOUT_ABORT(i2c_master_write_byte(cmd, reg, I2C_MASTER_ACK));
    ESP_ERROR_CHECK_WITHOUT_ABORT(i2c_master_write_byte(cmd, data, I2C_MASTER_ACK));
    ESP_ERROR_CHECK_WITHOUT_ABORT(i2c_master_stop(cmd));
    esp_err_t stat = i2c_master_cmd_begin(i2c_master_port, cmd, 0);
    ESP_ERROR_CHECK_WITHOUT_ABORT(stat);
    i2c_cmd_link_delete(cmd);
    return stat;
}

esp_err_t I2C::readBytes(int addr, uint8_t *data, int data_len) {
    i2c_cmd_handle_t cmd = i2c_cmd_link_create();
    i2c_master_start(cmd);
    i2c_master_write_byte(cmd, (addr<<1) | I2C_MASTER_READ, I2C_MASTER_ACK);
    // i2c_master_read(cmd, data, data_len-1, I2C_MASTER_ACK);
    i2c_master_read(cmd, data, data_len, I2C_MASTER_LAST_NACK);
    i2c_master_stop(cmd);
    esp_err_t stat = i2c_master_cmd_begin(i2c_master_port, cmd, 0);
    i2c_cmd_link_delete(cmd);
    return stat;
}

esp_err_t I2C::readBytes(int addr, uint8_t reg, uint8_t *data, int data_len) {
    i2c_cmd_handle_t cmd = i2c_cmd_link_create();
    i2c_master_start(cmd);
    i2c_master_write_byte(cmd, (addr<<1) | I2C_MASTER_WRITE, I2C_MASTER_ACK);
    i2c_master_write_byte(cmd, reg, I2C_MASTER_ACK);
    i2c_master_start(cmd);
    i2c_master_write_byte(cmd, (addr<<1) | I2C_MASTER_READ, I2C_MASTER_ACK);
    // if (data_len != 1){
    //     i2c_master_read(cmd, data, data_len-1, I2C_MASTER_ACK);
    // }
    i2c_master_read(cmd, data, data_len, I2C_MASTER_LAST_NACK);
    i2c_master_stop(cmd);
    esp_err_t stat = i2c_master_cmd_begin(i2c_master_port, cmd, 0);
    i2c_cmd_link_delete(cmd);
    return stat;
}

esp_err_t I2C::readBytes16reg(int addr, uint16_t reg, uint8_t *data, int data_len) {
    uint8_t *data_wr = (uint8_t *)malloc(sizeof(reg));
    data_wr[0] = uint8_t(reg & 0xFF);
    data_wr[1] = uint8_t(reg >> 8);
    i2c_cmd_handle_t cmd = i2c_cmd_link_create();
    i2c_master_start(cmd);
    i2c_master_write_byte(cmd, (addr<<1) | I2C_MASTER_WRITE, I2C_MASTER_ACK);
    i2c_master_write(cmd, data_wr, 2, I2C_MASTER_ACK);
    i2c_master_start(cmd);
    vTaskDelay(10 / portTICK_RATE_MS);

    i2c_master_write_byte(cmd, (addr<<1) | I2C_MASTER_READ, I2C_MASTER_ACK);
    i2c_master_read(cmd, data, data_len, I2C_MASTER_LAST_NACK);
    i2c_master_stop(cmd);
    esp_err_t stat = i2c_master_cmd_begin(i2c_master_port, cmd, 0);
    i2c_cmd_link_delete(cmd);
    return stat;
}

esp_err_t I2C::writeCommand(int addr, uint8_t cmdCode, uint16_t msg) {
    i2c_cmd_handle_t cmd = i2c_cmd_link_create();
    i2c_master_start(cmd);
    i2c_master_write_byte(cmd, (addr<<1) | I2C_MASTER_WRITE, I2C_MASTER_ACK);
    i2c_master_write_byte(cmd, 0, I2C_MASTER_ACK);
    i2c_master_write_byte(cmd, cmdCode, I2C_MASTER_ACK);
    i2c_master_write_byte(cmd, uint8_t(msg & 0xFFu), I2C_MASTER_ACK);
    i2c_master_write_byte(cmd, uint8_t((msg >> 8) & 0xFFu), I2C_MASTER_ACK);
    i2c_master_stop(cmd);
    esp_err_t stat = i2c_master_cmd_begin(i2c_master_port, cmd, 0);
    i2c_cmd_link_delete(cmd);
    return stat;
}

} // namespace Am