#ifndef GPIO_CONFIG_H
#define GPIO_CONFIG_H

/* PORTB:
   PIN0 = OUTPUT (LED1)
   PIN1 = OUTPUT (LED2)
   PIN2 = INPUT  (SW1)
   PIN3 = INPUT  (SW2)

   Binary: 0b00001100 = 0x0C
   0=output, 1=input */

#define GPIO_PORTB_DIR       0x0C
#define GPIO_PORTA_DIR       0x00

#define GPIO_PORTA_INIT_VAL  0x00
#define GPIO_PORTB_INIT_VAL  0x00

#endif