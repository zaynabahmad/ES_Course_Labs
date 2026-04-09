#include "ADC_Interface.h"
#include "ADC_Private.h"
#include "ADC_Config.h"

#include "../../SERVICES/BIT_MATH.h"

void ADC_Init(void)
{
    ADCON1 = ADCON1_CONFIG_VALUE;
    ADCON0 = (u8)(ADC_CLOCK_SELECT & (u8)0xC0);
    SET_BIT(ADCON0, ADON_BIT);
}

u16 ADC_ReadChannel(u8 Channel)
{
    u16 Local_Result;

    Channel &= 0x07;
    ADCON0 = (u8)((ADCON0 & (u8)0xC7) | (u8)(Channel << CHS0_BIT));

    SET_BIT(ADCON0, GO_DONE_BIT);
    while (GET_BIT(ADCON0, GO_DONE_BIT) != 0U)
    {
    }

    Local_Result = (u16)(((u16)ADRESH << 8) | ADRESL);
    return Local_Result;
}
