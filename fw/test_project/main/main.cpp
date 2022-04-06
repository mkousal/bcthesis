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
        taskChecker++;
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
    bmp.forceRead();
    vTaskDelay(20 / portTICK_RATE_MS);
    bmp.read();
    bmp.compensate();

    light.read();
    sht.read();
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

    taskChecker++;
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

    taskChecker++;
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

    taskChecker++;
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
    // power.isolateGPIO();
    vTaskDelay(3000 / portTICK_RATE_MS);
    esp_wifi_stop();
    esp_sleep_config_gpio_isolate();
    esp_sleep_pd_config(ESP_PD_DOMAIN_RTC_SLOW_MEM, ESP_PD_OPTION_OFF);
    esp_sleep_pd_config(ESP_PD_DOMAIN_RTC_FAST_MEM, ESP_PD_OPTION_OFF);
    esp_sleep_pd_config(ESP_PD_DOMAIN_RTC_PERIPH, ESP_PD_OPTION_OFF);
    esp_sleep_pd_config(ESP_PD_DOMAIN_XTAL, ESP_PD_OPTION_OFF);
    vTaskDelay(20 / portTICK_RATE_MS);
    esp_deep_sleep(300000000LL);

    vTaskDelete(NULL);
}

extern "C" void app_main(void)
{
    ESP_LOGI("main", "Hello world!");
        
    power.ldo();
    power.sensors();
    power.pms();
    pms.init();
    ESP_ERROR_CHECK(spi.begin(MOSI, MISO, SCLK));
    vTaskDelay(100 / portTICK_RATE_MS);
    vTaskDelay(50 / portTICK_RATE_MS);
    msg = cJSON_CreateObject();
    xTaskCreatePinnedToCore(taskI2C, "i2c_task", configMINIMAL_STACK_SIZE * 8, NULL, 5, NULL, APP_CPU_NUM);
    xTaskCreatePinnedToCore(taskSPI, "spi_task", configMINIMAL_STACK_SIZE * 8, NULL, 5, NULL, APP_CPU_NUM);
    xTaskCreatePinnedToCore(taskWiFi, "wifi_task", configMINIMAL_STACK_SIZE * 8, NULL, 5, NULL, APP_CPU_NUM);
    bool pmsMeasured = false;
    while (true) {
        if (taskChecker == 5) {
            xTaskCreatePinnedToCore(taskMQTT, "mqtt_task", configMINIMAL_STACK_SIZE * 8, NULL, 5, NULL, APP_CPU_NUM);
            taskChecker = 20;
        }
        else if (taskChecker < 5 && pmsMeasured == false) {
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

            taskChecker++;
            pmsMeasured = true;
        }
        vTaskDelay(10 / portTICK_RATE_MS);
    }
}