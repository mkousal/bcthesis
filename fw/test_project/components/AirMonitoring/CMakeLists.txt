idf_component_register(SRCS "AirMonitoring_wifi.cpp" "AirMonitoring_veml.cpp" "AirMonitoring_spi.cpp" "AirMonitoring_sht.cpp" "AirMonitoring_pms.cpp" "AirMonitoring_mcp3202.cpp" "AirMonitoring_bmp388.cpp" "AirMonitoring_i2c.cpp" "AirMonitoring_power.cpp"
                    INCLUDE_DIRS "include"
                    REQUIRES "nvs_flash")

                    
#here configure your WiFi SSID and PASSWORD
add_definitions(-DSSID="")
add_definitions(-DPWD="")