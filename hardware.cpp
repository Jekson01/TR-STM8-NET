#include "hardware.h"
#include "macros.h"
void HW::initialize(){
    // CPU init
    CLK_CKDIVR_bit.HSIDIV = HSI_16MHz;
    CLK_CKDIVR_bit.CPUDIV = 0;
    while (CLK_ICKR_bit.HSIRDY != 1){}
    
    // Timer 1 init for display and buttons check

    TIM1_SR1_bit.UIF = 0;
    TIM1_PSCRH = (4000) >> 8;
    TIM1_PSCRL = (4000) & 0xFF; //Делитель на 1000
    TIM1_ARRH = (19) >> 8; //Частота переполнений = 4М / 1000 / 20 = 200 Гц
    TIM1_ARRL = (19)& 0xFF;
    TIM1_IER_bit.UIE = 1;
    TIM1_CCR1H = (8) >> 8;
    TIM1_CCR1L = (8) & 0xFF;
    TIM1_IER_bit.CC1IE = 1;
    TIM1_CCR2H = (18) >> 8;
    TIM1_CCR2L = (18) & 0xFF;
    TIM1_IER_bit.CC2IE = 1;
    TIM1_CR1_bit.CEN = 1;
    
    // Global interrupt enable
    sei();
}