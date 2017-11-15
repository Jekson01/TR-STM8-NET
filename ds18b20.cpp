#include "ds18b20.h"
#include "crc.h"

namespace DS{
    int16_t temperatura;
}

void DS::startConvertion(){
    ONE_WIRE::reset();
    ONE_WIRE::write(SKIP_ROM);
    ONE_WIRE::write(CONVERT_T);
    ONE_WIRE::parazitPowerOn();
}

void DS::readDS(){
    CRC crc;
    ONE_WIRE::reset();
    ONE_WIRE::write(SKIP_ROM);
    ONE_WIRE::write(READ_SCRATCHPAD);
    uint8_t low = ONE_WIRE::read();
    crc.add8(low);
    uint8_t high =ONE_WIRE::read();
    crc.add8(high);
    crc.add8(ONE_WIRE::read());
    crc.add8(ONE_WIRE::read());
    crc.add8(ONE_WIRE::read());
    crc.add8(ONE_WIRE::read());
    crc.add8(ONE_WIRE::read());
    crc.add8(ONE_WIRE::read());
    crc.add8(ONE_WIRE::read());
    
    if (crc.getCRC8() == 0){
        temperatura = 0;
        temperatura = high << 8;
        temperatura |= low;
        temperatura = (temperatura * 6) / 10;
    }else{
        temperatura = 999;
    }
    
}

int16_t DS::getTemperature(){
    return temperatura;
}