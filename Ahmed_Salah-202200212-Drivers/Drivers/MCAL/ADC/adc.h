/**
 * @file    adc.h
 * @brief   PIC16F877 ADC Driver Header
 * @details 10-bit, 8-channel ADC (AN0–AN7)
 *
 * Key Registers (DS30292C):
 *   ADCON0 (0x1F):
 *     bit7-6  ADCS<1:0> — clock select
 *     bit5-3  CHS<2:0>  — channel select
 *     bit2    GO/DONE   — conversion status/start
 *     bit0    ADON      — ADC on/off
 *   ADCON1 (0x9F):
 *     bit7    ADFM      — result justification (1=right, 0=left)
 *     bit3-0  PCFG<3:0> — pin config (analog vs digital)
 *   ADRESH (0x1E) — high byte of result
 *   ADRESL (0x9E) — low byte of result
 *   PIR1<6> ADIF  — ADC interrupt flag
 *   PIE1<6> ADIE  — ADC interrupt enable
 *
 * Right-justified result: ADRESH<1:0>:ADRESL<7:0> = 10-bit value
 * Left-justified  result: ADRESH<7:0>:ADRESL<7:6> = 10-bit value
 */

#ifndef ADC_H
#define ADC_H

#include <pic16f877.h>
#include <stdint.h>

/*============================================================
 * ADC Channel
 *============================================================*/
typedef enum {
    ADC_CH0 = 0,   /* RA0/AN0 */
    ADC_CH1,       /* RA1/AN1 */
    ADC_CH2,       /* RA2/AN2 */
    ADC_CH3,       /* RA3/AN3 */
    ADC_CH4,       /* RA5/AN4 */
    ADC_CH5,       /* RE0/AN5 */
    ADC_CH6,       /* RE1/AN6 */
    ADC_CH7        /* RE2/AN7 */
} ADC_Channel_t;

/*============================================================
 * ADC Clock Source (ADCS<1:0>)
 *============================================================*/
typedef enum {
    ADC_CLK_FOSC_2  = 0x00,   /* Fosc/2  */
    ADC_CLK_FOSC_8  = 0x01,   /* Fosc/8  */
    ADC_CLK_FOSC_32 = 0x02,   /* Fosc/32 */
    ADC_CLK_FRC     = 0x03    /* Internal RC oscillator */
} ADC_Clock_t;

/*============================================================
 * Result Justification
 *============================================================*/
typedef enum {
    ADC_JUSTIFY_LEFT  = 0,   /* ADRESH<7:0>:ADRESL<7:6> */
    ADC_JUSTIFY_RIGHT = 1    /* ADRESH<1:0>:ADRESL<7:0> */
} ADC_Justify_t;

/*============================================================
 * Port Configuration (PCFG<3:0> — ADCON1)
 * Controls which pins are analog vs digital
 *============================================================*/
typedef enum {
    ADC_PCFG_ALL_ANALOG    = 0x00,  /* AN0-AN7 analog,  Vref=VDD/VSS  */
    ADC_PCFG_7AN_1REF      = 0x01,  /* AN0-AN6 analog,  AN3=Vref+      */
    ADC_PCFG_5AN           = 0x02,  /* AN0-AN4 analog                   */
    ADC_PCFG_4AN_1REF      = 0x03,  /* AN0-AN3,AN5,  AN3=Vref+         */
    ADC_PCFG_3AN_2REF      = 0x04,  /* AN0-AN2,  AN3=Vref+, AN2=Vref- */
    ADC_PCFG_ALL_DIGITAL   = 0x06,  /* No analog pins                   */
    ADC_PCFG_3AN           = 0x05,  /* AN0-AN2 analog                   */
    ADC_PCFG_2AN_2REF      = 0x08,  /* AN0-AN1, external Vref+/Vref-   */
    ADC_PCFG_1AN_2REF      = 0x09,  /* AN0,     external Vref+/Vref-   */
    ADC_PCFG_2AN           = 0x0A,  /* AN0-AN1  analog                  */
    ADC_PCFG_1AN           = 0x0B,  /* AN0      analog                  */
    ADC_PCFG_6AN_2REF      = 0x0C, /* AN0-AN5, AN3=Vref+, AN2=Vref-   */
    ADC_PCFG_6AN_1REF      = 0x0D, /* AN0-AN5, AN3=Vref+               */
    ADC_PCFG_6AN           = 0x0E  /* AN0-AN5  analog                   */
} ADC_PortCfg_t;

/*============================================================
 * Interrupt Control
 *============================================================*/
typedef enum {
    ADC_INT_DISABLE = 0,
    ADC_INT_ENABLE  = 1
} ADC_Int_t;

/*============================================================
 * Configuration Structure
 *============================================================*/
typedef struct {
    ADC_Clock_t   clock;      /* Conversion clock source        */
    ADC_Justify_t justify;    /* Result left or right justified  */
    ADC_PortCfg_t portCfg;   /* Pin configuration (PCFG bits)  */
    ADC_Int_t     intEnable;  /* Enable ADC interrupt            */
} ADC_Config_t;

/*============================================================
 * API
 *============================================================*/

/**
 * @brief  Initialize ADC module
 * @param  cfg  Pointer to ADC_Config_t
 */
void ADC_Init(const ADC_Config_t *cfg);

/** @brief  Power on ADC (ADON=1) */
void ADC_Enable(void);

/** @brief  Power off ADC (ADON=0) */
void ADC_Disable(void);

/**
 * @brief  Select active channel
 * @param  channel  ADC_CH0 – ADC_CH7
 */
void ADC_SelectChannel(ADC_Channel_t channel);

/** @brief  Start conversion (GO/DONE = 1) */
void ADC_StartConversion(void);

/** @brief  Check if conversion is complete (GO/DONE = 0) */
uint8_t ADC_IsConversionDone(void);

/**
 * @brief  Read 10-bit result after conversion completes
 * @return 10-bit ADC result (right-justified by default)
 */
uint16_t ADC_GetResult(void);

/**
 * @brief  Blocking single-channel read
 *         Selects channel, starts, waits, returns result.
 * @param  channel  ADC_CH0 – ADC_CH7
 * @return 10-bit result
 */
uint16_t ADC_Read(ADC_Channel_t channel);

/** @brief  Clear ADC interrupt flag */
void ADC_ClearFlag(void);

/**
 * @brief  Conversion complete callback (interrupt mode)
 *         Implement in application code.
 */
void ADC_ConvComplete_Callback(void);

#endif /* ADC_H */
