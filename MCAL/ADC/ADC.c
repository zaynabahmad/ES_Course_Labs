#include "ADC_Interface.h"
#include "ADC_Private.h"
#include "../../SERVICES/BIT_MATH.h"

void ADC_Init(void) {

    ADCON1 = 0x80;


    SET_BIT(ADCON0, ADON);
}

u16 ADC_ReadChannel(u8 Channel) {
    u16 result = 0;


    ADCON0 &= 0xC7;
    ADCON0 |= (Channel << 3);




    SET_BIT(ADCON0, GO_DONE);


    while (GET_BIT(ADCON0, GO_DONE) == 1);


    result = ((u16)ADRESH << 8) | ADRESL;

    return result;
}