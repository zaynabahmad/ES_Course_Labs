#include "../SERVICES/STD_TYPES.h"
#include "../SERVICES/BIT_MATH.h"

#include "../MCAL/ADC/ADC_interface.h"
#include "../MCAL/ADC/ADC_private.h"
#include "../MCAL/ADC/ADC_config.h"




void ADC_voidInit(void)
{
    // Reference = AVCC
    SET_BIT(ADMUX,6);

    // Enable ADC
    SET_BIT(ADCSRA,ADEN);

    // Prescaler->128
    SET_BIT(ADCSRA,0);
    SET_BIT(ADCSRA,1);
    SET_BIT(ADCSRA,2);
}

u16 ADC_u16ReadChannel(u8 channel)
{
    ADMUX &= 0b11100000;
    ADMUX |= channel;

    //  conversion
    SET_BIT(ADCSRA, ADSC);

    // Wait til complete
    while(GET_BIT(ADCSRA,ADIF)==0);

    // Clear flag
    SET_BIT(ADCSRA,ADIF);


    u16 result=ADCL;
    result|=(ADCH<<8);

    return result;
}