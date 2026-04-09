#include "TIMER_interface.h"
#include "D:\Timer-week3/SERVICES/BIT_MATH.h"


volatile u8 count = 0;
volatile u8 sec = 0;

static void (*TIMER_1Sec_Callback)(void) = 0;
static void (*TIMER_2Sec_Callback)(void) = 0;

void TIMER0_Init(void)
{
    SET_BIT(INTCON, 5);      // Enable Timer0 Interrupt
    CLR_BIT(INTCON, 2);      // Clear Timer0 Interrupt Flag
    CLR_BIT(OPTION_REG, 5);  // Select Internal Clock
    SET_BIT(INTCON, 7);      // Enable Global Interrupts
    CLR_BIT(OPTION_REG, 3);  // Assign Prescaler to Timer0

    // Set Prescaler to 1:256
    SET_BIT(OPTION_REG, 0);
    SET_BIT(OPTION_REG, 1);
    SET_BIT(OPTION_REG, 2);

    TMR0 = 0;
    count = 0;
    sec = 0;
}

void TIMER0_SetCallback_1Sec(void (*ptr)(void)) { TIMER_1Sec_Callback = ptr; }
void TIMER0_SetCallback_2Sec(void (*ptr)(void)) { TIMER_2Sec_Callback = ptr; }

void interrupt()
{
    if(GET_BIT(INTCON, 2))
    {
        CLR_BIT(INTCON, 2);

        if(count < 30) {
            TMR0 = 0;
            count++;
        }
        else if(count == 30) {
            TMR0 = 125;
            count++;
        }
        else {
            count = 0;

            // 1 Second has passed
            if(TIMER_1Sec_Callback != 0) {
                TIMER_1Sec_Callback();
            }

            sec++;
            // 2 Seconds have passed
            if(sec >= 2) {
                if(TIMER_2Sec_Callback != 0) {
                    TIMER_2Sec_Callback();
                }
                sec = 0;
            }
        }
    }
}