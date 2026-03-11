#include "GIE_interface.h"

#define INTCON *((volatile unsigned char*)0x0B)

void GIE_voidEnable(void) {
    INTCON |= (1 << 7); 
}

void GIE_voidDisable(void) {
    INTCON &= ~(1 << 7); 
}
