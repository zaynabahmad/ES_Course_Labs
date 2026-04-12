#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"
#include "ADC_Config.h"
#include "ADC_Private.h"

/* ================= Channel Macros ================= */

#define ADC_CHANNEL_0    0
#define ADC_CHANNEL_1    1
#define ADC_CHANNEL_2    2
#define ADC_CHANNEL_3    3
#define ADC_CHANNEL_4    4
#define ADC_CHANNEL_5    5
#define ADC_CHANNEL_6    6
#define ADC_CHANNEL_7    7

/* ================= Result Format Macros ================= */

#define ADC_RIGHT_JUSTIFIED    1
#define ADC_LEFT_JUSTIFIED     0

/* ================= Clock Source Macros ================= */

#define ADC_CLOCK_FOSC_2     0x00
#define ADC_CLOCK_FOSC_8     0x01
#define ADC_CLOCK_FOSC_32    0x02
#define ADC_CLOCK_FRC        0x03

/* ================= Analog Pin Config Macros ================= */

#define ADC_ANALOG_PINS_ALL   0x00    /* All 8 channels analog */
#define ADC_ANALOG_PINS_4     0x05    /* AN0-AN3 analog, rest digital */

/* ================= Function Prototypes ================= */

void ADC_Init(void);
u16  ADC_Read(u8 Channel);

#endif
