# For more information about build system see
# https://docs.espressif.com/projects/esp-idf/en/latest/api-guides/build-system.html
# The following five lines of boilerplate have to be in your project's
# CMakeLists in this exact order for cmake to work correctly
cmake_minimum_required(VERSION 3.5)

include($ENV{IDF_PATH}/tools/cmake/project.cmake)

# Uncomment one of these following lines to select WiFi and MQTT broker or LoRaWAN
# add_compile_definitions(WIFI)
add_compile_definitions(LORAWAN)

# Here define WiFi SSID, password and MQTT broker URL and port number
add_compile_definitions(SSID="")
add_compile_definitions(PWD="")
add_compile_definitions(MQTT_BROKER_URL="")
add_compile_definitions(MQTT_PORT=1883)

project(main)
