/* ============================================================
 * ADC_program.c  -  ADC driver implementation
 * Target : PIC16F877A  |  Compiler : mikroC Pro for PIC
 * ============================================================ */

#include "ADC_interface.h"
#include "ADC_private.h"
#include "../../SERVICES/bit_math.h"

/* Channel select bit mask in ADCON0 [CHS2:CHS1:CHS0] @ bits 5:3 */
#define CHANNEL_MASK    0b11000101u

/* ------------------------------------------------------------ */
void ADC_Init(void)
{
    SET_BIT(TRISA_REG, 0);      /* RA0 = analog input          */
    ADCON1_REG = 0x80;          /* AN0 analog, Vref = Vdd      */
    ADCON0_REG = 0x41;          /* ADC ON, channel 0, Fosc/16  */
}

/* ------------------------------------------------------------ */
unsigned int ADC_Read(unsigned char channel)
{
    /* Select channel */
    ADCON0_REG &= CHANNEL_MASK;
    ADCON0_REG |= (channel << 3);

    /* Start conversion and wait */
    SET_BIT(ADCON0_REG, GO_DONE);
    while (GET_BIT(ADCON0_REG, GO_DONE));

    /* Return 10-bit result */
    return (unsigned int)((ADRESH_REG << 8) | ADRESL_REG);
}
