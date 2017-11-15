#include "stm_defines.h"
#include "ind7seg.h"
#include <inttypes.h>
#include "hardware.h"
#include "macros.h"
#include "delay.h"
#include "hardware_delay.h"
#include "ds18b20.h"
#include "uart.h"
#include "buttons.h"

// Show symbols 

ISR(TIM1_OVR_handler, TIM1_OVR_UIF_vector){
    //if (!HWDelay::isRun()){
        DISPLAY::update();
    //}
    TIM1_SR1_bit.UIF = 0;
}

ISR(TIM1_CAPCOM_CC1IF_handler, TIM1_CAPCOM_CC1IF_vector){
    // Off all symbols and catods
    if (TIM1_SR1_bit.CC1IF == 1){
        DISPLAY::off();
        BTN_ENABLE();
        TIM1_SR1_bit.CC1IF = 0;
    }

    // Check buttons state
    if (TIM1_SR1_bit.CC2IF == 1){
        BTN::update();
        TIM1_SR1_bit.CC2IF = 0;
    }
}


int main()
{
    HW::initialize();
    DISPLAY::initialize();
    DISPLAY::setPoint(POINT2);
    
    HWDelay::delay_ms(100);
    
    UART::initialize();
    while(1){
        //DS::startConvertion();
        //HWDelay::delay_ms(1000);
        //DS::readDS();
        //int16_t t = DS::getTemperature();
        //DISPLAY::print(t);
        //UART::send(t);
        /*
        if (UART::isReady()){
           
        }
        */
        //UART::send(t & 0x00FF);
        uint8_t key = BTN::getState();
        if (key == keyLeft){
            DISPLAY::print(111);
        }
         if (key == keyRight){
            DISPLAY::print(222);
        }
    }
    return 0;
}
