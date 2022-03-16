idf_component_register(SRCS "main.cpp" "defines.hpp"
                    INCLUDE_DIRS ".")


#here configure your MQTT broker URL
add_definitions(-DMQTT_BROKER_URL="")