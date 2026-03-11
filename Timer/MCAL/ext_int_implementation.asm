
_EXT_INTO_Init:

;ext_int_implementation.c,9 :: 		void EXT_INTO_Init(void) {
;ext_int_implementation.c,10 :: 		set_pin_direction(_PORTB, 0, INPUT);
	MOVLW      1
	MOVWF      FARG_set_pin_direction_port+0
	CLRF       FARG_set_pin_direction_pin+0
	MOVLW      1
	MOVWF      FARG_set_pin_direction_direction+0
	CALL       _set_pin_direction+0
;ext_int_implementation.c,11 :: 		INTCON &= ~0x02;
	BCF        INTCON+0, 1
;ext_int_implementation.c,12 :: 		}
L_end_EXT_INTO_Init:
	RETURN
; end of _EXT_INTO_Init

_EXT_INTO_Enable:

;ext_int_implementation.c,14 :: 		void EXT_INTO_Enable(void) {
;ext_int_implementation.c,15 :: 		INTCON |= 0x10;
	BSF        INTCON+0, 4
;ext_int_implementation.c,16 :: 		INTCON |= 0x80;
	BSF        INTCON+0, 7
;ext_int_implementation.c,17 :: 		}
L_end_EXT_INTO_Enable:
	RETURN
; end of _EXT_INTO_Enable

_EXT_INTO_SetEdge:

;ext_int_implementation.c,19 :: 		void EXT_INTO_SetEdge(u8 edge_type) {
;ext_int_implementation.c,20 :: 		if(edge_type == 1) {
	MOVF       FARG_EXT_INTO_SetEdge_edge_type+0, 0
	XORLW      1
	BTFSS      STATUS+0, 2
	GOTO       L_EXT_INTO_SetEdge0
;ext_int_implementation.c,21 :: 		OPTION_REG |= 0x40;
	BSF        OPTION_REG+0, 6
;ext_int_implementation.c,22 :: 		} else {
	GOTO       L_EXT_INTO_SetEdge1
L_EXT_INTO_SetEdge0:
;ext_int_implementation.c,23 :: 		OPTION_REG &= ~0x40;
	BCF        OPTION_REG+0, 6
;ext_int_implementation.c,24 :: 		}
L_EXT_INTO_SetEdge1:
;ext_int_implementation.c,25 :: 		}
L_end_EXT_INTO_SetEdge:
	RETURN
; end of _EXT_INTO_SetEdge

_EXT_INTO_SetCallback:

;ext_int_implementation.c,27 :: 		void EXT_INTO_SetCallback(void (*ptr)(void)) {
;ext_int_implementation.c,28 :: 		ext_int_callback = ptr;
	MOVF       FARG_EXT_INTO_SetCallback_ptr+0, 0
	MOVWF      ext_int_implementation_ext_int_callback+0
	MOVF       FARG_EXT_INTO_SetCallback_ptr+1, 0
	MOVWF      ext_int_implementation_ext_int_callback+1
	MOVF       FARG_EXT_INTO_SetCallback_ptr+2, 0
	MOVWF      ext_int_implementation_ext_int_callback+2
	MOVF       FARG_EXT_INTO_SetCallback_ptr+3, 0
;ext_int_implementation.c,29 :: 		}
L_end_EXT_INTO_SetCallback:
	RETURN
; end of _EXT_INTO_SetCallback

_interrupt:
	MOVWF      R15+0
	SWAPF      STATUS+0, 0
	CLRF       STATUS+0
	MOVWF      ___saveSTATUS+0
	MOVF       PCLATH+0, 0
	MOVWF      ___savePCLATH+0
	CLRF       PCLATH+0

;ext_int_implementation.c,31 :: 		void interrupt(void) {
;ext_int_implementation.c,32 :: 		if(INTCON & 0x02) {
	BTFSS      INTCON+0, 1
	GOTO       L_interrupt2
;ext_int_implementation.c,33 :: 		if(ext_int_callback != 0) {
	MOVF       ext_int_implementation_ext_int_callback+0, 0
	MOVWF      R1+0
	MOVF       ext_int_implementation_ext_int_callback+1, 0
	MOVWF      R1+1
	MOVF       ext_int_implementation_ext_int_callback+2, 0
	MOVWF      R1+2
	MOVF       ext_int_implementation_ext_int_callback+3, 0
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
;ext_int_implementation.c,34 :: 		ext_int_callback();
	MOVF       ext_int_implementation_ext_int_callback+0, 0
	MOVWF      ___DoICPAddr+0
	MOVF       ext_int_implementation_ext_int_callback+1, 0
	MOVWF      ___DoICPAddr+1
	CALL       _____DoIFC+0
;ext_int_implementation.c,35 :: 		}
L_interrupt3:
;ext_int_implementation.c,36 :: 		INTCON &= ~0x02;
	BCF        INTCON+0, 1
;ext_int_implementation.c,37 :: 		}
L_interrupt2:
;ext_int_implementation.c,38 :: 		if(INTCON & 0x04){
	BTFSS      INTCON+0, 2
	GOTO       L_interrupt4
;ext_int_implementation.c,40 :: 		TIMER0_ISR_Handler();
	CALL       _TIMER0_ISR_Handler+0
;ext_int_implementation.c,42 :: 		INTCON &= ~0x04;
	BCF        INTCON+0, 2
;ext_int_implementation.c,43 :: 		}
L_interrupt4:
;ext_int_implementation.c,44 :: 		}
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

ext_int_implementation____?ag:

L_end_ext_int_implementation___?ag:
	RETURN
; end of ext_int_implementation____?ag
