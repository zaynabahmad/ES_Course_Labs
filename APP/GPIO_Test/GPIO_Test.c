#include "GPIO_Test.h"

#include "../../MCAL/GPIO/GPIO_interface.h"
#include "../../HAL/LED/LED_interface.h"
#include "../../HAL/SWITCH/SWITCH_interface.h"

/* Define LED Pins */
#define LED1_PORT   GPIO_PORTD
#define LED1_PIN    GPIO_PIN0

#define LED2_PORT   GPIO_PORTD
#define LED2_PIN    GPIO_PIN1

/* Define Switch Pins */
#define SW1_PORT    GPIO_PORTD
#define SW1_PIN     GPIO_PIN2

#define SW2_PORT    GPIO_PORTD
#define SW2_PIN     GPIO_PIN3

/* Dummy explicit loop delay to avoid compiler-specific dependencies */
static void Delay_ms_custom(unsigned long ms)
{
    unsigned long i;
    /* Adjust this multiplier for a realistic hardware clock if testing live */
    for(i = 0; i < (ms * 150); i++)
    {
        /* Busy Wait */
    }
}

void GPIO_Test_Init(void)
{
    /* Initialize LEDs */
    LED_Init(LED1_PORT, LED1_PIN);
    LED_Init(LED2_PORT, LED2_PIN);

    /* Initialize Switches */
    SWITCH_Init(SW1_PORT, SW1_PIN);
    SWITCH_Init(SW2_PORT, SW2_PIN);
}

void GPIO_Test_App(void)
{
    u8 sw1_state = SWITCH_GetState(SW1_PORT, SW1_PIN);
    u8 sw2_state = SWITCH_GetState(SW2_PORT, SW2_PIN);

    /* Check Switch 1 State */
    if (sw1_state == GPIO_HIGH) 
    {
        /* Short sequence: 0.2s ON / 0.2s OFF */
        LED_On(LED1_PORT, LED1_PIN);
        LED_On(LED2_PORT, LED2_PIN);
        Delay_ms_custom(200);   /* 0.2 seconds */
        
        LED_Off(LED1_PORT, LED1_PIN);
        LED_Off(LED2_PORT, LED2_PIN);
        Delay_ms_custom(200);   /* 0.2 seconds */
    }
    /* Check Switch 2 State */
    else if (sw2_state == GPIO_HIGH)
    {
        /* Long sequence: 0.5s ON / 0.5s OFF */
        LED_On(LED1_PORT, LED1_PIN);
        LED_On(LED2_PORT, LED2_PIN);
        Delay_ms_custom(500);   /* 0.5 seconds */
        
        LED_Off(LED1_PORT, LED1_PIN);
        LED_Off(LED2_PORT, LED2_PIN);
        Delay_ms_custom(500);   /* 0.5 seconds */
    }
    /* If neither switch is pressed */
    else
    {
        LED_Off(LED1_PORT, LED1_PIN);
        LED_Off(LED2_PORT, LED2_PIN);
    }
}