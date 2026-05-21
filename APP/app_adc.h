/**
 * @file    app_adc.h
 * @brief   Entry point for the ADC streaming application.
 */
#ifndef APP_ADC_H
#define APP_ADC_H

/**
 * @brief  Continuously sample an analogue channel and stream the converted
 *         value out over the UART as readable text. Never returns.
 */
void vApp_Adc(void);

#endif /* APP_ADC_H */
