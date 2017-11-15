#ifndef _UART_H_
#define _UART_H_
#include <inttypes.h>

namespace UART{
    void initialize();
    void send(uint8_t data);
    uint8_t isReady();
    uint8_t getData();
}

#endif /* _UART_H_ */