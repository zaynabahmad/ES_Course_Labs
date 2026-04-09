#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"

#include "ADC_Interface.h"
#include "ADC_Private.h"
#include "ADC_Config.h"

void ADC_Init(void)
{
    /* Select ADC clock (ADCS1:ADCS0 bits) */
    ADCON0 &= 0xC7;
    ADCON0 |= (ADC_CLOCK_SELECT << 6);

    /* Configure result format */
    if(ADC_RESULT_FORMAT == 1)
    {
        SET_BIT(ADCON1, 7);  // Right justified
    }
    else
    {
        CLR_BIT(ADCON1, 7);  // Left justified
    }

    /* Configure analog pins (AN0 as analog, rest digital) */
    ADCON1 = 0x80;

    /* Enable ADC */
    SET_BIT(ADCON0, ADON);
}

u16 ADC_Read(u8 Channel)
{
    u16 result;
    unsigned long i;   // ? moved here

    /* Select channel */
    ADCON0 &= 0xC7;
    ADCON0 |= (Channel << 3);

    /* Acquisition delay */
    for(i = 0; i < 1000; i++);

    /* Start conversion */
    SET_BIT(ADCON0, GO_DONE);

    /* Wait for conversion */
    while(GET_BIT(ADCON0, GO_DONE));

    /* Read result */
    result = ((u16)ADRESH << 8) | ADRESL;

    return result;
}