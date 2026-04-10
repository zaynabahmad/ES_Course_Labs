#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

/* ADC Channels (PIC16F877A) */
#define ADC_CHANNEL_0       0
#define ADC_CHANNEL_1       1
#define ADC_CHANNEL_2       2
#define ADC_CHANNEL_3       3
#define ADC_CHANNEL_4       4
#define ADC_CHANNEL_5       5
#define ADC_CHANNEL_6       6
#define ADC_CHANNEL_7       7
 
/* Status Codes */
#define ADC_OK              0
#define ADC_ERR_TIMEOUT     1
#define ADC_ERR_INVALID_CH  2
 
/* Functions */
void ADC_voidInit(void);
u8   ADC_u8ReadChannel(u8 Copy_u8Channel, u16 *Add_pu16Result);
u16  ADC_u16ReadChannel(u8 Copy_u8Channel);
u8   ADC_u8ReadPercent(u8 Copy_u8Channel);
void ADC_voidDisable(void);
void ADC_voidEnable(void);
void ADC_voidSetAllDigital(void);  // configures all pins as digital (ADCON1 = 0x06)

#endif