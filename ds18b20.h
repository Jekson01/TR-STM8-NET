#ifndef _DS18B20_H_
#define _DS18B20_H_
#include <inttypes.h>
#include "onewire.h"

// ROM commands
#define SEARCH_ROM      0xF0
#define READ_ROM        0x33
#define MATCH_ROM       0x55
#define SKIP_ROM        0xCC
#define ALARM_SEARCH    0xEC

// Functional commands
#define CONVERT_T               0x44
#define WRITE_SCRATCHPAD        0x4E
#define READ_SCRATCHPAD         0xBE
#define COPY_SCRATCHPAD         0x48
#define RECALL_E2               0xB8
#define READ_POWER_SUPPLY       0xB4

namespace DS{
    void startConvertion();
    void readDS();
    int16_t getTemperature();
}

#endif /* _DS18B20_H_ */