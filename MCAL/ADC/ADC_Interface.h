#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

#include "../../SERVICES/BIT_MATH.h"
#include "../../SERVICES/STD_TYPES.h"
#include "../GPIO/GPIO_interface.h"
#include "ADC_Config.h"
#include "ADC_Private.h"

/* Interrupt Configuration */

#define GIE_BIT 7
#define INTE_BIT 4
#define INTF_BIT 1

// ADCON0
#define ADCS1_BIT 7
#define ADCS0_BIT 6

#define CHS2_BIT 5
#define CHS1_BIT 4
#define CHS0_BIT 3

#define GO_DONE_BIT 2
#define ADON_BIT 0

// ADCON1
#define ADFM_BIT 7

#define PCFG3_BIT 3
#define PCFG2_BIT 2
#define PCFG1_BIT 1
#define PCFG0_BIT 0

// ResultFormat
#define LeftJustified 1
#define RightJustified 0

void ADC_Init(u8 Channel);
void ADC_Enable(void);
void ADC_Disable(void);

void ADC_SetClock(u8 Fosc);

void ADC_SetChannel(u8 Channel);
void ADC_SetPortConfig(u8 PCFG);
void ADC_SetADFM(u8 ResultFormat);

u16 ADC_Read(void);

void ADC_SetCallback(void (*Callback)(void));
void ADC_ISR(void);

#endif
