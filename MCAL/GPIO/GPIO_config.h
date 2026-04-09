#ifndef GPIO_CONFIG_H
#define GPIO_CONFIG_H

#define GPIO_PORTA_DIR 0x00   // All Output
#define GPIO_PORTB_DIR 0xFF   // All Input
#define GPIO_PORTC_DIR 0x80   /* RC7 input (UART RX), rest output */
#define GPIO_PORTD_DIR 0x00
#define GPIO_PORTE_DIR 0x07   /* RE0-RE2 input (ADC), rest output */

#define GPIO_PORTA_INIT_VAL  0x00
#define GPIO_PORTB_INIT_VAL  0x00
#define GPIO_PORTC_INIT_VAL  0x00
#define GPIO_PORTD_INIT_VAL  0x00
#define GPIO_PORTE_INIT_VAL  0x00

#endif