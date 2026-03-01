
_EXTI0_Init:

;exti0.c,8 :: 		void EXTI0_Init(void) {
;exti0.c,9 :: 		TRISB.B0 = 1;        // RB0 as input
	BSF        TRISB+0, 0
;exti0.c,10 :: 		OPTION_REG.B6 = 0;   // INTEDG = 0 -> interrupt on falling edge
	BCF        OPTION_REG+0, 6
;exti0.c,12 :: 		INTCON.B1 = 0;       // Clear INT0 interrupt flag (INT0IF)
	BCF        INTCON+0, 1
;exti0.c,13 :: 		INTCON.B4 = 1;       // Enable INT0 interrupt (INTE)
	BSF        INTCON+0, 4
;exti0.c,14 :: 		INTCON.B7 = 1;       // Enable global interrupts (GIE)
	BSF        INTCON+0, 7
;exti0.c,15 :: 		}
L_end_EXTI0_Init:
	RETURN
; end of _EXTI0_Init

_EXTI0_SetCallback:

;exti0.c,18 :: 		void EXTI0_SetCallback(void (*callback)(void)) {
;exti0.c,19 :: 		EXTI0_Callback = callback;
	MOVF       FARG_EXTI0_SetCallback_callback+0, 0
	MOVWF      exti0_EXTI0_Callback+0
	MOVF       FARG_EXTI0_SetCallback_callback+1, 0
	MOVWF      exti0_EXTI0_Callback+1
	MOVF       FARG_EXTI0_SetCallback_callback+2, 0
	MOVWF      exti0_EXTI0_Callback+2
	MOVF       FARG_EXTI0_SetCallback_callback+3, 0
;exti0.c,20 :: 		}
L_end_EXTI0_SetCallback:
	RETURN
; end of _EXTI0_SetCallback

_interrupt:
	MOVWF      R15+0
	SWAPF      STATUS+0, 0
	CLRF       STATUS+0
	MOVWF      ___saveSTATUS+0
	MOVF       PCLATH+0, 0
	MOVWF      ___savePCLATH+0
	CLRF       PCLATH+0

;exti0.c,23 :: 		void interrupt() {
;exti0.c,24 :: 		if (INTCON.B1) {           // INT0IF
	BTFSS      INTCON+0, 1
	GOTO       L_interrupt0
;exti0.c,25 :: 		if (EXTI0_Callback)
	MOVF       exti0_EXTI0_Callback+0, 0
	IORWF      exti0_EXTI0_Callback+1, 0
	IORWF      exti0_EXTI0_Callback+2, 0
	BTFSC      STATUS+0, 2
	GOTO       L_interrupt1
;exti0.c,26 :: 		EXTI0_Callback();  // Call registered callback
	MOVF       exti0_EXTI0_Callback+0, 0
	MOVWF      ___DoICPAddr+0
	MOVF       exti0_EXTI0_Callback+1, 0
	MOVWF      ___DoICPAddr+1
	CALL       _____DoIFC+0
L_interrupt1:
;exti0.c,28 :: 		INTCON.B1 = 0;         // Clear INT0 flag
	BCF        INTCON+0, 1
;exti0.c,29 :: 		}
L_interrupt0:
;exti0.c,30 :: 		}
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
