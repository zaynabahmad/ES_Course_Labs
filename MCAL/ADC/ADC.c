#include "ADC_Interface.h"

void ADC_Init(void)
{
    /* All pins analog, Vref = VDD */
    ADCON1 = 0x00;

    /* Right justify result */
    #if ADC_RIGHT_JUSTIFIED == 1
        SET_BIT(ADCON1, ADFM);
    #else
        CLR_BIT(ADCON1, ADFM);
    #endif

    /* Set ADC clock */
    ADCON0 = (ADCON0 & 0x3F) | ((ADC_CLOCK_SELECT & 0x03) << 6);

    /* Turn on ADC */
    SET_BIT(ADCON0, ADON);
}

u16 ADC_Read(u8 Channel)
{
    u16 Result = 0;

    /* Select channel */
    ADCON0 = (ADCON0 & 0xC7) | ((Channel & 0x07) << 3);

    /* Acquisition delay (~20us at 4MHz) */
    __delay_us(20);

    /* Start conversion */
    SET_BIT(ADCON0, GO_DONE);

    /* Wait for conversion to complete */
    while (GET_BIT(ADCON0, GO_DONE));

    /* Read 10-bit result */
    Result = (u16)ADRESH << 8;
    Result |= ADRESL;

    return Result;
}
