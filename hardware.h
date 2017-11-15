#ifndef _HARDWARE_H_
#define _HARDWARE_H_

#include "stm_defines.h"

#define HSI_16MHz     0
#define HSI_8MHz      1
#define HSI_4MHz      2
#define HSI_2MHz      3

namespace HW{
    void initialize();
};

#endif /* _HARDWARE_H_ */