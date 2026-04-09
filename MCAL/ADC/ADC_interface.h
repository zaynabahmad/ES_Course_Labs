#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H
#include "ADC_private.h"
#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"

#define ADON_BIT 0
#define GO_DONE_BIT 2
#define ADIF_BIT 6
#define ADIE_BIT 6
#define PEIE_BIT 6
#define GIE_BIT 7
void ADC_voidInit(void);
u16 ADC_u16Read(u8 copy_u8Channel);
//Confgiure analog pins and voltage reference
void ADC_voidConfigure(u8 channel, u8 voltage_ref);
//Select ADC channel
void ADC_voidSelectChannel(u8 channel);
//Select Conversion clock
void ADC_voidSelectConversionClock(u8 clock);
//Turn ADC on/off
void ADC_voidPowerControl(u8 state);

//Start ADC conversion
void ADC_voidStartConversion(void);

void ADC_voidEnableInterrupt(void);
void ADC_voidDisableInterrupt(void);

//Get ADC conversion result
u16 ADC_u16GetConversionResult(void);


#endif // ADC_INTERFACE_H
