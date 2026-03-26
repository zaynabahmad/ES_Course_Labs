#include "../../SERVICES/Bit_Math.h"
#include "EXTI.h"

/* Registers */
#define INTCON        *((volatile u8*)0x0B)
#define OPTION_REG    *((volatile u8*)0x81)
#define TRISB         *((volatile u8*)0x86)

/* Global Pointer - Removed 'static' so it is visible to main.c */
void (*EXTI_CallBackPtr)(void) = 0;

void M_EXTI_voidInit(void) {
    /* 1. Set RB0 as Input (Pin 33) */
    SET_BIT(TRISB, 0);
    
    /* 2. Set Falling Edge Trigger (Button with Pull-up R1) */
    CLR_BIT(OPTION_REG, 6);
    
    /* 3. Clear Flag */
    CLR_BIT(INTCON, 1);
    
    /* 4. Enable External Interrupt (INTE) */
    SET_BIT(INTCON, 4);
    
    /* Note: GIE is NOT set here; handled by GIE driver in main */
}

void M_EXTI_voidSetCallBack(void (*ptr)(void)) {
    EXTI_CallBackPtr = ptr;
}