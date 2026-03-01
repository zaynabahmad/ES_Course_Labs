#ifndef EXTI_REGISTER_H
#define EXTI_REGISTER_H



#define INTCON      *((volatile unsigned char*)0x000B)
#define OPTION_REG  *((volatile unsigned char*)0x0081)

#define INTCON_GIE   7
#define INTCON_PEIE  6
#define INTCON_INTE  4
#define INTCON_INTF  1


#define OPTION_REG_INTEDG 6

#endif