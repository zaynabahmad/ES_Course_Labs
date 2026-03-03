#include "HAL/LED/LED_INTERFACE.h"
#include "MCAL/GPIO/GPIO_INTERFACE.h"
#include <util/delay.h>

/* LED Definitions */
#define LED1_PORT     GPIO_PORTB
#define LED1_PIN      GPIO_PIN0

#define LED2_PORT     GPIO_PORTB
#define LED2_PIN      GPIO_PIN1

/* Switch Definitions */
#define SWITCH1_PORT  GPIO_PORTD
#define SWITCH1_PIN   GPIO_PIN2

#define SWITCH2_PORT  GPIO_PORTD
#define SWITCH2_PIN   GPIO_PIN3

int main(void)
{
   
    GPIO_Init();


    LED_Init(LED1_PORT, LED1_PIN);
    LED_Init(LED2_PORT, LED2_PIN);

  
    GPIO_SetPinDirection(SWITCH1_PORT, SWITCH1_PIN, GPIO_INPUT);
    GPIO_SetPinDirection(SWITCH2_PORT, SWITCH2_PIN, GPIO_INPUT);

 
    GPIO_SetPinValue(SWITCH1_PORT, SWITCH1_PIN, GPIO_HIGH);
    GPIO_SetPinValue(SWITCH2_PORT, SWITCH2_PIN, GPIO_HIGH);

    while (1)
    {
        /* Short Sequence (0.2s) */
        if (GPIO_GetPinValue(SWITCH1_PORT, SWITCH1_PIN) == GPIO_LOW)
        {
            LED_On(LED1_PORT, LED1_PIN);
            LED_On(LED2_PORT, LED2_PIN);
            _delay_ms(200);

            LED_Off(LED1_PORT, LED1_PIN);
            LED_Off(LED2_PORT, LED2_PIN);
            _delay_ms(200);
        }

        /* Long Sequence (0.5s) */
        else if (GPIO_GetPinValue(SWITCH2_PORT, SWITCH2_PIN) == GPIO_LOW)
        {
            LED_On(LED1_PORT, LED1_PIN);
            LED_On(LED2_PORT, LED2_PIN);
            _delay_ms(500);

            LED_Off(LED1_PORT, LED1_PIN);
            LED_Off(LED2_PORT, LED2_PIN);
            _delay_ms(500);
        }
    }
}
