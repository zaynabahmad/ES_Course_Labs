#include <stdint.h>

#define LED_TRIS    TRISC0_bit
#define LED_PIN     PORTC0_bit

#define INT0_TRIS   TRISB0_bit

volatile uint8_t g_int0_event = 0;

void interrupt(void)
{
    if (INTCON.INTF)
    {
        INTCON.INTF = 0;
        LED_PIN = !LED_PIN;
        g_int0_event = 1;
    }
}

static void INT0_Init(void)
{
    INT0_TRIS = 1;

    OPTION_REG &= 0x7F;
    PORTB0_bit = 1;

    OPTION_REG.INTEDG = 0;

    INTCON.INTF = 0;
    INTCON.INTE = 1;
    INTCON.GIE  = 1;
}

void main(void)
{
    LED_TRIS = 0;
    LED_PIN  = 0;

    INT0_Init();

    while(1)
    {
        if (g_int0_event)
        {
            Delay_ms(150);
            g_int0_event = 0;
            INTCON.INTF = 0;
        }
    }
}
