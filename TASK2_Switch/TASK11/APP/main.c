#include "../MCAL/GPIO/GPIO_interface.h"
#include "../HAL/LED/LED_interface.h"
#include "../SERVICES/STD_TYPES.h"
#include "built_in.h"   // if Delay_ms is used in MikroC

#define SW1_PORT GPIO_PORTB
#define SW1_PIN  GPIO_PIN0
#define SW2_PORT GPIO_PORTB
#define SW2_PIN  GPIO_PIN1

void ShortSequence(void)
{
    LED_On(LED1);
    LED_On(LED2);
    Delay_ms(200);
    LED_Off(LED1);
    LED_Off(LED2);
    Delay_ms(200);
}

void LongSequence(void)
{
    LED_On(LED1);
    LED_On(LED2);
    Delay_ms(500);
    LED_Off(LED1);
    LED_Off(LED2);
    Delay_ms(500);
}

void main(void)
{
    GPIO_Init();
    LED_Init();

    GPIO_SetPinDirection(SW1_PORT, SW1_PIN, GPIO_INPUT);
    GPIO_SetPinDirection(SW2_PORT, SW2_PIN, GPIO_INPUT);

    while(1)
    {
        if(GPIO_GetPinValue(SW1_PORT, SW1_PIN) == 0)
            ShortSequence();
        else if(GPIO_GetPinValue(SW2_PORT, SW2_PIN) == 0)
            LongSequence();
        else
        {
            LED_Off(LED1);
            LED_Off(LED2);
        }
    }
}