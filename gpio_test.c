#include "../SERVICES/types.h"
#include "gpio_test.h"
#include "../MCAL/GPIO/gpio_interface.h"
#include "../HAL/LED/led_interface.h"
#include "../HAL/SWITCH/switch_interface.h"
#include <built_in.h>
/* Test configuration */
#define LED_A_PORT      PORTC_ID
#define LED_A_PIN       PIN0
#define LED_B_PORT      PORTC_ID
#define LED_B_PIN       PIN1
#define BUTTON1_PORT    PORTB_ID
#define BUTTON1_PIN     PIN1
#define BUTTON2_PORT    PORTB_ID
#define BUTTON2_PIN     PIN2

static void DelayCycles(u16 ms)
{
    u16 i, j;
    for(i = 0; i < ms; i++)
        for(j = 0; j < 400; j++);  /* Approximate delay */
}



static void BlinkPattern(u16 on_time, u16 off_time, u8 repeats)
{
    u8 cnt;
    for(cnt = 0; cnt < repeats; cnt++)
    {
        LED_TurnOn(LED_A_PORT, LED_A_PIN);
        LED_TurnOn(LED_B_PORT, LED_B_PIN);
        Vdelay_ms(on_time);
        LED_TurnOff(LED_A_PORT, LED_A_PIN);
        LED_TurnOff(LED_B_PORT, LED_B_PIN);
        Vdelay_ms(off_time);
    }
}

void GPIO_Test_Runner(void)
{
    u8 sw1, sw2;

    LED_Setup(LED_A_PORT, LED_A_PIN);
    LED_Setup(LED_B_PORT, LED_B_PIN);
    Switch_Setup(BUTTON1_PORT, BUTTON1_PIN);
    Switch_Setup(BUTTON2_PORT, BUTTON2_PIN);

    while(1)
    {
        sw1 = Switch_ReadState(BUTTON1_PORT, BUTTON1_PIN);
        sw2 = Switch_ReadState(BUTTON2_PORT, BUTTON2_PIN);

        if(sw1 == SW_STATE_PRESSED)
        {
            BlinkPattern(200, 200, 10);
        }
        else if(sw2 == SW_STATE_PRESSED)
        {
            BlinkPattern(500, 500, 6);
        }
        else
        {
            LED_TurnOff(LED_A_PORT, LED_A_PIN);
            LED_TurnOff(LED_B_PORT, LED_B_PIN);
        }
    }
}