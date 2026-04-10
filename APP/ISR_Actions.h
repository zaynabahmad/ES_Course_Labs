// ES_Drivers/APP/ISR_Actions.h
#ifndef ISR_ACTIONS_H
#define ISR_ACTIONS_H

#include "../SERVICES/STD_TYPES.h"
#include "app_config.h"

// These volatile flags are the ONLY things touched inside the ISR.
// No HAL or MCAL functions are called from within ISR context.

extern volatile u8 g_flag_extint;
extern volatile u8 g_flag_timer;
extern volatile u8 g_flag_uart_rx;
extern volatile u8 g_uart_rx_byte;

#endif