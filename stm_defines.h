#ifndef _STM_DEFINES_H_
#define _STM_DEFINES_H_

#include <iostm8s003f3.h>

#define SEG_A(x)  PC_ODR_bit.ODR3 = x
#define DDR_A() PC_DDR_bit.DDR3 = 1;\
                PC_CR1_bit.C13 = 1

#define SEG_B(x)  PC_ODR_bit.ODR6 = x
#define DDR_B() PC_DDR_bit.DDR6 = 1; \
                PC_CR1_bit.C16 = 1

#define SEG_C(x)  PC_ODR_bit.ODR7 = x
#define DDR_C() PC_DDR_bit.DDR7 = 1;\
                PC_CR1_bit.C17 = 1

#define SEG_D(x)  PD_ODR_bit.ODR2 = x
#define DDR_D() PD_DDR_bit.DDR2 = 1;\
                PD_CR1_bit.C12 = 1

#define SEG_E(x)  PD_ODR_bit.ODR3 = x
#define DDR_E() PD_DDR_bit.DDR3 = 1;\
                PD_CR1_bit.C13 = 1

#define SEG_F(x)  PC_ODR_bit.ODR4 = x
#define DDR_F() PC_DDR_bit.DDR4 = 1;\
                PC_CR1_bit.C14 = 1

#define SEG_G(x)  PA_ODR_bit.ODR3 = x
#define DDR_G() PA_DDR_bit.DDR3 = 1;\
                PA_CR1_bit.C13 = 1

#define SEG_H(x)  PD_ODR_bit.ODR1 = x
#define DDR_H() PD_DDR_bit.DDR1 = 1;\
                PD_CR1_bit.C11 = 1

#define SEG_D3(x)  PB_DDR_bit.DDR5 = x
#define SEG_D2(x)  PB_DDR_bit.DDR4 = x
#define SEG_D1(x)  PC_DDR_bit.DDR5 = x

#define BTN_LEFT        PC_IDR_bit.IDR7
#define BTN_RIGHT       PA_IDR_bit.IDR3

#define BTN_ENABLE()    PC_DDR_bit.DDR7 = 0;\
                        PC_ODR_bit.ODR7 = 1;\
                        PA_DDR_bit.DDR3 = 0;\
                        PA_ODR_bit.ODR3 = 1

#define BTN_DISABLE()   PC_DDR_bit.DDR7 = 1;\
                        PC_ODR_bit.ODR7 = 0;\
                        PA_DDR_bit.DDR3 = 1;\
                        PA_ODR_bit.ODR3 = 0

//#define RELAY_INIT()    PD_DDR_bit.DDR4 = 1;\
//                       PD_CR1_bit.C14 = 1

//#define RELAY(x)        PD_ODR_bit.ODR4 = x

#define ONE_WIRE_IN     PD_IDR_bit.IDR4
#define ONE_WIRE_DDR(x) PD_DDR_bit.DDR4 = x
#define ONE_WIRE_OUT(x) PD_ODR_bit.ODR4 = x;\
                         PD_CR1_bit.C14 = x
                            
#endif /* _STM_DEFINES_H_ */