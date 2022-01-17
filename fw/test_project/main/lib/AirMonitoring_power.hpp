#pragma once

#include "lib/AirMonitoring_pinout.hpp"

#include <driver/gpio.h>

namespace Am {

class Power {
private:
    enum power_state { OFF, ON };

public:
    Power() {       // Constructor, set default state of power stages
        gpio_config_t io_conf = {};
        io_conf.intr_type = GPIO_INTR_DISABLE;
        io_conf.mode = GPIO_MODE_OUTPUT;
        io_conf.pin_bit_mask = (1<<LDO_EN) | (1<<LORA_EN) | (1<<MQ_EN) | (1<<PMS_EN) | (1<<SEN_VDD_EN);
        io_conf.pull_down_en = GPIO_PULLDOWN_DISABLE;
        io_conf.pull_up_en = GPIO_PULLUP_DISABLE;
        gpio_config(&io_conf);
    }

    void ldo(bool state = ON){
        gpio_set_level(LDO_EN, state);
    }

    void sensors(bool state = ON){
        gpio_set_level(SEN_VDD_EN, state);
    }

    void lora(bool state = ON){
        gpio_set_level(LORA_EN, state);
    }

    void mq(bool state = ON){
        gpio_set_level(MQ_EN, state);
    }

    void pms(bool state = ON){
        gpio_set_level(PMS_EN, state);
    }

    void device(bool state = ON){
        gpio_set_level(POWER_OFF, state);
    }
};   // class Power

} // namespace Am