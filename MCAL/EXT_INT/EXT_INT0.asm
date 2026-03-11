
_EXT_INT0_Init:

;EXT_INT0.c,8 :: 		void EXT_INT0_Init(void) {
;EXT_INT0.c,10 :: 		TRISB0_bit = 1;
	BSF        TRISB0_bit+0, BitPos(TRISB0_bit+0)
;EXT_INT0.c,16 :: 		INTEDG_bit = 0;
	BCF        INTEDG_bit+0, BitPos(INTEDG_bit+0)
;EXT_INT0.c,20 :: 		INTF_bit = 0;
	BCF        INTF_bit+0, BitPos(INTF_bit+0)
;EXT_INT0.c,21 :: 		}
L_end_EXT_INT0_Init:
	RETURN
; end of _EXT_INT0_Init

_EXT_INT0_Enable:

;EXT_INT0.c,23 :: 		void EXT_INT0_Enable(void) {
;EXT_INT0.c,24 :: 		INTE_bit = 1; // Enable External Interrupt INT0
	BSF        INTE_bit+0, BitPos(INTE_bit+0)
;EXT_INT0.c,25 :: 		GIE_bit  = 1; // Enable Global Interrupts
	BSF        GIE_bit+0, BitPos(GIE_bit+0)
;EXT_INT0.c,26 :: 		}
L_end_EXT_INT0_Enable:
	RETURN
; end of _EXT_INT0_Enable

_EXT_INT0_Disable:

;EXT_INT0.c,28 :: 		void EXT_INT0_Disable(void) {
;EXT_INT0.c,29 :: 		INTE_bit = 0; // Disable External Interrupt INT0
	BCF        INTE_bit+0, BitPos(INTE_bit+0)
;EXT_INT0.c,30 :: 		}
L_end_EXT_INT0_Disable:
	RETURN
; end of _EXT_INT0_Disable

_EXT_INT0_SetEdge:

;EXT_INT0.c,32 :: 		void EXT_INT0_SetEdge(u8 edge_type) {
;EXT_INT0.c,33 :: 		if (edge_type == EXT_INT0_RISING_EDGE) {
	MOVF       FARG_EXT_INT0_SetEdge_edge_type+0, 0
	XORLW      1
	BTFSS      STATUS+0, 2
	GOTO       L_EXT_INT0_SetEdge0
;EXT_INT0.c,34 :: 		INTEDG_bit = 1;
	BSF        INTEDG_bit+0, BitPos(INTEDG_bit+0)
;EXT_INT0.c,35 :: 		} else if (edge_type == EXT_INT0_FALLING_EDGE) {
	GOTO       L_EXT_INT0_SetEdge1
L_EXT_INT0_SetEdge0:
	MOVF       FARG_EXT_INT0_SetEdge_edge_type+0, 0
	XORLW      0
	BTFSS      STATUS+0, 2
	GOTO       L_EXT_INT0_SetEdge2
;EXT_INT0.c,36 :: 		INTEDG_bit = 0;
	BCF        INTEDG_bit+0, BitPos(INTEDG_bit+0)
;EXT_INT0.c,37 :: 		}
L_EXT_INT0_SetEdge2:
L_EXT_INT0_SetEdge1:
;EXT_INT0.c,38 :: 		}
L_end_EXT_INT0_SetEdge:
	RETURN
; end of _EXT_INT0_SetEdge

_EXT_INT0_SetCallback:

;EXT_INT0.c,40 :: 		void EXT_INT0_SetCallback(void (*ptr)(void)) {
;EXT_INT0.c,41 :: 		if (ptr != 0) {
	MOVF       FARG_EXT_INT0_SetCallback_ptr+0, 0
	MOVWF      R1+0
	MOVF       FARG_EXT_INT0_SetCallback_ptr+1, 0
	MOVWF      R1+1
	MOVF       FARG_EXT_INT0_SetCallback_ptr+2, 0
	MOVWF      R1+2
	MOVF       FARG_EXT_INT0_SetCallback_ptr+3, 0
	MOVWF      R1+3
	MOVLW      0
	MOVWF      R0+0
	XORWF      R1+3, 0
	BTFSS      STATUS+0, 2
	GOTO       L__EXT_INT0_SetCallback11
	MOVF       R0+0, 0
	XORWF      R1+2, 0
	BTFSS      STATUS+0, 2
	GOTO       L__EXT_INT0_SetCallback11
	MOVF       R0+0, 0
	XORWF      R1+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__EXT_INT0_SetCallback11
	MOVF       R1+0, 0
	XORLW      0
L__EXT_INT0_SetCallback11:
	BTFSC      STATUS+0, 2
	GOTO       L_EXT_INT0_SetCallback3
;EXT_INT0.c,42 :: 		EXT_INT0_Callback = ptr;
	MOVF       FARG_EXT_INT0_SetCallback_ptr+0, 0
	MOVWF      EXT_INT0_EXT_INT0_Callback+0
	MOVF       FARG_EXT_INT0_SetCallback_ptr+1, 0
	MOVWF      EXT_INT0_EXT_INT0_Callback+1
	MOVF       FARG_EXT_INT0_SetCallback_ptr+2, 0
	MOVWF      EXT_INT0_EXT_INT0_Callback+2
	MOVF       FARG_EXT_INT0_SetCallback_ptr+3, 0
;EXT_INT0.c,43 :: 		}
L_EXT_INT0_SetCallback3:
;EXT_INT0.c,44 :: 		}
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

;EXT_INT0.c,47 :: 		void interrupt(void) {
;EXT_INT0.c,49 :: 		if (INTF_bit == 1) {
	BTFSS      INTF_bit+0, BitPos(INTF_bit+0)
	GOTO       L_interrupt4
;EXT_INT0.c,51 :: 		INTF_bit = 0;
	BCF        INTF_bit+0, BitPos(INTF_bit+0)
;EXT_INT0.c,54 :: 		if (EXT_INT0_Callback != 0) {
	MOVF       EXT_INT0_EXT_INT0_Callback+0, 0
	MOVWF      R1+0
	MOVF       EXT_INT0_EXT_INT0_Callback+1, 0
	MOVWF      R1+1
	MOVF       EXT_INT0_EXT_INT0_Callback+2, 0
	MOVWF      R1+2
	MOVF       EXT_INT0_EXT_INT0_Callback+3, 0
	MOVWF      R1+3
	MOVLW      0
	MOVWF      R0+0
	XORWF      R1+3, 0
	BTFSS      STATUS+0, 2
	GOTO       L__interrupt14
	MOVF       R0+0, 0
	XORWF      R1+2, 0
	BTFSS      STATUS+0, 2
	GOTO       L__interrupt14
	MOVF       R0+0, 0
	XORWF      R1+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__interrupt14
	MOVF       R1+0, 0
	XORLW      0
L__interrupt14:
	BTFSC      STATUS+0, 2
	GOTO       L_interrupt5
;EXT_INT0.c,55 :: 		EXT_INT0_Callback();
	MOVF       EXT_INT0_EXT_INT0_Callback+0, 0
	MOVWF      ___DoICPAddr+0
	MOVF       EXT_INT0_EXT_INT0_Callback+1, 0
	MOVWF      ___DoICPAddr+1
	CALL       _____DoIFC+0
;EXT_INT0.c,56 :: 		}
L_interrupt5:
;EXT_INT0.c,57 :: 		}
L_interrupt4:
;EXT_INT0.c,58 :: 		}
L_end_interrupt:
L__interrupt13:
	MOVF       ___savePCLATH+0, 0
	MOVWF      PCLATH+0
	SWAPF      ___saveSTATUS+0, 0
	MOVWF      STATUS+0
	SWAPF      R15+0, 1
	SWAPF      R15+0, 0
	RETFIE
; end of _interrupt

EXT_INT0____?ag:

L_end_EXT_INT0___?ag:
	RETURN
; end of EXT_INT0____?ag
