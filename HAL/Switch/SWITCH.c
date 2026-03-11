#include "SWITCH.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/GPIO/GPIO_private.h"
#include "SWITCH_config.h"

void SWITCH_Init(uint8 pin)
{
    TRISB |= (1 << pin);   
}

uint8 SWITCH_Read(uint8 pin)
{
    uint8 first_read;
    uint8 second_read;

    first_read = (PORTB >> pin) & 1;
    Delay_ms(SWITCH_DEBOUNCE_TIME_MS);

    second_read = (PORTB >> pin) & 1;

       if (first_read == second_read)
    {
        return second_read;
    }
    
    return 0; 
}