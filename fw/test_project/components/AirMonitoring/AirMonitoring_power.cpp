#include "AirMonitoring_power.hpp"

#include "AirMonitoring_pinout.hpp"

#include <driver/gpio.h>

namespace Am {

Power::Power() {       // Constructor, set default state of power stages
    gpio_config_t io_conf = {};
    io_conf.intr_type = GPIO_INTR_DISABLE;
    io_conf.mode = GPIO_MODE_OUTPUT;
    io_conf.pin_bit_mask = (1<<LDO_EN) | (1<<LORA_EN) | (1<<MQ_EN) | (1<<PMS_EN) | (1<<SEN_VDD_EN) | (1<<IO26) | (1<<LED);
    io_conf.pull_down_en = GPIO_PULLDOWN_DISABLE;
    io_conf.pull_up_en = GPIO_PULLUP_DISABLE;
    gpio_config(&io_conf);
}

Power::~Power() {}

void Power::ldo(bool state){
    gpio_set_level(LDO_EN, state);
}

void Power::sensors(bool state){
    gpio_set_level(SEN_VDD_EN, state);
    gpio_set_level(IO26, state);
}

void Power::lora(bool state){
    gpio_set_level(LORA_EN, state);
}

void Power::mq(bool state){
    gpio_set_level(MQ_EN, state);
}

void Power::pms(bool state){
    gpio_set_level(PMS_EN, state);
}

void Power::device(bool state){
    gpio_set_level(POWER_OFF, state);
}

} // namespace Am