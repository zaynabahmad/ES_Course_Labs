// ES_Drivers/APP/ISR_Actions.c
#include "ISR_Actions.h"

volatile u8 g_flag_extint   = 0;
volatile u8 g_flag_timer    = 0;
volatile u8 g_flag_uart_rx  = 0;
volatile u8 g_uart_rx_byte  = 0;