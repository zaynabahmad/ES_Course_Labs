#include "ADC_interface.h"
#include "ADC_private.h"
#include "../SERVICES/BIT_MATH.h"

void ADC_Init(void) {
    // ADCON1: ADFM=1 (Right Justified), ADCS2=0, PCFG=0000 (All Analog)
    ADCON1 = 0x80;
    // ADCON0: Clock = Fosc/8, ADON=1
    ADCON0 = 0x41;
}

u16 ADC_Read(u8 Channel) {
    // Clear channel selection bits (3, 4, 5) and set new channel
    ADCON0 &= 0xC7;
    ADCON0 |= (Channel << 3);

    // Acquisition time delay
    Delay_us(30);

    // Start conversion
    SET_BIT(ADCON0, GO_DONE_BIT);

    // Wait for completion (GO/DONE bit becomes 0)
    while(GET_BIT(ADCON0, GO_DONE_BIT));

    // Combine ADRESH and ADRESL for 10-bit result
    return ((u16)ADRESH << 8) | ADRESL;
}