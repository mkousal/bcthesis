idf_component_register(SRCS "main.cpp"
                    INCLUDE_DIRS ".")


#here configure your MQTT broker URL
add_definitions(-DMQTT_BROKER_URL="")