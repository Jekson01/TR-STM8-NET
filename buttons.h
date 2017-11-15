#ifndef _BUTTONS_H_
#define _BUTTONS_H_
#include <inttypes.h>
#include "stm_defines.h"
                           
#define LONG_PRESS_DELAY        10
#define PRESS_DELAY             50
#define MIN_PRESS_DELAY         5
                            
typedef enum KEYCODES{keyNone = 0, keyLeft = 1, keyRight = 2, keyTwo = 3} KEYCODES;
namespace BTN{
    void update();
    uint8_t getState();
    uint8_t isLongPress();
    uint8_t isLongPress(uint8_t count);
    void accelerationEnable(uint8_t enable);
}

#endif /* _BUTTONS_H_ */