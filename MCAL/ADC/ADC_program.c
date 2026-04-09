#include "ADC_interface.h"
#include "ADC_private.h"

void ADC_Init(void)
{
    // RA0 input
    TRISA_REG |= (1 << 0);

    // AN0 analog, Vref = Vdd
    ADCON1_REG = 0x80;

    // ADC ON + channel 0
    ADCON0_REG = 0x41;
}

unsigned int ADC_Read(unsigned char channel)
{
    // select channel
    ADCON0_REG &= 0b11000101;
    ADCON0_REG |= (channel << 3);

    // start conversion
    ADCON0_REG |= (1 << GO_DONE);

    // wait finish
    while(ADCON0_REG & (1 << GO_DONE));

    // read result
    return ((ADRESH_REG << 8) | ADRESL_REG);
}