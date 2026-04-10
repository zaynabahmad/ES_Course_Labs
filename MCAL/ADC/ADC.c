#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"

#include "ADC_private.h"
#include "ADC_config.h"
#include "ADC_interface.h"

#define ADC_TIMEOUT_MAX  50000 

void ADC_voidInit(void)
{
    ADCON1 = ADC_PORT_CONFIG;      /* Set pins as analog/digital */
    SET_BIT(ADCON1, ADCON1_ADFM);  /* Right-justify 10-bit result */
    SET_BIT(ADCON0, ADCON0_ADON);  /* Enable ADC module */
}

u8 ADC_u8ReadChannel(u8 Copy_u8Channel, u16 *Add_pu16Result)
{
    u32 Local_u32TimeoutCounter = 0;
    
    if ((Copy_u8Channel > ADC_CHANNEL_7) || (Add_pu16Result == NULL_PTR))
    {
        return ADC_ERR_INVALID_CH;
    }

    ADCON0 &= 0b11000111;              /* Clear old channel */
    ADCON0 |= (Copy_u8Channel << 3);   /* Set new channel */
    SET_BIT(ADCON0, ADCON0_GO_DONE);   /* Start conversion */

    /* Wait for conversion to finish or timeout */
    while ((GET_BIT(ADCON0, ADCON0_GO_DONE) == 1) && (Local_u32TimeoutCounter < ADC_TIMEOUT_MAX))
    {
        Local_u32TimeoutCounter++;
    }

    if (Local_u32TimeoutCounter >= ADC_TIMEOUT_MAX)
    {
        return ADC_ERR_TIMEOUT;
    }

    *Add_pu16Result = ADRESL | (ADRESH << 8); /* Combine High and Low registers */

    return ADC_OK;
}

u16 ADC_u16ReadChannel(u8 Copy_u8Channel)
{
    u16 Local_u16Result = 0;
    ADC_u8ReadChannel(Copy_u8Channel, &Local_u16Result);
    return Local_u16Result;
}

u8 ADC_u8ReadPercent(u8 Copy_u8Channel)
{
    u16 Local_u16RawValue = 0;
    
    if (ADC_u8ReadChannel(Copy_u8Channel, &Local_u16RawValue) == ADC_OK)
    {
        return (u8)(((u32)Local_u16RawValue * 100) / 1023); /* Scale 0-1023 to 0-100% */
    }
    
    return 0;
}

void ADC_voidDisable(void)
{
    CLR_BIT(ADCON0, ADCON0_ADON);
}

void ADC_voidEnable(void)
{
    SET_BIT(ADCON0, ADCON0_ADON);
}

void ADC_voidSetAllDigital(void)
{
    ADCON1 = 0x06;
}