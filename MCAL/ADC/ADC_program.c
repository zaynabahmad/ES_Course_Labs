#include "ADC_interface.h"
#include "ADC_private.h"
#include "Services/bit_math.h"

void ADC_Init(void)
{
    SET_BIT(TRISA_REG, 0);    /* ra0 analog input */

    ADCON1_REG = 0x80;        /* all analog, right-justified, vref = vdd */
    ADCON0_REG = 0x41;        /* adc on, channel 0, fosc/8 */
}

unsigned int ADC_Read(unsigned char channel)
{
    ADCON0_REG = (ADCON0_REG & CHS_MASK) | (unsigned char)(channel << 3);

    SET_BIT(ADCON0_REG, GO_DONE_BIT);
    while (GET_BIT(ADCON0_REG, GO_DONE_BIT));

    return (unsigned int)((ADRESH_REG << 8) | ADRESL_REG);
}