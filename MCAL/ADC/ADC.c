#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"
#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"

void ADC_voidInit(void)
{

    ADCON1_REG = 0x80;

    CLR_BIT(ADCON1_REG, ADCS2);
    SET_BIT(ADCON0_REG, ADCS1);
    CLR_BIT(ADCON0_REG, ADCS0);


    SET_BIT(ADCON0_REG, ADON);
}

u16 ADC_u16GetChannelReading(u8 Copy_u8Channel)
{
    u16 Local_u16Result = 0;


    ADCON0_REG &= 0xC7;
    ADCON0_REG |= (Copy_u8Channel << 3);


    Delay_us(20);


    SET_BIT(ADCON0_REG, GO_DONE);


    while (GET_BIT(ADCON0_REG, GO_DONE) == 1);

    Local_u16Result = (u16)((ADRESH_REG << 8) | ADRESL_REG);

    return Local_u16Result;
}