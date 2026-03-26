#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

/* ADC Channels */
#define ADC_CHANNEL_AN0   0
#define ADC_CHANNEL_AN1   1
#define ADC_CHANNEL_AN2   2
#define ADC_CHANNEL_AN3   3
#define ADC_CHANNEL_AN4   4
#define ADC_CHANNEL_AN5   5
#define ADC_CHANNEL_AN6   6
#define ADC_CHANNEL_AN7   7

#define ADC_CLOCK_FOSC_DIV_2    0
#define ADC_CLOCK_FOSC_DIV_8    1
#define ADC_CLOCK_FOSC_DIV_32   2
#define ADC_CLOCK_FRC           3

#define ADC_LEFT_JUSTIFIED      0
#define ADC_RIGHT_JUSTIFIED     1

#define ADC_INTERRUPT_DISABLE   0
#define ADC_INTERRUPT_ENABLE    1

#define ADC_CFG_ALL_ANALOG          0x00
#define ADC_CFG_AN0_ONLY_ANALOG     0x0E

void ADC_Step1_Init(u8 channel, u8 clock, u8 port_cfg, u8 result_format);
void ADC_Step2_InterruptConfig(u8 interrupt_state);
void ADC_Step3_WaitAcquisitionTime_us(u16 time_us);
void ADC_Step4_StartConversion(void);
void ADC_Step5_WaitForConversion(void);
u16  ADC_Step6_ReadResult(void);
void ADC_Step7_WaitBeforeNextSample_us(u16 time_us);

u16 ADC_ReadChannelBlocking(u8 channel, u16 acquisition_time_us);

#endif