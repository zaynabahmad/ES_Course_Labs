#include "ADC_Interface.h"
#include "ADC_Private.h"
#include "../../SERVICES/BIT_MATH.h"

void ADC_Init(void)
{
    /* Configure AN0 to AN3 as analog inputs, VREF = VDD/VSS */
    ADCON1 = 0x04;

    /* Right Justified result (for 10-bit reading) */
    SET_BIT(ADCON1, ADFM);

    /* Turn on ADC module */
    SET_BIT(ADCON0, ADON);
}

u16 ADC_Read(u8 Channel)
{
    /* Clear previous channel selection (Bits 3,4,5) */
    ADCON0 &= 0xC7;

    /* Set new channel */
    ADCON0 |= (Channel << 3);

    /* Delay for acquisition time (approx 20us) */
    for(volatile u8 i = 0; i < 20; i++);

    /* Start conversion */
    SET_BIT(ADCON0, GO_DONE);

    /* Wait for conversion to complete */
    while(GET_BIT(ADCON0, GO_DONE));

    /* Combine ADRESH (upper 2 bits) and ADRESL (lower 8 bits) */
    return ((u16)(ADRESH << 8) | ADRESL);
}
