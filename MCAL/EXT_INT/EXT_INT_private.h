#ifndef EXT_INT_PRIVATE_H
#define EXT_INT_PRIVATE_H


#define INTCON      (*((volatile u8*)0x0B))
#define OPTION_REG  (*((volatile u8*)0x81))
#define TMR0        (*((volatile u8*)0x01))


#define GIE     7
#define T0IE    5    
#define INTE    4
#define T0IF    2    
#define INTF    1


#define T0CS    5    
#define PSA     3    
#define INTEDG  6
#define PS2     2   
#define PS1     1    
#define PS0     0    

#endif