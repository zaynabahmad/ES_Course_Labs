#include "STD_TYPES.h"
#include "TIMER0_private.h"
#include "TIMER0_interface.h"

static void (*TIMER0_CallBack)(void) = 0;

void TIMER0_voidInit(void) {
    
    OPTION_REG &= 0b11000000; 
    OPTION_REG |= 0b00000010; 
}

void TIMER0_voidSetPreload(unsigned char Copy_u8Preload) {
    TMR0 = Copy_u8Preload;
}

void TIMER0_voidEnableInterrupt(void) {
  
    INTCON |= (1 << 5);
}

void TIMER0_voidSetCallBack(void (*Copy_ptrToFunc)(void)) {
    if (Copy_ptrToFunc != 0) {
        TIMER0_CallBack = Copy_ptrToFunc;
    }
}


void interrupt() {
    
    if (INTCON & (1 << 2)) {
        INTCON &= ~(1 << 2);
        TMR0 = 6;
        if (TIMER0_CallBack != 0) {
            TIMER0_CallBack();
        }
    }
}