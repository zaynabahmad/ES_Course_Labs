#include "../SERVICES/std_types.h"       // Added to define u32 and u8
#include "../MCAL/TIMER0/TIMER0_interface.h"
#include "../HAL/LED/LED_interface.h"
#include "../MCAL/TIMER0/TIMER0_private.h"

void TIMER0_test(void) {
    u32 Local_u32Counter = 0;
    static u8 Local_u8State = 0; // Added for the manual toggle

    LED_voidInit(LED0);
    TIMER0_voidInit(TIMER0_PRESCALER_256);
    TIMER0_voidSetPreload(0);

    while(1) {
        /* Check if Timer Overflow Flag is set (TMR0IF is Bit 2 of INTCON) */
        if( ( (INTCON_REG >> 2) & 0x01 ) == 1 ) {
            Local_u32Counter++;

            /* Clear the flag to start again */
            INTCON_REG &= ~(1 << 2);

            /* ~30 overflows for a visible delay */
            if(Local_u32Counter == 30) {

                /* MANUAL TOGGLE */
                if(Local_u8State == 0) {
                    LED_voidOn(LED0);
                    Local_u8State = 1;
                } else {
                    LED_voidOff(LED0);
                    Local_u8State = 0;
                }

                Local_u32Counter = 0;
            }
        }
    }
}