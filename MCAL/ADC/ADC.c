#include "ADC_Interface.h"

void ADC_Init(void)
{
    /* 1. Configure analog/digital pins via ADCON1 PCFG bits */
    ADCON1 &= 0xF0;
    ADCON1 |= (ADC_PORT_CONFIG & 0x0F);

    /* 2. Result format */
    #if ADC_JUSTIFY == ADC_RIGHT_JUSTIFY
        SET_BIT(ADCON1, ADFM_BIT);
    #else
        CLR_BIT(ADCON1, ADFM_BIT);
    #endif

    /* 3. Clock source */
    ADCON0 &= 0x3F;
    ADCON0 |= ((ADC_CLK_SRC & 0x03) << 6);

    /* 4. Turn on ADC module */
    SET_BIT(ADCON0, ADON_BIT);
}

void ADC_StartConversion(u8 Channel)
{
    /* Select channel CHS2:CHS0 */
    ADCON0 &= 0xC7;
    ADCON0 |= ((Channel & 0x07) << 3);

    /* Short acquisition delay */
    {
        volatile u8 i;
        for(i = 0; i < 20; i++);
    }

    /* Start conversion */
    SET_BIT(ADCON0, GO_DONE_BIT);
}

u8 ADC_IsConversionDone(void)
{
    /* GO/DONE bit clears when conversion is complete */
    return (GET_BIT(ADCON0, GO_DONE_BIT) == 0) ? 1 : 0;
}

u16 ADC_GetResult(void)
{
    u16 result;
    #if ADC_JUSTIFY == ADC_RIGHT_JUSTIFY
        result = (u16)ADRESL;
        result |= ((u16)ADRESH << 8);
    #else
        result = ((u16)ADRESH << 2);
        result |= ((u16)ADRESL >> 6);
    #endif
    return result;
}

u16 ADC_Read(u8 Channel)
{
    ADC_StartConversion(Channel);
    while(!ADC_IsConversionDone());
    return ADC_GetResult();
}
