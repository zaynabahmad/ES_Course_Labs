#include "ADC_Interface.h"
#include "ADC_Private.h"
#include "ADC_Config.h"
#include "../../SERVICES/BIT_MATH.h"

void ADC_Init(void)
{
    /* Select Fosc/8 as conversion clock */
    SET_BIT(ADCON0, ADCS0);
    CLR_BIT(ADCON0, ADCS1);
    CLR_BIT(ADCON1, ADCS2);
    
    /* Config result format */
#if ADC_JUSTIFICATION == ADC_RIGHT_JUSTIFIED
    SET_BIT(ADCON1, ADFM);
#else
    CLR_BIT(ADCON1, ADFM);
#endif

    /* Configure analog pins, voltage reference and digital I/O */
    /* All analog, Vref = VDD and VSS */
    CLR_BIT(ADCON1, PCFG0);
    CLR_BIT(ADCON1, PCFG1);
    CLR_BIT(ADCON1, PCFG2);
    CLR_BIT(ADCON1, PCFG3);

    /* Turn on ADC module */
    SET_BIT(ADCON0, ADON);
}

u16 ADC_ReadChannel(u8 Channel)
{
    volatile int i;

    /* Clear channel selection bits */
    ADCON0 &= 0xC7; // 11000111
    
    /* Set new channel */
    ADCON0 |= (Channel << 3);
    
    /* Wait for acquisition time */
    for(i = 0; i < 100; i++);
    
    /* Start conversion */
    SET_BIT(ADCON0, GO_DONE);
    
    /* Wait for conversion to complete */
    while(GET_BIT(ADCON0, GO_DONE) == 1);
    
    /* Return the 10-bit result */
#if ADC_JUSTIFICATION == ADC_RIGHT_JUSTIFIED
    return ((u16)((ADRESH << 8) + ADRESL));
#else
    return ((u16)(ADRESH << 2) | (ADRESL >> 6));
#endif
}
