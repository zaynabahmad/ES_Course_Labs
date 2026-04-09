#include "../SERVICES/STD_TYPES.h"
#include "gpio_test.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../HAL/LED/LED_interface.h"
#include "../HAL/SWITCH/SWITCH_interface.h"

#define LED1_PORT  GPIO_PORTC
#define LED1_PIN   GPIO_PIN0
#define LED2_PORT  GPIO_PORTC
#define LED2_PIN   GPIO_PIN1
#define SW1_PORT   GPIO_PORTB
#define SW1_PIN    GPIO_PIN1
#define SW2_PORT   GPIO_PORTB
#define SW2_PIN    GPIO_PIN2

static u8          bs_i;
static u32         bs_outer;
static u32         bs_inner;
static volatile u32 bs_dummy;

static void blink_sequence(u16 on_ms, u16 off_ms, u8 count)
{
    bs_i = 0;
    while (bs_i < count)
    {
        LED_On(LED1_PORT, LED1_PIN);
        LED_On(LED2_PORT, LED2_PIN);
        for (bs_outer = 0; bs_outer < on_ms; bs_outer++)
            for (bs_inner = 0; bs_inner < 500; bs_inner++)
                bs_dummy++;
        LED_Off(LED1_PORT, LED1_PIN);
        LED_Off(LED2_PORT, LED2_PIN);
        for (bs_outer = 0; bs_outer < off_ms; bs_outer++)
            for (bs_inner = 0; bs_inner < 500; bs_inner++)
                bs_dummy++;
        bs_i++;
    }
}

void GPIO_TEST_Run(void)
{
    u8 sw1, sw2;
    LED_Init(LED1_PORT, LED1_PIN);
    LED_Init(LED2_PORT, LED2_PIN);
    SWITCH_Init(SW1_PORT, SW1_PIN);
    SWITCH_Init(SW2_PORT, SW2_PIN);
    while (1)
    {
        sw1 = SWITCH_GetState(SW1_PORT, SW1_PIN);
        sw2 = SWITCH_GetState(SW2_PORT, SW2_PIN);
        if (sw1 == SWITCH_PRESSED)
            blink_sequence(200, 200, 10);
        else if (sw2 == SWITCH_PRESSED)
            blink_sequence(500, 500, 6);
        else
        {
            LED_Off(LED1_PORT, LED1_PIN);
            LED_Off(LED2_PORT, LED2_PIN);
        }
    }
}