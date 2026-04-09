/*
 * gpio_test.c
 * APP Layer - GPIO Driver Test
 *
 * Test Description:
 *   - PORTB pins 0-3 as outputs (LEDs)
 *   - PORTB pin 4 as input (button)
 *   - LED chaser pattern
 *   - Button controls direction
 */

#include "gpio_test.h"
#include "../MCAL/GPIO/gpio.h"
#include "../MCAL/TIMER0/timer0.h"

/* LED pins on PORTB */
#define LED_PORT    GPIO_PORTB
#define LED_PIN0    GPIO_PIN0
#define LED_PIN1    GPIO_PIN1
#define LED_PIN2    GPIO_PIN2
#define LED_PIN3    GPIO_PIN3

/* Button pin */
#define BTN_PORT    GPIO_PORTB
#define BTN_PIN     GPIO_PIN4

void GPIO_Test_Init(void)
{
    /* Configure LED pins as output */
    GPIO_SetPinDirection(LED_PORT, LED_PIN0, GPIO_OUTPUT);
    GPIO_SetPinDirection(LED_PORT, LED_PIN1, GPIO_OUTPUT);
    GPIO_SetPinDirection(LED_PORT, LED_PIN2, GPIO_OUTPUT);
    GPIO_SetPinDirection(LED_PORT, LED_PIN3, GPIO_OUTPUT);

    /* Configure button as input */
    GPIO_SetPinDirection(BTN_PORT, BTN_PIN, GPIO_INPUT);

    /* All LEDs OFF initially */
    GPIO_WritePin(LED_PORT, LED_PIN0, GPIO_LOW);
    GPIO_WritePin(LED_PORT, LED_PIN1, GPIO_LOW);
    GPIO_WritePin(LED_PORT, LED_PIN2, GPIO_LOW);
    GPIO_WritePin(LED_PORT, LED_PIN3, GPIO_LOW);
}

void GPIO_Test_LEDChaser(void)
{
    u8 i;
    GPIO_Pin_t pins[4] = {LED_PIN0, LED_PIN1, LED_PIN2, LED_PIN3};

    /* Forward sweep */
    for(i = 0; i < 4; i++)
    {
        GPIO_WritePin(LED_PORT, pins[i], GPIO_HIGH);
        TIMER0_DelayMs(200);
        GPIO_WritePin(LED_PORT, pins[i], GPIO_LOW);
    }
}

void GPIO_Test_ButtonRead(void)
{
    /* Turn on all LEDs when button pressed, off when released */
    if(GPIO_ReadPin(BTN_PORT, BTN_PIN) == GPIO_LOW)   /* Active low button */
    {
        GPIO_WritePort(LED_PORT, 0x0F);    /* Turn on lower 4 bits */
    }
    else
    {
        GPIO_WritePort(LED_PORT, 0x00);    /* Turn off all */
    }
}

void GPIO_Test_ToggleAll(void)
{
    GPIO_TogglePin(LED_PORT, LED_PIN0);
    GPIO_TogglePin(LED_PORT, LED_PIN1);
    GPIO_TogglePin(LED_PORT, LED_PIN2);
    GPIO_TogglePin(LED_PORT, LED_PIN3);
    TIMER0_DelayMs(500);
}

void GPIO_Test_Run(void)
{
    GPIO_Test_Init();

    /* Run chaser 3 times */
    u8 rep;
    for(rep = 0; rep < 3; rep++)
    {
        GPIO_Test_LEDChaser();
    }

    /* Then blink all 5 times */
    for(rep = 0; rep < 5; rep++)
    {
        GPIO_Test_ToggleAll();
    }

    /* Read button in infinite loop */
    while(1)
    {
        GPIO_Test_ButtonRead();
    }
}
