
_EXT_INT0_Init:

;EXT_INT.c,6 :: 		void EXT_INT0_Init(void) {
;EXT_INT.c,7 :: 		TRISB.F0 = 1;       // INT0 pin (RB0) as input
	BSF        TRISB+0, 0
;EXT_INT.c,8 :: 		EXT_INT0_SetEdge(1); // Default to rising edge
	MOVLW      1
	MOVWF      FARG_EXT_INT0_SetEdge_edge_type+0
	CALL       _EXT_INT0_SetEdge+0
;EXT_INT.c,9 :: 		EXT_INT0_Enable();
	CALL       _EXT_INT0_Enable+0
;EXT_INT.c,10 :: 		INTCON.GIE = 1;     // Enable Global Interrupts
	BSF        INTCON+0, 7
;EXT_INT.c,11 :: 		INTCON.PEIE = 1;    // Enable Peripheral Interrupts
	BSF        INTCON+0, 6
;EXT_INT.c,12 :: 		}
L_end_EXT_INT0_Init:
	RETURN
; end of _EXT_INT0_Init

_EXT_INT0_Enable:

;EXT_INT.c,14 :: 		void EXT_INT0_Enable(void)  { INTCON.INTE = 1; }
	BSF        INTCON+0, 4
L_end_EXT_INT0_Enable:
	RETURN
; end of _EXT_INT0_Enable

_EXT_INT0_Disable:

;EXT_INT.c,15 :: 		void EXT_INT0_Disable(void) { INTCON.INTE = 0; }
	BCF        INTCON+0, 4
L_end_EXT_INT0_Disable:
	RETURN
; end of _EXT_INT0_Disable

_EXT_INT0_SetEdge:

;EXT_INT.c,17 :: 		void EXT_INT0_SetEdge(unsigned char edge_type) {
;EXT_INT.c,18 :: 		if(edge_type == 1) OPTION_REG.INTEDG = 1; // Rising
	MOVF       FARG_EXT_INT0_SetEdge_edge_type+0, 0
	XORLW      1
	BTFSS      STATUS+0, 2
	GOTO       L_EXT_INT0_SetEdge0
	BSF        OPTION_REG+0, 6
	GOTO       L_EXT_INT0_SetEdge1
L_EXT_INT0_SetEdge0:
;EXT_INT.c,19 :: 		else OPTION_REG.INTEDG = 0;               // Falling
	BCF        OPTION_REG+0, 6
L_EXT_INT0_SetEdge1:
;EXT_INT.c,20 :: 		}
L_end_EXT_INT0_SetEdge:
	RETURN
; end of _EXT_INT0_SetEdge

_EXT_INT0_SetCallback:

;EXT_INT.c,22 :: 		void EXT_INT0_SetCallback(void (*ptr)(void)) {
;EXT_INT.c,23 :: 		INT0_CallBackPtr = ptr;
	MOVF       FARG_EXT_INT0_SetCallback_ptr+0, 0
	MOVWF      EXT_INT_INT0_CallBackPtr+0
	MOVF       FARG_EXT_INT0_SetCallback_ptr+1, 0
	MOVWF      EXT_INT_INT0_CallBackPtr+1
	MOVF       FARG_EXT_INT0_SetCallback_ptr+2, 0
	MOVWF      EXT_INT_INT0_CallBackPtr+2
	MOVF       FARG_EXT_INT0_SetCallback_ptr+3, 0
;EXT_INT.c,24 :: 		}
L_end_EXT_INT0_SetCallback:
	RETURN
; end of _EXT_INT0_SetCallback

_interrupt:
	MOVWF      R15+0
	SWAPF      STATUS+0, 0
	CLRF       STATUS+0
	MOVWF      ___saveSTATUS+0
	MOVF       PCLATH+0, 0
	MOVWF      ___savePCLATH+0
	CLRF       PCLATH+0

;EXT_INT.c,27 :: 		void interrupt() {
;EXT_INT.c,28 :: 		if (INTCON.INTF) {
	BTFSS      INTCON+0, 1
	GOTO       L_interrupt2
;EXT_INT.c,29 :: 		if (INT0_CallBackPtr != 0) {
	MOVF       EXT_INT_INT0_CallBackPtr+0, 0
	MOVWF      R1+0
	MOVF       EXT_INT_INT0_CallBackPtr+1, 0
	MOVWF      R1+1
	MOVF       EXT_INT_INT0_CallBackPtr+2, 0
	MOVWF      R1+2
	MOVF       EXT_INT_INT0_CallBackPtr+3, 0
	MOVWF      R1+3
	MOVLW      0
	MOVWF      R0+0
	XORWF      R1+3, 0
	BTFSS      STATUS+0, 2
	GOTO       L__interrupt11
	MOVF       R0+0, 0
	XORWF      R1+2, 0
	BTFSS      STATUS+0, 2
	GOTO       L__interrupt11
	MOVF       R0+0, 0
	XORWF      R1+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__interrupt11
	MOVF       R1+0, 0
	XORLW      0
L__interrupt11:
	BTFSC      STATUS+0, 2
	GOTO       L_interrupt3
;EXT_INT.c,30 :: 		INT0_CallBackPtr(); // Execute the App-level function
	MOVF       EXT_INT_INT0_CallBackPtr+0, 0
	MOVWF      ___DoICPAddr+0
	MOVF       EXT_INT_INT0_CallBackPtr+1, 0
	MOVWF      ___DoICPAddr+1
	CALL       _____DoIFC+0
;EXT_INT.c,31 :: 		}
L_interrupt3:
;EXT_INT.c,32 :: 		INTCON.INTF = 0; // Clear flag
	BCF        INTCON+0, 1
;EXT_INT.c,33 :: 		}
L_interrupt2:
;EXT_INT.c,34 :: 		}
L_end_interrupt:
L__interrupt10:
	MOVF       ___savePCLATH+0, 0
	MOVWF      PCLATH+0
	SWAPF      ___saveSTATUS+0, 0
	MOVWF      STATUS+0
	SWAPF      R15+0, 1
	SWAPF      R15+0, 0
	RETFIE
; end of _interrupt

EXT_INT____?ag:

L_end_EXT_INT___?ag:
	RETURN
; end of EXT_INT____?ag
