subtitle "Microchip MPLAB XC8 C Compiler v3.10 (Free license) build 20250813170317 Og9 "

pagewidth 120

	opt flic

	processor	16F877A
include "C:/Users/Ziad/Desktop/Academic/College zewail city/Courses/CIE/Year 4/CIE 408 Embedded Systems/Compiler/Microchip.PIC16Fxxx_DFP.1.7.162/xc8\pic\include\proc\16f877a.cgen.inc"
getbyte	macro	val,pos
	(((val) >> (8 * pos)) and 0xff)
endm
byte0	macro	val
	(getbyte(val,0))
endm
byte1	macro	val
	(getbyte(val,1))
endm
byte2	macro	val
	(getbyte(val,2))
endm
byte3	macro	val
	(getbyte(val,3))
endm
byte4	macro	val
	(getbyte(val,4))
endm
byte5	macro	val
	(getbyte(val,5))
endm
byte6	macro	val
	(getbyte(val,6))
endm
byte7	macro	val
	(getbyte(val,7))
endm
getword	macro	val,pos
	(((val) >> (8 * pos)) and 0xffff)
endm
word0	macro	val
	(getword(val,0))
endm
word1	macro	val
	(getword(val,2))
endm
word2	macro	val
	(getword(val,4))
endm
word3	macro	val
	(getword(val,6))
endm
gettword	macro	val,pos
	(((val) >> (8 * pos)) and 0xffffff)
endm
tword0	macro	val
	(gettword(val,0))
endm
tword1	macro	val
	(gettword(val,3))
endm
tword2	macro	val
	(gettword(val,6))
endm
getdword	macro	val,pos
	(((val) >> (8 * pos)) and 0xffffffff)
endm
dword0	macro	val
	(getdword(val,0))
endm
dword1	macro	val
	(getdword(val,4))
endm
clrc	macro
	bcf	3,0
	endm
clrz	macro
	bcf	3,2
	endm
setc	macro
	bsf	3,0
	endm
setz	macro
	bsf	3,2
	endm
skipc	macro
	btfss	3,0
	endm
skipz	macro
	btfss	3,2
	endm
skipnc	macro
	btfsc	3,0
	endm
skipnz	macro
	btfsc	3,2
	endm
# 52 "C:/Users/Ziad/Desktop/Academic/College zewail city/Courses/CIE/Year 4/CIE 408 Embedded Systems/Compiler/Microchip.PIC16Fxxx_DFP.1.7.162/xc8\pic\include\proc/pic16f877a.h"
INDF equ 00h ;# 
# 59 "C:/Users/Ziad/Desktop/Academic/College zewail city/Courses/CIE/Year 4/CIE 408 Embedded Systems/Compiler/Microchip.PIC16Fxxx_DFP.1.7.162/xc8\pic\include\proc/pic16f877a.h"
TMR0 equ 01h ;# 
# 66 "C:/Users/Ziad/Desktop/Academic/College zewail city/Courses/CIE/Year 4/CIE 408 Embedded Systems/Compiler/Microchip.PIC16Fxxx_DFP.1.7.162/xc8\pic\include\proc/pic16f877a.h"
PCL equ 02h ;# 
# 73 "C:/Users/Ziad/Desktop/Academic/College zewail city/Courses/CIE/Year 4/CIE 408 Embedded Systems/Compiler/Microchip.PIC16Fxxx_DFP.1.7.162/xc8\pic\include\proc/pic16f877a.h"
STATUS equ 03h ;# 
# 159 "C:/Users/Ziad/Desktop/Academic/College zewail city/Courses/CIE/Year 4/CIE 408 Embedded Systems/Compiler/Microchip.PIC16Fxxx_DFP.1.7.162/xc8\pic\include\proc/pic16f877a.h"
FSR equ 04h ;# 
# 166 "C:/Users/Ziad/Desktop/Academic/College zewail city/Courses/CIE/Year 4/CIE 408 Embedded Systems/Compiler/Microchip.PIC16Fxxx_DFP.1.7.162/xc8\pic\include\proc/pic16f877a.h"
PORTA equ 05h ;# 
# 216 "C:/Users/Ziad/Desktop/Academic/College zewail city/Courses/CIE/Year 4/CIE 408 Embedded Systems/Compiler/Microchip.PIC16Fxxx_DFP.1.7.162/xc8\pic\include\proc/pic16f877a.h"
PORTB equ 06h ;# 
# 278 "C:/Users/Ziad/Desktop/Academic/College zewail city/Courses/CIE/Year 4/CIE 408 Embedded Systems/Compiler/Microchip.PIC16Fxxx_DFP.1.7.162/xc8\pic\include\proc/pic16f877a.h"
PORTC equ 07h ;# 
# 340 "C:/Users/Ziad/Desktop/Academic/College zewail city/Courses/CIE/Year 4/CIE 408 Embedded Systems/Compiler/Microchip.PIC16Fxxx_DFP.1.7.162/xc8\pic\include\proc/pic16f877a.h"
PORTD equ 08h ;# 
# 402 "C:/Users/Ziad/Desktop/Academic/College zewail city/Courses/CIE/Year 4/CIE 408 Embedded Systems/Compiler/Microchip.PIC16Fxxx_DFP.1.7.162/xc8\pic\include\proc/pic16f877a.h"
PORTE equ 09h ;# 
# 434 "C:/Users/Ziad/Desktop/Academic/College zewail city/Courses/CIE/Year 4/CIE 408 Embedded Systems/Compiler/Microchip.PIC16Fxxx_DFP.1.7.162/xc8\pic\include\proc/pic16f877a.h"
PCLATH equ 0Ah ;# 
# 454 "C:/Users/Ziad/Desktop/Academic/College zewail city/Courses/CIE/Year 4/CIE 408 Embedded Systems/Compiler/Microchip.PIC16Fxxx_DFP.1.7.162/xc8\pic\include\proc/pic16f877a.h"
INTCON equ 0Bh ;# 
# 532 "C:/Users/Ziad/Desktop/Academic/College zewail city/Courses/CIE/Year 4/CIE 408 Embedded Systems/Compiler/Microchip.PIC16Fxxx_DFP.1.7.162/xc8\pic\include\proc/pic16f877a.h"
PIR1 equ 0Ch ;# 
# 594 "C:/Users/Ziad/Desktop/Academic/College zewail city/Courses/CIE/Year 4/CIE 408 Embedded Systems/Compiler/Microchip.PIC16Fxxx_DFP.1.7.162/xc8\pic\include\proc/pic16f877a.h"
PIR2 equ 0Dh ;# 
# 634 "C:/Users/Ziad/Desktop/Academic/College zewail city/Courses/CIE/Year 4/CIE 408 Embedded Systems/Compiler/Microchip.PIC16Fxxx_DFP.1.7.162/xc8\pic\include\proc/pic16f877a.h"
TMR1 equ 0Eh ;# 
# 641 "C:/Users/Ziad/Desktop/Academic/College zewail city/Courses/CIE/Year 4/CIE 408 Embedded Systems/Compiler/Microchip.PIC16Fxxx_DFP.1.7.162/xc8\pic\include\proc/pic16f877a.h"
TMR1L equ 0Eh ;# 
# 648 "C:/Users/Ziad/Desktop/Academic/College zewail city/Courses/CIE/Year 4/CIE 408 Embedded Systems/Compiler/Microchip.PIC16Fxxx_DFP.1.7.162/xc8\pic\include\proc/pic16f877a.h"
TMR1H equ 0Fh ;# 
# 655 "C:/Users/Ziad/Desktop/Academic/College zewail city/Courses/CIE/Year 4/CIE 408 Embedded Systems/Compiler/Microchip.PIC16Fxxx_DFP.1.7.162/xc8\pic\include\proc/pic16f877a.h"
T1CON equ 010h ;# 
# 730 "C:/Users/Ziad/Desktop/Academic/College zewail city/Courses/CIE/Year 4/CIE 408 Embedded Systems/Compiler/Microchip.PIC16Fxxx_DFP.1.7.162/xc8\pic\include\proc/pic16f877a.h"
TMR2 equ 011h ;# 
# 737 "C:/Users/Ziad/Desktop/Academic/College zewail city/Courses/CIE/Year 4/CIE 408 Embedded Systems/Compiler/Microchip.PIC16Fxxx_DFP.1.7.162/xc8\pic\include\proc/pic16f877a.h"
T2CON equ 012h ;# 
# 808 "C:/Users/Ziad/Desktop/Academic/College zewail city/Courses/CIE/Year 4/CIE 408 Embedded Systems/Compiler/Microchip.PIC16Fxxx_DFP.1.7.162/xc8\pic\include\proc/pic16f877a.h"
SSPBUF equ 013h ;# 
# 815 "C:/Users/Ziad/Desktop/Academic/College zewail city/Courses/CIE/Year 4/CIE 408 Embedded Systems/Compiler/Microchip.PIC16Fxxx_DFP.1.7.162/xc8\pic\include\proc/pic16f877a.h"
SSPCON equ 014h ;# 
# 885 "C:/Users/Ziad/Desktop/Academic/College zewail city/Courses/CIE/Year 4/CIE 408 Embedded Systems/Compiler/Microchip.PIC16Fxxx_DFP.1.7.162/xc8\pic\include\proc/pic16f877a.h"
CCPR1 equ 015h ;# 
# 892 "C:/Users/Ziad/Desktop/Academic/College zewail city/Courses/CIE/Year 4/CIE 408 Embedded Systems/Compiler/Microchip.PIC16Fxxx_DFP.1.7.162/xc8\pic\include\proc/pic16f877a.h"
CCPR1L equ 015h ;# 
# 899 "C:/Users/Ziad/Desktop/Academic/College zewail city/Courses/CIE/Year 4/CIE 408 Embedded Systems/Compiler/Microchip.PIC16Fxxx_DFP.1.7.162/xc8\pic\include\proc/pic16f877a.h"
CCPR1H equ 016h ;# 
# 906 "C:/Users/Ziad/Desktop/Academic/College zewail city/Courses/CIE/Year 4/CIE 408 Embedded Systems/Compiler/Microchip.PIC16Fxxx_DFP.1.7.162/xc8\pic\include\proc/pic16f877a.h"
CCP1CON equ 017h ;# 
# 964 "C:/Users/Ziad/Desktop/Academic/College zewail city/Courses/CIE/Year 4/CIE 408 Embedded Systems/Compiler/Microchip.PIC16Fxxx_DFP.1.7.162/xc8\pic\include\proc/pic16f877a.h"
RCSTA equ 018h ;# 
# 1059 "C:/Users/Ziad/Desktop/Academic/College zewail city/Courses/CIE/Year 4/CIE 408 Embedded Systems/Compiler/Microchip.PIC16Fxxx_DFP.1.7.162/xc8\pic\include\proc/pic16f877a.h"
TXREG equ 019h ;# 
# 1066 "C:/Users/Ziad/Desktop/Academic/College zewail city/Courses/CIE/Year 4/CIE 408 Embedded Systems/Compiler/Microchip.PIC16Fxxx_DFP.1.7.162/xc8\pic\include\proc/pic16f877a.h"
RCREG equ 01Ah ;# 
# 1073 "C:/Users/Ziad/Desktop/Academic/College zewail city/Courses/CIE/Year 4/CIE 408 Embedded Systems/Compiler/Microchip.PIC16Fxxx_DFP.1.7.162/xc8\pic\include\proc/pic16f877a.h"
CCPR2 equ 01Bh ;# 
# 1080 "C:/Users/Ziad/Desktop/Academic/College zewail city/Courses/CIE/Year 4/CIE 408 Embedded Systems/Compiler/Microchip.PIC16Fxxx_DFP.1.7.162/xc8\pic\include\proc/pic16f877a.h"
CCPR2L equ 01Bh ;# 
# 1087 "C:/Users/Ziad/Desktop/Academic/College zewail city/Courses/CIE/Year 4/CIE 408 Embedded Systems/Compiler/Microchip.PIC16Fxxx_DFP.1.7.162/xc8\pic\include\proc/pic16f877a.h"
CCPR2H equ 01Ch ;# 
# 1094 "C:/Users/Ziad/Desktop/Academic/College zewail city/Courses/CIE/Year 4/CIE 408 Embedded Systems/Compiler/Microchip.PIC16Fxxx_DFP.1.7.162/xc8\pic\include\proc/pic16f877a.h"
CCP2CON equ 01Dh ;# 
# 1152 "C:/Users/Ziad/Desktop/Academic/College zewail city/Courses/CIE/Year 4/CIE 408 Embedded Systems/Compiler/Microchip.PIC16Fxxx_DFP.1.7.162/xc8\pic\include\proc/pic16f877a.h"
ADRESH equ 01Eh ;# 
# 1159 "C:/Users/Ziad/Desktop/Academic/College zewail city/Courses/CIE/Year 4/CIE 408 Embedded Systems/Compiler/Microchip.PIC16Fxxx_DFP.1.7.162/xc8\pic\include\proc/pic16f877a.h"
ADCON0 equ 01Fh ;# 
# 1255 "C:/Users/Ziad/Desktop/Academic/College zewail city/Courses/CIE/Year 4/CIE 408 Embedded Systems/Compiler/Microchip.PIC16Fxxx_DFP.1.7.162/xc8\pic\include\proc/pic16f877a.h"
OPTION_REG equ 081h ;# 
# 1325 "C:/Users/Ziad/Desktop/Academic/College zewail city/Courses/CIE/Year 4/CIE 408 Embedded Systems/Compiler/Microchip.PIC16Fxxx_DFP.1.7.162/xc8\pic\include\proc/pic16f877a.h"
TRISA equ 085h ;# 
# 1375 "C:/Users/Ziad/Desktop/Academic/College zewail city/Courses/CIE/Year 4/CIE 408 Embedded Systems/Compiler/Microchip.PIC16Fxxx_DFP.1.7.162/xc8\pic\include\proc/pic16f877a.h"
TRISB equ 086h ;# 
# 1437 "C:/Users/Ziad/Desktop/Academic/College zewail city/Courses/CIE/Year 4/CIE 408 Embedded Systems/Compiler/Microchip.PIC16Fxxx_DFP.1.7.162/xc8\pic\include\proc/pic16f877a.h"
TRISC equ 087h ;# 
# 1499 "C:/Users/Ziad/Desktop/Academic/College zewail city/Courses/CIE/Year 4/CIE 408 Embedded Systems/Compiler/Microchip.PIC16Fxxx_DFP.1.7.162/xc8\pic\include\proc/pic16f877a.h"
TRISD equ 088h ;# 
# 1561 "C:/Users/Ziad/Desktop/Academic/College zewail city/Courses/CIE/Year 4/CIE 408 Embedded Systems/Compiler/Microchip.PIC16Fxxx_DFP.1.7.162/xc8\pic\include\proc/pic16f877a.h"
TRISE equ 089h ;# 
# 1618 "C:/Users/Ziad/Desktop/Academic/College zewail city/Courses/CIE/Year 4/CIE 408 Embedded Systems/Compiler/Microchip.PIC16Fxxx_DFP.1.7.162/xc8\pic\include\proc/pic16f877a.h"
PIE1 equ 08Ch ;# 
# 1680 "C:/Users/Ziad/Desktop/Academic/College zewail city/Courses/CIE/Year 4/CIE 408 Embedded Systems/Compiler/Microchip.PIC16Fxxx_DFP.1.7.162/xc8\pic\include\proc/pic16f877a.h"
PIE2 equ 08Dh ;# 
# 1720 "C:/Users/Ziad/Desktop/Academic/College zewail city/Courses/CIE/Year 4/CIE 408 Embedded Systems/Compiler/Microchip.PIC16Fxxx_DFP.1.7.162/xc8\pic\include\proc/pic16f877a.h"
PCON equ 08Eh ;# 
# 1754 "C:/Users/Ziad/Desktop/Academic/College zewail city/Courses/CIE/Year 4/CIE 408 Embedded Systems/Compiler/Microchip.PIC16Fxxx_DFP.1.7.162/xc8\pic\include\proc/pic16f877a.h"
SSPCON2 equ 091h ;# 
# 1816 "C:/Users/Ziad/Desktop/Academic/College zewail city/Courses/CIE/Year 4/CIE 408 Embedded Systems/Compiler/Microchip.PIC16Fxxx_DFP.1.7.162/xc8\pic\include\proc/pic16f877a.h"
PR2 equ 092h ;# 
# 1823 "C:/Users/Ziad/Desktop/Academic/College zewail city/Courses/CIE/Year 4/CIE 408 Embedded Systems/Compiler/Microchip.PIC16Fxxx_DFP.1.7.162/xc8\pic\include\proc/pic16f877a.h"
SSPADD equ 093h ;# 
# 1830 "C:/Users/Ziad/Desktop/Academic/College zewail city/Courses/CIE/Year 4/CIE 408 Embedded Systems/Compiler/Microchip.PIC16Fxxx_DFP.1.7.162/xc8\pic\include\proc/pic16f877a.h"
SSPSTAT equ 094h ;# 
# 1999 "C:/Users/Ziad/Desktop/Academic/College zewail city/Courses/CIE/Year 4/CIE 408 Embedded Systems/Compiler/Microchip.PIC16Fxxx_DFP.1.7.162/xc8\pic\include\proc/pic16f877a.h"
TXSTA equ 098h ;# 
# 2080 "C:/Users/Ziad/Desktop/Academic/College zewail city/Courses/CIE/Year 4/CIE 408 Embedded Systems/Compiler/Microchip.PIC16Fxxx_DFP.1.7.162/xc8\pic\include\proc/pic16f877a.h"
SPBRG equ 099h ;# 
# 2087 "C:/Users/Ziad/Desktop/Academic/College zewail city/Courses/CIE/Year 4/CIE 408 Embedded Systems/Compiler/Microchip.PIC16Fxxx_DFP.1.7.162/xc8\pic\include\proc/pic16f877a.h"
CMCON equ 09Ch ;# 
# 2157 "C:/Users/Ziad/Desktop/Academic/College zewail city/Courses/CIE/Year 4/CIE 408 Embedded Systems/Compiler/Microchip.PIC16Fxxx_DFP.1.7.162/xc8\pic\include\proc/pic16f877a.h"
CVRCON equ 09Dh ;# 
# 2222 "C:/Users/Ziad/Desktop/Academic/College zewail city/Courses/CIE/Year 4/CIE 408 Embedded Systems/Compiler/Microchip.PIC16Fxxx_DFP.1.7.162/xc8\pic\include\proc/pic16f877a.h"
ADRESL equ 09Eh ;# 
# 2229 "C:/Users/Ziad/Desktop/Academic/College zewail city/Courses/CIE/Year 4/CIE 408 Embedded Systems/Compiler/Microchip.PIC16Fxxx_DFP.1.7.162/xc8\pic\include\proc/pic16f877a.h"
ADCON1 equ 09Fh ;# 
# 2288 "C:/Users/Ziad/Desktop/Academic/College zewail city/Courses/CIE/Year 4/CIE 408 Embedded Systems/Compiler/Microchip.PIC16Fxxx_DFP.1.7.162/xc8\pic\include\proc/pic16f877a.h"
EEDATA equ 010Ch ;# 
# 2295 "C:/Users/Ziad/Desktop/Academic/College zewail city/Courses/CIE/Year 4/CIE 408 Embedded Systems/Compiler/Microchip.PIC16Fxxx_DFP.1.7.162/xc8\pic\include\proc/pic16f877a.h"
EEADR equ 010Dh ;# 
# 2302 "C:/Users/Ziad/Desktop/Academic/College zewail city/Courses/CIE/Year 4/CIE 408 Embedded Systems/Compiler/Microchip.PIC16Fxxx_DFP.1.7.162/xc8\pic\include\proc/pic16f877a.h"
EEDATH equ 010Eh ;# 
# 2309 "C:/Users/Ziad/Desktop/Academic/College zewail city/Courses/CIE/Year 4/CIE 408 Embedded Systems/Compiler/Microchip.PIC16Fxxx_DFP.1.7.162/xc8\pic\include\proc/pic16f877a.h"
EEADRH equ 010Fh ;# 
# 2316 "C:/Users/Ziad/Desktop/Academic/College zewail city/Courses/CIE/Year 4/CIE 408 Embedded Systems/Compiler/Microchip.PIC16Fxxx_DFP.1.7.162/xc8\pic\include\proc/pic16f877a.h"
EECON1 equ 018Ch ;# 
# 2361 "C:/Users/Ziad/Desktop/Academic/College zewail city/Courses/CIE/Year 4/CIE 408 Embedded Systems/Compiler/Microchip.PIC16Fxxx_DFP.1.7.162/xc8\pic\include\proc/pic16f877a.h"
EECON2 equ 018Dh ;# 
	debug_source C
	FNCALL	_main,_PWM_setDutyCycle
	FNCALL	_main,_setup
	FNCALL	_setup,_MOTOR_Init
	FNCALL	_MOTOR_Init,_GPIO_SetPinDirection
	FNCALL	_MOTOR_Init,_PWM_inti
	FNCALL	_MOTOR_Init,_PWM_setDutyCycle
	FNCALL	_MOTOR_Init,_PWM_setFrequency
	FNCALL	_PWM_setFrequency,___lldiv
	FNCALL	_PWM_setFrequency,___lmul
	FNCALL	_PWM_setFrequency,_get_preScaler
	FNCALL	_PWM_setFrequency,_set_period_timer_2_Reg
	FNCALL	_PWM_setDutyCycle,___lldiv
	FNCALL	_PWM_setDutyCycle,___lmul
	FNCALL	_PWM_setDutyCycle,_get_PR2
	FNCALL	_PWM_inti,_timer_2_intialize
	FNCALL	_timer_2_intialize,_set_timer_2_postScaler
	FNCALL	_timer_2_intialize,_set_timer_2_preScaler
	FNROOT	_main
	FNCALL	_ISR_ExtCall,_adjusted_timer_0_second_count
	FNCALL	_adjusted_timer_0_second_count,___llmod
	FNCALL	_adjusted_timer_0_second_count,_get_timer_0_Ticks
	FNCALL	_adjusted_timer_0_second_count,_increment_timer_0_Ticks
	FNCALL	_adjusted_timer_0_second_count,_set_timer_0_Reg
	FNCALL	intlevel1,_ISR_ExtCall
	global	intlevel1
	FNROOT	intlevel1
	global	_current_preScaler
	global	_current_postScaler
psect	idataBANK0,class=CODE,space=0,delta=2,noexec
global __pidataBANK0
__pidataBANK0:
	file	"MCAL/TIMER/TIMER2/TIMER2.c"
	line	8

;initializer for _current_preScaler
	retlw	010h
	line	7

;initializer for _current_postScaler
	retlw	010h
	global	_count_ticks
	global	_interruptCount
	global	_delayTime
; #config settings
	config pad_punits      = on
	config apply_mask      = off
	config ignore_cmsgs    = off
	config default_configs = off
	config default_idlocs  = off
	file	"Lab_2.s"
	line	#
psect cinit,class=CODE,delta=2
global start_initialization
start_initialization:

global __initialization
__initialization:
psect	bssBANK0,class=BANK0,space=1,noexec
global __pbssBANK0
__pbssBANK0:
_count_ticks:
       ds      4

_interruptCount:
       ds      2

_delayTime:
       ds      1

_PTR_EXT_INTO_CALLBACK:
       ds      1

psect	dataBANK0,class=BANK0,space=1,noexec
global __pdataBANK0
__pdataBANK0:
	file	"MCAL/TIMER/TIMER2/TIMER2.c"
	line	8
_current_preScaler:
       ds      1

psect	dataBANK0
	file	"MCAL/TIMER/TIMER2/TIMER2.c"
	line	7
_current_postScaler:
       ds      1

	file	"Lab_2.s"
	line	#
; Initialize objects allocated to BANK0
	global __pidataBANK0
psect cinit,class=CODE,delta=2,merge=1
	fcall	__pidataBANK0+0		;fetch initializer
	movwf	__pdataBANK0+0&07fh		
	fcall	__pidataBANK0+1		;fetch initializer
	movwf	__pdataBANK0+1&07fh		
	line	#
; Clear objects allocated to BANK0
psect cinit,class=CODE,delta=2,merge=1
	clrf	((__pbssBANK0)+0)&07Fh
	clrf	((__pbssBANK0)+1)&07Fh
	clrf	((__pbssBANK0)+2)&07Fh
	clrf	((__pbssBANK0)+3)&07Fh
	clrf	((__pbssBANK0)+4)&07Fh
	clrf	((__pbssBANK0)+5)&07Fh
	clrf	((__pbssBANK0)+6)&07Fh
	clrf	((__pbssBANK0)+7)&07Fh
psect cinit,class=CODE,delta=2,merge=1
global end_of_initialization,__end_of__initialization

;End of C runtime variable initialization code

end_of_initialization:
__end_of__initialization:
clrf status
ljmp _main	;jump to C main() function
psect	cstackCOMMON,class=COMMON,space=1,noexec
global __pcstackCOMMON
__pcstackCOMMON:
?_MOTOR_Init:	; 1 bytes @ 0x0
?_PWM_setDutyCycle:	; 1 bytes @ 0x0
?_PWM_inti:	; 1 bytes @ 0x0
?_adjusted_timer_0_second_count:	; 1 bytes @ 0x0
?_set_timer_2_postScaler:	; 1 bytes @ 0x0
?_set_timer_2_preScaler:	; 1 bytes @ 0x0
?_setup:	; 1 bytes @ 0x0
?_main:	; 1 bytes @ 0x0
?_ISR_ExtCall:	; 1 bytes @ 0x0
?_set_timer_0_Reg:	; 1 bytes @ 0x0
?_increment_timer_0_Ticks:	; 1 bytes @ 0x0
?_set_period_timer_2_Reg:	; 1 bytes @ 0x0
?_get_PR2:	; 1 bytes @ 0x0
?_timer_2_intialize:	; 1 bytes @ 0x0
?_get_preScaler:	; 1 bytes @ 0x0
	global	?_get_timer_0_Ticks
?_get_timer_0_Ticks:	; 4 bytes @ 0x0
??_set_timer_0_Reg:	; 1 bytes @ 0x0
??_increment_timer_0_Ticks:	; 1 bytes @ 0x0
	ds	4
	global	?___llmod
?___llmod:	; 4 bytes @ 0x4
	global	___llmod@divisor
___llmod@divisor:	; 4 bytes @ 0x4
??_get_timer_0_Ticks:	; 1 bytes @ 0x4
	ds	4
	global	___llmod@dividend
___llmod@dividend:	; 4 bytes @ 0x8
	ds	4
??___llmod:	; 1 bytes @ 0xC
	ds	1
	global	___llmod@counter
___llmod@counter:	; 1 bytes @ 0xD
	ds	1
??_adjusted_timer_0_second_count:	; 1 bytes @ 0xE
psect	cstackBANK0,class=BANK0,space=1,noexec
global __pcstackBANK0
__pcstackBANK0:
??_ISR_ExtCall:	; 1 bytes @ 0x0
	ds	3
?_GPIO_SetPinDirection:	; 1 bytes @ 0x3
	global	?___lmul
?___lmul:	; 4 bytes @ 0x3
	global	GPIO_SetPinDirection@Pin
GPIO_SetPinDirection@Pin:	; 1 bytes @ 0x3
	global	set_period_timer_2_Reg@desired_value
set_period_timer_2_Reg@desired_value:	; 1 bytes @ 0x3
	global	set_timer_2_preScaler@PRESCALE_SELECT
set_timer_2_preScaler@PRESCALE_SELECT:	; 1 bytes @ 0x3
	global	set_timer_2_postScaler@POSTSCALE_SELECT
set_timer_2_postScaler@POSTSCALE_SELECT:	; 1 bytes @ 0x3
	global	___lmul@multiplier
___lmul@multiplier:	; 4 bytes @ 0x3
??_set_timer_2_postScaler:	; 1 bytes @ 0x3
??_set_timer_2_preScaler:	; 1 bytes @ 0x3
??_set_period_timer_2_Reg:	; 1 bytes @ 0x3
??_get_PR2:	; 1 bytes @ 0x3
??_get_preScaler:	; 1 bytes @ 0x3
	ds	1
	global	GPIO_SetPinDirection@Direction
GPIO_SetPinDirection@Direction:	; 1 bytes @ 0x4
??_PWM_inti:	; 1 bytes @ 0x4
??_timer_2_intialize:	; 1 bytes @ 0x4
	ds	1
??_GPIO_SetPinDirection:	; 1 bytes @ 0x5
	ds	1
	global	GPIO_SetPinDirection@Port
GPIO_SetPinDirection@Port:	; 1 bytes @ 0x6
	ds	1
	global	___lmul@multiplicand
___lmul@multiplicand:	; 4 bytes @ 0x7
	ds	4
??___lmul:	; 1 bytes @ 0xB
	ds	1
	global	___lmul@product
___lmul@product:	; 4 bytes @ 0xC
	ds	4
	global	?___lldiv
?___lldiv:	; 4 bytes @ 0x10
	global	___lldiv@divisor
___lldiv@divisor:	; 4 bytes @ 0x10
	ds	4
	global	___lldiv@dividend
___lldiv@dividend:	; 4 bytes @ 0x14
	ds	4
??___lldiv:	; 1 bytes @ 0x18
	ds	1
	global	___lldiv@quotient
___lldiv@quotient:	; 4 bytes @ 0x19
	ds	4
	global	___lldiv@counter
___lldiv@counter:	; 1 bytes @ 0x1D
	ds	1
?_PWM_setFrequency:	; 1 bytes @ 0x1E
	global	PWM_setFrequency@desired_frequency
PWM_setFrequency@desired_frequency:	; 4 bytes @ 0x1E
??_PWM_setDutyCycle:	; 1 bytes @ 0x1E
	ds	4
??_PWM_setFrequency:	; 1 bytes @ 0x22
	ds	2
	global	PWM_setDutyCycle@desired_dutyCycle
PWM_setDutyCycle@desired_dutyCycle:	; 1 bytes @ 0x24
	ds	1
	global	PWM_setDutyCycle@totalRegisterVal
PWM_setDutyCycle@totalRegisterVal:	; 4 bytes @ 0x25
	ds	5
	global	PWM_setFrequency@denominator
PWM_setFrequency@denominator:	; 4 bytes @ 0x2A
	ds	4
	global	PWM_setFrequency@pr2_value
PWM_setFrequency@pr2_value:	; 4 bytes @ 0x2E
	ds	4
??_MOTOR_Init:	; 1 bytes @ 0x32
??_setup:	; 1 bytes @ 0x32
??_main:	; 1 bytes @ 0x32
;!
;!Data Sizes:
;!    Strings     0
;!    Constant    0
;!    Data        2
;!    BSS         8
;!    Persistent  0
;!    Stack       0
;!
;!Auto Spaces:
;!    Space          Size  Autos    Used
;!    COMMON           14     14      14
;!    BANK0            80     50      60
;!    BANK1            80      0       0
;!    BANK3            96      0       0
;!    BANK2            96      0       0

;!
;!Pointer List with Targets:
;!
;!    PTR_EXT_INTO_CALLBACK	PTR FTN()void  size(1) Largest target is 1
;!		 -> NULL(), 
;!


;!
;!Critical Paths under _main in COMMON
;!
;!    None.
;!
;!Critical Paths under _ISR_ExtCall in COMMON
;!
;!    _adjusted_timer_0_second_count->___llmod
;!    ___llmod->_get_timer_0_Ticks
;!
;!Critical Paths under _main in BANK0
;!
;!    _MOTOR_Init->_PWM_setFrequency
;!    _PWM_setFrequency->___lldiv
;!    _PWM_setDutyCycle->___lldiv
;!    ___lldiv->___lmul
;!    _timer_2_intialize->_set_timer_2_postScaler
;!    _timer_2_intialize->_set_timer_2_preScaler
;!
;!Critical Paths under _ISR_ExtCall in BANK0
;!
;!    None.
;!
;!Critical Paths under _main in BANK1
;!
;!    None.
;!
;!Critical Paths under _ISR_ExtCall in BANK1
;!
;!    None.
;!
;!Critical Paths under _main in BANK3
;!
;!    None.
;!
;!Critical Paths under _ISR_ExtCall in BANK3
;!
;!    None.
;!
;!Critical Paths under _main in BANK2
;!
;!    None.
;!
;!Critical Paths under _ISR_ExtCall in BANK2
;!
;!    None.

;;
;;Main: autosize = 0, tempsize = 0, incstack = 0, save=0
;;

;!
;!Call Graph Tables:
;!
;! ---------------------------------------------------------------------------------
;! (Depth) Function   	        Calls       Base Space   Used Autos Params    Refs
;! ---------------------------------------------------------------------------------
;! (0) _main                                                 0     0      0    1639
;!                   _PWM_setDutyCycle
;!                              _setup
;! ---------------------------------------------------------------------------------
;! (1) _setup                                                0     0      0    1250
;!                         _MOTOR_Init
;! ---------------------------------------------------------------------------------
;! (2) _MOTOR_Init                                           0     0      0    1250
;!               _GPIO_SetPinDirection
;!                           _PWM_inti
;!                   _PWM_setDutyCycle
;!                   _PWM_setFrequency
;! ---------------------------------------------------------------------------------
;! (3) _PWM_setFrequency                                    20    16      4     382
;!                                             30 BANK0     20    16      4
;!                            ___lldiv
;!                             ___lmul
;!                      _get_preScaler
;!             _set_period_timer_2_Reg
;! ---------------------------------------------------------------------------------
;! (4) _set_period_timer_2_Reg                               1     1      0      29
;!                                              3 BANK0      1     1      0
;! ---------------------------------------------------------------------------------
;! (4) _get_preScaler                                        0     0      0       0
;! ---------------------------------------------------------------------------------
;! (3) _PWM_setDutyCycle                                    11    11      0     389
;!                                             30 BANK0     11    11      0
;!                            ___lldiv
;!                             ___lmul
;!                            _get_PR2
;! ---------------------------------------------------------------------------------
;! (4) _get_PR2                                              0     0      0       0
;! ---------------------------------------------------------------------------------
;! (4) ___lmul                                              13     5      8      96
;!                                              3 BANK0     13     5      8
;!                            _get_PR2 (ARG)
;!                      _get_preScaler (ARG)
;! ---------------------------------------------------------------------------------
;! (4) ___lldiv                                             14     6      8     166
;!                                             16 BANK0     14     6      8
;!                             ___lmul (ARG)
;!                            _get_PR2 (ARG)
;! ---------------------------------------------------------------------------------
;! (3) _PWM_inti                                             0     0      0     116
;!                  _timer_2_intialize
;! ---------------------------------------------------------------------------------
;! (4) _timer_2_intialize                                    0     0      0     116
;!             _set_timer_2_postScaler
;!              _set_timer_2_preScaler
;! ---------------------------------------------------------------------------------
;! (5) _set_timer_2_preScaler                                1     1      0      58
;!                                              3 BANK0      1     1      0
;! ---------------------------------------------------------------------------------
;! (5) _set_timer_2_postScaler                               1     1      0      58
;!                                              3 BANK0      1     1      0
;! ---------------------------------------------------------------------------------
;! (3) _GPIO_SetPinDirection                                 4     2      2     363
;!                                              3 BANK0      4     2      2
;! ---------------------------------------------------------------------------------
;! Estimated maximum stack depth 5
;! ---------------------------------------------------------------------------------
;! (Depth) Function   	        Calls       Base Space   Used Autos Params    Refs
;! ---------------------------------------------------------------------------------
;! (6) _ISR_ExtCall                                          3     3      0     161
;!                                              0 BANK0      3     3      0
;!      _adjusted_timer_0_second_count
;! ---------------------------------------------------------------------------------
;! (7) _adjusted_timer_0_second_count                        0     0      0     161
;!                            ___llmod
;!                  _get_timer_0_Ticks
;!            _increment_timer_0_Ticks
;!                    _set_timer_0_Reg
;! ---------------------------------------------------------------------------------
;! (8) _set_timer_0_Reg                                      0     0      0       0
;! ---------------------------------------------------------------------------------
;! (8) _increment_timer_0_Ticks                              0     0      0       0
;! ---------------------------------------------------------------------------------
;! (8) _get_timer_0_Ticks                                    4     0      4       0
;!                                              0 COMMON     4     0      4
;! ---------------------------------------------------------------------------------
;! (8) ___llmod                                             10     2      8     161
;!                                              4 COMMON    10     2      8
;!                  _get_timer_0_Ticks (ARG)
;! ---------------------------------------------------------------------------------
;! Estimated maximum stack depth 8
;! ---------------------------------------------------------------------------------
;!
;! Call Graph Graphs:
;!
;! _main (ROOT)
;!   _PWM_setDutyCycle
;!     ___lldiv
;!       ___lmul (ARG)
;!         _get_PR2 (ARG)
;!         _get_preScaler (ARG)
;!       _get_PR2 (ARG)
;!     ___lmul
;!     _get_PR2
;!   _setup
;!     _MOTOR_Init
;!       _GPIO_SetPinDirection
;!       _PWM_inti
;!         _timer_2_intialize
;!           _set_timer_2_postScaler
;!           _set_timer_2_preScaler
;!       _PWM_setDutyCycle
;!       _PWM_setFrequency
;!         ___lldiv
;!         ___lmul
;!         _get_preScaler
;!         _set_period_timer_2_Reg
;!
;! _ISR_ExtCall (ROOT)
;!   _adjusted_timer_0_second_count
;!     ___llmod
;!       _get_timer_0_Ticks (ARG)
;!     _get_timer_0_Ticks
;!     _increment_timer_0_Ticks
;!     _set_timer_0_Reg
;!

;!Address spaces:

;!Name               Size   Autos  Total    Usage
;!BANK3               96      0       0      0.0%
;!BITBANK3            96      0       0      0.0%
;!BANK2               96      0       0      0.0%
;!BITBANK2            96      0       0      0.0%
;!BANK1               80      0       0      0.0%
;!BITBANK1            80      0       0      0.0%
;!BANK0               80     50      60     75.0%
;!BITBANK0            80      0       0      0.0%
;!COMMON              14     14      14    100.0%
;!BITCOMMON           14      0       0      0.0%
;!DATA                 0      0      74      0.0%
;!STACK                0      0       0      0.0%

	global	_main

;; *************** function _main *****************
;; Defined at:
;;		line 83 in file "APP/main.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;                  1    wreg      void 
;; Registers used:
;;		wreg, fsr0l, fsr0h, status,2, status,0, pclath, cstack
;; Tracked objects:
;;		On entry : B00/0
;;		On exit  : 300/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK3   BANK2
;;      Params:         0       0       0       0       0
;;      Locals:         0       0       0       0       0
;;      Temps:          0       0       0       0       0
;;      Totals:         0       0       0       0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels required when called: 8
;; This function calls:
;;		_PWM_setDutyCycle
;;		_setup
;; This function is called by:
;;		Startup code after reset
;; This function uses a non-reentrant model
;;
psect	maintext,global,class=CODE,delta=2,split=1,group=0
	file	"APP/main.c"
	line	83
global __pmaintext
__pmaintext:	;psect for function _main
psect	maintext
	file	"APP/main.c"
	line	83
	
_main:	
;incstack = 0
	callstack 0
; Regs used in _main: [wreg-fsr0h+status,2+status,0+pclath+cstack]
	line	85
	
l1348:	
	fcall	_setup
	line	86
	
l1350:	
	movlw	low(0Ah)
	fcall	_PWM_setDutyCycle
	line	87
	
l12:	
	
l13:	
	goto	l12
	global	start
	ljmp	start
	callstack 0
	line	89
GLOBAL	__end_of_main
	__end_of_main:
	signat	_main,89
	global	_setup

;; *************** function _setup *****************
;; Defined at:
;;		line 75 in file "APP/main.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;                  1    wreg      void 
;; Registers used:
;;		wreg, fsr0l, fsr0h, status,2, status,0, pclath, cstack
;; Tracked objects:
;;		On entry : B00/0
;;		On exit  : 200/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK3   BANK2
;;      Params:         0       0       0       0       0
;;      Locals:         0       0       0       0       0
;;      Temps:          0       0       0       0       0
;;      Totals:         0       0       0       0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels used: 1
;; Hardware stack levels required when called: 7
;; This function calls:
;;		_MOTOR_Init
;; This function is called by:
;;		_main
;; This function uses a non-reentrant model
;;
psect	text1,local,class=CODE,delta=2,merge=1,group=0
	line	75
global __ptext1
__ptext1:	;psect for function _setup
psect	text1
	file	"APP/main.c"
	line	75
	
_setup:	
;incstack = 0
	callstack 0
; Regs used in _setup: [wreg-fsr0h+status,2+status,0+pclath+cstack]
	line	77
	
l1336:	
	fcall	_MOTOR_Init
	line	80
	
l7:	
	return
	callstack 0
GLOBAL	__end_of_setup
	__end_of_setup:
	signat	_setup,89
	global	_MOTOR_Init

;; *************** function _MOTOR_Init *****************
;; Defined at:
;;		line 12 in file "HAL/MOTOR/MOTOR.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;                  1    wreg      void 
;; Registers used:
;;		wreg, fsr0l, fsr0h, status,2, status,0, pclath, cstack
;; Tracked objects:
;;		On entry : B00/0
;;		On exit  : 200/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK3   BANK2
;;      Params:         0       0       0       0       0
;;      Locals:         0       0       0       0       0
;;      Temps:          0       0       0       0       0
;;      Totals:         0       0       0       0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels used: 1
;; Hardware stack levels required when called: 6
;; This function calls:
;;		_GPIO_SetPinDirection
;;		_PWM_inti
;;		_PWM_setDutyCycle
;;		_PWM_setFrequency
;; This function is called by:
;;		_setup
;; This function uses a non-reentrant model
;;
psect	text2,local,class=CODE,delta=2,merge=1,group=0
	file	"HAL/MOTOR/MOTOR.c"
	line	12
global __ptext2
__ptext2:	;psect for function _MOTOR_Init
psect	text2
	file	"HAL/MOTOR/MOTOR.c"
	line	12
	
_MOTOR_Init:	
;incstack = 0
	callstack 0
; Regs used in _MOTOR_Init: [wreg-fsr0h+status,2+status,0+pclath+cstack]
	line	15
	
l1304:	
	movlw	low(02h)
	movwf	(GPIO_SetPinDirection@Pin)
	clrf	(GPIO_SetPinDirection@Direction)
	incf	(GPIO_SetPinDirection@Direction),f
	movlw	low(02h)
	fcall	_GPIO_SetPinDirection
	line	17
	fcall	_PWM_inti
	line	18
	
l1306:	
	movlw	0
	movwf	(PWM_setFrequency@desired_frequency+3)
	movlw	0
	movwf	(PWM_setFrequency@desired_frequency+2)
	movlw	013h
	movwf	(PWM_setFrequency@desired_frequency+1)
	movlw	088h
	movwf	(PWM_setFrequency@desired_frequency)

	fcall	_PWM_setFrequency
	line	19
	
l1308:	
	movlw	low(0)
	fcall	_PWM_setDutyCycle
	line	21
	movlw	low(02h)
	movwf	(GPIO_SetPinDirection@Pin)
	clrf	(GPIO_SetPinDirection@Direction)
	movlw	low(02h)
	fcall	_GPIO_SetPinDirection
	line	22
	
l60:	
	return
	callstack 0
GLOBAL	__end_of_MOTOR_Init
	__end_of_MOTOR_Init:
	signat	_MOTOR_Init,89
	global	_PWM_setFrequency

;; *************** function _PWM_setFrequency *****************
;; Defined at:
;;		line 59 in file "MCAL/PWM/PWM.c"
;; Parameters:    Size  Location     Type
;;  desired_freq    4   30[BANK0 ] unsigned long 
;; Auto vars:     Size  Location     Type
;;  pr2_value       4   46[BANK0 ] unsigned long 
;;  denominator     4   42[BANK0 ] unsigned long 
;; Return value:  Size  Location     Type
;;                  1    wreg      void 
;; Registers used:
;;		wreg, status,2, status,0, pclath, cstack
;; Tracked objects:
;;		On entry : 300/0
;;		On exit  : 300/100
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK3   BANK2
;;      Params:         0       4       0       0       0
;;      Locals:         0       8       0       0       0
;;      Temps:          0       8       0       0       0
;;      Totals:         0      20       0       0       0
;;Total ram usage:       20 bytes
;; Hardware stack levels used: 1
;; Hardware stack levels required when called: 4
;; This function calls:
;;		___lldiv
;;		___lmul
;;		_get_preScaler
;;		_set_period_timer_2_Reg
;; This function is called by:
;;		_MOTOR_Init
;; This function uses a non-reentrant model
;;
psect	text3,local,class=CODE,delta=2,merge=1,group=0
	file	"MCAL/PWM/PWM.c"
	line	59
global __ptext3
__ptext3:	;psect for function _PWM_setFrequency
psect	text3
	file	"MCAL/PWM/PWM.c"
	line	59
	
_PWM_setFrequency:	
;incstack = 0
	callstack 1
; Regs used in _PWM_setFrequency: [wreg+status,2+status,0+pclath+cstack]
	line	61
	
l1296:	
	movf	(PWM_setFrequency@desired_frequency),w
	movwf	(??_PWM_setFrequency)
	movf	(PWM_setFrequency@desired_frequency+1),w
	movwf	((??_PWM_setFrequency)+1)
	movf	(PWM_setFrequency@desired_frequency+2),w
	movwf	((??_PWM_setFrequency)+2)
	movf	(PWM_setFrequency@desired_frequency+3),w
	movwf	((??_PWM_setFrequency)+3)
	movlw	02h
u805:
	clrc
	rlf	(??_PWM_setFrequency),f
	rlf	(??_PWM_setFrequency+1),f
	rlf	(??_PWM_setFrequency+2),f
	rlf	(??_PWM_setFrequency+3),f
u800:
	addlw	-1
	skipz
	goto	u805
	movf	(3+(??_PWM_setFrequency)),w
	movwf	(___lmul@multiplier+3)
	movf	(2+(??_PWM_setFrequency)),w
	movwf	(___lmul@multiplier+2)
	movf	(1+(??_PWM_setFrequency)),w
	movwf	(___lmul@multiplier+1)
	movf	(0+(??_PWM_setFrequency)),w
	movwf	(___lmul@multiplier)

	fcall	_get_preScaler
	movwf	(??_PWM_setFrequency+4)
	clrf	((??_PWM_setFrequency+4)+1)
	clrf	((??_PWM_setFrequency+4)+2)
	clrf	((??_PWM_setFrequency+4)+3)
	movf	(3+(??_PWM_setFrequency+4)),w
	movwf	(___lmul@multiplicand+3)
	movf	(2+(??_PWM_setFrequency+4)),w
	movwf	(___lmul@multiplicand+2)
	movf	(1+(??_PWM_setFrequency+4)),w
	movwf	(___lmul@multiplicand+1)
	movf	(0+(??_PWM_setFrequency+4)),w
	movwf	(___lmul@multiplicand)

	fcall	___lmul
	movf	(3+(?___lmul)),w
	movwf	(PWM_setFrequency@denominator+3)
	movf	(2+(?___lmul)),w
	movwf	(PWM_setFrequency@denominator+2)
	movf	(1+(?___lmul)),w
	movwf	(PWM_setFrequency@denominator+1)
	movf	(0+(?___lmul)),w
	movwf	(PWM_setFrequency@denominator)

	line	62
	movlw	0FFh
	movwf	((??_PWM_setFrequency))
	movlw	0FFh
	movwf	((??_PWM_setFrequency)+1)
	movlw	0FFh
	movwf	((??_PWM_setFrequency)+2)
	movlw	0FFh
	movwf	((??_PWM_setFrequency)+3)
	movf	(PWM_setFrequency@denominator+3),w
	movwf	(___lldiv@divisor+3)
	movf	(PWM_setFrequency@denominator+2),w
	movwf	(___lldiv@divisor+2)
	movf	(PWM_setFrequency@denominator+1),w
	movwf	(___lldiv@divisor+1)
	movf	(PWM_setFrequency@denominator),w
	movwf	(___lldiv@divisor)

	movlw	0
	movwf	(___lldiv@dividend+3)
	movlw	07Ah
	movwf	(___lldiv@dividend+2)
	movlw	012h
	movwf	(___lldiv@dividend+1)
	movlw	0
	movwf	(___lldiv@dividend)

	fcall	___lldiv
	movf	(0+(?___lldiv)),w
	addwf	(??_PWM_setFrequency),f
	movf	(1+(?___lldiv)),w
	skipnc
	incfsz	(1+(?___lldiv)),w
	goto	u810
	goto	u811
u810:
	addwf	(??_PWM_setFrequency+1),f
u811:
	movf	(2+(?___lldiv)),w
	skipnc
	incfsz	(2+(?___lldiv)),w
	goto	u812
	goto	u813
u812:
	addwf	(??_PWM_setFrequency+2),f
u813:
	movf	(3+(?___lldiv)),w
	skipnc
	incf	(3+(?___lldiv)),w
	addwf	(??_PWM_setFrequency+3),f
	movf	(3+(??_PWM_setFrequency)),w
	movwf	(PWM_setFrequency@pr2_value+3)
	movf	(2+(??_PWM_setFrequency)),w
	movwf	(PWM_setFrequency@pr2_value+2)
	movf	(1+(??_PWM_setFrequency)),w
	movwf	(PWM_setFrequency@pr2_value+1)
	movf	(0+(??_PWM_setFrequency)),w
	movwf	(PWM_setFrequency@pr2_value)

	line	68
	
l1298:	
		movf	(PWM_setFrequency@pr2_value+3),w
	btfss	status,2
	goto	u821
	movf	(PWM_setFrequency@pr2_value+2),w
	btfss	status,2
	goto	u821
	movlw	1
	subwf	(PWM_setFrequency@pr2_value+1),w
	skipz
	goto	u823
	movlw	0
	subwf	(PWM_setFrequency@pr2_value),w
	skipz
	goto	u823
u823:
	btfsc	status,0
	goto	u821
	goto	u820

u821:
	goto	l1302
u820:
	line	70
	
l1300:	
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	movf	(PWM_setFrequency@pr2_value),w
	fcall	_set_period_timer_2_Reg
	line	71
	goto	l284
	line	74
	
l1302:	
	movlw	low(0FFh)
	fcall	_set_period_timer_2_Reg
	line	76
	
l284:	
	return
	callstack 0
GLOBAL	__end_of_PWM_setFrequency
	__end_of_PWM_setFrequency:
	signat	_PWM_setFrequency,4217
	global	_set_period_timer_2_Reg

;; *************** function _set_period_timer_2_Reg *****************
;; Defined at:
;;		line 10 in file "MCAL/TIMER/TIMER2/TIMER2.c"
;; Parameters:    Size  Location     Type
;;  desired_valu    1    wreg     unsigned char 
;; Auto vars:     Size  Location     Type
;;  desired_valu    1    3[BANK0 ] unsigned char 
;; Return value:  Size  Location     Type
;;                  1    wreg      void 
;; Registers used:
;;		wreg
;; Tracked objects:
;;		On entry : 0/0
;;		On exit  : 300/100
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK3   BANK2
;;      Params:         0       0       0       0       0
;;      Locals:         0       1       0       0       0
;;      Temps:          0       0       0       0       0
;;      Totals:         0       1       0       0       0
;;Total ram usage:        1 bytes
;; Hardware stack levels used: 1
;; Hardware stack levels required when called: 3
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_PWM_setFrequency
;; This function uses a non-reentrant model
;;
psect	text4,local,class=CODE,delta=2,merge=1,group=0
	file	"MCAL/TIMER/TIMER2/TIMER2.c"
	line	10
global __ptext4
__ptext4:	;psect for function _set_period_timer_2_Reg
psect	text4
	file	"MCAL/TIMER/TIMER2/TIMER2.c"
	line	10
	
_set_period_timer_2_Reg:	
;incstack = 0
	callstack 1
; Regs used in _set_period_timer_2_Reg: [wreg]
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	movwf	(set_period_timer_2_Reg@desired_value)
	line	12
	
l1184:	
	movf	(set_period_timer_2_Reg@desired_value),w
	bsf	status, 5	;RP0=1, select bank1
	movwf	(146)^080h	;volatile
	line	13
	
l217:	
	return
	callstack 0
GLOBAL	__end_of_set_period_timer_2_Reg
	__end_of_set_period_timer_2_Reg:
	signat	_set_period_timer_2_Reg,4217
	global	_get_preScaler

;; *************** function _get_preScaler *****************
;; Defined at:
;;		line 30 in file "MCAL/TIMER/TIMER2/TIMER2.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;                  1    wreg      unsigned char 
;; Registers used:
;;		wreg
;; Tracked objects:
;;		On entry : 300/0
;;		On exit  : 300/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK3   BANK2
;;      Params:         0       0       0       0       0
;;      Locals:         0       0       0       0       0
;;      Temps:          0       0       0       0       0
;;      Totals:         0       0       0       0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels used: 1
;; Hardware stack levels required when called: 3
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_PWM_setFrequency
;; This function uses a non-reentrant model
;;
psect	text5,local,class=CODE,delta=2,merge=1,group=0
	line	30
global __ptext5
__ptext5:	;psect for function _get_preScaler
psect	text5
	file	"MCAL/TIMER/TIMER2/TIMER2.c"
	line	30
	
_get_preScaler:	
;incstack = 0
	callstack 1
; Regs used in _get_preScaler: [wreg]
	line	32
	
l1194:	
	movf	(_current_preScaler),w
	line	33
	
l226:	
	return
	callstack 0
GLOBAL	__end_of_get_preScaler
	__end_of_get_preScaler:
	signat	_get_preScaler,89
	global	_PWM_setDutyCycle

;; *************** function _PWM_setDutyCycle *****************
;; Defined at:
;;		line 20 in file "MCAL/PWM/PWM.c"
;; Parameters:    Size  Location     Type
;;  desired_duty    1    wreg     unsigned char 
;; Auto vars:     Size  Location     Type
;;  desired_duty    1   36[BANK0 ] unsigned char 
;;  totalRegiste    4   37[BANK0 ] unsigned long 
;; Return value:  Size  Location     Type
;;                  1    wreg      void 
;; Registers used:
;;		wreg, status,2, status,0, pclath, cstack
;; Tracked objects:
;;		On entry : 200/0
;;		On exit  : 300/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK3   BANK2
;;      Params:         0       0       0       0       0
;;      Locals:         0       5       0       0       0
;;      Temps:          0       6       0       0       0
;;      Totals:         0      11       0       0       0
;;Total ram usage:       11 bytes
;; Hardware stack levels used: 1
;; Hardware stack levels required when called: 3
;; This function calls:
;;		___lldiv
;;		___lmul
;;		_get_PR2
;; This function is called by:
;;		_main
;;		_MOTOR_Init
;; This function uses a non-reentrant model
;;
psect	text6,local,class=CODE,delta=2,merge=1,group=0
	file	"MCAL/PWM/PWM.c"
	line	20
global __ptext6
__ptext6:	;psect for function _PWM_setDutyCycle
psect	text6
	file	"MCAL/PWM/PWM.c"
	line	20
	
_PWM_setDutyCycle:	
;incstack = 0
	callstack 2
; Regs used in _PWM_setDutyCycle: [wreg+status,2+status,0+pclath+cstack]
	bcf	status, 5	;RP0=0, select bank0
	movwf	(PWM_setDutyCycle@desired_dutyCycle)
	line	23
	
l1236:	
	movlw	low(065h)
	subwf	(PWM_setDutyCycle@desired_dutyCycle),w
	skipc
	goto	u591
	goto	u590
u591:
	goto	l1240
u590:
	line	25
	
l1238:	
	movlw	064h
	movwf	(PWM_setDutyCycle@desired_dutyCycle)
	line	34
	
l1240:	
	movlw	0
	movwf	(___lldiv@divisor+3)
	movlw	0
	movwf	(___lldiv@divisor+2)
	movlw	0
	movwf	(___lldiv@divisor+1)
	movlw	064h
	movwf	(___lldiv@divisor)

	movf	(PWM_setDutyCycle@desired_dutyCycle),w
	movwf	(??_PWM_setDutyCycle)
	clrf	(??_PWM_setDutyCycle)+1
	clrf	(??_PWM_setDutyCycle)+2
	clrf	(??_PWM_setDutyCycle)+3
	movlw	02h
u605:
	clrc
	rlf	(??_PWM_setDutyCycle),f
	rlf	(??_PWM_setDutyCycle+1),f
	rlf	(??_PWM_setDutyCycle+2),f
	rlf	(??_PWM_setDutyCycle+3),f
u600:
	addlw	-1
	skipz
	goto	u605
	movf	(3+(??_PWM_setDutyCycle)),w
	movwf	(___lmul@multiplier+3)
	movf	(2+(??_PWM_setDutyCycle)),w
	movwf	(___lmul@multiplier+2)
	movf	(1+(??_PWM_setDutyCycle)),w
	movwf	(___lmul@multiplier+1)
	movf	(0+(??_PWM_setDutyCycle)),w
	movwf	(___lmul@multiplier)

	fcall	_get_PR2
	addlw	low(01h)
	bcf	status, 5	;RP0=0, select bank0
	movwf	(??_PWM_setDutyCycle+4)
	movlw	high(01h)
	skipnc
	movlw	(high(01h)+1)&0ffh
	movwf	((??_PWM_setDutyCycle+4))+1
	movf	(0+(??_PWM_setDutyCycle+4)),w
	movwf	(___lmul@multiplicand)
	movf	(1+(??_PWM_setDutyCycle+4)),w
	movwf	(___lmul@multiplicand+1)
	movlw	0
	btfsc	(___lmul@multiplicand+1),7
	movlw	255
	movwf	(___lmul@multiplicand+2)
	movwf	(___lmul@multiplicand+3)
	fcall	___lmul
	movf	(3+(?___lmul)),w
	movwf	(___lldiv@dividend+3)
	movf	(2+(?___lmul)),w
	movwf	(___lldiv@dividend+2)
	movf	(1+(?___lmul)),w
	movwf	(___lldiv@dividend+1)
	movf	(0+(?___lmul)),w
	movwf	(___lldiv@dividend)

	fcall	___lldiv
	movf	(3+(?___lldiv)),w
	movwf	(PWM_setDutyCycle@totalRegisterVal+3)
	movf	(2+(?___lldiv)),w
	movwf	(PWM_setDutyCycle@totalRegisterVal+2)
	movf	(1+(?___lldiv)),w
	movwf	(PWM_setDutyCycle@totalRegisterVal+1)
	movf	(0+(?___lldiv)),w
	movwf	(PWM_setDutyCycle@totalRegisterVal)

	line	36
	
l1242:	
	movf	(PWM_setDutyCycle@totalRegisterVal),w
	movwf	(??_PWM_setDutyCycle)
	movf	(PWM_setDutyCycle@totalRegisterVal+1),w
	movwf	((??_PWM_setDutyCycle)+1)
	movf	(PWM_setDutyCycle@totalRegisterVal+2),w
	movwf	((??_PWM_setDutyCycle)+2)
	movf	(PWM_setDutyCycle@totalRegisterVal+3),w
	movwf	((??_PWM_setDutyCycle)+3)
	movlw	02h
u615:
	clrc
	rrf	(??_PWM_setDutyCycle+3),f
	rrf	(??_PWM_setDutyCycle+2),f
	rrf	(??_PWM_setDutyCycle+1),f
	rrf	(??_PWM_setDutyCycle),f
u610:
	addlw	-1
	skipz
	goto	u615
	movf	(0+(??_PWM_setDutyCycle)),w
	movwf	(21)	;volatile
	line	38
	
l1244:	
	btfss	(PWM_setDutyCycle@totalRegisterVal),(0)&7
	goto	u621
	goto	u620
u621:
	goto	l1248
u620:
	line	40
	
l1246:	
	bsf	(23)+(4/8),(4)&7	;volatile
	line	41
	goto	l276
	line	44
	
l1248:	
	movlw	low(0EFh)
	andwf	(23),f	;volatile
	line	45
	
l276:	
	line	47
	movf	(PWM_setDutyCycle@totalRegisterVal),w
	movwf	(??_PWM_setDutyCycle)
	movlw	01h
u635:
	clrc
	rrf	(??_PWM_setDutyCycle),f
	addlw	-1
	skipz
	goto	u635
	btfss	(0+(??_PWM_setDutyCycle)),(0)&7
	goto	u641
	goto	u640
u641:
	goto	l1252
u640:
	line	49
	
l1250:	
	bsf	(23)+(5/8),(5)&7	;volatile
	line	50
	goto	l279
	line	53
	
l1252:	
	movlw	low(0DFh)
	andwf	(23),f	;volatile
	line	56
	
l279:	
	return
	callstack 0
GLOBAL	__end_of_PWM_setDutyCycle
	__end_of_PWM_setDutyCycle:
	signat	_PWM_setDutyCycle,4217
	global	_get_PR2

;; *************** function _get_PR2 *****************
;; Defined at:
;;		line 15 in file "MCAL/TIMER/TIMER2/TIMER2.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;                  1    wreg      unsigned char 
;; Registers used:
;;		wreg
;; Tracked objects:
;;		On entry : 300/0
;;		On exit  : 300/100
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK3   BANK2
;;      Params:         0       0       0       0       0
;;      Locals:         0       0       0       0       0
;;      Temps:          0       0       0       0       0
;;      Totals:         0       0       0       0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels used: 1
;; Hardware stack levels required when called: 3
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_PWM_setDutyCycle
;; This function uses a non-reentrant model
;;
psect	text7,local,class=CODE,delta=2,merge=1,group=0
	file	"MCAL/TIMER/TIMER2/TIMER2.c"
	line	15
global __ptext7
__ptext7:	;psect for function _get_PR2
psect	text7
	file	"MCAL/TIMER/TIMER2/TIMER2.c"
	line	15
	
_get_PR2:	
;incstack = 0
	callstack 1
; Regs used in _get_PR2: [wreg]
	line	17
	
l1186:	
	bsf	status, 5	;RP0=1, select bank1
	movf	(146)^080h,w	;volatile
	line	18
	
l220:	
	return
	callstack 0
GLOBAL	__end_of_get_PR2
	__end_of_get_PR2:
	signat	_get_PR2,89
	global	___lmul

;; *************** function ___lmul *****************
;; Defined at:
;;		line 15 in file "C:\Program Files\Microchip\xc8\v3.10\pic\sources\c99\common\Umul32.c"
;; Parameters:    Size  Location     Type
;;  multiplier      4    3[BANK0 ] unsigned long 
;;  multiplicand    4    7[BANK0 ] unsigned long 
;; Auto vars:     Size  Location     Type
;;  product         4   12[BANK0 ] unsigned long 
;; Return value:  Size  Location     Type
;;                  4    3[BANK0 ] unsigned long 
;; Registers used:
;;		wreg, status,2, status,0
;; Tracked objects:
;;		On entry : 300/0
;;		On exit  : 300/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK3   BANK2
;;      Params:         0       8       0       0       0
;;      Locals:         0       4       0       0       0
;;      Temps:          0       1       0       0       0
;;      Totals:         0      13       0       0       0
;;Total ram usage:       13 bytes
;; Hardware stack levels used: 1
;; Hardware stack levels required when called: 3
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_PWM_setDutyCycle
;;		_PWM_setFrequency
;; This function uses a non-reentrant model
;;
psect	text8,local,class=CODE,delta=2,merge=1,group=1
	file	"C:\Program Files\Microchip\xc8\v3.10\pic\sources\c99\common\Umul32.c"
	line	15
global __ptext8
__ptext8:	;psect for function ___lmul
psect	text8
	file	"C:\Program Files\Microchip\xc8\v3.10\pic\sources\c99\common\Umul32.c"
	line	15
	
___lmul:	
;incstack = 0
	callstack 1
; Regs used in ___lmul: [wreg+status,2+status,0]
	line	119
	
l1198:	
	movlw	high highword(0)
	movwf	(___lmul@product+3)
	movlw	low highword(0)
	movwf	(___lmul@product+2)
	movlw	high(0)
	movwf	(___lmul@product+1)
	movlw	low(0)
	movwf	(___lmul@product)

	line	121
	
l1200:	
	btfss	(___lmul@multiplier),(0)&7
	goto	u471
	goto	u470
u471:
	goto	l1204
u470:
	line	122
	
l1202:	
	movf	(___lmul@multiplicand),w
	addwf	(___lmul@product),f
	movf	(___lmul@multiplicand+1),w
	clrz
	skipnc
	addlw	1
	skipnz
	goto	u481
	addwf	(___lmul@product+1),f
u481:
	movf	(___lmul@multiplicand+2),w
	clrz
	skipnc
	addlw	1
	skipnz
	goto	u482
	addwf	(___lmul@product+2),f
u482:
	movf	(___lmul@multiplicand+3),w
	clrz
	skipnc
	addlw	1
	skipnz
	goto	u483
	addwf	(___lmul@product+3),f
u483:

	line	123
	
l1204:	
	movlw	01h
	movwf	(??___lmul)
u495:
	clrc
	rlf	(___lmul@multiplicand),f
	rlf	(___lmul@multiplicand+1),f
	rlf	(___lmul@multiplicand+2),f
	rlf	(___lmul@multiplicand+3),f
	decfsz	(??___lmul)
	goto	u495
	line	124
	
l1206:	
	movlw	01h
u505:
	clrc
	rrf	(___lmul@multiplier+3),f
	rrf	(___lmul@multiplier+2),f
	rrf	(___lmul@multiplier+1),f
	rrf	(___lmul@multiplier),f
	addlw	-1
	skipz
	goto	u505

	line	125
	movf	(___lmul@multiplier+3),w
	iorwf	(___lmul@multiplier+2),w
	iorwf	(___lmul@multiplier+1),w
	iorwf	(___lmul@multiplier),w
	skipz
	goto	u511
	goto	u510
u511:
	goto	l1200
u510:
	line	128
	
l1208:	
	movf	(___lmul@product+3),w
	movwf	(?___lmul+3)
	movf	(___lmul@product+2),w
	movwf	(?___lmul+2)
	movf	(___lmul@product+1),w
	movwf	(?___lmul+1)
	movf	(___lmul@product),w
	movwf	(?___lmul)

	line	129
	
l384:	
	return
	callstack 0
GLOBAL	__end_of___lmul
	__end_of___lmul:
	signat	___lmul,8316
	global	___lldiv

;; *************** function ___lldiv *****************
;; Defined at:
;;		line 5 in file "C:\Program Files\Microchip\xc8\v3.10\pic\sources\c99\common\__lldiv.c"
;; Parameters:    Size  Location     Type
;;  divisor         4   16[BANK0 ] unsigned long 
;;  dividend        4   20[BANK0 ] unsigned long 
;; Auto vars:     Size  Location     Type
;;  quotient        4   25[BANK0 ] unsigned long 
;;  counter         1   29[BANK0 ] unsigned char 
;; Return value:  Size  Location     Type
;;                  4   16[BANK0 ] unsigned long 
;; Registers used:
;;		wreg, status,2, status,0
;; Tracked objects:
;;		On entry : 300/0
;;		On exit  : 300/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK3   BANK2
;;      Params:         0       8       0       0       0
;;      Locals:         0       5       0       0       0
;;      Temps:          0       1       0       0       0
;;      Totals:         0      14       0       0       0
;;Total ram usage:       14 bytes
;; Hardware stack levels used: 1
;; Hardware stack levels required when called: 3
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_PWM_setDutyCycle
;;		_PWM_setFrequency
;; This function uses a non-reentrant model
;;
psect	text9,local,class=CODE,delta=2,merge=1,group=1
	file	"C:\Program Files\Microchip\xc8\v3.10\pic\sources\c99\common\__lldiv.c"
	line	5
global __ptext9
__ptext9:	;psect for function ___lldiv
psect	text9
	file	"C:\Program Files\Microchip\xc8\v3.10\pic\sources\c99\common\__lldiv.c"
	line	5
	
___lldiv:	
;incstack = 0
	callstack 1
; Regs used in ___lldiv: [wreg+status,2+status,0]
	line	13
	
l1212:	
	movlw	high highword(0)
	movwf	(___lldiv@quotient+3)
	movlw	low highword(0)
	movwf	(___lldiv@quotient+2)
	movlw	high(0)
	movwf	(___lldiv@quotient+1)
	movlw	low(0)
	movwf	(___lldiv@quotient)

	line	14
	movf	(___lldiv@divisor+3),w
	iorwf	(___lldiv@divisor+2),w
	iorwf	(___lldiv@divisor+1),w
	iorwf	(___lldiv@divisor),w
	skipnz
	goto	u521
	goto	u520
u521:
	goto	l1232
u520:
	line	15
	
l1214:	
	movlw	01h
	movwf	(___lldiv@counter)
	line	16
	goto	l1218
	line	17
	
l1216:	
	movlw	01h
	movwf	(??___lldiv)
u535:
	clrc
	rlf	(___lldiv@divisor),f
	rlf	(___lldiv@divisor+1),f
	rlf	(___lldiv@divisor+2),f
	rlf	(___lldiv@divisor+3),f
	decfsz	(??___lldiv)
	goto	u535
	line	18
	movlw	low(01h)
	addwf	(___lldiv@counter),f
	line	16
	
l1218:	
	btfss	(___lldiv@divisor+3),(31)&7
	goto	u541
	goto	u540
u541:
	goto	l1216
u540:
	line	21
	
l1220:	
	movlw	01h
	movwf	(??___lldiv)
u555:
	clrc
	rlf	(___lldiv@quotient),f
	rlf	(___lldiv@quotient+1),f
	rlf	(___lldiv@quotient+2),f
	rlf	(___lldiv@quotient+3),f
	decfsz	(??___lldiv)
	goto	u555
	line	22
	
l1222:	
	movf	(___lldiv@divisor+3),w
	subwf	(___lldiv@dividend+3),w
	skipz
	goto	u565
	movf	(___lldiv@divisor+2),w
	subwf	(___lldiv@dividend+2),w
	skipz
	goto	u565
	movf	(___lldiv@divisor+1),w
	subwf	(___lldiv@dividend+1),w
	skipz
	goto	u565
	movf	(___lldiv@divisor),w
	subwf	(___lldiv@dividend),w
u565:
	skipc
	goto	u561
	goto	u560
u561:
	goto	l1228
u560:
	line	23
	
l1224:	
	movf	(___lldiv@divisor),w
	subwf	(___lldiv@dividend),f
	movf	(___lldiv@divisor+1),w
	skipc
	incfsz	(___lldiv@divisor+1),w
	subwf	(___lldiv@dividend+1),f
	movf	(___lldiv@divisor+2),w
	skipc
	incfsz	(___lldiv@divisor+2),w
	subwf	(___lldiv@dividend+2),f
	movf	(___lldiv@divisor+3),w
	skipc
	incfsz	(___lldiv@divisor+3),w
	subwf	(___lldiv@dividend+3),f
	line	24
	
l1226:	
	bsf	(___lldiv@quotient)+(0/8),(0)&7
	line	26
	
l1228:	
	movlw	01h
u575:
	clrc
	rrf	(___lldiv@divisor+3),f
	rrf	(___lldiv@divisor+2),f
	rrf	(___lldiv@divisor+1),f
	rrf	(___lldiv@divisor),f
	addlw	-1
	skipz
	goto	u575

	line	27
	
l1230:	
	movlw	01h
	subwf	(___lldiv@counter),f
	btfss	status,2
	goto	u581
	goto	u580
u581:
	goto	l1220
u580:
	line	29
	
l1232:	
	movf	(___lldiv@quotient+3),w
	movwf	(?___lldiv+3)
	movf	(___lldiv@quotient+2),w
	movwf	(?___lldiv+2)
	movf	(___lldiv@quotient+1),w
	movwf	(?___lldiv+1)
	movf	(___lldiv@quotient),w
	movwf	(?___lldiv)

	line	30
	
l406:	
	return
	callstack 0
GLOBAL	__end_of___lldiv
	__end_of___lldiv:
	signat	___lldiv,8316
	global	_PWM_inti

;; *************** function _PWM_inti *****************
;; Defined at:
;;		line 9 in file "MCAL/PWM/PWM.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;                  1    wreg      void 
;; Registers used:
;;		wreg, fsr0l, fsr0h, status,2, status,0, pclath, cstack
;; Tracked objects:
;;		On entry : 200/0
;;		On exit  : 300/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK3   BANK2
;;      Params:         0       0       0       0       0
;;      Locals:         0       0       0       0       0
;;      Temps:          0       0       0       0       0
;;      Totals:         0       0       0       0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels used: 1
;; Hardware stack levels required when called: 5
;; This function calls:
;;		_timer_2_intialize
;; This function is called by:
;;		_MOTOR_Init
;; This function uses a non-reentrant model
;;
psect	text10,local,class=CODE,delta=2,merge=1,group=0
	file	"MCAL/PWM/PWM.c"
	line	9
global __ptext10
__ptext10:	;psect for function _PWM_inti
psect	text10
	file	"MCAL/PWM/PWM.c"
	line	9
	
_PWM_inti:	
;incstack = 0
	callstack 0
; Regs used in _PWM_inti: [wreg-fsr0h+status,2+status,0+pclath+cstack]
	line	11
	
l1290:	
	bcf	status, 5	;RP0=0, select bank0
	bsf	(23)+(3/8),(3)&7	;volatile
	line	12
	bsf	(23)+(2/8),(2)&7	;volatile
	line	13
	
l1292:	
	movlw	low(0FDh)
	andwf	(23),f	;volatile
	line	14
	movlw	low(0FEh)
	andwf	(23),f	;volatile
	line	16
	
l1294:	
	fcall	_timer_2_intialize
	line	17
	
l271:	
	return
	callstack 0
GLOBAL	__end_of_PWM_inti
	__end_of_PWM_inti:
	signat	_PWM_inti,89
	global	_timer_2_intialize

;; *************** function _timer_2_intialize *****************
;; Defined at:
;;		line 20 in file "MCAL/TIMER/TIMER2/TIMER2.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;                  1    wreg      void 
;; Registers used:
;;		wreg, fsr0l, fsr0h, status,2, status,0, pclath, cstack
;; Tracked objects:
;;		On entry : 300/0
;;		On exit  : 300/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK3   BANK2
;;      Params:         0       0       0       0       0
;;      Locals:         0       0       0       0       0
;;      Temps:          0       0       0       0       0
;;      Totals:         0       0       0       0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels used: 1
;; Hardware stack levels required when called: 4
;; This function calls:
;;		_set_timer_2_postScaler
;;		_set_timer_2_preScaler
;; This function is called by:
;;		_PWM_inti
;; This function uses a non-reentrant model
;;
psect	text11,local,class=CODE,delta=2,merge=1,group=0
	file	"MCAL/TIMER/TIMER2/TIMER2.c"
	line	20
global __ptext11
__ptext11:	;psect for function _timer_2_intialize
psect	text11
	file	"MCAL/TIMER/TIMER2/TIMER2.c"
	line	20
	
_timer_2_intialize:	
;incstack = 0
	callstack 0
; Regs used in _timer_2_intialize: [wreg-fsr0h+status,2+status,0+pclath+cstack]
	line	23
	
l1190:	
	bsf	(18)+(2/8),(2)&7	;volatile
	line	25
	
l1192:	
	movlw	low(010h)
	fcall	_set_timer_2_postScaler
	line	27
	movlw	low(010h)
	fcall	_set_timer_2_preScaler
	line	28
	
l223:	
	return
	callstack 0
GLOBAL	__end_of_timer_2_intialize
	__end_of_timer_2_intialize:
	signat	_timer_2_intialize,89
	global	_set_timer_2_preScaler

;; *************** function _set_timer_2_preScaler *****************
;; Defined at:
;;		line 40 in file "MCAL/TIMER/TIMER2/TIMER2.c"
;; Parameters:    Size  Location     Type
;;  PRESCALE_SEL    1    wreg     unsigned char 
;; Auto vars:     Size  Location     Type
;;  PRESCALE_SEL    1    3[BANK0 ] unsigned char 
;; Return value:  Size  Location     Type
;;                  1    wreg      void 
;; Registers used:
;;		wreg, fsr0l, fsr0h, status,2, status,0
;; Tracked objects:
;;		On entry : 300/0
;;		On exit  : 300/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK3   BANK2
;;      Params:         0       0       0       0       0
;;      Locals:         0       1       0       0       0
;;      Temps:          0       0       0       0       0
;;      Totals:         0       1       0       0       0
;;Total ram usage:        1 bytes
;; Hardware stack levels used: 1
;; Hardware stack levels required when called: 3
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_timer_2_intialize
;; This function uses a non-reentrant model
;;
psect	text12,local,class=CODE,delta=2,merge=1,group=0
	line	40
global __ptext12
__ptext12:	;psect for function _set_timer_2_preScaler
psect	text12
	file	"MCAL/TIMER/TIMER2/TIMER2.c"
	line	40
	
_set_timer_2_preScaler:	
;incstack = 0
	callstack 0
; Regs used in _set_timer_2_preScaler: [wreg-fsr0h+status,2+status,0]
	movwf	(set_timer_2_preScaler@PRESCALE_SELECT)
	line	44
	
l1166:	
	goto	l1180
	line	48
	
l1168:	
	movlw	low(0FDh)
	andwf	(18),f	;volatile
	line	49
	movlw	low(0FEh)
	andwf	(18),f	;volatile
	line	50
	goto	l1182
	line	54
	
l1170:	
	movlw	low(0FDh)
	andwf	(18),f	;volatile
	line	55
	
l1172:	
	bsf	(18)+(0/8),(0)&7	;volatile
	line	56
	goto	l1182
	line	58
	
l236:	
	line	60
	bsf	(18)+(1/8),(1)&7	;volatile
	line	61
	
l1174:	
	movlw	low(0FEh)
	andwf	(18),f	;volatile
	line	62
	goto	l1182
	line	69
	
l1180:	
	movf	(set_timer_2_preScaler@PRESCALE_SELECT),w
	; Switch size 1, requested type "simple"
; Number of cases is 3, Range of values is 1 to 16
; switch strategies available:
; Name         Instructions Cycles
; simple_byte           10     6 (average)
; direct_byte           59    11 (fixed)
; jumptable            263     9 (fixed)
;	Chosen strategy is simple_byte

	asmopt push
	asmopt off
	xorlw	1^0	; case 1
	skipnz
	goto	l1168
	xorlw	4^1	; case 4
	skipnz
	goto	l1170
	xorlw	16^4	; case 16
	skipnz
	goto	l236
	goto	l236
	asmopt pop

	line	70
	
l1182:	
	movf	(set_timer_2_preScaler@PRESCALE_SELECT),w
	movwf	(_current_preScaler)
	line	71
	
l238:	
	return
	callstack 0
GLOBAL	__end_of_set_timer_2_preScaler
	__end_of_set_timer_2_preScaler:
	signat	_set_timer_2_preScaler,4217
	global	_set_timer_2_postScaler

;; *************** function _set_timer_2_postScaler *****************
;; Defined at:
;;		line 73 in file "MCAL/TIMER/TIMER2/TIMER2.c"
;; Parameters:    Size  Location     Type
;;  POSTSCALE_SE    1    wreg     unsigned char 
;; Auto vars:     Size  Location     Type
;;  POSTSCALE_SE    1    3[BANK0 ] unsigned char 
;; Return value:  Size  Location     Type
;;                  1    wreg      void 
;; Registers used:
;;		wreg, fsr0l, fsr0h, status,2, status,0
;; Tracked objects:
;;		On entry : 300/0
;;		On exit  : 300/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK3   BANK2
;;      Params:         0       0       0       0       0
;;      Locals:         0       1       0       0       0
;;      Temps:          0       0       0       0       0
;;      Totals:         0       1       0       0       0
;;Total ram usage:        1 bytes
;; Hardware stack levels used: 1
;; Hardware stack levels required when called: 3
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_timer_2_intialize
;; This function uses a non-reentrant model
;;
psect	text13,local,class=CODE,delta=2,merge=1,group=0
	line	73
global __ptext13
__ptext13:	;psect for function _set_timer_2_postScaler
psect	text13
	file	"MCAL/TIMER/TIMER2/TIMER2.c"
	line	73
	
_set_timer_2_postScaler:	
;incstack = 0
	callstack 0
; Regs used in _set_timer_2_postScaler: [wreg-fsr0h+status,2+status,0]
	movwf	(set_timer_2_postScaler@POSTSCALE_SELECT)
	line	77
	
l1094:	
	goto	l1162
	line	81
	
l1096:	
	movlw	low(0BFh)
	andwf	(18),f	;volatile
	line	82
	movlw	low(0DFh)
	andwf	(18),f	;volatile
	line	83
	movlw	low(0EFh)
	andwf	(18),f	;volatile
	line	84
	movlw	low(0F7h)
	andwf	(18),f	;volatile
	line	85
	goto	l1164
	line	89
	
l1098:	
	movlw	low(0BFh)
	andwf	(18),f	;volatile
	line	90
	movlw	low(0DFh)
	andwf	(18),f	;volatile
	line	91
	movlw	low(0EFh)
	andwf	(18),f	;volatile
	line	92
	
l1100:	
	bsf	(18)+(3/8),(3)&7	;volatile
	line	93
	goto	l1164
	line	97
	
l1102:	
	movlw	low(0BFh)
	andwf	(18),f	;volatile
	line	98
	movlw	low(0DFh)
	andwf	(18),f	;volatile
	line	99
	
l1104:	
	bsf	(18)+(4/8),(4)&7	;volatile
	line	100
	movlw	low(0F7h)
	andwf	(18),f	;volatile
	line	101
	goto	l1164
	line	105
	
l1106:	
	movlw	low(0BFh)
	andwf	(18),f	;volatile
	line	106
	movlw	low(0DFh)
	andwf	(18),f	;volatile
	line	107
	
l1108:	
	bsf	(18)+(4/8),(4)&7	;volatile
	goto	l1100
	line	113
	
l1112:	
	movlw	low(0BFh)
	andwf	(18),f	;volatile
	line	114
	
l1114:	
	bsf	(18)+(5/8),(5)&7	;volatile
	line	115
	movlw	low(0EFh)
	andwf	(18),f	;volatile
	line	116
	movlw	low(0F7h)
	andwf	(18),f	;volatile
	line	117
	goto	l1164
	line	121
	
l1116:	
	movlw	low(0BFh)
	andwf	(18),f	;volatile
	line	122
	
l1118:	
	bsf	(18)+(5/8),(5)&7	;volatile
	line	123
	movlw	low(0EFh)
	andwf	(18),f	;volatile
	goto	l1100
	line	129
	
l1122:	
	movlw	low(0BFh)
	andwf	(18),f	;volatile
	line	130
	
l1124:	
	bsf	(18)+(5/8),(5)&7	;volatile
	goto	l1104
	line	137
	
l1128:	
	movlw	low(0BFh)
	andwf	(18),f	;volatile
	line	138
	
l1130:	
	bsf	(18)+(5/8),(5)&7	;volatile
	goto	l1108
	line	143
	
l251:	
	line	145
	bsf	(18)+(6/8),(6)&7	;volatile
	line	146
	
l1136:	
	movlw	low(0DFh)
	andwf	(18),f	;volatile
	line	147
	movlw	low(0EFh)
	andwf	(18),f	;volatile
	line	148
	movlw	low(0F7h)
	andwf	(18),f	;volatile
	line	149
	goto	l1164
	line	151
	
l252:	
	line	153
	bsf	(18)+(6/8),(6)&7	;volatile
	line	154
	
l1138:	
	movlw	low(0DFh)
	andwf	(18),f	;volatile
	line	155
	movlw	low(0EFh)
	andwf	(18),f	;volatile
	goto	l1100
	line	159
	
l253:	
	line	161
	bsf	(18)+(6/8),(6)&7	;volatile
	line	162
	
l1142:	
	movlw	low(0DFh)
	andwf	(18),f	;volatile
	goto	l1104
	line	167
	
l254:	
	line	169
	bsf	(18)+(6/8),(6)&7	;volatile
	line	170
	
l1146:	
	movlw	low(0DFh)
	andwf	(18),f	;volatile
	goto	l1108
	line	175
	
l255:	
	line	177
	bsf	(18)+(6/8),(6)&7	;volatile
	line	178
	bsf	(18)+(5/8),(5)&7	;volatile
	line	179
	
l1152:	
	movlw	low(0EFh)
	andwf	(18),f	;volatile
	line	180
	movlw	low(0F7h)
	andwf	(18),f	;volatile
	line	181
	goto	l1164
	line	183
	
l256:	
	line	185
	bsf	(18)+(6/8),(6)&7	;volatile
	line	186
	bsf	(18)+(5/8),(5)&7	;volatile
	line	187
	
l1154:	
	movlw	low(0EFh)
	andwf	(18),f	;volatile
	goto	l1100
	line	191
	
l257:	
	line	193
	bsf	(18)+(6/8),(6)&7	;volatile
	line	194
	bsf	(18)+(5/8),(5)&7	;volatile
	line	195
	bsf	(18)+(4/8),(4)&7	;volatile
	line	196
	
l1158:	
	movlw	low(0F7h)
	andwf	(18),f	;volatile
	line	197
	goto	l1164
	line	199
	
l258:	
	line	201
	bsf	(18)+(6/8),(6)&7	;volatile
	line	202
	bsf	(18)+(5/8),(5)&7	;volatile
	line	203
	bsf	(18)+(4/8),(4)&7	;volatile
	line	204
	bsf	(18)+(3/8),(3)&7	;volatile
	line	205
	goto	l1164
	line	214
	
l1162:	
	movf	(set_timer_2_postScaler@POSTSCALE_SELECT),w
	; Switch size 1, requested type "simple"
; Number of cases is 16, Range of values is 1 to 16
; switch strategies available:
; Name         Instructions Cycles
; simple_byte           49    25 (average)
; direct_byte           59    11 (fixed)
; jumptable            263     9 (fixed)
;	Chosen strategy is simple_byte

	asmopt push
	asmopt off
	xorlw	1^0	; case 1
	skipnz
	goto	l1096
	xorlw	2^1	; case 2
	skipnz
	goto	l1098
	xorlw	3^2	; case 3
	skipnz
	goto	l1102
	xorlw	4^3	; case 4
	skipnz
	goto	l1106
	xorlw	5^4	; case 5
	skipnz
	goto	l1112
	xorlw	6^5	; case 6
	skipnz
	goto	l1116
	xorlw	7^6	; case 7
	skipnz
	goto	l1122
	xorlw	8^7	; case 8
	skipnz
	goto	l1128
	xorlw	9^8	; case 9
	skipnz
	goto	l251
	xorlw	10^9	; case 10
	skipnz
	goto	l252
	xorlw	11^10	; case 11
	skipnz
	goto	l253
	xorlw	12^11	; case 12
	skipnz
	goto	l254
	xorlw	13^12	; case 13
	skipnz
	goto	l255
	xorlw	14^13	; case 14
	skipnz
	goto	l256
	xorlw	15^14	; case 15
	skipnz
	goto	l257
	xorlw	16^15	; case 16
	skipnz
	goto	l258
	goto	l258
	asmopt pop

	line	215
	
l1164:	
	movf	(set_timer_2_postScaler@POSTSCALE_SELECT),w
	movwf	(_current_postScaler)
	line	216
	
l260:	
	return
	callstack 0
GLOBAL	__end_of_set_timer_2_postScaler
	__end_of_set_timer_2_postScaler:
	signat	_set_timer_2_postScaler,4217
	global	_GPIO_SetPinDirection

;; *************** function _GPIO_SetPinDirection *****************
;; Defined at:
;;		line 8 in file "MCAL/GPIO/GPIO.c"
;; Parameters:    Size  Location     Type
;;  Port            1    wreg     unsigned char 
;;  Pin             1    3[BANK0 ] unsigned char 
;;  Direction       1    4[BANK0 ] unsigned char 
;; Auto vars:     Size  Location     Type
;;  Port            1    6[BANK0 ] unsigned char 
;; Return value:  Size  Location     Type
;;                  1    wreg      void 
;; Registers used:
;;		wreg, fsr0l, fsr0h, status,2, status,0
;; Tracked objects:
;;		On entry : 300/0
;;		On exit  : 200/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK3   BANK2
;;      Params:         0       2       0       0       0
;;      Locals:         0       1       0       0       0
;;      Temps:          0       1       0       0       0
;;      Totals:         0       4       0       0       0
;;Total ram usage:        4 bytes
;; Hardware stack levels used: 1
;; Hardware stack levels required when called: 3
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_MOTOR_Init
;; This function uses a non-reentrant model
;;
psect	text14,local,class=CODE,delta=2,merge=1,group=0
	file	"MCAL/GPIO/GPIO.c"
	line	8
global __ptext14
__ptext14:	;psect for function _GPIO_SetPinDirection
psect	text14
	file	"MCAL/GPIO/GPIO.c"
	line	8
	
_GPIO_SetPinDirection:	
;incstack = 0
	callstack 2
; Regs used in _GPIO_SetPinDirection: [wreg-fsr0h+status,2+status,0]
	movwf	(GPIO_SetPinDirection@Port)
	line	10
	
l1254:	
	goto	l1288
	line	13
	
l1256:	
	movf	((GPIO_SetPinDirection@Direction)),w
	btfss	status,2
	goto	u651
	goto	u650
u651:
	goto	l1260
u650:
	line	14
	
l1258:	
	movlw	low(01h)
	movwf	(??_GPIO_SetPinDirection)
	incf	(GPIO_SetPinDirection@Pin),w
	goto	u664
u665:
	clrc
	rlf	(??_GPIO_SetPinDirection),f
u664:
	addlw	-1
	skipz
	goto	u665
	movf	(0+(??_GPIO_SetPinDirection)),w
	xorlw	0ffh
	bsf	status, 5	;RP0=1, select bank1
	andwf	(133)^080h,f	;volatile
	goto	l81
	line	16
	
l1260:	
	movlw	low(01h)
	movwf	(??_GPIO_SetPinDirection)
	incf	(GPIO_SetPinDirection@Pin),w
	goto	u674
u675:
	clrc
	rlf	(??_GPIO_SetPinDirection),f
u674:
	addlw	-1
	skipz
	goto	u675
	movf	(0+(??_GPIO_SetPinDirection)),w
	bsf	status, 5	;RP0=1, select bank1
	iorwf	(133)^080h,f	;volatile
	goto	l81
	line	20
	
l1262:	
	movf	((GPIO_SetPinDirection@Direction)),w
	btfss	status,2
	goto	u681
	goto	u680
u681:
	goto	l1266
u680:
	line	21
	
l1264:	
	movlw	low(01h)
	movwf	(??_GPIO_SetPinDirection)
	incf	(GPIO_SetPinDirection@Pin),w
	goto	u694
u695:
	clrc
	rlf	(??_GPIO_SetPinDirection),f
u694:
	addlw	-1
	skipz
	goto	u695
	movf	(0+(??_GPIO_SetPinDirection)),w
	xorlw	0ffh
	bsf	status, 5	;RP0=1, select bank1
	andwf	(134)^080h,f	;volatile
	goto	l81
	line	23
	
l1266:	
	movlw	low(01h)
	movwf	(??_GPIO_SetPinDirection)
	incf	(GPIO_SetPinDirection@Pin),w
	goto	u704
u705:
	clrc
	rlf	(??_GPIO_SetPinDirection),f
u704:
	addlw	-1
	skipz
	goto	u705
	movf	(0+(??_GPIO_SetPinDirection)),w
	bsf	status, 5	;RP0=1, select bank1
	iorwf	(134)^080h,f	;volatile
	goto	l81
	line	27
	
l1268:	
	movf	((GPIO_SetPinDirection@Direction)),w
	btfss	status,2
	goto	u711
	goto	u710
u711:
	goto	l1272
u710:
	line	28
	
l1270:	
	movlw	low(01h)
	movwf	(??_GPIO_SetPinDirection)
	incf	(GPIO_SetPinDirection@Pin),w
	goto	u724
u725:
	clrc
	rlf	(??_GPIO_SetPinDirection),f
u724:
	addlw	-1
	skipz
	goto	u725
	movf	(0+(??_GPIO_SetPinDirection)),w
	xorlw	0ffh
	bsf	status, 5	;RP0=1, select bank1
	andwf	(135)^080h,f	;volatile
	goto	l81
	line	30
	
l1272:	
	movlw	low(01h)
	movwf	(??_GPIO_SetPinDirection)
	incf	(GPIO_SetPinDirection@Pin),w
	goto	u734
u735:
	clrc
	rlf	(??_GPIO_SetPinDirection),f
u734:
	addlw	-1
	skipz
	goto	u735
	movf	(0+(??_GPIO_SetPinDirection)),w
	bsf	status, 5	;RP0=1, select bank1
	iorwf	(135)^080h,f	;volatile
	goto	l81
	line	34
	
l1274:	
	movf	((GPIO_SetPinDirection@Direction)),w
	btfss	status,2
	goto	u741
	goto	u740
u741:
	goto	l1278
u740:
	line	35
	
l1276:	
	movlw	low(01h)
	movwf	(??_GPIO_SetPinDirection)
	incf	(GPIO_SetPinDirection@Pin),w
	goto	u754
u755:
	clrc
	rlf	(??_GPIO_SetPinDirection),f
u754:
	addlw	-1
	skipz
	goto	u755
	movf	(0+(??_GPIO_SetPinDirection)),w
	xorlw	0ffh
	bsf	status, 5	;RP0=1, select bank1
	andwf	(136)^080h,f	;volatile
	goto	l81
	line	37
	
l1278:	
	movlw	low(01h)
	movwf	(??_GPIO_SetPinDirection)
	incf	(GPIO_SetPinDirection@Pin),w
	goto	u764
u765:
	clrc
	rlf	(??_GPIO_SetPinDirection),f
u764:
	addlw	-1
	skipz
	goto	u765
	movf	(0+(??_GPIO_SetPinDirection)),w
	bsf	status, 5	;RP0=1, select bank1
	iorwf	(136)^080h,f	;volatile
	goto	l81
	line	41
	
l1280:	
	movf	((GPIO_SetPinDirection@Direction)),w
	btfss	status,2
	goto	u771
	goto	u770
u771:
	goto	l1284
u770:
	line	42
	
l1282:	
	movlw	low(01h)
	movwf	(??_GPIO_SetPinDirection)
	incf	(GPIO_SetPinDirection@Pin),w
	goto	u784
u785:
	clrc
	rlf	(??_GPIO_SetPinDirection),f
u784:
	addlw	-1
	skipz
	goto	u785
	movf	(0+(??_GPIO_SetPinDirection)),w
	xorlw	0ffh
	bsf	status, 5	;RP0=1, select bank1
	andwf	(137)^080h,f	;volatile
	goto	l81
	line	44
	
l1284:	
	movlw	low(01h)
	movwf	(??_GPIO_SetPinDirection)
	incf	(GPIO_SetPinDirection@Pin),w
	goto	u794
u795:
	clrc
	rlf	(??_GPIO_SetPinDirection),f
u794:
	addlw	-1
	skipz
	goto	u795
	movf	(0+(??_GPIO_SetPinDirection)),w
	bsf	status, 5	;RP0=1, select bank1
	iorwf	(137)^080h,f	;volatile
	goto	l81
	line	49
	
l1288:	
	movf	(GPIO_SetPinDirection@Port),w
	; Switch size 1, requested type "simple"
; Number of cases is 5, Range of values is 0 to 4
; switch strategies available:
; Name         Instructions Cycles
; simple_byte           16     9 (average)
; direct_byte           23     8 (fixed)
; jumptable            260     6 (fixed)
;	Chosen strategy is simple_byte

	asmopt push
	asmopt off
	xorlw	0^0	; case 0
	skipnz
	goto	l1256
	xorlw	1^0	; case 1
	skipnz
	goto	l1262
	xorlw	2^1	; case 2
	skipnz
	goto	l1268
	xorlw	3^2	; case 3
	skipnz
	goto	l1274
	xorlw	4^3	; case 4
	skipnz
	goto	l1280
	goto	l81
	asmopt pop

	line	50
	
l81:	
	return
	callstack 0
GLOBAL	__end_of_GPIO_SetPinDirection
	__end_of_GPIO_SetPinDirection:
	signat	_GPIO_SetPinDirection,12409
	global	_ISR_ExtCall

;; *************** function _ISR_ExtCall *****************
;; Defined at:
;;		line 58 in file "MCAL/INT/INT.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;                  1    wreg      void 
;; Registers used:
;;		wreg, status,2, status,0, pclath, cstack
;; Tracked objects:
;;		On entry : 0/0
;;		On exit  : 300/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK3   BANK2
;;      Params:         0       0       0       0       0
;;      Locals:         0       0       0       0       0
;;      Temps:          0       3       0       0       0
;;      Totals:         0       3       0       0       0
;;Total ram usage:        3 bytes
;; Hardware stack levels used: 1
;; Hardware stack levels required when called: 2
;; This function calls:
;;		_adjusted_timer_0_second_count
;; This function is called by:
;;		Interrupt level 1
;; This function uses a non-reentrant model
;;
psect	text15,local,class=CODE,delta=2,merge=1,group=0
	file	"MCAL/INT/INT.c"
	line	58
global __ptext15
__ptext15:	;psect for function _ISR_ExtCall
psect	text15
	file	"MCAL/INT/INT.c"
	line	58
	
_ISR_ExtCall:	
;incstack = 0
	callstack 0
; Regs used in _ISR_ExtCall: [wreg+status,2+status,0+pclath+cstack]
psect	intentry,class=CODE,delta=2
global __pintentry
__pintentry:
global interrupt_function
interrupt_function:
	global saved_w
	saved_w	set	btemp+0
	movwf	saved_w
	swapf	status,w
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	movwf	(??_ISR_ExtCall+1)
	movf	pclath,w
	movwf	(??_ISR_ExtCall+2)
	ljmp	_ISR_ExtCall
psect	text15
	line	61
	
i1l1352:	
	movf	(11),w	;volatile
	movwf	(??_ISR_ExtCall)
	movlw	02h
u91_25:
	clrc
	rrf	(??_ISR_ExtCall),f
	addlw	-1
	skipz
	goto	u91_25
	btfss	(0+(??_ISR_ExtCall)),(0)&7
	goto	u92_21
	goto	u92_20
u92_21:
	goto	i1l153
u92_20:
	line	63
	
i1l1354:	
	fcall	_adjusted_timer_0_second_count
	line	64
	
i1l1356:	
	movlw	low(0FBh)
	andwf	(11),f	;volatile
	line	68
	
i1l153:	
	movf	(??_ISR_ExtCall+2),w
	movwf	pclath
	swapf	(??_ISR_ExtCall+1),w
	movwf	status
	swapf	saved_w,f
	swapf	saved_w,w
	retfie
	callstack 0
GLOBAL	__end_of_ISR_ExtCall
	__end_of_ISR_ExtCall:
	signat	_ISR_ExtCall,89
	global	_adjusted_timer_0_second_count

;; *************** function _adjusted_timer_0_second_count *****************
;; Defined at:
;;		line 133 in file "MCAL/TIMER/TIMER.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;                  1    wreg      void 
;; Registers used:
;;		wreg, status,2, status,0, pclath, cstack
;; Tracked objects:
;;		On entry : 300/0
;;		On exit  : 300/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK3   BANK2
;;      Params:         0       0       0       0       0
;;      Locals:         0       0       0       0       0
;;      Temps:          0       0       0       0       0
;;      Totals:         0       0       0       0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels used: 1
;; Hardware stack levels required when called: 1
;; This function calls:
;;		___llmod
;;		_get_timer_0_Ticks
;;		_increment_timer_0_Ticks
;;		_set_timer_0_Reg
;; This function is called by:
;;		_ISR_ExtCall
;; This function uses a non-reentrant model
;;
psect	text16,local,class=CODE,delta=2,merge=1,group=0
	file	"MCAL/TIMER/TIMER.c"
	line	133
global __ptext16
__ptext16:	;psect for function _adjusted_timer_0_second_count
psect	text16
	file	"MCAL/TIMER/TIMER.c"
	line	133
	
_adjusted_timer_0_second_count:	
;incstack = 0
	callstack 0
; Regs used in _adjusted_timer_0_second_count: [wreg+status,2+status,0+pclath+cstack]
	line	136
	
i1l1338:	
	fcall	_increment_timer_0_Ticks
	line	137
	
i1l1340:	
	fcall	_get_timer_0_Ticks
	movf	(3+(?_get_timer_0_Ticks)),w
	iorwf	(2+(?_get_timer_0_Ticks)),w
	iorwf	(1+(?_get_timer_0_Ticks)),w
	iorwf	(0+(?_get_timer_0_Ticks)),w
	skipz
	goto	u89_21
	goto	u89_20
u89_21:
	goto	i1l1344
u89_20:
	goto	i1l206
	line	138
	
i1l1344:	
	movlw	0
	movwf	(___llmod@divisor+3)
	movlw	0
	movwf	(___llmod@divisor+2)
	movlw	0
	movwf	(___llmod@divisor+1)
	movlw	01Eh
	movwf	(___llmod@divisor)

	fcall	_get_timer_0_Ticks
	movf	(3+(?_get_timer_0_Ticks)),w
	movwf	(___llmod@dividend+3)
	movf	(2+(?_get_timer_0_Ticks)),w
	movwf	(___llmod@dividend+2)
	movf	(1+(?_get_timer_0_Ticks)),w
	movwf	(___llmod@dividend+1)
	movf	(0+(?_get_timer_0_Ticks)),w
	movwf	(___llmod@dividend)

	fcall	___llmod
	movf	(3+(?___llmod)),w
	iorwf	(2+(?___llmod)),w
	iorwf	(1+(?___llmod)),w
	iorwf	(0+(?___llmod)),w
	skipz
	goto	u90_21
	goto	u90_20
u90_21:
	goto	i1l206
u90_20:
	line	140
	
i1l1346:	
	fcall	_set_timer_0_Reg
	line	143
	
i1l206:	
	return
	callstack 0
GLOBAL	__end_of_adjusted_timer_0_second_count
	__end_of_adjusted_timer_0_second_count:
	signat	_adjusted_timer_0_second_count,89
	global	_set_timer_0_Reg

;; *************** function _set_timer_0_Reg *****************
;; Defined at:
;;		line 10 in file "MCAL/TIMER/TIMER.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;                  1    wreg      void 
;; Registers used:
;;		None
;; Tracked objects:
;;		On entry : 300/0
;;		On exit  : 300/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK3   BANK2
;;      Params:         0       0       0       0       0
;;      Locals:         0       0       0       0       0
;;      Temps:          0       0       0       0       0
;;      Totals:         0       0       0       0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels used: 1
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_adjusted_timer_0_second_count
;; This function uses a non-reentrant model
;;
psect	text17,local,class=CODE,delta=2,merge=1,group=0
	line	10
global __ptext17
__ptext17:	;psect for function _set_timer_0_Reg
psect	text17
	file	"MCAL/TIMER/TIMER.c"
	line	10
	
_set_timer_0_Reg:	
;incstack = 0
	callstack 0
; Regs used in _set_timer_0_Reg: []
	line	12
	
i1l1044:	
	movlw	07Ch
	movwf	(1)	;volatile
	line	13
	
i1l162:	
	return
	callstack 0
GLOBAL	__end_of_set_timer_0_Reg
	__end_of_set_timer_0_Reg:
	signat	_set_timer_0_Reg,89
	global	_increment_timer_0_Ticks

;; *************** function _increment_timer_0_Ticks *****************
;; Defined at:
;;		line 116 in file "MCAL/TIMER/TIMER.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;                  1    wreg      void 
;; Registers used:
;;		wreg
;; Tracked objects:
;;		On entry : 300/0
;;		On exit  : 300/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK3   BANK2
;;      Params:         0       0       0       0       0
;;      Locals:         0       0       0       0       0
;;      Temps:          0       0       0       0       0
;;      Totals:         0       0       0       0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels used: 1
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_adjusted_timer_0_second_count
;; This function uses a non-reentrant model
;;
psect	text18,local,class=CODE,delta=2,merge=1,group=0
	line	116
global __ptext18
__ptext18:	;psect for function _increment_timer_0_Ticks
psect	text18
	file	"MCAL/TIMER/TIMER.c"
	line	116
	
_increment_timer_0_Ticks:	
;incstack = 0
	callstack 0
; Regs used in _increment_timer_0_Ticks: [wreg]
	line	118
	
i1l1310:	
	movlw	01h
	addwf	(_count_ticks),f	;volatile
	movlw	0
	skipnc
movlw 1
	addwf	(_count_ticks+1),f	;volatile
	movlw	0
	skipnc
movlw 1
	addwf	(_count_ticks+2),f	;volatile
	movlw	0
	skipnc
movlw 1
	addwf	(_count_ticks+3),f	;volatile
	line	119
	
i1l191:	
	return
	callstack 0
GLOBAL	__end_of_increment_timer_0_Ticks
	__end_of_increment_timer_0_Ticks:
	signat	_increment_timer_0_Ticks,89
	global	_get_timer_0_Ticks

;; *************** function _get_timer_0_Ticks *****************
;; Defined at:
;;		line 121 in file "MCAL/TIMER/TIMER.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;                  4    0[COMMON] unsigned long 
;; Registers used:
;;		wreg
;; Tracked objects:
;;		On entry : 300/0
;;		On exit  : 300/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK3   BANK2
;;      Params:         4       0       0       0       0
;;      Locals:         0       0       0       0       0
;;      Temps:          0       0       0       0       0
;;      Totals:         4       0       0       0       0
;;Total ram usage:        4 bytes
;; Hardware stack levels used: 1
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_adjusted_timer_0_second_count
;; This function uses a non-reentrant model
;;
psect	text19,local,class=CODE,delta=2,merge=1,group=0
	line	121
global __ptext19
__ptext19:	;psect for function _get_timer_0_Ticks
psect	text19
	file	"MCAL/TIMER/TIMER.c"
	line	121
	
_get_timer_0_Ticks:	
;incstack = 0
	callstack 0
; Regs used in _get_timer_0_Ticks: [wreg]
	line	123
	
i1l1312:	
	movf	(_count_ticks+3),w	;volatile
	movwf	(?_get_timer_0_Ticks+3)
	movf	(_count_ticks+2),w	;volatile
	movwf	(?_get_timer_0_Ticks+2)
	movf	(_count_ticks+1),w	;volatile
	movwf	(?_get_timer_0_Ticks+1)
	movf	(_count_ticks),w	;volatile
	movwf	(?_get_timer_0_Ticks)

	line	124
	
i1l194:	
	return
	callstack 0
GLOBAL	__end_of_get_timer_0_Ticks
	__end_of_get_timer_0_Ticks:
	signat	_get_timer_0_Ticks,92
	global	___llmod

;; *************** function ___llmod *****************
;; Defined at:
;;		line 5 in file "C:\Program Files\Microchip\xc8\v3.10\pic\sources\c99\common\llmod.c"
;; Parameters:    Size  Location     Type
;;  divisor         4    4[COMMON] unsigned long 
;;  dividend        4    8[COMMON] unsigned long 
;; Auto vars:     Size  Location     Type
;;  counter         1   13[COMMON] unsigned char 
;; Return value:  Size  Location     Type
;;                  4    4[COMMON] unsigned long 
;; Registers used:
;;		wreg, status,2, status,0
;; Tracked objects:
;;		On entry : 300/0
;;		On exit  : 300/0
;;		Unchanged: 300/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK3   BANK2
;;      Params:         8       0       0       0       0
;;      Locals:         1       0       0       0       0
;;      Temps:          1       0       0       0       0
;;      Totals:        10       0       0       0       0
;;Total ram usage:       10 bytes
;; Hardware stack levels used: 1
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_adjusted_timer_0_second_count
;; This function uses a non-reentrant model
;;
psect	text20,local,class=CODE,delta=2,merge=1,group=1
	file	"C:\Program Files\Microchip\xc8\v3.10\pic\sources\c99\common\llmod.c"
	line	5
global __ptext20
__ptext20:	;psect for function ___llmod
psect	text20
	file	"C:\Program Files\Microchip\xc8\v3.10\pic\sources\c99\common\llmod.c"
	line	5
	
___llmod:	
;incstack = 0
	callstack 0
; Regs used in ___llmod: [wreg+status,2+status,0]
	line	12
	
i1l1316:	
	movf	(___llmod@divisor+3),w
	iorwf	(___llmod@divisor+2),w
	iorwf	(___llmod@divisor+1),w
	iorwf	(___llmod@divisor),w
	skipnz
	goto	u83_21
	goto	u83_20
u83_21:
	goto	i1l1332
u83_20:
	line	13
	
i1l1318:	
	movlw	01h
	movwf	(___llmod@counter)
	line	14
	goto	i1l1322
	line	15
	
i1l1320:	
	movlw	01h
	movwf	(??___llmod)
u84_25:
	clrc
	rlf	(___llmod@divisor),f
	rlf	(___llmod@divisor+1),f
	rlf	(___llmod@divisor+2),f
	rlf	(___llmod@divisor+3),f
	decfsz	(??___llmod)
	goto	u84_25
	line	16
	movlw	low(01h)
	addwf	(___llmod@counter),f
	line	14
	
i1l1322:	
	btfss	(___llmod@divisor+3),(31)&7
	goto	u85_21
	goto	u85_20
u85_21:
	goto	i1l1320
u85_20:
	line	19
	
i1l1324:	
	movf	(___llmod@divisor+3),w
	subwf	(___llmod@dividend+3),w
	skipz
	goto	u86_25
	movf	(___llmod@divisor+2),w
	subwf	(___llmod@dividend+2),w
	skipz
	goto	u86_25
	movf	(___llmod@divisor+1),w
	subwf	(___llmod@dividend+1),w
	skipz
	goto	u86_25
	movf	(___llmod@divisor),w
	subwf	(___llmod@dividend),w
u86_25:
	skipc
	goto	u86_21
	goto	u86_20
u86_21:
	goto	i1l1328
u86_20:
	line	20
	
i1l1326:	
	movf	(___llmod@divisor),w
	subwf	(___llmod@dividend),f
	movf	(___llmod@divisor+1),w
	skipc
	incfsz	(___llmod@divisor+1),w
	subwf	(___llmod@dividend+1),f
	movf	(___llmod@divisor+2),w
	skipc
	incfsz	(___llmod@divisor+2),w
	subwf	(___llmod@dividend+2),f
	movf	(___llmod@divisor+3),w
	skipc
	incfsz	(___llmod@divisor+3),w
	subwf	(___llmod@dividend+3),f
	line	21
	
i1l1328:	
	movlw	01h
u87_25:
	clrc
	rrf	(___llmod@divisor+3),f
	rrf	(___llmod@divisor+2),f
	rrf	(___llmod@divisor+1),f
	rrf	(___llmod@divisor),f
	addlw	-1
	skipz
	goto	u87_25

	line	22
	
i1l1330:	
	movlw	01h
	subwf	(___llmod@counter),f
	btfss	status,2
	goto	u88_21
	goto	u88_20
u88_21:
	goto	i1l1324
u88_20:
	line	24
	
i1l1332:	
	movf	(___llmod@dividend+3),w
	movwf	(?___llmod+3)
	movf	(___llmod@dividend+2),w
	movwf	(?___llmod+2)
	movf	(___llmod@dividend+1),w
	movwf	(?___llmod+1)
	movf	(___llmod@dividend),w
	movwf	(?___llmod)

	line	25
	
i1l600:	
	return
	callstack 0
GLOBAL	__end_of___llmod
	__end_of___llmod:
	signat	___llmod,8316
global	___latbits
___latbits	equ	2
	global	btemp
	btemp set 07Eh

	DABS	1,0x7E,2	;btemp
	global btemp0
	btemp0 set btemp+0
	global btemp1
	btemp1 set btemp+1
	global wtemp0
	wtemp0 set btemp+0
	global wtemp0a
	wtemp0a set btemp+1
	global ttemp0a
	ttemp0a set btemp+1
	global ltemp0a
	ltemp0a set btemp+2
	end
