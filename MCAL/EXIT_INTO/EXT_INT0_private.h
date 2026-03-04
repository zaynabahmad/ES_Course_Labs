 #ifndef EXT_INT0_PRIVATE_H
 #define EXT_INT0_PRIVATE_H
 
 #include "../../SERVICES/STD_TYPES.h"
 
 /* Register definitions for INT0 on PIC16F877A */
 #define INTCON      (*((volatile u8*)0x0B))
 #define OPTION_REG  (*((volatile u8*)0x81))
 
 /* INTCON bits */
 #define GIE_BIT     7u   /* Global Interrupt Enable */
 #define INTE_BIT    4u   /* INT0 External Interrupt Enable */
 #define INTF_BIT    1u   /* INT0 External Interrupt Flag */
 
 /* OPTION_REG bits */
 #define INTEDG_BIT  6u   /* Interrupt Edge Select for INT0 */
 
 #endif
