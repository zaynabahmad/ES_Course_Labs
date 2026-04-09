#include "ADC_Interface.h"
#include "ADC_Private.h"
#include "ADC_Config.h"

#include "../../SERVICES/BIT_MATH.h"

void ADC_Init(void)
{
    /* Set Result Format */
#if (ADC_RESULT_FORMAT == 1)
    SET_BIT(ADCON1, ADFM);
#else
    CLR_BIT(ADCON1, ADFM);
#endif

    /* Set Clock Selection */
    ADCON1 = (ADCON1 & 0xBF) | (((ADC_CLOCK_SEL >> 2) & 0x01) << ADCS2);
    ADCON0 = (ADCON0 & 0x3F) | ((ADC_CLOCK_SEL & 0x03) << ADCS0);

    /* Set Port Configuration Control */
    ADCON1 = (ADCON1 & 0xF0) | (ADC_PORT_CONFIG & 0x0F);

    /* Turn on ADC Module */
    SET_BIT(ADCON0, ADON);
}

u16 ADC_ReadChannel(u8 Channel)
{
    u16 Local_Result = 0;

    /* Select Channel (Bits 5-3 in ADCON0) */
    ADCON0 = (ADCON0 & 0xC7) | ((Channel & 0x07) << CHS0);

    /* Start Conversion */
    SET_BIT(ADCON0, GO_DONE);

    /* Wait for Conversion to Complete */
    while (GET_BIT(ADCON0, GO_DONE) == 1);

    /* Read Result */
#if (ADC_RESULT_FORMAT == 1)
    /* Right Justified: Read lower 8 bits, then upper 2 bits */
    Local_Result = (u16)ADRESL;
    Local_Result |= ((u16)ADRESH << 8);
#else
    /* Left Justified: Read upper 8 bits, then lower 2 bits */
    Local_Result = ((u16)ADRESH << 2);
    Local_Result |= ((u16)ADRESL >> 6);
#endif

    return Local_Result;
}
