#define DEBUG

#include "main.hpp"

#include "esp_event.h"
#include "esp_err.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "freertos/timers.h"

static void vSGPTimerCallback(xTimerHandle xTimer) {
    static uint8_t cntMeasurement = 0;
    sgp.measure();
    cntMeasurement++;
    if (cntMeasurement > 22 && (sgp.getCO2() != 65535)) {
        power.sensors(false);
        cJSON_AddNumberToObject(msg, "C", sgp.getCO2());
        cJSON_AddNumberToObject(msg, "E", sgp.getTVOC());
        setTaskChecker(SGP_CHECKER);
        xTimerDelete(sgpTimer, 0);
    }

    #ifdef DEBUG
    ESP_LOGI("SGP30", "CO2: %d   TVOC: %d", sgp.getCO2(), sgp.getTVOC());
    #endif
}

void taskI2C(void *pvParameters)
{
    sht.init();
    sgp.init();
    light.init(light.ALS_SD_POWER_ON, light.ALS_IT_25, light.ALS_GAIN_1_4);
    bmp.softReset();
    bmp.init();
    bmp.readCalibrationData();

    sht.sendRequestToRead();
    vTaskDelay(10 / portTICK_RATE_MS);
    sht.read();
    bmp.forceRead();
    vTaskDelay(20 / portTICK_RATE_MS);
    bmp.read();
    bmp.compensate();
    if (sht.getTemp() > 120){
        sht.sendRequestToRead();
        vTaskDelay(10 / portTICK_RATE_MS);
        sht.read();
    }

    light.read();
    sgp.getSerialID();
    sgpTimer = xTimerCreate("SGP30_timer", pdMS_TO_TICKS(1000), pdTRUE, (void *)0, vSGPTimerCallback);
    if (xTimerStart(sgpTimer, 10) != pdPASS) {
        ESP_LOGI("timer", "Timer start error");
    }
    cJSON_AddNumberToObject(msg, "T", (int)(sht.getTemp() * 10));
    cJSON_AddNumberToObject(msg, "H", (int)(sht.getHum() * 10));
    cJSON_AddNumberToObject(msg, "L", light.getValue());
    cJSON_AddNumberToObject(msg, "P", (int)(bmp.calcRelativePressure(sht.getTemp(), 377) * 10));
    
    #ifdef DEBUG
    ESP_LOGI("I2C", "Temperature: %.1f  Humidity: %.1f  Light: %d  Pressure: %.1f  Temp: %.1f", sht.getTemp(), sht.getHum(), light.getValue(), bmp.calcRelativePressure(sht.getTemp(), 377), bmp.getTemp());
    #endif

    setTaskChecker(I2C_CHECKER);
    vTaskDelete(NULL);
}

void taskSPI(void *pvParameters)
{
    mcp.init();
    mcp.read(1);
    cJSON_AddNumberToObject(msg, "U", (int)(mcp.getUVmW() * 1000000));

    #ifdef DEBUG
    ESP_LOGI("SPI", "UV: %f", mcp.getUVmW());
    #endif

    setTaskChecker(SPI_CHECKER);
    vTaskDelete(NULL);
}

void taskWiFi(void *pvParameters)
{
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    };

    ESP_ERROR_CHECK(ret);
    ESP_LOGI("WiFi", "ESP_WIFI_MODE_STA");
    wifi_init_sta();

    setTaskChecker(WIFI_CHECKER);
    vTaskDelete(NULL);
}

void taskMQTT(void *pvParameters)
{
    esp_mqtt_client_config_t mqtt_cfg = {
        .uri = MQTT_BROKER_URL,
        .port = 2000,
    };
    esp_mqtt_client_handle_t client = esp_mqtt_client_init(&mqtt_cfg);
    esp_mqtt_client_start(client);
    char *json_str = cJSON_PrintUnformatted(msg);
    int json_str_size = strlen(json_str);

    #ifdef DEBUG
    ESP_LOGI("MQTT", "size of JSON message: %d JSON:\n%s\n", json_str_size, json_str);
    #endif

    esp_mqtt_client_publish(client, "AIR_MONITOR_1/values", json_str, json_str_size, 0, false);
    esp_mqtt_client_stop(client);

    #ifdef DEBUG
    ESP_LOGI("MQTT", "MQTT Publish sent");
    #endif
    power.isolateGPIO();
    vTaskDelay(3000 / portTICK_RATE_MS);
    esp_wifi_stop();
    
    power.goToSleep(10);

    vTaskDelete(NULL);
}

void taskLoRaWAN(void *pvParameters) {
    ESP_ERROR_CHECK(gpio_install_isr_service(ESP_INTR_FLAG_IRAM));
    ESP_ERROR_CHECK(nvs_flash_init());
    ttn.configurePins(VSPI_HOST, CS_LORA, TTN_NOT_CONNECTED, LORA_RST, DIO0, DIO1);
    // ttn.provision(devEui, appEui, appKey);   // can be commented after first upload, keys stored in NVS
    ttn.onMessage(messageReceived);
    if (ttn.resumeAfterDeepSleep())
        ESP_LOGI("TTN", "Resumed from deep sleep");
    else {
        ESP_LOGI("TTN", "Joining...");
        if (ttn.join())
            ESP_LOGI("TTN", "Joined");
        else {
            ESP_LOGI("TTN", "Join failed.");
            return;
        }
    }
    setTaskChecker(LORAWAN_CHECKER);
    vTaskDelete(NULL);
}

void taskTTN(void *pvParameters) {
    char *json_str = cJSON_PrintUnformatted(msg);
    int json_str_size = strlen(json_str);

    #ifdef DEBUG
    ESP_LOGI("TTN", "size of JSON message: %d JSON:\n%s\n", json_str_size, json_str);
    #endif
    ESP_LOGI("TTN", "Sending message");
    TTNResponseCode res = ttn.transmitMessage((uint8_t *)json_str, json_str_size);
    if (res == kTTNSuccessfulTransmission)
        ESP_LOGI("TTN", "Message sent");
    else
        ESP_LOGI("TTN", "Transmission failed");
    ttn.waitForIdle();
    ttn.prepareForDeepSleep();
    ESP_LOGI("TTN", "Go to sleep");

    power.goToSleep(10);

    vTaskDelete(NULL);
}

extern "C" void app_main(void)
{
    ESP_LOGI("main", "Hello world!");
    ADCCalibrationEnable = initADC();
    uint32_t battery = getBatteryVoltage(ADCCalibrationEnable);
    if (battery < 2900)
        power.device(0);
    ESP_LOGI("battery", "Voltage: %d", battery);
    power.ldo();
    power.sensors();
    power.pms();
    pms.init();
    power.lora();
    power.sgp30();
    ESP_ERROR_CHECK(spi.begin(MOSI, MISO, SCLK));
    vTaskDelay(100 / portTICK_RATE_MS);
    vTaskDelay(50 / portTICK_RATE_MS);
    msg = cJSON_CreateObject();
    cJSON_AddNumberToObject(msg, "B", battery);
    xTaskCreatePinnedToCore(taskI2C, "i2c_task", configMINIMAL_STACK_SIZE * 8, NULL, 5, NULL, APP_CPU_NUM);
    xTaskCreatePinnedToCore(taskSPI, "spi_task", configMINIMAL_STACK_SIZE * 8, NULL, 5, NULL, APP_CPU_NUM);
    // xTaskCreatePinnedToCore(taskWiFi, "wifi_task", configMINIMAL_STACK_SIZE * 8, NULL, 5, NULL, APP_CPU_NUM);
    xTaskCreatePinnedToCore(taskLoRaWAN, "LoRaWAN_join_task", configMINIMAL_STACK_SIZE * 8, NULL, 5, NULL, APP_CPU_NUM);
    bool pmsMeasured = false;
    while (true) {
        if (getTaskChecker(MEAS_DONE_CHECKER | LORAWAN_CHECKER)) {
            // xTaskCreatePinnedToCore(taskMQTT, "mqtt_task", configMINIMAL_STACK_SIZE * 8, NULL, 5, NULL, APP_CPU_NUM);
            xTaskCreatePinnedToCore(taskTTN, "TTN_task", configMINIMAL_STACK_SIZE * 8, NULL, 5, NULL, APP_CPU_NUM);
            resetTaskChecker(MEAS_DONE_CHECKER);
        }
        if (getTaskChecker(PMS_CHECKER) == false) {
            unsigned long timer = clock();
            while(((clock() - timer) / CLOCKS_PER_SEC) < 20){
                pms.readPMS();
                vTaskDelay(100 / portTICK_RATE_MS);
            }

            if (pms.readPMS() != 0){
                #ifdef DEBUG
                pms.printPM();
                #endif
            }
            power.pms(false);
            cJSON_AddNumberToObject(msg, "P1", pms.getPM1());
            cJSON_AddNumberToObject(msg, "P25", pms.getPM25());
            cJSON_AddNumberToObject(msg, "P10", pms.getPM10());

            setTaskChecker(PMS_CHECKER);
            // pmsMeasured = true;
        }
        vTaskDelay(10 / portTICK_RATE_MS);
    }
}