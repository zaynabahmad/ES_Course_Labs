
#include "DIO.h"

void DIO_Init(void)
{
    ADCON1 = 0x06;   // Make PORTA digital

    TRISA = 0xFF;    // Switches input
    TRISB = 0x00;    // LEDs output

    PORTB = 0x00;    // LEDs off
}