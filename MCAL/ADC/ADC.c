#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"
#include "ADC_interface.h"
#include "ADC_private.h"

void ADC_voidInit(void)
{

    ADCON1 = 0x8E;

    /* ADCON0: Clock Fosc/32, ADC On */
    /* Bits 7-6: 10 (Fosc/32) */
    SET_BIT(ADCON0, 7);
    CLR_BIT(ADCON0, 6);
    SET_BIT(ADCON0, ADON);
}

unsigned int ADC_u16GetChannelReading(unsigned char Copy_u8Channel)
{
       volatile u16  i;


    ADCON0 &= 0xC7;
    ADCON0 |= (Copy_u8Channel << 3);


    for(i = 0; i < 1000; i++);

    SET_BIT(ADCON0, 2);

    while(GET_BIT(ADCON0, 2));

    return (unsigned int)((ADRESH << 8) | ADRESL);
}