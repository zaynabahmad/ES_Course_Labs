#include "../MCAL/TIMER0/TIMER0_interface.h"
#include "../SERVICES/STD_TYPES.h"
#include "../SERVICES/BIT_MATH.h"

/* PORT registers for LED */

#define TRISB  (*((volatile u8*)0x86))
#define PORTB  (*((volatile u8*)0x06))

u8 counter = 0;

/* Timer callback */

void Timer_Task(void)
{
    counter++;

    if(counter >= 31)     // ˜ 1 second
    {
        PORTB ^= (1<<0);  // toggle RB0 LED
        counter = 0;
    }
}

void main()
{

    /* RB0 output */

    CLR_BIT(TRISB , 0);

    /* Timer0 init */

    TIMER0_Init(TIMER0_MODE_NORMAL , 1 , TIMER0_PRESCALER_256);

    TIMER0_SetCallback(Timer_Task);

    /* enable interrupts */

    INTCON = 0xA0;
    TIMER0_Start();

    while(1)
    {

    }
}