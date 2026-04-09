/*
 * timer_test.c
 * APP Layer - Timer0 Driver Test
 *
 * Test Description:
 *   - Test 1: Blocking delay - blink LED every 500ms
 *   - Test 2: Overflow interrupt - toggle LED in ISR
 */

#include "timer_test.h"
#include "../MCAL/TIMER0/timer0.h"
#include "../MCAL/GPIO/gpio.h"

#define TMR_LED_PORT    GPIO_PORTB
#define TMR_LED_PIN     GPIO_PIN2

static volatile u8 g_timerTick = 0;

void TIMER_Test_Init(void)
{
    /* LED as output */
    GPIO_SetPinDirection(TMR_LED_PORT, TMR_LED_PIN, GPIO_OUTPUT);
    GPIO_WritePin(TMR_LED_PORT, TMR_LED_PIN, GPIO_LOW);

    /* Timer0 with internal clock, prescaler 1:256 */
    TIMER0_Init(TIMER0_CLK_INTERNAL, TIMER0_PRESCALER_256);
    TIMER0_SetPreload(131);  /* ~32ms per overflow */
}

void TIMER_Test_BlockingBlink(void)
{
    /* Use hardware-assisted ms delay */
    while(1)
    {
        GPIO_WritePin(TMR_LED_PORT, TMR_LED_PIN, GPIO_HIGH);
        TIMER0_DelayMs(500);
        GPIO_WritePin(TMR_LED_PORT, TMR_LED_PIN, GPIO_LOW);
        TIMER0_DelayMs(500);
    }
}

/*
 * ISR Handler - called from interrupt routine in main.c
 * Toggles LED every ~32ms (prescaler=256, preload=131)
 * ~32 ticks for 1s visible blink rate
 */
void TIMER_Test_ISR_Handler(void)
{
    TIMER0_ClearFlag();
    TIMER0_SetPreload(131);

    g_timerTick++;
    if(g_timerTick >= 15)   /* ~0.5 sec (15 x 32ms) */
    {
        g_timerTick = 0;
        GPIO_TogglePin(TMR_LED_PORT, TMR_LED_PIN);
    }
}

void TIMER_Test_InterruptBlink(void)
{
    TIMER_Test_Init();
    TIMER0_Start();   /* Enable interrupt-driven mode */

    /* Main loop does nothing - LED blinks via ISR */
    while(1);
}

void TIMER_Test_Run(void)
{
    /* Uncomment one test at a time */
    TIMER_Test_BlockingBlink();
    /* TIMER_Test_InterruptBlink(); */
}
