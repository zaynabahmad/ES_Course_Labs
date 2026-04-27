#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

/* ---- Registers ---- */
#define INTCON_REG  *((volatile unsigned char*)0x0B)
#define OPTION_REG  *((volatile unsigned char*)0x81)

/* ---- INTCON bit positions ---- */
#define GIE     7   /* Global interrupt enable  */
#define INTE    4   /* INT0 interrupt enable     */
#define INTF    1   /* INT0 interrupt flag       */

/* ---- OPTION_REG bit positions ---- */
#define INTEDG  6   /* Edge select: 1=rising, 0=falling */

#endif
