#ifndef GPIO_CONFIG_H
#define GPIO_CONFIG_H

/**
 * Port Directions:
 * 0x00 = All Pins are Outputs
 * 0xFF = All Pins are Inputs
 */
#define GPIO_PORTA_DIR       0x00  // All Output
#define GPIO_PORTB_DIR       0xFF  // All Input (Standard for switches/interrupts)
#define GPIO_PORTC_DIR       0x00  // Added: All Output
#define GPIO_PORTD_DIR       0x00  // Added: All Output
#define GPIO_PORTE_DIR       0x00  // Added: All Output

/**
 * Initial Values:
 * 0x00 = All Pins are LOW (0V)
 * 0xFF = All Pins are HIGH (5V)
 */
#define GPIO_PORTA_INIT_VAL  0x00
#define GPIO_PORTB_INIT_VAL  0x00
#define GPIO_PORTC_INIT_VAL  0x00  // Added: All Low
#define GPIO_PORTD_INIT_VAL  0x00  // Added: All Low
#define GPIO_PORTE_INIT_VAL  0x00  // Added: All Low

#endif