#ifndef EXT_INT_PRIVATE_H
#define EXT_INT_PRIVATE_H


//INTCON Register 
#define INTCON          (*(volatile u8*)0x0B)
#define INTCON_GIE      7    
#define INTCON_INTE     4    
#define INTCON_INTF     1    

// OPTION_REG Register 
#define OPTION_REG      (*(volatile u8*)0x81)
#define OPTION_INTEDG   6    
#define OPTION_nRBPU    7   

// TRISB Register  
#define TRISB           (*(volatile u8*)0x86)
#define TRISB0          0

#endif 
