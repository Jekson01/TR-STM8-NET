#ifndef _HARDWARE_DELAY_H_
#define _HARDWARE_DELAY_H_
#include <inttypes.h>
#include "macros.h"

#define TIM4_PERIOD_MS  124
#define TIM4_PERIOD_US  9



namespace HWDelay{
    void delay_us(uint16_t us);
    void delay_ms(uint16_t ms);
    uint8_t isRun();
};

#endif /* _HARDWARE_DELAY_H_ */