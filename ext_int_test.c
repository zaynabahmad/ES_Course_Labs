#include "../SERVICES/types.h"
#include "ext_int_test.h"
#include "../MCAL/EXT_INT/ext_int_interface.h"
#include "../HAL/LED/led_interface.h"
#include "../MCAL/GPIO/gpio_interface.h"

#define TEST_LED_PORT   PORTD_ID
#define TEST_LED_PIN    PIN0

static void ToggleLedCallback(void)
{
    LED_SwitchState(TEST_LED_PORT, TEST_LED_PIN);
}

void ExtInt_Test_Runner(void)
{
    LED_Setup(TEST_LED_PORT, TEST_LED_PIN);
    LED_TurnOff(TEST_LED_PORT, TEST_LED_PIN);

    EXTINT_Setup();
    EXTINT_SetTriggerEdge(EDGE_RISING);
    EXTINT_RegisterCallback(ToggleLedCallback);
    EXTINT_Activate();

    while(1);
}