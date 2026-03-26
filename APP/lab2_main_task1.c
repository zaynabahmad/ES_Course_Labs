#include "../HAL/LED/LED_interface.h"
#include "../HAL/LED/LED_config.h"
#include "../HAL/SWITCH/SWITCH_interface.h"
#include "../HAL/SWITCH/SWITCH_config.h"
#include "../SERVICES/STD_TYPES.h"

void Delay_ms(u16 time)
{
    u16 i, j;
    for(i = 0; i < time; i++)
    {
        for(j = 0; j < 1275; j++)
        {
        }
    }
}

void Short_Sequence(void)
{
    LED_On(LED1_PORT, LED1_PIN);
    LED_Off(LED2_PORT, LED2_PIN);
    Delay_ms(200);

    LED_Off(LED1_PORT, LED1_PIN);
    LED_On(LED2_PORT, LED2_PIN);
    Delay_ms(200);
}

void Long_Sequence(void)
{
    LED_On(LED1_PORT, LED1_PIN);
    LED_Off(LED2_PORT, LED2_PIN);
    Delay_ms(500);

    LED_Off(LED1_PORT, LED1_PIN);
    LED_On(LED2_PORT, LED2_PIN);
    Delay_ms(500);
}

void main(void)
{
    LED_Init(LED1_PORT, LED1_PIN);
    LED_Init(LED2_PORT, LED2_PIN);

    SWITCH_Init(&SW1);
    SWITCH_Init(&SW2);

    LED_Off(LED1_PORT, LED1_PIN);
    LED_Off(LED2_PORT, LED2_PIN);

    while(1)
    {
        if(SWITCH_GetState(&SW1) == SWITCH_PRESSED)
        {
            Short_Sequence();
        }
        else if(SWITCH_GetState(&SW2) == SWITCH_PRESSED)
        {
            Long_Sequence();
        }
        else
        {
            LED_Off(LED1_PORT, LED1_PIN);
            LED_Off(LED2_PORT, LED2_PIN);
        }
    }
}