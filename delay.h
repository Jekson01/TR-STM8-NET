#ifndef _DELAY_H_
#define _DELAY_H_
#include <inttypes.h>

typedef struct Delay{
    volatile uint16_t time;
    void setMS(uint16_t ms){
        time = ms;
    }
    
    uint8_t isDone(){
        if (time == 0)
            return 1;
        return 0;
    }
    
    void tickMS(){
        if (time != 0)
            time--;
    }
}Delay;

Delay delay;

#endif /* _DELAY_H_ */