#include "crc.h"

CRC::CRC(){
    crc = 0;
}

void CRC::add8(uint8_t data){
    crc ^= data;
    for (unsigned char i = 0; i < 8; i++){
        crc = crc & 0x01 ? (crc >> 1) ^ polynom : crc >> 1;
    }
}

void CRC::add16(uint16_t data){
    add8(data >> 8);
    add8(data & 0x00FF);
}

uint8_t CRC::getCRC8(){
    return crc;
}

void CRC::reset(){
    crc = 0;
}