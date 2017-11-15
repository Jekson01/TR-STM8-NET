#include "uart.h"
#include "stm_defines.h"
#include "macros.h"

namespace UART{
    uint8_t rx_data = 0;
    uint8_t isDone = 0;
}

void UART::initialize(){
    UART1_BRR2 = 0x0B;
    UART1_BRR1 = 0x08;
    UART1_CR2_bit.TEN = 1;
    UART1_CR2_bit.REN = 1;
    UART1_CR2_bit.RIEN = 1;
}

void UART::send(uint8_t data){
    while (!UART1_SR_TXE);
    UART1_DR = data;
}

ISR(UART1_R_RXNE, UART1_R_RXNE_vector){
    UART::rx_data = UART1_DR;
    UART::isDone = 1;
    UART1_SR_bit.RXNE = 0;
}

uint8_t UART::isReady(){
    if (isDone){
        isDone = 0;
        return 1;
    }
    return 0;
}
uint8_t UART::getData(){
    return rx_data;
}