#include "../HAL/LED/LED_interface.h"
#include "../HAL/LED/LED_config.h"
#include "../HAL/SWITCH/SWITCH_interface.h"
#include "../HAL/SWITCH/SWITCH_config.h"

#define DELAY_SHORT  20000   /*0.2s*/
#define DELAY_LONG   50000   /*0.5s*/

void delay(unsigned int count)
{
    unsigned int i;
    for(i = 0; i < count; i++);
}

void main()
{
    LED_Init(LED1_PORT, LED1_PIN);
    LED_Init(LED2_PORT, LED2_PIN);

    SWITCH_Init(SW1_PORT, SW1_PIN);
    SWITCH_Init(SW2_PORT, SW2_PIN);

    while(1)
    {
        if(SWITCH_GetState(SW1_PORT, SW1_PIN) == SWITCH_PRESSED)
        {
            /*fast blink (0.2s ON / 0.2s OFF)*/
            LED_On(LED1_PORT, LED1_PIN);
            LED_On(LED2_PORT, LED2_PIN);
            delay(DELAY_SHORT);
            LED_Off(LED1_PORT, LED1_PIN);
            LED_Off(LED2_PORT, LED2_PIN);
            delay(DELAY_SHORT);
        }
        else if(SWITCH_GetState(SW2_PORT, SW2_PIN) == SWITCH_PRESSED)
        {
            /*slow blink (0.5s ON / 0.5s OFF)*/
            LED_On(LED1_PORT, LED1_PIN);
            LED_On(LED2_PORT, LED2_PIN);
            delay(DELAY_LONG);
            LED_Off(LED1_PORT, LED1_PIN);
            LED_Off(LED2_PORT, LED2_PIN);
            delay(DELAY_LONG);
        }
        else
        {
            /*LEDs off*/
            LED_Off(LED1_PORT, LED1_PIN);
            LED_Off(LED2_PORT, LED2_PIN);
        }
    }
}
