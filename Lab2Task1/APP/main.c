#include "../MCAL/GPIO/gpio_interface.h"
#include "../HAL/LED/LED_interface.h"


void delay_ms(int ms)
{
    volatile int i, j;
    for(i = 0; i < ms; i++)
        for(j = 0; j < 1000; j++);
}


#define LED1_PORT _PORTA
#define LED2_PORT _PORTA
#define SW1_PORT  _PORTA
#define SW2_PORT  _PORTA


#define LED1_PIN 0 // RA0
#define LED2_PIN 1 // RA1
#define SW1_PIN  2 // RA2
#define SW2_PIN  3 // RA3

int main()
{
    // Make RA0/RA1 digital
    ADCON1 = 0x06;


    GPIO_Init();
    LED_Init(LED1_PORT, LED1_PIN, LED2_PORT, LED2_PIN);


    setpindirection(SW1_PORT, SW1_PIN, INPUT);
    setpindirection(SW2_PORT, SW2_PIN, INPUT);

    while(1)
    {

        if(getpinvalue(SW1_PORT, SW1_PIN) == 0)
        {

            LED_On(LED1_PORT, LED1_PIN);
            LED_Off(LED2_PORT, LED2_PIN);
            delay_ms(200);

            LED_Off(LED1_PORT, LED1_PIN);
            LED_On(LED2_PORT, LED2_PIN);
            delay_ms(200);
        }
        // Check Switch2 (Active Low)
        else if(getpinvalue(SW2_PORT, SW2_PIN) == 0)
        {
            // Long sequence: 500ms alternating LEDs
            LED_On(LED1_PORT, LED1_PIN);
            LED_Off(LED2_PORT, LED2_PIN);
            delay_ms(500);

            LED_Off(LED1_PORT, LED1_PIN);
            LED_On(LED2_PORT, LED2_PIN);
            delay_ms(500);
        }
        else
        {
            // No switch pressed ? LEDs OFF
            LED_Off(LED1_PORT, LED1_PIN);
            LED_Off(LED2_PORT, LED2_PIN);
        }
    }

    return 0;
}