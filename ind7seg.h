#ifndef _IND7SEG_H_
#define _IND7SEG_H_
#include <inttypes.h>

#define ON      1
#define OFF     0



#define SEGMENT_COUNT   7
#define DGT_COUNT       3
#define MAX_BRIGHT      12
#define MIN_BRIGHT      1
                    
#define S_CLEAR 10
#define S_U     11
#define S_u     12
#define S_P     13
#define S_d     14
#define S_n     15
#define S_t     16
#define S_C     17
#define S_A     18
#define S_L     19
#define S_MINUS 20
#define S_E     21
#define S_F     22
#define S_b     23
#define S_r     24

#define POINT3  0
#define POINT2  1
#define POINT1  2
                    
namespace DISPLAY{
    extern uint8_t digits[DGT_COUNT];
    void initialize();
    void update();
    void off();
    void onCatode(uint8_t num);
    void offCatode(uint8_t num);
    
    void print(uint16_t num);
    void setBright(uint8_t bright);
    
    void blinkOn(uint8_t enable);
    void blink();
    void setPoint(uint8_t pos);
}

#endif /* _IND7SEG_H_ */