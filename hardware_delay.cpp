#include "hardware_delay.h"
#include "stm_defines.h"

namespace HWDelay{
    volatile uint16_t count = 0;
}

ISR(TIM4_OVR_UIF, TIM4_OVR_UIF_vector){
    if (HWDelay::count)
        HWDelay::count--;
    TIM4_SR_bit.UIF = 0;
}

void HWDelay::delay_us(uint16_t us){
    TIM4_CR1_bit.CEN = 0;
    TIM4_IER_bit.UIE = 0;
    TIM4_PSCR_bit.PSC = 4; // div by 4
    TIM4_ARR = TIM4_PERIOD_US;
    TIM4_IER_bit.UIE = 1;
    count = us / 10;
    TIM4_CR1_bit.CEN = 1;
    while (count){}
    TIM4_CR1_bit.CEN = 0;
    TIM4_IER_bit.UIE = 0;
}

void HWDelay::delay_ms(uint16_t ms){
    TIM4_CR1_bit.CEN = 0;
    TIM4_IER_bit.UIE = 0;
    TIM4_PSCR_bit.PSC = 7; // div by 128
    TIM4_ARR = TIM4_PERIOD_MS;
    TIM4_IER_bit.UIE = 1;
    count = ms;
    TIM4_CR1_bit.CEN = 1;
    while (count){}
    TIM4_CR1_bit.CEN = 0;
    TIM4_IER_bit.UIE = 0;
}

uint8_t HWDelay::isRun(){
    if (count)
        return 1;
    return 0;
}