#include "../HAL/LED/LED.h"
#include "../HAL/Switch/SWITCH.h"
#include "../MCAL/GPIO/GPIO_interface.h" 

#define LED1     GPIO_PIN1
#define LED2     GPIO_PIN2
#define SWITCH1  GPIO_PIN3
#define SWITCH2  GPIO_PIN4

void main()
{
    LED_Init(LED1);
    LED_Init(LED2);

    SWITCH_Init(SWITCH1);
    SWITCH_Init(SWITCH2);

    LED_Off(LED1);
    LED_Off(LED2);

    while(1)
    {
        // Short sequence (0.2s)
        if(SWITCH_Read(SWITCH1))
        {
            LED_On(LED1);
            LED_On(LED2);
            Delay_ms(200);

            LED_Off(LED1);
            LED_Off(LED2);
            Delay_ms(200);
        }

        // Long sequence (0.5s)
        else if(SWITCH_Read(SWITCH2))
        {
            LED_On(LED1);
            LED_On(LED2);
            Delay_ms(500);

            LED_Off(LED1);
            LED_Off(LED2);
            Delay_ms(500);
        }
        else
        {
            LED_Off(LED1);
            LED_Off(LED2);
        }
    }
}