#ifndef GPIO_CONFIG_H
#define GPIO_CONFIG_H


/* RA0=in, RA1=out, RA2=in, RA3-5=in */
#define GPIO_PORTA_DIR      0x3D   /* 0b00111101 */

/* RB0=in, RB1-3=out, RB4-7=in */
#define GPIO_PORTB_DIR      0xF1   /* 0b11110001 */

/* RC7=in(RX), RC3/RC4 managed by I2C HW, rest=out */
#define GPIO_PORTC_DIR      0x80   /* 0b10000000 */

/* All outputs: motor direction + headlight LEDs */
#define GPIO_PORTD_DIR      0x00

/* RE0-RE2 kept as inputs (unused) */
#define GPIO_PORTE_DIR      0x07

/* Initial output values: everything off / low */
#define GPIO_PORTA_INIT_VAL 0x00
#define GPIO_PORTB_INIT_VAL 0x00
#define GPIO_PORTC_INIT_VAL 0x00
#define GPIO_PORTD_INIT_VAL 0x00
#define GPIO_PORTE_INIT_VAL 0x00

#endif /* GPIO_CONFIG_H */