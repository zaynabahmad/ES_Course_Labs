/*
 * exti_test.c
 * APP Layer - External Interrupt Test
 *
 * Test Description:
 *   - INT0 on RB0 (falling edge)
 *   - Each interrupt toggles LED on RB1
 *   - ISR counter incremented on each interrupt
 */

#include "exti_test.h"
#include "../MCAL/EXTI/exti.h"
#include "../MCAL/GPIO/gpio.h"
#include "../MCAL/TIMER0/timer0.h"

#define EXTI_LED_PORT   GPIO_PORTB
#define EXTI_LED_PIN    GPIO_PIN1

/* Shared variable - must be volatile for ISR use */
static volatile u8 g_extiCount = 0;

void EXTI_Test_Init(void)
{
    /* Configure LED as output */
    GPIO_SetPinDirection(EXTI_LED_PORT, EXTI_LED_PIN, GPIO_OUTPUT);
    GPIO_WritePin(EXTI_LED_PORT, EXTI_LED_PIN, GPIO_LOW);

    /* Initialize INT0 on falling edge (RB0) */
    EXTI_Init(EXTI_FALLING_EDGE);

    /* Enable INT0 and global interrupt */
    EXTI_Enable(EXTI_INT0);

    g_extiCount = 0;
}

/*
 * NOTE FOR MIKROC:
 * In MikroC, the ISR is defined using the 'interrupt' keyword.
 * The ISR below must be placed in this file or main.c.
 *
 * void interrupt(void)
 * {
 *     if(EXTI_GetFlag(EXTI_INT0))
 *     {
 *         EXTI_Test_ISR_Handler();
 *         EXTI_ClearFlag(EXTI_INT0);
 *     }
 * }
 */
void EXTI_Test_ISR_Handler(void)
{
    g_extiCount++;
    GPIO_TogglePin(EXTI_LED_PORT, EXTI_LED_PIN);
}

u8 EXTI_Test_GetCount(void)
{
    return g_extiCount;
}

void EXTI_Test_Run(void)
{
    EXTI_Test_Init();

    /* Main loop - just wait for interrupts */
    /* LED toggling and counter incrementing happen in ISR */
    while(1)
    {
        /* Application can do other work here */
        TIMER0_DelayMs(100);
        /* Count visible on g_extiCount */
    }
}
