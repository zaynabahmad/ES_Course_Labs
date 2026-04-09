#ifndef INTERRUPT_MANAGER_H
#define INTERRUPT_MANAGER_H

#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"
#include "../GPIO/GPIO_interface.h"
#include "../TMR_INT/TMR_INT_interface.h"
#include "../EXT_INT/EXT_INT_interface.h"
#include "../ADC/ADC_interface.h"
#include "../USART/USART_Interface.h"
#include "../SPI/SPI_Interface.h"
/* Timer0 variables (shared with HAL) */
extern volatile u16 TMR0_Counter;      // counts Timer0 interrupts
extern volatile u16 target_overflows;  // number of overflows needed for delay

/* Callback registration */
void TMR_INT_SetCallback(void (*ptr)(void));
void EXT_INT_SetCallback(void (*ptr)(void));
void ADC_SetConversionComplete_SetCallback(void (*ptr)(void));
void I2C_SetCallback(void (*ptr)(void));
void SPI_SetCallback(void (*ptr)(void)); // New function to set SPI callback
/* ISR */
void interrupt(void);

#endif