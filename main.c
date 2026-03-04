#include "../MCAL/DIO.h"
#include "../HAL/LED_SWITCH.h"

void main()
{
    DIO_Init();

    while(1)
    {
        if(SW1_Read())
        {
            while(SW1_Read())
            {
                LED_On();
                Delay_ms(200);
                LED_Off();
                Delay_ms(200);
            }
        }

        else if(SW2_Read())
        {
            while(SW2_Read())
            {
                LED_On();
                Delay_ms(500);
                LED_Off();
                Delay_ms(500);
            }
        }

        else
        {
            LED_Off();
        }
    }
}