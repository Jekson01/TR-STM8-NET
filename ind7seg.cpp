#include "ind7seg.h"
#include "stm_defines.h"
#include "macros.h"

namespace DISPLAY{
    uint8_t digits[DGT_COUNT] = {S_MINUS, S_MINUS, S_MINUS};
    uint8_t segmentNum = 0;
    uint8_t catodNum = 0;
    uint8_t pointPos = 0xFF;
    volatile uint8_t blinkEnable = 0;
    volatile uint8_t blinkCounter = 0;
    const char charTable[] = {   0x3F, // 0
                            0x06, // 1
                            0x5B, // 2
                            0x4F, // 3
                            0x66, // 4
                            0x6D, // 5
                            0x7D, // 6
                            0x07, // 7
                            0x7F, // 8
                            0x6F, // 9
                            0x00, // clear
                            0x3E, // U
                            0x1C, // u
                            0x73, // P
                            0x5E, // d
                            0x54, // n
                            0x78, // t
                            0x39, // C
                            0x77, // A
                            0x38, // L
                            0x40, // minus '-'
                            0x79, // E
                            0x71, // F
                            0x7C, // b
                            0x50  // r
    };
}

void DISPLAY::initialize(){
    DDR_A();
    DDR_B();
    DDR_C();
    DDR_D();
    DDR_E();
    DDR_F();
    DDR_G();
    DDR_H();
}

void DISPLAY::update(){
    
    uint8_t outCode = charTable[digits[catodNum]];
    if (catodNum == pointPos)
        outCode |= (1 << 7);
    
     if (bit_is_set(outCode, 0))
         SEG_A(ON);
     
     if (bit_is_set(outCode, 1))
         SEG_B(ON);
     
     if (bit_is_set(outCode, 2))
         SEG_C(ON);
     
     if (bit_is_set(outCode, 3))
         SEG_D(ON);
     
     if (bit_is_set(outCode, 4))
         SEG_E(ON);
     
     if (bit_is_set(outCode, 5))
         SEG_F(ON);
     
     if (bit_is_set(outCode, 6))
         SEG_G(ON);
     
     if (bit_is_set(outCode, 7))
         SEG_H(ON);
    
    
    if (blinkEnable){
        if (blinkCounter)
            onCatode(catodNum);
    }else onCatode(catodNum);
    
    catodNum++;
    if (catodNum == DGT_COUNT)
        catodNum = 0;
    
}

void DISPLAY::off(){
    SEG_A(OFF);
    SEG_B(OFF);
    SEG_C(OFF);
    SEG_D(OFF);
    SEG_E(OFF);
    SEG_F(OFF);
    SEG_G(OFF);
    SEG_H(OFF);
    SEG_D1(OFF);
    SEG_D2(OFF);
    SEG_D3(OFF);
}

void DISPLAY::onCatode(uint8_t num){
    switch(num){
        case 0: SEG_D3(ON); break;
        case 1: SEG_D2(ON); break;
        case 2: SEG_D1(ON); break;
    }
}

void DISPLAY::offCatode(uint8_t num){
    switch(num){
        case 0: SEG_D3(OFF); break;
        case 1: SEG_D2(OFF); break;
        case 2: SEG_D1(OFF); break;
    }
}

void DISPLAY::print(uint16_t num){
    digits[2] = num % 10;
    num /= 10;
    digits[1] = num % 10;
    num /= 10;
    digits[0] = num % 10;
}

void DISPLAY::setBright(uint8_t bright){
    TIM1_CCR1H = (bright) >> 8;
    TIM1_CCR1L = (bright) & 0xFF;
}

void DISPLAY::blinkOn(uint8_t enable){
    blinkEnable = enable;
}

void DISPLAY::blink(){
    blinkCounter++;
    blinkCounter = blinkCounter % 2;
}

void DISPLAY::setPoint(uint8_t pos){
    pointPos = pos;
}