#include "LED.h"
#include "GPIO.h"
#include <util/delay.h>

#define SWITCH1_PORT   PORTD
#define SWITCH1_PIN    PIN2

#define SWITCH2_PORT   PORTD
#define SWITCH2_PIN    PIN3



int main(void)
{
    LED_Init(LED1);
    LED_Init(LED2);

    GPIO_SetPinDirection(SWITCH1_PORT, SWITCH1_PIN, INPUT);
    GPIO_SetPinDirection(SWITCH2_PORT, SWITCH2_PIN, INPUT);

    while (1)
    {
        if (GPIO_ReadPin(SWITCH1_PORT, SWITCH1_PIN) == HIGH)
        {
               LED_On(LED1);
               LED_On(LED2);
              _delay_ms(200);

              LED_Off(LED1);
              LED_Off(LED2);
              _delay_ms(200);
        }
        else if (GPIO_ReadPin(SWITCH2_PORT, SWITCH2_PIN) == HIGH)
        {
               LED_On(LED1);
                LED_On(LED2);
                _delay_ms(500);
            
                LED_Off(LED1);
                LED_Off(LED2);
                _delay_ms(500);
        }
      
    }
}
