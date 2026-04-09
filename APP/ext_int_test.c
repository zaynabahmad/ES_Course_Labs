// ============================================================================
// ext_int_test.c
// Purpose: EXT_INT Lab Task – Toggle LED on RD0 every time a rising edge
//          is detected on RB0 (INT0 pin) via external interrupt.
//          No polling used – fully interrupt-driven.
// ============================================================================
#include "../SERVICES/STD_TYPES.h"
#include "ext_int_test.h"
#include "../MCAL/EXT_INT/EXT_INT_interface.h"
#include "../HAL/LED/LED_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"

#define TEST_LED_PORT   GPIO_PORTD
#define TEST_LED_PIN    GPIO_PIN0

static void EXT_INT_Callback(void)
{
    LED_Toggle(TEST_LED_PORT, TEST_LED_PIN);
}

void EXT_INT_TEST_Run(void)
{
    LED_Init(TEST_LED_PORT, TEST_LED_PIN);
    LED_Off(TEST_LED_PORT, TEST_LED_PIN);

    EXT_INT0_Init();
    EXT_INT0_SetEdge(RISING_EDGE);
    EXT_INT0_SetCallback(EXT_INT_Callback);
    EXT_INT0_Enable();

    while (1);
}