#include "ADC_Interface.h"
#include "ADC_Private.h"
#include "ADC_Config.h"
#include "../../SERVICES/BIT_MATH.h"

/* Registers (PIC16F877A) */
#define ADCON0   *((volatile u8*)0x1F)
#define ADCON1   *((volatile u8*)0x9F)
#define ADRESH   *((volatile u8*)0x1E)
#define ADRESL   *((volatile u8*)0x9E)

void ADC_Init(void)
{
    /* Select Fosc/32 */
    ADCON0 = 0b10000001;

    /* Configure all pins as analog */
    ADCON1 = 0x80;

#if ADC_RESULT_FORMAT == 1
    SET_BIT(ADCON1 , 7); // Right justified
#else
    CLR_BIT(ADCON1 , 7); // Left justified
#endif
}

/* ============================= */

u16 ADC_Read(u8 channel)
{
    u16 result = 0;

    /* Select channel */
    ADCON0 &= 0b11000101;
    ADCON0 |= (channel << 3);

    /* Start conversion */
    SET_BIT(ADCON0 , GO_DONE);

    /* Wait until conversion complete */
    while(GET_BIT(ADCON0 , GO_DONE));

    /* Read result */
    result = ((u16)ADRESH << 8) | ADRESL;

    return result;
}