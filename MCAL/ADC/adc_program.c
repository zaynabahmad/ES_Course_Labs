#include "D:/ES-Project-Lab/SERVICES/std_types.h"
#include "D:/ES-Project-Lab/SERVICES/bit_math.h"
#include "adc_prv.h"
#include "adc_interface.h"

void ADC_Init(void)
{
    /* Right justified result */
    SET_BIT(ADCON1_REG, ADFM_BIT);

    /* ADC clock = Fosc/32 style setup */
    CLR_BIT(ADCON1_REG, ADCS2_BIT);
    SET_BIT(ADCON0_REG, ADCS1_BIT);
    CLR_BIT(ADCON0_REG, ADCS0_BIT);

    /* Turn ADC ON */
    SET_BIT(ADCON0_REG, ADON_BIT);
}

u16 ADC_Read(u8 channel)
{
    u8 local_u8Counter = 0;
    u16 result = 0;

    /* Clear channel select bits */
    CLR_BIT(ADCON0_REG, CHS0_BIT);
    CLR_BIT(ADCON0_REG, CHS1_BIT);
    CLR_BIT(ADCON0_REG, CHS2_BIT);

    /* Set selected channel */
    if(channel & 0x01) SET_BIT(ADCON0_REG, CHS0_BIT);
    if(channel & 0x02) SET_BIT(ADCON0_REG, CHS1_BIT);
    if(channel & 0x04) SET_BIT(ADCON0_REG, CHS2_BIT);

    /* Small acquisition delay */
    for(local_u8Counter = 0; local_u8Counter < 20; local_u8Counter++)
    {
        ;
    }

    /* Start conversion */
    SET_BIT(ADCON0_REG, GO_DONE_BIT);

    /* Wait until conversion finishes */
    while(GET_BIT(ADCON0_REG, GO_DONE_BIT) == 1)
    {
        ;
    }

    /* Read result */
    result = ((u16)ADRESH_REG << 8) | ADRESL_REG;

    return result;
}