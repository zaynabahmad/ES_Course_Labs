#line 1 "C:/Users/engfa/OneDrive/Desktop/Embedded CIE 349/EmbeddedLab2/LabTask - External Interrupt (INT0) driver/INT0_Folders/HAL/SWITCH.c"
#line 1 "c:/users/engfa/onedrive/desktop/embedded cie 349/embeddedlab2/labtask - external interrupt (int0) driver/int0_folders/hal/switch.h"



void SWITCH_Init(unsigned char pin);
#line 3 "C:/Users/engfa/OneDrive/Desktop/Embedded CIE 349/EmbeddedLab2/LabTask - External Interrupt (INT0) driver/INT0_Folders/HAL/SWITCH.c"
void SWITCH_Init(unsigned char pin)
{
 TRISB.F0 = 1;
}
