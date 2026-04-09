#include "adc_interface.h"
#include "adc_private.h"
#include "adc_config.h"
#include "../../SERVICES/bit_ops.h"

void ADC_Configure(void)
{
    /* RA0 as analog input */
    BIT_SET(TRISA_REG, 0);

    ADCON0_REG = 0x41;   /* ADC on, channel 0 */
    ADCON1_REG = 0x80;   /* Right justify, Vref=VDD */
}

u16 ADC_GetConversion(u8 channel)
{
    /* Clear channel bits, set new channel */
    ADCON0_REG &= 0xC7;
    ADCON0_REG |= (channel << 3);

    BIT_SET(ADCON0_REG, GO_DONE);
    while(BIT_READ(ADCON0_REG, GO_DONE));

    return ((u16)ADRESH_REG << 8) | ADRESL_REG;
}