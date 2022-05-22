# For more information about build system see
# https://docs.espressif.com/projects/esp-idf/en/latest/api-guides/build-system.html
# The following five lines of boilerplate have to be in your project's
# CMakeLists in this exact order for cmake to work correctly
cmake_minimum_required(VERSION 3.5)

include($ENV{IDF_PATH}/tools/cmake/project.cmake)

#define WiFi SSID, password and MQTT broker url
add_compile_definitions(SSID="")
add_compile_definitions(PWD="")
add_compile_definitions(MQTT_BROKER_URL="")

project(main)
