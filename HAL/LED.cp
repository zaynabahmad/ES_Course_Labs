#line 1 "C:/Users/engfa/OneDrive/Desktop/Embedded CIE 349/EmbeddedLab2/LabTask - External Interrupt (INT0) driver/INT0_Folders/HAL/LED.c"
#line 1 "c:/users/engfa/onedrive/desktop/embedded cie 349/embeddedlab2/labtask - external interrupt (int0) driver/int0_folders/hal/led.h"



void LED_Init(void);
void LED_Toggle(void);
#line 3 "C:/Users/engfa/OneDrive/Desktop/Embedded CIE 349/EmbeddedLab2/LabTask - External Interrupt (INT0) driver/INT0_Folders/HAL/LED.c"
void LED_Init(void)
{
 TRISC.F0 = 0;
 PORTC.F0 = 0;
}

void LED_Toggle(void)
{
 PORTC.F0 = ~PORTC.F0;
}
