#include "../HAL Layer/SWITCH.h"

#define TRISB_REG   (*((volatile uint8*)0x86))
void SWITCH_Init(uint8 pin) {
    
TRISB_REG |= (1 << pin);

}

