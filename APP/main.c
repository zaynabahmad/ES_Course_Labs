#include "../HAL/LED/LED_interface.h"
#include "../HAL/Switch/Switch.h"
#include "../MCAL/Exit.INT/EXT_INT_Interface.h"

#define LED_PORT         PORTC
#define LED_1            0
#define LED_2            1
#define INT_LED_PORT     PORTD
#define INT_LED_PIN      3

// Switches (Input)
#define SW1_PORT         PORTD
#define SW1_PIN          1
#define SW2_PORT         PORTB
#define SW2_PIN          2

#define GPIO_HIGH        1

void App_OnInterrupt(void)
{
    LED_Toggle(INT_LED_PORT, INT_LED_PIN);
}

void main()
{

    LED_Init(LED_PORT, LED_1);
    LED_Init(LED_PORT, LED_2);
    LED_Init(INT_LED_PORT, INT_LED_PIN);

    SWITCH_Init(SW1_PORT, SW1_PIN);
    SWITCH_Init(SW2_PORT, SW2_PIN);


    EXT_INT0_Init();
    EXT_INT0_SetCallback(App_OnInterrupt);
    EXT_INT0_Enable();


    while (1)
    {

        if (SWITCH_Read(SW1_PORT, SW1_PIN) == GPIO_HIGH)
        {
            LED_On(LED_PORT, LED_1);
            LED_On(LED_PORT, LED_2);
            Delay_ms(200);
            LED_Off(LED_PORT, LED_1);
            LED_Off(LED_PORT, LED_2);
            Delay_ms(200);
        }

        else if (SWITCH_Read(SW2_PORT, SW2_PIN) == GPIO_HIGH)
        {
            LED_On(LED_PORT, LED_1);
            LED_On(LED_PORT, LED_2);
            Delay_ms(500);
            LED_Off(LED_PORT, LED_1);
            LED_Off(LED_PORT, LED_2);
            Delay_ms(500);
        }
        else
        {
            LED_Off(LED_PORT, LED_1);
            LED_Off(LED_PORT, LED_2);
        }
    }
}