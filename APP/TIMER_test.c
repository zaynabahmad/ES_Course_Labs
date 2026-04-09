 #include "../MCAL/TIMER0/TIMER0_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../SERVICES/STD_TYPES.h"

volatile u16 led1_counter = 0;
volatile u16 led2_counter = 0;

#define LED1_PORT GPIO_PORTB
#define LED1_PIN  GPIO_PIN0
#define LED2_PORT GPIO_PORTB
#define LED2_PIN  GPIO_PIN1

void Timer0_ISR(void) // ISR must be called inside actual interrupt vector
{
    led1_counter++;
    led2_counter++;

    if(led1_counter >= 2000) // 1ms * 2000 = 2s
    {
        GPIO_TogglePin(LED1_PORT, LED1_PIN);
        led1_counter = 0;
    }

    if(led2_counter >= 1000) // 1ms * 1000 = 1s
    {
        GPIO_TogglePin(LED2_PORT, LED2_PIN);
        led2_counter = 0;
    }
}

void Timer0_Test(void)
{
    GPIO_SetPinDirection(LED1_PORT, LED1_PIN, GPIO_OUTPUT);
    GPIO_SetPinDirection(LED2_PORT, LED2_PIN, GPIO_OUTPUT);

    Timer0_Init();
    Timer0_SetCallBack(Timer0_ISR);

    while(1)
    {
        // main loop free for other tasks
    }
}