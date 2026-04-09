#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"

#include "../../SERVICES/BIT_MATH.h"

void ADC_Init(void)
{
    /* Configure RA0 as input (AN0 example) */
    SET_BIT(TRISA, 0);

    /* Configure ADC */
    ADCON0 = 0x41;   // ADC ON + Channel 0
    ADCON1 = 0x80;   // Right justified + Vref = VDD
}

u16 ADC_Read(u8 channel)
{
    /* Select channel (clear first 3 bits) */
    ADCON0 &= 0xC7;
    ADCON0 |= (channel << 3);

    /* Start conversion */
    SET_BIT(ADCON0, GO);

    /* Wait until done */
    while (GET_BIT(ADCON0, GO));

    /* Return result */
    return ((ADRESH << 8) | ADRESL);
}