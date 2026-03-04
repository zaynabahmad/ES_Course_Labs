//#include "SWITCH.h"

//void SWITCH_Init(void)
//{
//    TRISB.B0 = 1;   // RB0 input
//}



#include "SWITCH.h"

void SWITCH_Init(void)
{
    TRISB.B0 = 1;   // SW1 input (RB0)
    TRISB.B1 = 1;   // SW2 input (RB1)
    OPTION_REG.B7 = 0;   // Enable PORTB pull-ups
}

unsigned char SWITCH1_Read(void)
{
    return PORTB.B0;
}

unsigned char SWITCH2_Read(void)
{
    return PORTB.B1;
}

