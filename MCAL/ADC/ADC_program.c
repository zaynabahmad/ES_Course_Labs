#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"
#include "../../SERVICES/BIT_MATH.h"
#include "../../SERVICES/STD_TYPES.h"


void ADC_Init(void)
{
    /* Step 1 – RA0 as input */
    SET_BIT(TRISA, 0);

    /* Step 2 – ADCON1: right-justified result, AN0 analog only     */
    ADCON1 = ADC_ADCON1_CONFIG;    /* 0x8E = 0b10001110             */

    /* Step 3 – ADCON0: Fosc/32 clock, channel 0, ADC ON           */
    ADCON0 = ADC_ADCON0_INIT;      /* 0x81 = 0b10000001             */
}


u16 ADC_Read(u8 channel)
{
    u16 Local_Delay;
    u16 Local_Result;

    /* Step 1 – select channel (CHS bits are [5:3] in ADCON0)       */
    ADCON0 &= 0xC7;                        /* clear CHS<2:0>         */
    ADCON0 |= (u8)((channel & 0x07) << 3); /* set new channel        */

    /* Step 2 – acquisition delay (~20 µs @ 8 MHz)                  */
    for (Local_Delay = 0; Local_Delay < 40u; Local_Delay++) { }

    /* Step 3 – start conversion                                     */
    SET_BIT(ADCON0, ADCON0_GO_DONE);

    /* Step 4 – wait for conversion to finish                        */
    while (GET_BIT(ADCON0, ADCON0_GO_DONE) == 1) { }

    /* Step 5 – right-justified: ADRESH holds bits [9:8], ADRESL [7:0] */
    Local_Result  = (u16)ADRESH << 8;
    Local_Result |= (u16)ADRESL;

    return Local_Result;
}
