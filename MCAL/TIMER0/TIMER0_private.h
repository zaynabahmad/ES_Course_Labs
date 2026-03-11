#ifndef TIMER0_PRIVATE_H
#define TIMER0_PRIVATE_H

#define OPTION_REG *((volatile unsigned char*)0x81)
#define TMR0       *((volatile unsigned char*)0x01)
#define INTCON     *((volatile unsigned char*)0x0B)

#endif