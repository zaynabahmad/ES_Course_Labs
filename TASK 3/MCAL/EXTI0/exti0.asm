
_MEXTI0_vInit:

;exti0.c,7 :: 		void MEXTI0_vInit(void) {
;exti0.c,8 :: 		TRISB0_bit = 1;   // RB0 as Input
	BSF        TRISB0_bit+0, BitPos(TRISB0_bit+0)
;exti0.c,9 :: 		INTEDG_bit = 1;   // Rising Edge
	BSF        INTEDG_bit+0, BitPos(INTEDG_bit+0)
;exti0.c,10 :: 		INTE_bit   = 1;   // Enable INT0
	BSF        INTE_bit+0, BitPos(INTE_bit+0)
;exti0.c,11 :: 		GIE_bit    = 1;   // Global Interrupt Enable
	BSF        GIE_bit+0, BitPos(GIE_bit+0)
;exti0.c,12 :: 		}
L_end_MEXTI0_vInit:
	RETURN
; end of _MEXTI0_vInit

_MEXTI0_vSetCallback:

;exti0.c,14 :: 		void MEXTI0_vSetCallback(void (*ptr)(void)) {
;exti0.c,15 :: 		G_EXTI0_Callback = ptr;
	MOVF       FARG_MEXTI0_vSetCallback_ptr+0, 0
	MOVWF      exti0_G_EXTI0_Callback+0
	MOVF       FARG_MEXTI0_vSetCallback_ptr+1, 0
	MOVWF      exti0_G_EXTI0_Callback+1
	MOVF       FARG_MEXTI0_vSetCallback_ptr+2, 0
	MOVWF      exti0_G_EXTI0_Callback+2
	MOVF       FARG_MEXTI0_vSetCallback_ptr+3, 0
;exti0.c,16 :: 		}
L_end_MEXTI0_vSetCallback:
	RETURN
; end of _MEXTI0_vSetCallback

_interrupt:
	MOVWF      R15+0
	SWAPF      STATUS+0, 0
	CLRF       STATUS+0
	MOVWF      ___saveSTATUS+0
	MOVF       PCLATH+0, 0
	MOVWF      ___savePCLATH+0
	CLRF       PCLATH+0

;exti0.c,19 :: 		void interrupt() {
;exti0.c,20 :: 		if (INTF_bit == 1) {
	BTFSS      INTF_bit+0, BitPos(INTF_bit+0)
	GOTO       L_interrupt0
;exti0.c,21 :: 		if (G_EXTI0_Callback != 0) {
	MOVF       exti0_G_EXTI0_Callback+0, 0
	MOVWF      R1+0
	MOVF       exti0_G_EXTI0_Callback+1, 0
	MOVWF      R1+1
	MOVF       exti0_G_EXTI0_Callback+2, 0
	MOVWF      R1+2
	MOVF       exti0_G_EXTI0_Callback+3, 0
	MOVWF      R1+3
	MOVLW      0
	MOVWF      R0+0
	XORWF      R1+3, 0
	BTFSS      STATUS+0, 2
	GOTO       L__interrupt6
	MOVF       R0+0, 0
	XORWF      R1+2, 0
	BTFSS      STATUS+0, 2
	GOTO       L__interrupt6
	MOVF       R0+0, 0
	XORWF      R1+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__interrupt6
	MOVF       R1+0, 0
	XORLW      0
L__interrupt6:
	BTFSC      STATUS+0, 2
	GOTO       L_interrupt1
;exti0.c,22 :: 		G_EXTI0_Callback();
	MOVF       exti0_G_EXTI0_Callback+0, 0
	MOVWF      ___DoICPAddr+0
	MOVF       exti0_G_EXTI0_Callback+1, 0
	MOVWF      ___DoICPAddr+1
	CALL       _____DoIFC+0
;exti0.c,23 :: 		}
L_interrupt1:
;exti0.c,24 :: 		INTF_bit = 0; // Clear Flag
	BCF        INTF_bit+0, BitPos(INTF_bit+0)
;exti0.c,25 :: 		}
L_interrupt0:
;exti0.c,26 :: 		}
L_end_interrupt:
L__interrupt5:
	MOVF       ___savePCLATH+0, 0
	MOVWF      PCLATH+0
	SWAPF      ___saveSTATUS+0, 0
	MOVWF      STATUS+0
	SWAPF      R15+0, 1
	SWAPF      R15+0, 0
	RETFIE
; end of _interrupt

exti0____?ag:

L_end_exti0___?ag:
	RETURN
; end of exti0____?ag
