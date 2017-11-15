#ifndef _CRC_H_
#define _CRC_H_
#include <inttypes.h>


class CRC{
    uint8_t crc;
    const uint8_t polynom = 0x8C;
public:
    CRC();
    void add8(uint8_t data);
    void add16(uint16_t data);
    uint8_t getCRC8();
    void reset();
};

/*
uint8_t getCRC8(uint8_t *data, uint8_t length){
    uint8_t crc = 0;
    const uint8_t poly = 0x8C;
        
    while(length--){
        crc ^= *data++;
            
        for (unsigned char i = 0; i < 8; i++){
            crc = crc & 0x01 ? (crc >> 1) ^ poly : crc >> 1;
        }
    }
    return crc;
}
*/

#endif /* _CRC_H_ */