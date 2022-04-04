#pragma once

#include "AirMonitoring_pinout.hpp"

#include <driver/gpio.h>
#include "driver/rtc_io.h"

namespace Am {

class Power {
private:
    enum power_state { OFF, ON };

public:
    Power();

    ~Power();

    void ldo(bool state = ON);

    void sensors(bool state = ON);

    void lora(bool state = ON);

    void mq(bool state = ON);

    void pms(bool state = ON);

    void device(bool state = ON);

    void isolateGPIO();
    
};   // class Power

} // namespace Am