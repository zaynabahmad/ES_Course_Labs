#line 1 "C:/Users/engfa/OneDrive/Desktop/Embedded CIE 349/EmbeddedLab2/LabTask - External Interrupt (INT0) driver/INT0_Folders/Application/main.c"
#line 1 "c:/users/engfa/onedrive/desktop/embedded cie 349/embeddedlab2/labtask - external interrupt (int0) driver/int0_folders/mcal/exit_int0 .h"






void EXT_INT0_Init(void);
void EXT_INT0_Enable(void);
void EXT_INT0_Disable(void);
void EXT_INT0_SetEdge(unsigned char edge_type);
void EXT_INT0_SetCallback(void (*ptr)(void));
#line 1 "c:/users/engfa/onedrive/desktop/embedded cie 349/embeddedlab2/labtask - external interrupt (int0) driver/int0_folders/hal/led.h"



void LED_Init(void);
void LED_Toggle(void);
#line 1 "c:/users/engfa/onedrive/desktop/embedded cie 349/embeddedlab2/labtask - external interrupt (int0) driver/int0_folders/hal/switch.h"



void SWITCH_Init(unsigned char pin);
#line 5 "C:/Users/engfa/OneDrive/Desktop/Embedded CIE 349/EmbeddedLab2/LabTask - External Interrupt (INT0) driver/INT0_Folders/Application/main.c"
void APP_ToggleLED(void)
{
 LED_Toggle();
}

void main()
{
 LED_Init();
 SWITCH_Init(0);

 EXT_INT0_Init();
 EXT_INT0_SetEdge( 1 );
 EXT_INT0_SetCallback(APP_ToggleLED);
 EXT_INT0_Enable();

 while(1)
 {

 }
}
