#include "onewire.h"

uint8_t ONE_WIRE::reset(){
    ONE_WIRE_OUT(0);
    ONE_WIRE_DDR(1);
    
    ONE_WIRE_DELAY(500);
    
    ONE_WIRE_DDR(0);
    ONE_WIRE_DELAY(10);
    if (ONE_WIRE_IN == 0){
        return 1;
    }
    ONE_WIRE_DELAY(40);
    if (ONE_WIRE_IN != 0){
        return 2;
    }
    ONE_WIRE_DELAY(500);
    return 0;
}

void ONE_WIRE::write(uint8_t data){
    for (uint8_t i = 0; i < 8; i++){
        ONE_WIRE_DDR(1);
        asm("nop");
        asm("nop");
        asm("nop");
        if (bit_is_set(data, i) != 0){
            ONE_WIRE_DDR(0);
        }
        ONE_WIRE_DELAY(60);
        ONE_WIRE_DDR(0);
        asm("nop");
        asm("nop");
        asm("nop");
    }
}

uint8_t ONE_WIRE::read(){
    uint8_t data = 0;
    
    for (uint8_t i = 0; i < 8; i++){
        ONE_WIRE_DDR(1);
        asm("nop");
        asm("nop");
        asm("nop");
        ONE_WIRE_DDR(0);
        asm("nop");
        asm("nop");
        asm("nop");
        asm("nop");
        asm("nop");
        asm("nop");
        if (ONE_WIRE_IN == 1)
        {
            data |= (1 << i);
        }
        ONE_WIRE_DELAY(60);
    }
    
    return data;
}

void ONE_WIRE::parazitPowerOn(){
    ONE_WIRE_DDR(1);
    ONE_WIRE_OUT(1);
}