#ifndef _MACROS_H_
#define _MACROS_H_

// Прерывания
#define STRINGVECTOR(x) #x
 #define ISR( a, b )  \
 _Pragma( STRINGVECTOR( vector = (b) ) )        \
 __interrupt void (a)( void )
   
#define set(x, y) (x |= (1 << y))
#define clr(x, y) (x &= ~(1 << y))
   
#define sei() asm("rim")
#define cli() asm("sim")
   
#define bit_is_set(x, y) (x & (1 << y))
#define bit_is_clr(x, y) (!(x & (1 << y)))
   
#define EEPROM_ENABLE() FLASH_DUKR = 0xAE; \
                        FLASH_DUKR = 0x56

#define EEPROM_DISABLE()        FLASH_IAPSR_bit.DUL = 0
                            
#endif /* _MACROS_H_ */