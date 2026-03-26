#include "../../SERVICES/Bit_Math.h"
#include "Timer0.h"

/* Register Definitions */
#define OPTION_REG    *((volatile u8*)0x81)
#define TMR0          *((volatile u8*)0x01)
#define INTCON        *((volatile u8*)0x0B)

/* Global pointer - Removed 'static' so it is visible to main.c */
void (*Timer0_CallBackPtr)(void) = 0;

void M_TIMER0_voidInit(void) {
    /* 1. Select Internal Clock (Fosc/4) */
    CLR_BIT(OPTION_REG, 5);
    
    /* 2. Configure Prescaler 1:8 
       PSA = 0 (Assign to TMR0), PS2:PS0 = 010 */
    CLR_BIT(OPTION_REG, 3);
    CLR_BIT(OPTION_REG, 2);
    SET_BIT(OPTION_REG, 1);
    CLR_BIT(OPTION_REG, 0);

    /* 3. Preload Timer for 1ms @ 8MHz */
    TMR0 = 6;

    /* 4. Enable Timer0 Interrupt (TMR0IE) */
    SET_BIT(INTCON, 5);
    
    /* Note: GIE is NOT set here; handled by GIE driver in main */
}

void M_TIMER0_voidSetPreload(u8 copy_u8Preload) {
    TMR0 = copy_u8Preload;
}

void M_TIMER0_voidSetCallBack(void (*ptr)(void)) {
    Timer0_CallBackPtr = ptr;
}