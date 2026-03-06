#ifndef TIMER_PRIVATE_H
#define TIMER_PRIVATE_H


#define TMR0 (*((volatile u8*)0x01))

//QUESTION
//This register already exists in the INT file, however
//i wasnt sure if i had to redefine it here or if i could
//access from its already existing definition in INT, seemed complicated
//so i went with just redefining it
//How is such a case usually handled ? 
#define OPTION_REG (*((volatile u8*)0x81))


//Pre scaller selection bits PS0 - PS2 SET 111 for 256:1
#define PS0 0
#define PS1 1
#define PS2 2

//QUESTION Why am i only able to set a prescaller for either the normal timer or WDT
//Assigning prescaller to TIMER or WDT 
#define PSA 3 

// Clock Source Select bit (Set for external CLK) (CLR for internal CLK)
#define TOCS 5



#endif