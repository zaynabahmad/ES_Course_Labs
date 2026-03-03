#line 1 "C:/Users/Amr/OneDrive/Desktop/Lab 1 Taskk 2/main.c"
#line 1 "c:/users/amr/onedrive/desktop/lab 1 taskk 2/ext_int.h"



void EXT_INT0_Init(void);
void EXT_INT0_Enable(void);
void EXT_INT0_Disable(void);
void EXT_INT0_SetEdge(unsigned char edge_type);
void EXT_INT0_SetCallback(void (*ptr)(void));
#line 1 "c:/users/amr/onedrive/desktop/lab 1 taskk 2/led.h"




void LED_Init(void);
void LED_Toggle(void);
#line 5 "C:/Users/Amr/OneDrive/Desktop/Lab 1 Taskk 2/main.c"
void My_App_Task(void) {
 LED_Toggle();
}

void main() {

 LED_Init();


 EXT_INT0_Init();


 EXT_INT0_SetCallback(My_App_Task);

 while(1) {


 }
}
