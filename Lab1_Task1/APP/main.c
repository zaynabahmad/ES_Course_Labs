/*
 * Application Layer
 * Lab Task 1: LED Sequences Controlled by Switches
 *
 * Hardware:
 *   LED1  -> RB0 (Port B, Pin 0) with 330 ohm resistor to GND
 *   LED2  -> RB1 (Port B, Pin 1) with 330 ohm resistor to GND
 *   SW1   -> RB2 (Port B, Pin 2) with pull-up to VDD (active LOW)
 *   SW2   -> RB3 (Port B, Pin 3) with pull-up to VDD (active LOW)
 *
 * Behavior:
 *   SW1 pressed -> Short/Fast blink (0.2s ON / 0.2s OFF)
 *   SW2 pressed -> Long/Slow blink (0.5s ON / 0.5s OFF)
 *   No switch   -> LEDs OFF
 */

#include "../HAL/LED/LED_interface.h"
#include "../HAL/SWITCH/SWITCH_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"

/* ---- Pin Definitions ---- */
#define LED1_PORT       GPIO_PORTB
#define LED1_PIN        GPIO_PIN0

#define LED2_PORT       GPIO_PORTB
#define LED2_PIN        GPIO_PIN1

#define SW1_PORT        GPIO_PORTB
#define SW1_PIN         GPIO_PIN2

#define SW2_PORT        GPIO_PORTB
#define SW2_PIN         GPIO_PIN3

/* ---- Delay Counts (approximate at 4 MHz, adjust as needed) ----
 * Each loop iteration ~5 instructions = ~5us at 4 MHz (1 MIPS)
 * 200ms -> 40000 iterations
 * 500ms -> 100000 iterations
 */
#define DELAY_200MS     40000UL
#define DELAY_500MS     100000UL

/* ---- Helper Functions ---- */
static void delay_count(unsigned long count)
{
    unsigned long i;
    for(i = 0; i < count; i++)
    {
        /* empty loop - burns clock cycles */
    }
}

static void blink_leds(unsigned long on_time, unsigned long off_time)
{
    /* Turn both LEDs ON */
    LED_On(LED1_PORT, LED1_PIN);
    LED_On(LED2_PORT, LED2_PIN);
    delay_count(on_time);

    /* Turn both LEDs OFF */
    LED_Off(LED1_PORT, LED1_PIN);
    LED_Off(LED2_PORT, LED2_PIN);
    delay_count(off_time);
}

/* ---- Main Application ---- */
void main(void)
{
    /* --- Initialization --- */
    LED_Init(LED1_PORT, LED1_PIN);
    LED_Init(LED2_PORT, LED2_PIN);

    SWITCH_Init(SW1_PORT, SW1_PIN);
    SWITCH_Init(SW2_PORT, SW2_PIN);

    /* --- Super Loop --- */
    while(1)
    {
        uint8 sw1_state = SWITCH_Read(SW1_PORT, SW1_PIN);
        uint8 sw2_state = SWITCH_Read(SW2_PORT, SW2_PIN);

        if(sw1_state == SWITCH_PRESSED)
        {
            /* Short sequence: fast blink 0.2s ON / 0.2s OFF */
            blink_leds(DELAY_200MS, DELAY_200MS);
        }
        else if(sw2_state == SWITCH_PRESSED)
        {
            /* Long sequence: slow blink 0.5s ON / 0.5s OFF */
            blink_leds(DELAY_500MS, DELAY_500MS);
        }
        else
        {
            /* No switch pressed: turn off both LEDs */
            LED_Off(LED1_PORT, LED1_PIN);
            LED_Off(LED2_PORT, LED2_PIN);
        }
    }
}
