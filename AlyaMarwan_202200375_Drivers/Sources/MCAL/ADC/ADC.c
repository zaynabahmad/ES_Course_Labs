#include "adc.h"
#include "bit_math.h"

void ADC_Init(void)
{
    /* Set RA0 as input */
    SET_BIT(TRISA, 0);

    /* ADCON1:
       ADFM  = 1 ? right justified (bit 7)
       PCFG  = 1110 ? AN0 only analog
       0x8E  = 10001110                    */
    ADCON1 = 0x8E;

    /* ADCON0:
       ADCS1:ADCS0 = 10 ? Fosc/32
       CHS   = 000  ? channel 0
       ADON  = 1    ? ADC on
       0x81  = 10000001                    */
    ADCON0 = 0x81;

    /* Acquisition delay */
    Delay_us(50);
}

uint16 ADC_Read(uint8 channel)
{
    uint16 result = 0;

    /* Select channel — bits 5:3 of ADCON0 */
    ADCON0 = (ADCON0 & 0xC7) | ((channel & 0x07) << 3);

    /* Acquisition delay */
    Delay_us(50);

    /* Start conversion */
    SET_BIT(ADCON0, 2);

    /* Wait until conversion complete */
    while(GET_BIT(ADCON0, 2));

    /* Read 10-bit result */
    result = (uint16)(((uint16)(ADRESH & 0x03) << 8) | ADRESL);

    return result;
}