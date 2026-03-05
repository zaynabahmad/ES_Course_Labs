#include "EXT_INT0.h"

static void (*INT0_Callback)(void) = 0;

void EXT_INT0_Init(void) {
   TRISB_REG  |=  (1 << 0);
   INTCON_REG &= ~(1 << 1);
}

void EXT_INT0_Enable(void) {
   INTCON_REG |=  (1 << 4);
    INTCON_REG |=  (1 << 7);
}

void EXT_INT0_Disable(void) {
   INTCON_REG &= ~(1 << 4);
}

void EXT_INT0_SetEdge(uint8 edge_type) {
   if(edge_type == RISING_EDGE)
        OPTION_REG |=  (1 << 6);   
    else if(edge_type == FALLING_EDGE)
        OPTION_REG &= ~(1 << 6);   
    
}

void EXT_INT0_SetCallback(void (*ptr)(void)) {
  INT0_Callback = ptr;
}


void interrupt() {
    if((INTCON_REG & (1 << 1)) != 0) {
        if(INT0_Callback != 0) {
            INT0_Callback();
        }
       INTCON_REG &= ~(1 << 1);
    }

}
