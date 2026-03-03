#include "../HAL/LED/LED_interface.h"
#include "../HAL/SWITCH/SWITCH_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"

void main()
{
    ADCON1 = 0x07;   // ?? VERY IMPORTANT (All PORTA digital)

    TRISA = 0xFF;   // Make PORTA input
    TRISB = 0x00;   // Make PORTB output

    PORTA = 0x00;
    PORTB = 0x00;

    while(1)
    {
        if((PORTA.F0) == 1)   // RA0 pressed
        {
            PORTB.F0 = 1;
            PORTB.F1 = 1;
            Delay_ms(200);

            PORTB.F0 = 0;
            PORTB.F1 = 0;
            Delay_ms(200);
        }

        else if((PORTA.F1) == 1)  // RA1 pressed
        {
            PORTB.F0 = 1;
            PORTB.F1 = 1;
            Delay_ms(500);

            PORTB.F0 = 0;
            PORTB.F1 = 0;
            Delay_ms(500);
        }

        else
        {
            PORTB.F0 = 0;
            PORTB.F1 = 0;
        }
    }
}