/*
 * adc.h
 * MCAL - ADC Driver Interface for PIC16F877A (10-bit ADC)
 */

#ifndef ADC_H
#define ADC_H

typedef unsigned char  u8;
typedef unsigned int   u16;

/* =====================================================
 * Type Definitions
 * ===================================================== */

/* ADC Channel Selection */
typedef enum {
    ADC_CHANNEL_0 = 0,   /* AN0 - RA0 */
    ADC_CHANNEL_1,        /* AN1 - RA1 */
    ADC_CHANNEL_2,        /* AN2 - RA2 */
    ADC_CHANNEL_3,        /* AN3 - RA3 */
    ADC_CHANNEL_4,        /* AN4 - RA5 */
    ADC_CHANNEL_5,        /* AN5 - RE0 */
    ADC_CHANNEL_6,        /* AN6 - RE1 */
    ADC_CHANNEL_7         /* AN7 - RE2 */
} ADC_Channel_t;

/* ADC Clock Selection */
typedef enum {
    ADC_CLK_FOSC_2  = 0x00,
    ADC_CLK_FOSC_8  = 0x01,
    ADC_CLK_FOSC_32 = 0x02,
    ADC_CLK_FRC     = 0x03   /* Internal RC oscillator */
} ADC_Clock_t;

/* Result Justification */
typedef enum {
    ADC_LEFT_JUSTIFIED  = 0,
    ADC_RIGHT_JUSTIFIED = 1
} ADC_Justify_t;

/* Number of Analog Pins Configuration */
typedef enum {
    ADC_ALL_ANALOG     = 0x00,  /* PCFG = 0000: AN0-AN7 analog */
    ADC_7_ANALOG       = 0x01,  /* PCFG = 0001: AN0-AN6 analog */
    ADC_5_ANALOG       = 0x02,  /* AN0-AN4 analog               */
    ADC_4_ANALOG       = 0x03,
    ADC_3_ANALOG       = 0x04,
    ADC_2_ANALOG       = 0x05,
    ADC_1_ANALOG       = 0x06,
    ADC_VREF_ONLY      = 0x07,
    ADC_ALL_DIGITAL    = 0x06   /* All pins digital             */
} ADC_PortConfig_t;

/* =====================================================
 * Function Prototypes
 * ===================================================== */

/**
 * @brief  Initialize the ADC module
 * @param  clk    : ADC conversion clock
 * @param  justify: left or right justified result
 * @param  config : analog/digital pin configuration
 */
void ADC_Init(ADC_Clock_t clk, ADC_Justify_t justify, ADC_PortConfig_t config);

/**
 * @brief  Select ADC channel and start conversion
 * @param  ch : ADC_CHANNEL_0 .. ADC_CHANNEL_7
 */
void ADC_SelectChannel(ADC_Channel_t ch);

/**
 * @brief  Start ADC conversion (set GO bit)
 */
void ADC_StartConversion(void);

/**
 * @brief  Check if ADC conversion is complete
 * @return 1 if complete, 0 if busy
 */
u8 ADC_IsConversionDone(void);

/**
 * @brief  Read 10-bit ADC result (blocking - waits for completion)
 * @param  ch : ADC channel to read
 * @return 10-bit result (0-1023)
 */
u16 ADC_Read(ADC_Channel_t ch);

/**
 * @brief  Enable ADC module
 */
void ADC_Enable(void);

/**
 * @brief  Disable ADC module (saves power)
 */
void ADC_Disable(void);

#endif /* ADC_H */
