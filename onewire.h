#ifndef _ONEWIRE_H_
#define _ONEWIRE_H_

#include "stm_defines.h"
#include <inttypes.h>
#include "hardware_delay.h"

#define ONE_WIRE_DELAY(x) HWDelay::delay_us(x)

namespace ONE_WIRE{
    uint8_t reset();
    void write(uint8_t data);
    uint8_t read();
    void parazitPowerOn();
}

#endif /* _ONEWIRE_H_ */