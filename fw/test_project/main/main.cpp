// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// #include <stddef.h>
// #include <stdint.h>
// #include "esp_log.h"
// #include "freertos/FreeRTOS.h"
// #include "freertos/task.h"
// #include "freertos/queue.h"
// #include "driver/gpio.h"
// #include "driver/i2c.h"
// #include "freertos/event_groups.h"
// #include "esp_system.h"
// #include "esp_wifi.h"
// #include "esp_event.h"
// #include "nvs_flash.h"

// #include "lwip/err.h"
// #include "lwip/sys.h"

// #include "esp_netif.h"

// #include "freertos/semphr.h"
// #include "lwip/sockets.h"
// #include "lwip/dns.h"
// #include "lwip/netdb.h"
// #include "mqtt_client.h"

// #include "esp_sleep.h"

// #include "cJSON.h"

// #define BTN 35
// #define LED 15
// #define LDO 13

// #define SCL 22
// #define SDA 21
// #define I2C_MASTER_NUM 0
// #define I2C_MASTER_FREQ 400000
// #define SHT40_ADDR  0x44

// static const char *TAG = "testIoT";

// #define SSID "" // Place WiFi SSID here
// #define PWD ""   // Place WiFi password here
// #define MAX_RETRY 5

// static EventGroupHandle_t s_wifi_event_group;

// #define WIFI_CONNECTED_BIT  BIT0
// #define WIFI_FAIL_BIT       BIT1

// static int s_retry_num = 0;

// static void event_handler(void* arg, esp_event_base_t event_base,
//                                 int32_t event_id, void* event_data)
// {
//     if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_START) {
//         esp_wifi_connect();
//     } else if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_DISCONNECTED) {
//         if (s_retry_num < MAX_RETRY) {
//             esp_wifi_connect();
//             s_retry_num++;
//             ESP_LOGI(TAG, "retry to connect to the AP");
//         } else {
//             xEventGroupSetBits(s_wifi_event_group, WIFI_FAIL_BIT);
//         }
//         ESP_LOGI(TAG,"connect to the AP fail");
//     } else if (event_base == IP_EVENT && event_id == IP_EVENT_STA_GOT_IP) {
//         ip_event_got_ip_t* event = (ip_event_got_ip_t*) event_data;
//         ESP_LOGI(TAG, "got ip:" IPSTR, IP2STR(&event->ip_info.ip));
//         s_retry_num = 0;
//         xEventGroupSetBits(s_wifi_event_group, WIFI_CONNECTED_BIT);
//     }
// }

// void wifi_init_sta(void)
// {
//     s_wifi_event_group = xEventGroupCreate();

//     ESP_ERROR_CHECK(esp_netif_init());

//     ESP_ERROR_CHECK(esp_event_loop_create_default());
//     esp_netif_create_default_wifi_sta();

//     wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
//     ESP_ERROR_CHECK(esp_wifi_init(&cfg));

//     esp_event_handler_instance_t instance_any_id;
//     esp_event_handler_instance_t instance_got_ip;
//     ESP_ERROR_CHECK(esp_event_handler_instance_register(WIFI_EVENT,
//                                                         ESP_EVENT_ANY_ID,
//                                                         &event_handler,
//                                                         NULL,
//                                                         &instance_any_id));
//     ESP_ERROR_CHECK(esp_event_handler_instance_register(IP_EVENT,
//                                                         IP_EVENT_STA_GOT_IP,
//                                                         &event_handler,
//                                                         NULL,
//                                                         &instance_got_ip));

//     wifi_config_t wifi_config = {
//         .sta = {
//             .ssid = SSID,
//             .password = PWD,
//             /* Setting a password implies station will connect to all security modes including WEP/WPA.
//              * However these modes are deprecated and not advisable to be used. Incase your Access point
//              * doesn't support WPA2, these mode can be enabled by commenting below line */
// 	     .threshold.authmode = WIFI_AUTH_WPA2_PSK,

//             .pmf_cfg = {
//                 .capable = true,
//                 .required = false
//             },
//         },
//     };
//     ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA) );
//     ESP_ERROR_CHECK(esp_wifi_set_config(WIFI_IF_STA, &wifi_config) );
//     ESP_ERROR_CHECK(esp_wifi_start() );

//     ESP_LOGI(TAG, "wifi_init_sta finished.");

//     /* Waiting until either the connection is established (WIFI_CONNECTED_BIT) or connection failed for the maximum
//      * number of re-tries (WIFI_FAIL_BIT). The bits are set by event_handler() (see above) */
//     EventBits_t bits = xEventGroupWaitBits(s_wifi_event_group,
//             WIFI_CONNECTED_BIT | WIFI_FAIL_BIT,
//             pdFALSE,
//             pdFALSE,
//             portMAX_DELAY);

//     /* xEventGroupWaitBits() returns the bits before the call returned, hence we can test which event actually
//      * happened. */
//     if (bits & WIFI_CONNECTED_BIT) {
//         ESP_LOGI(TAG, "connected to ap SSID:%s password:%s",
//                  SSID, PWD);
//     } else if (bits & WIFI_FAIL_BIT) {
//         ESP_LOGI(TAG, "Failed to connect to SSID:%s, password:%s",
//                  SSID, PWD);
//     } else {
//         ESP_LOGE(TAG, "UNEXPECTED EVENT");
//     }

//     /* The event will not be processed after unregister */
//     ESP_ERROR_CHECK(esp_event_handler_instance_unregister(IP_EVENT, IP_EVENT_STA_GOT_IP, instance_got_ip));
//     ESP_ERROR_CHECK(esp_event_handler_instance_unregister(WIFI_EVENT, ESP_EVENT_ANY_ID, instance_any_id));
//     vEventGroupDelete(s_wifi_event_group);
// }

// static esp_err_t i2c_master_init(void)
// {
//     int i2c_master_port = I2C_MASTER_NUM;

//     i2c_config_t conf = {
//         .mode = I2C_MODE_MASTER,
//         .sda_io_num = SDA,
//         .scl_io_num = SCL,
//         .master.clk_speed = I2C_MASTER_FREQ,
//     };

//     i2c_param_config(i2c_master_port, &conf);

//     return i2c_driver_install(i2c_master_port, conf.mode, 0, 0, 0);
// }


// static esp_err_t i2c_master_read_slave_reg(i2c_port_t i2c_num, uint8_t i2c_addr, uint8_t i2c_reg, uint8_t* data_rd, size_t size)
// {
//     if (size == 0) {
//         return ESP_OK;
//     }
//     i2c_cmd_handle_t cmd = i2c_cmd_link_create();
//     i2c_master_start(cmd);
//     // first, send device address (indicating write) & register to be read
//     i2c_master_write_byte(cmd, ( i2c_addr << 1 ) | I2C_MASTER_WRITE, I2C_MASTER_ACK);
//     // send register we want
//     i2c_master_write_byte(cmd, i2c_reg, I2C_MASTER_ACK);
//     i2c_master_stop(cmd);
//     esp_err_t ret = i2c_master_cmd_begin(i2c_num, cmd, 1000 / portTICK_RATE_MS);
//     i2c_cmd_link_delete(cmd);
//     vTaskDelay(500 / portTICK_RATE_MS);
//     cmd = i2c_cmd_link_create();
//     // Send repeated start
//     i2c_master_start(cmd);
//     // now send device address (indicating read) & read data
//     i2c_master_write_byte(cmd, ( i2c_addr << 1 ) | I2C_MASTER_READ, I2C_MASTER_ACK);
//     if (size > 1) {
//         i2c_master_read(cmd, data_rd, size - 1, I2C_MASTER_ACK);
//     }
//     i2c_master_read_byte(cmd, data_rd + size - 1, I2C_MASTER_NACK);
//     i2c_master_stop(cmd);
//     ret = i2c_master_cmd_begin(i2c_num, cmd, 1000 / portTICK_RATE_MS);
//     i2c_cmd_link_delete(cmd);
//     return ret;
// }

// static esp_err_t i2c_master_write_slave_reg(i2c_port_t i2c_num, uint8_t i2c_addr, uint8_t i2c_reg, uint8_t* data_wr, size_t size)
// {
//     i2c_cmd_handle_t cmd = i2c_cmd_link_create();
//     i2c_master_start(cmd);
//     // first, send device address (indicating write) & register to be written
//     i2c_master_write_byte(cmd, ( i2c_addr << 1 ) | I2C_MASTER_WRITE, I2C_MASTER_ACK);
//     // send register we want
//     i2c_master_write_byte(cmd, i2c_reg, I2C_MASTER_ACK);
//     // write the data
//     i2c_master_write(cmd, data_wr, size, I2C_MASTER_ACK);
//     i2c_master_stop(cmd);
//     esp_err_t ret = i2c_master_cmd_begin(i2c_num, cmd, 1000 / portTICK_RATE_MS);
//     i2c_cmd_link_delete(cmd);
//     return ret;
// }

// esp_err_t rdSHT40( uint8_t reg, uint8_t *pdata, uint8_t cnt )
// {
//     return(i2c_master_read_slave_reg(I2C_MASTER_NUM, SHT40_ADDR, reg, pdata, cnt));
// }

// esp_err_t wrSHT40( uint8_t reg, uint8_t *pdata, uint8_t cnt)
// {
//     return(i2c_master_write_slave_reg(I2C_MASTER_NUM, SHT40_ADDR, reg, pdata, cnt));
// }

// static void log_error_if_nonzero(const char * message, int error_code)
// {
//     if (error_code != 0) {
//         ESP_LOGE(TAG, "Last error %s: 0x%x", message, error_code);
//     }
// }

// static esp_err_t mqtt_event_handler_cb(esp_mqtt_event_handle_t event)
// {
//     esp_mqtt_client_handle_t client = event->client;
//     int msg_id;
//     // your_context_t *context = event->context;
//     switch (event->event_id) {
//         case MQTT_EVENT_CONNECTED:
//             ESP_LOGI(TAG, "MQTT_EVENT_CONNECTED");
//             msg_id = esp_mqtt_client_publish(client, "/topic/qos1", "data_3", 0, 1, 0);
//             ESP_LOGI(TAG, "sent publish successful, msg_id=%d", msg_id);

//             msg_id = esp_mqtt_client_subscribe(client, "/topic/qos0", 0);
//             ESP_LOGI(TAG, "sent subscribe successful, msg_id=%d", msg_id);

//             msg_id = esp_mqtt_client_subscribe(client, "/topic/qos1", 1);
//             ESP_LOGI(TAG, "sent subscribe successful, msg_id=%d", msg_id);

//             msg_id = esp_mqtt_client_unsubscribe(client, "/topic/qos1");
//             ESP_LOGI(TAG, "sent unsubscribe successful, msg_id=%d", msg_id);
//             break;
//         case MQTT_EVENT_DISCONNECTED:
//             ESP_LOGI(TAG, "MQTT_EVENT_DISCONNECTED");
//             break;

//         case MQTT_EVENT_SUBSCRIBED:
//             ESP_LOGI(TAG, "MQTT_EVENT_SUBSCRIBED, msg_id=%d", event->msg_id);
//             msg_id = esp_mqtt_client_publish(client, "/topic/qos0", "data", 0, 0, 0);
//             ESP_LOGI(TAG, "sent publish successful, msg_id=%d", msg_id);
//             break;
//         case MQTT_EVENT_UNSUBSCRIBED:
//             ESP_LOGI(TAG, "MQTT_EVENT_UNSUBSCRIBED, msg_id=%d", event->msg_id);
//             break;
//         case MQTT_EVENT_PUBLISHED:
//             ESP_LOGI(TAG, "MQTT_EVENT_PUBLISHED, msg_id=%d", event->msg_id);
//             break;
//         case MQTT_EVENT_DATA:
//             ESP_LOGI(TAG, "MQTT_EVENT_DATA");
//             printf("TOPIC=%.*s\r\n", event->topic_len, event->topic);
//             printf("DATA=%.*s\r\n", event->data_len, event->data);
//             break;
//         case MQTT_EVENT_ERROR:
//             ESP_LOGI(TAG, "MQTT_EVENT_ERROR");
//             if (event->error_handle->error_type == MQTT_ERROR_TYPE_TCP_TRANSPORT) {
//                 log_error_if_nonzero("reported from esp-tls", event->error_handle->esp_tls_last_esp_err);
//                 log_error_if_nonzero("reported from tls stack", event->error_handle->esp_tls_stack_err);
//                 log_error_if_nonzero("captured as transport's socket errno",  event->error_handle->esp_transport_sock_errno);
//                 ESP_LOGI(TAG, "Last errno string (%s)", strerror(event->error_handle->esp_transport_sock_errno));

//             }
//             break;
//         default:
//             ESP_LOGI(TAG, "Other event id:%d", event->event_id);
//             break;
//     }
//     return ESP_OK;
// }

// static void mqtt_event_handler(void *handler_args, esp_event_base_t base, int32_t event_id, void *event_data) {
//     ESP_LOGD(TAG, "Event dispatched from event loop base=%s, event_id=%d", base, event_id);
//     mqtt_event_handler_cb(event_data);
// }

// esp_mqtt_client_handle_t client;

// static void mqtt_app_start(void)
// {
//     esp_mqtt_client_config_t mqtt_cfg = {
//         .host = "192.168.88.20",
//     };
//     client = esp_mqtt_client_init(&mqtt_cfg);
//     esp_mqtt_client_register_event(client, ESP_EVENT_ANY_ID, mqtt_event_handler, client);
//     esp_mqtt_client_start(client);
// }

// #define FLOAT_TO_INT(x) ((x)>=0?(int)((x)+0.5):(int)((x)-0.5))

// extern "C" void app_main()
// {
//     gpio_config_t io_conf = {};
//     io_conf.intr_type = GPIO_INTR_DISABLE;
//     io_conf.mode = GPIO_MODE_OUTPUT;
//     io_conf.pin_bit_mask = ((1<<LED) | (1<<LDO));
//     io_conf.pull_down_en = 0;
//     io_conf.pull_up_en = 0;
//     gpio_config(&io_conf);

//     ESP_ERROR_CHECK(i2c_master_init());
//     ESP_LOGI(TAG, "I2C init succesfull");

//     uint8_t data[6];   

//     int cnt = 0;

//     esp_err_t ret = nvs_flash_init();
//     if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
//         ESP_ERROR_CHECK(nvs_flash_erase());;
//         ret = nvs_flash_init();;
//     };

//     ESP_ERROR_CHECK(ret);;
//     ESP_LOGI(TAG, "ESP_WIFI_MODE_STA");;
//     wifi_init_sta();;
//     mqtt_app_start();;


//     while(1) {;
//         printf("cnt: %d\n", cnt++);;
//         vTaskDelay(1000 / portTICK_RATE_MS);;
//         gpio_set_level(LED, cnt % 2);;

//         rdSHT40(0xFD, &data, 2);;

//         int16_t temp = data[0]<<8 | data[1];;
//         float temperature = (-45+(175*((temp)*1.0/65535)));;
//         ESP_LOGI(TAG, "temp: %X", temp);;
//         ESP_LOGI(TAG, "Temperature: %.2f", temperature);;

//         char temp_str[32];
//         sprintf(temp_str, "%.2f", temperature);;

//         char buf[64];
//         sprintf(buf, "%.2f", temperature);
//         temperature = temperature * 10;
//         int decTemp = FLOAT_TO_INT(temperature);

//         cJSON *root;;
//         root = cJSON_CreateObject();
//         cJSON_AddNumberToObject(root, "T", decTemp);
//         // cJSON_AddStringToObject(root, "T", buf);
//         char *json_string = cJSON_PrintUnformatted(root);
//         int sizeJSON = strlen(json_string);
//         ESP_LOGI(TAG, "%d", sizeJSON);
//         cJSON_Delete(root);
//         ESP_LOGI(TAG, "json:\n%s", json_string);

//         esp_mqtt_client_publish(client, "TEMPERATURE/values", json_string, sizeJSON, 0, false);
        

//         vTaskDelay(5000 / portTICK_RATE_MS);
//         esp_wifi_stop();
//         esp_deep_sleep(6000000LL * 10);
//     }
// }
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
    if (cntMeasurement > 25 && (sgp.getCO2() != 65535)) {
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

// void taskUART2(void *pvParameters)
// {
//     vTaskDelay(20000 / portTICK_RATE_MS);
//     ESP_LOGI("uart2>>>>>>>>>>>>>", "fsdf");
//     unsigned long timer = clock();
//     while(((clock() - timer) / CLOCKS_PER_SEC) < 20){
//         pms.readPMS();
//         vTaskDelay(100 / portTICK_RATE_MS);
//     }
//     ESP_LOGI("uart2>>>>>>>>>>>", "aaaaaa");
    
//     if (pms.readPMS() != 0){
//         #ifdef DEBUG
//         pms.printPM();
//         #endif
//     }
//     cJSON_AddNumberToObject(msg, "P1", pms.getPM1());
//     cJSON_AddNumberToObject(msg, "P25", pms.getPM25());
//     cJSON_AddNumberToObject(msg, "P10", pms.getPM10());

//     taskChecker++;
//     vTaskDelete(NULL);
// }

void taskMQTT(void *pvParameters)
{
    esp_mqtt_client_config_t mqtt_cfg = {
        .host = MQTT_BROKER_URL,
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

    vTaskDelay(3000 / portTICK_RATE_MS);
    esp_wifi_stop();
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
    // xTaskCreatePinnedToCore(taskUART2, "uart2_task", 8192, NULL, 5, NULL, APP_CPU_NUM);
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
            cJSON_AddNumberToObject(msg, "P1", pms.getPM1());
            cJSON_AddNumberToObject(msg, "P25", pms.getPM25());
            cJSON_AddNumberToObject(msg, "P10", pms.getPM10());

            taskChecker++;
            pmsMeasured = true;
        }
    }
}