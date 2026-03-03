#line 1 "C:/Users/Amr/OneDrive/Desktop/Lab 1 Taskk 2/EXT_INT.c"
#line 1 "c:/users/amr/onedrive/desktop/lab 1 taskk 2/ext_int.h"



void EXT_INT0_Init(void);
void EXT_INT0_Enable(void);
void EXT_INT0_Disable(void);
void EXT_INT0_SetEdge(unsigned char edge_type);
void EXT_INT0_SetCallback(void (*ptr)(void));
#line 4 "C:/Users/Amr/OneDrive/Desktop/Lab 1 Taskk 2/EXT_INT.c"
static void (*INT0_CallBackPtr)(void) = 0;

void EXT_INT0_Init(void) {
 TRISB.F0 = 1;
 EXT_INT0_SetEdge(1);
 EXT_INT0_Enable();
 INTCON.GIE = 1;
 INTCON.PEIE = 1;
}

void EXT_INT0_Enable(void) { INTCON.INTE = 1; }
void EXT_INT0_Disable(void) { INTCON.INTE = 0; }

void EXT_INT0_SetEdge(unsigned char edge_type) {
 if(edge_type == 1) OPTION_REG.INTEDG = 1;
 else OPTION_REG.INTEDG = 0;
}

void EXT_INT0_SetCallback(void (*ptr)(void)) {
 INT0_CallBackPtr = ptr;
}


void interrupt() {
 if (INTCON.INTF) {
 if (INT0_CallBackPtr != 0) {
 INT0_CallBackPtr();
 }
 INTCON.INTF = 0;
 }
}
