#include "ADC_interface.h"

// ADC Registers (mikroC already defines them, no need for addresses)

void ADC_Init(void)
{
    // Configure AN0 as analog, rest digital, right justified
    ADCON1 = 0x80;
    // 1000 0000 ? Right justified + AN0 analog

    // ADC ON + Fosc/32 + select channel 0
    ADCON0 = 0x41;
    // 0100 0001 ? ADON=1, CH0=AN0, Fosc/32
}

unsigned int ADC_Read(unsigned char channel)
{
    // Select channel (AN0 ? AN7)
    ADCON0 &= 0xC5;              // clear channel bits
    ADCON0 |= (channel << 3);    // set new channel

    Delay_us(20); // Acquisition time

    GO_DONE_bit = 1;  // Start conversion

    while(GO_DONE_bit); // wait till finish

    return ((ADRESH << 8) + ADRESL); // 10-bit result
}