#include "AirMonitoring_utils.hpp"

namespace Am {

void setTaskChecker(uint8_t flag) {
    taskStatus |= flag;
}

bool getTaskChecker(uint8_t flag) {
    if ((taskStatus & flag) == flag)
        return true;
    else
        return false;
}

void resetTaskChecker(uint8_t flag, bool all) {
    if (all)
        taskStatus = 0;
    else
        taskStatus &= ~flag;
}

void messageReceived(const uint8_t *message, size_t length, ttn_port_t port)
{
    printf("Message of %d bytes received on port %d:", length, port);
    for (int i = 0; i < length; i++)
        printf(" %02x", message[i]);
    printf("\n");
}

bool initADC() {
    esp_err_t ret;
    bool calibrationEnable = false;

    ESP_ERROR_CHECK(adc1_config_width((adc_bits_width_t)ADC_WIDTH_BIT_DEFAULT));
    ESP_ERROR_CHECK(adc1_config_channel_atten(ADC1_CHANNEL_6, ADC_ATTEN_DB_0));

    ret = esp_adc_cal_check_efuse(ESP_ADC_CAL_VAL_EFUSE_VREF);
    if (ret == ESP_ERR_NOT_SUPPORTED)
        ESP_LOGW("ADC", "Calibration scheme not supported, skip sw calibration");
    else if (ret == ESP_ERR_INVALID_VERSION)
        ESP_LOGW("ADC", "eFuse not burnt, skip sw calibration");
    else if (ret == ESP_OK) {
        ESP_LOGI("ADC", "Calibration start");
        calibrationEnable = true;
        esp_adc_cal_characterize(ADC_UNIT_1, ADC_ATTEN_DB_0, (adc_bits_width_t)ADC_WIDTH_BIT_DEFAULT, 0, &adc1_char);
    }
    else
        ESP_LOGE("ADC", "Invalid argument");

    return calibrationEnable;
}

uint32_t getBatteryVoltage(bool calibEnable) {
    uint32_t voltage;
    ESP_LOGI("bat", "CalibEN %d", calibEnable);
    if (calibEnable == 1) {
        ESP_LOGI("bat", "calibrated, measure start");
        esp_adc_cal_get_voltage(ADC_CHANNEL_6, &adc1_char, &voltage);
        voltage = (voltage * (1000000+270000)) / 270000;
        return voltage;
    }
    else 
        return 0;
}

}   // namespace Am