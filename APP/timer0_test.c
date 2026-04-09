#include "../MCAL/GPIO/GPIO_Interface.h"
#include "../MCAL/TIMER0/TIMER0_Interface.h"

/* Callback: toggle LED on RA0 every overflow */
void TMR0_Callback(void)
{
    static u8 state = 0;
    state ^= 1;
    GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN0, state);
}

/* Test: Timer0 interrupt toggles LED */
void TIMER0_Test(void)
{
    GPIO_SetPinDirection(GPIO_PORTA, GPIO_PIN0, GPIO_OUTPUT);

    TIMER0_Init();
    TIMER0_SetPreload(0);
    TIMER0_SetCallback(TMR0_Callback);
    TIMER0_EnableInterrupt();

    while(1)
    {
        /* Timer ISR handles the toggling */
    }
}
