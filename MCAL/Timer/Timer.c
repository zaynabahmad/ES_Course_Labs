#include "Timer_Interface.h"




TmrPtr_t TMR0_Callbacks[3];
volatile unsigned int cnt = 0, cnt1 = 0, cnt2 = 0;

void Timer_Init(){
    OPTION_REG = 0b00000111;
    TMR0 = 0;
    INTCON = 0b10100000;

}

void Timer_SetCallback(unsigned char index, TmrPtr_t ptr) {
    if (ptr!=0) {
        TMR0_Callbacks[index] = ptr;
    }
}