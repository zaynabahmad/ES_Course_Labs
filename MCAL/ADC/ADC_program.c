#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"

#include "../../SERVICES/BIT_MATH.h"

void ADC_Init(void)
{
    /* Configure pins as analog */
    ADCON1 = 0x80; // Right justified, Vref = VDD

    /* Enable ADC */
    SET_BIT(ADCON0, 0);
}

u16 ADC_Read(u8 channel)
{
    u16 result;

    /* Select channel */
    ADCON0 &= 0b11000101;
    ADCON0 |= (channel << 3);

    /* Start conversion */
    SET_BIT(ADCON0, 2);

    /* Wait for completion */
    while (GET_BIT(ADCON0, 2))
        ;

    /* Read result */
    result = ((u16)ADRESH << 8) | ADRESL;

    return result;
}