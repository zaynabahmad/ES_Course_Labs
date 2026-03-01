#ifndef EXTI_SERVICE_H
#define EXTI_SERVICE_H

// Initialize LED + INT0 interrupt
void EXTI0_Service_Init(void);

// Call this in main loop to safely handle LED toggling
void EXTI0_Service_Loop(void);

#endif