/**
 * @file    test_exti.c
 * @brief   External-interrupt exercise -- application layer, no register access.
 *
 * @details The callback runs in interrupt context, so it does the smallest
 *          possible amount of work -- a single LED toggle through the HAL.
 *          The main loop stays empty on purpose: all the behaviour is
 *          interrupt-driven, which is the point of the exercise.
 */
#include "test_exti.h"
#include "../MCAL/EXTI_interface.h"
#include "../HAL/LED.h"

/**
 * @brief  Edge handler -- kept tiny because it runs inside the ISR.
 */
static void vOnEdge(void)
{
    vLED_Toggle(LED_ALERT);
}

void vTest_Exti(void)
{
    vLED_Init(LED_ALERT);

    vEXTI_Init();                       /* INT pin as input, default edge. */
    vEXTI_SetEdge(EXTI_EDGE_FALLING);
    vEXTI_SetCallback(&vOnEdge);        /* register before enabling.       */
    vEXTI_Enable();

    while (1)
    {
        /* Nothing to do here -- the LED is serviced entirely by the ISR. */
    }
}
