 #ifndef EXT_INT0_PRIVATE_H
 #define EXT_INT0_PRIVATE_H
 
 #include "../../SERVICES/STD_TYPES.h"
 
 #define INTCON      (*((volatile u8*)0x0B))
 #define OPTION_REG  (*((volatile u8*)0x81))
 
 /* INTCON bits */
 #define GIE_BIT     7u   
 #define INTE_BIT    4u   
 #define INTF_BIT    1u   
 
#define INTEDG_BIT  6u  
#define RBPU_BIT    7u 
 
 #endif
