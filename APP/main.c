#include "../SERVICES/STD_TYPES.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../HAL/LED/LED_interface.h"
#include "../HAL/SWITCH/SWITCH_Interface.h"

/* ── Pin assignment ─────────────────────────── */
#define LED1_PORT GPIO_PORTA
#define LED1_PIN GPIO_PIN0

#define LED2_PORT GPIO_PORTA
#define LED2_PIN GPIO_PIN1

#define SW1_PORT GPIO_PORTB /* short-sequence button */
#define SW1_PIN GPIO_PIN1

#define SW2_PORT GPIO_PORTB /* long-sequence button  */
#define SW2_PIN GPIO_PIN2

/* ── Timing ─────────────────────────────────── */
#define SHORT_ON_MS 200
#define SHORT_OFF_MS 200
#define LONG_ON_MS 500
#define LONG_OFF_MS 500

/* ── Sequences ──────────────────────────────── */
static void Short_Sequence(void)
{
    LED_On(LED1_PORT, LED1_PIN);
    LED_On(LED2_PORT, LED2_PIN);
    Delay_ms(SHORT_ON_MS);
    LED_Off(LED1_PORT, LED1_PIN);
    LED_Off(LED2_PORT, LED2_PIN);
    Delay_ms(SHORT_OFF_MS);
}

static void Long_Sequence(void)
{
    LED_On(LED1_PORT, LED1_PIN);
    LED_On(LED2_PORT, LED2_PIN);
    Delay_ms(LONG_ON_MS);
    LED_Off(LED1_PORT, LED1_PIN);
    LED_Off(LED2_PORT, LED2_PIN);
    Delay_ms(LONG_OFF_MS);
}

static void LEDs_Off(void)
{
    LED_Off(LED1_PORT, LED1_PIN);
    LED_Off(LED2_PORT, LED2_PIN);
}

/* ── Main ───────────────────────────────────── */
int main(void)
{
    GPIO_Init();

    LED_Init(LED1_PORT, LED1_PIN);
    LED_Init(LED2_PORT, LED2_PIN);

    SWITCH_Init(SW1_PORT, SW1_PIN);
    SWITCH_Init(SW2_PORT, SW2_PIN);

    while (1)
    {
        u8 sw1 = SWITCH_Read(SW1_PORT, SW1_PIN);
        u8 sw2 = SWITCH_Read(SW2_PORT, SW2_PIN);

        if (sw1 == SWITCH_PRESSED)
            Short_Sequence();
        else if (sw2 == SWITCH_PRESSED)
            Long_Sequence();
        else
            LEDs_Off();
    }

    return 0;
}