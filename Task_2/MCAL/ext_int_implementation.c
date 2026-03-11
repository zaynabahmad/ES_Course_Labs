#include "../SERVICES/std_types.h"
#include "ext_int_interface.h"
#include "/TIMER/timer_interface.h"

#include <stddef.h>

static void (*ext_int_callback)(void) = 0;

void EXT_INTO_Init(void) {
    set_pin_direction(_PORTB, 0, INPUT);
    INTCON &= ~0x02;
}

void EXT_INTO_Enable(void) {
    INTCON |= 0x10;
    INTCON |= 0x80;
}

void EXT_INTO_SetEdge(u8 edge_type) {
    if(edge_type == 1) {
        OPTION_REG |= 0x40;
    } else {
        OPTION_REG &= ~0x40;
    }
}

void EXT_INTO_SetCallback(void (*ptr)(void)) {
    ext_int_callback = ptr;
}

void interrupt(void) {
    if(INTCON & 0x02) {
        if(ext_int_callback != 0) {
            ext_int_callback();
        }
        INTCON &= ~0x02;
    }
     if(INTCON & 0x04){
        
        TIMER0_ISR_Handler();
        
        INTCON &= ~0x04;
    }
}