#include "ADC_Interface.h"

void ADC_Init(void)
{
    SET_BIT(ADCON1, ADFM);
    
    ADCON1 &= 0xF0;
    ADCON1 |= 0x00;
    
    ADCON0 = 0x41;
    
    SET_BIT(ADCON0, ADON);
}

void ADC_StartConversion(u8 Channel)
{
    ADCON0 &= 0xC5;
    ADCON0 |= (Channel << 3);
    
    SET_BIT(ADCON0, GO_DONE);
}

u8 ADC_IsConversionDone(void)
{
    return !GET_BIT(ADCON0, GO_DONE);
}

u16 ADC_GetResult(void)
{
    u16 result = 0;
    
    result = ADRESL;
    result |= ((u16)ADRESH << 8);
    
    return result;
}

u16 ADC_Read(u8 Channel)
{
    ADC_StartConversion(Channel);
    
    while(!ADC_IsConversionDone());
    
    return ADC_GetResult();
}
