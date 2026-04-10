#include "ADC_INTERFACE.h"

void ADC_init(){

SET_BIT(ADCON1, ADFM);

SET_BIT(ADCON1, PCFG3);
SET_BIT(ADCON1, PCFG2);
SET_BIT(ADCON1, PCFG1);
CLR_BIT(ADCON1, PCFG0);

SET_BIT(ADCON0, ADCS1);
CLR_BIT(ADCON0, ADCS0);
// No conversion running initially
CLR_BIT(ADCON0, GO_DONE);

// Enable ADC
SET_BIT(ADCON0, ADON);



}
void ADC_SelectChannel(u8 channel)
{
    CLR_BIT(ADCON0, CHS0);
    CLR_BIT(ADCON0, CHS1);
    CLR_BIT(ADCON0, CHS2);

    if(channel & 0x01) SET_BIT(ADCON0, CHS0);
    if(channel & 0x02) SET_BIT(ADCON0, CHS1);
    if(channel & 0x04) SET_BIT(ADCON0, CHS2);

    Delay_us(20);
}

u16 ADConversion(){
u16 adc_value;
Delay_us(20);
SET_BIT(ADCON0,GO_DONE);
while(GET_BIT(ADCON0,GO_DONE));
adc_value=ADRESH;
adc_value=adc_value<<8;
adc_value=adc_value+ADRESL;
return adc_value;
}