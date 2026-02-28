#line 1 "C:/Users/engfa/OneDrive/Desktop/Embedded CIE 349/EmbeddedLab2/LabTask - External Interrupt (INT0) driver/INT0_Folders/MCAL/EXIT_INT0.c"
#line 1 "c:/users/engfa/onedrive/desktop/embedded cie 349/embeddedlab2/labtask - external interrupt (int0) driver/int0_folders/mcal/exit_int0 .h"






void EXT_INT0_Init(void);
void EXT_INT0_Enable(void);
void EXT_INT0_Disable(void);
void EXT_INT0_SetEdge(unsigned char edge_type);
void EXT_INT0_SetCallback(void (*ptr)(void));
#line 3 "C:/Users/engfa/OneDrive/Desktop/Embedded CIE 349/EmbeddedLab2/LabTask - External Interrupt (INT0) driver/INT0_Folders/MCAL/EXIT_INT0.c"
static void (*EXT_INT0_Callback)(void);

void EXT_INT0_Init(void)
{
 TRISB.F0 = 1;
 INTCON.INTE = 0;
 INTCON.INTF = 0;
}

void EXT_INT0_SetEdge(unsigned char edge_type)
{
 OPTION_REG.INTEDG = edge_type;
}

void EXT_INT0_Enable(void)
{
 INTCON.INTF = 0;
 INTCON.INTE = 1;
 INTCON.GIE = 1;
}

void EXT_INT0_Disable(void)
{
 INTCON.INTE = 0;
}

void EXT_INT0_SetCallback(void (*ptr)(void))
{
 EXT_INT0_Callback = ptr;
}

void interrupt()
{
 if(INTCON.INTF)
 {
 if(EXT_INT0_Callback != 0)
 {
 EXT_INT0_Callback();
 }

 INTCON.INTF = 0;
 }
}
