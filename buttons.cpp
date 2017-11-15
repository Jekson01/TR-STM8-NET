#include "buttons.h"

namespace BTN{
    uint8_t btnCounter;
    uint8_t btnState;
    uint8_t lastCode;
    uint8_t longPressCounter;
    uint8_t pressDelay = PRESS_DELAY;
    uint8_t acceleration;
}

void BTN::update(){
    uint8_t keyCode = 0;
    if (BTN_LEFT == 0) keyCode = 1;
    if (BTN_RIGHT == 0) keyCode |= (1 << 1);
    
    if (keyCode != 0){
        if (lastCode != keyCode)
            btnCounter = 0;
        btnCounter++;  
        if (btnCounter == pressDelay){
            btnCounter = 0;
            btnState = keyCode;
            if (longPressCounter < 0xFF)
                longPressCounter++;
            
            if (acceleration){
                /*
                if (longPressCounter == 10){
                    pressDelay /= 2;
                }
                */
            
                if (longPressCounter > 10){
                    if (pressDelay > MIN_PRESS_DELAY)
                    pressDelay -= 2;
                }
            }
        }
    }else
    {
        btnCounter = 0;
        longPressCounter = 0;
        pressDelay = PRESS_DELAY;
    }
    lastCode = keyCode;
    BTN_DISABLE();
}

uint8_t BTN::getState(){
    uint8_t state = btnState;
    btnState = 0;
    return state;
}

uint8_t BTN::isLongPress(){
    return isLongPress(1);
}

uint8_t BTN::isLongPress(uint8_t delay){
    if (longPressCounter > (LONG_PRESS_DELAY * delay)){
        longPressCounter = 0;
        return 1;
    }
    return 0;
}

void BTN::accelerationEnable(uint8_t enable){
    acceleration = enable;
}
