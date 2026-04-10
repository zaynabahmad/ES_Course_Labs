#include "ADC_Private.h"
#include "ADC_interface.h"

void ADC_Init(u8 Channel) {
  ADCON0 = 0b10000000; // Fosc/32, ADC initially disabled
  ADCON1 = 0x00;       // LeftJustified, All ports Analog

  ADC_SetChannel(Channel);
}
void ADC_Enable(void) { SET_BIT(ADCON0, ADON_BIT); }
void ADC_Disable(void) { CLR_BIT(ADCON0, ADON_BIT); }

void ADC_SetClock(u8 Fosc) {
  u8 mask = 0b11;
  ADCON0 = (ADCON0 & ~(mask << 6)) | ((Fosc & mask) << 6);
}

void ADC_SetChannel(u8 Channel) {
  u8 mask = 0b111;
  ADCON0 = (ADCON0 & ~(mask << 3)) |
           ((Channel & mask) << 3); // port input handling by user
}

void ADC_SetPortConfig(u8 PCFG) {
  u8 mask = 0b1111;
  ADCON1 = (ADCON1 & ~(mask)) | (PCFG & mask);
}

void ADC_SetADFM(u8 ResultFormat) {
  if (ResultFormat == LeftJustified) {
    CLR_BIT(ADCON1, ADFM_BIT);
  } else {
    SET_BIT(ADCON1, ADFM_BIT);
  }
}

u16 ADC_Read(void) {
  SET_BIT(ADCON0, GO_DONE_BIT);
  u16 adc_value;

  while (GET_BIT(ADCON0, GO_DONE_BIT)) {
  };

  if (GET_BIT(ADCON1, ADFM_BIT) == LeftJustified) {
    adc_value = ADRESH;
    adc_value = (adc_value << 2) | (ADRESL >> 6);
  } else {
    adc_value = (adc_value << 8) | ADRESL;
  }
  return adc_value;
}

// Unimplemented
void ADC_SetCallback(void (*Callback)(void)) {}
void ADC_ISR(void) {}
