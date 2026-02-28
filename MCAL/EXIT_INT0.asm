
_EXT_INT0_Init:

;EXIT_INT0.c,5 :: 		void EXT_INT0_Init(void)
;EXIT_INT0.c,7 :: 		TRISB.F0 = 1;            // RB0 input
	BSF        TRISB+0, 0
;EXIT_INT0.c,8 :: 		INTCON.INTE = 0;         // Disable first
	BCF        INTCON+0, 4
;EXIT_INT0.c,9 :: 		INTCON.INTF = 0;         // Clear flag
	BCF        INTCON+0, 1
;EXIT_INT0.c,10 :: 		}
L_end_EXT_INT0_Init:
	RETURN
; end of _EXT_INT0_Init

_EXT_INT0_SetEdge:

;EXIT_INT0.c,12 :: 		void EXT_INT0_SetEdge(unsigned char edge_type)
;EXIT_INT0.c,14 :: 		OPTION_REG.INTEDG = edge_type;
	BTFSC      FARG_EXT_INT0_SetEdge_edge_type+0, 0
	GOTO       L__EXT_INT0_SetEdge4
	BCF        OPTION_REG+0, 6
	GOTO       L__EXT_INT0_SetEdge5
L__EXT_INT0_SetEdge4:
	BSF        OPTION_REG+0, 6
L__EXT_INT0_SetEdge5:
;EXIT_INT0.c,15 :: 		}
L_end_EXT_INT0_SetEdge:
	RETURN
; end of _EXT_INT0_SetEdge

_EXT_INT0_Enable:

;EXIT_INT0.c,17 :: 		void EXT_INT0_Enable(void)
;EXIT_INT0.c,19 :: 		INTCON.INTF = 0;
	BCF        INTCON+0, 1
;EXIT_INT0.c,20 :: 		INTCON.INTE = 1;
	BSF        INTCON+0, 4
;EXIT_INT0.c,21 :: 		INTCON.GIE  = 1;
	BSF        INTCON+0, 7
;EXIT_INT0.c,22 :: 		}
L_end_EXT_INT0_Enable:
	RETURN
; end of _EXT_INT0_Enable

_EXT_INT0_Disable:

;EXIT_INT0.c,24 :: 		void EXT_INT0_Disable(void)
;EXIT_INT0.c,26 :: 		INTCON.INTE = 0;
	BCF        INTCON+0, 4
;EXIT_INT0.c,27 :: 		}
L_end_EXT_INT0_Disable:
	RETURN
; end of _EXT_INT0_Disable

_EXT_INT0_SetCallback:

;EXIT_INT0.c,29 :: 		void EXT_INT0_SetCallback(void (*ptr)(void))
;EXIT_INT0.c,31 :: 		EXT_INT0_Callback = ptr;
	MOVF       FARG_EXT_INT0_SetCallback_ptr+0, 0
	MOVWF      EXIT_INT0_EXT_INT0_Callback+0
	MOVF       FARG_EXT_INT0_SetCallback_ptr+1, 0
	MOVWF      EXIT_INT0_EXT_INT0_Callback+1
	MOVF       FARG_EXT_INT0_SetCallback_ptr+2, 0
	MOVWF      EXIT_INT0_EXT_INT0_Callback+2
	MOVF       FARG_EXT_INT0_SetCallback_ptr+3, 0
;EXIT_INT0.c,32 :: 		}
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

;EXIT_INT0.c,34 :: 		void interrupt()
;EXIT_INT0.c,36 :: 		if(INTCON.INTF)
	BTFSS      INTCON+0, 1
	GOTO       L_interrupt0
;EXIT_INT0.c,38 :: 		if(EXT_INT0_Callback != 0)
	MOVF       EXIT_INT0_EXT_INT0_Callback+0, 0
	MOVWF      R1+0
	MOVF       EXIT_INT0_EXT_INT0_Callback+1, 0
	MOVWF      R1+1
	MOVF       EXIT_INT0_EXT_INT0_Callback+2, 0
	MOVWF      R1+2
	MOVF       EXIT_INT0_EXT_INT0_Callback+3, 0
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
	GOTO       L_interrupt1
;EXIT_INT0.c,40 :: 		EXT_INT0_Callback();   // Call application function
	MOVF       EXIT_INT0_EXT_INT0_Callback+0, 0
	MOVWF      ___DoICPAddr+0
	MOVF       EXIT_INT0_EXT_INT0_Callback+1, 0
	MOVWF      ___DoICPAddr+1
	CALL       _____DoIFC+0
;EXIT_INT0.c,41 :: 		}
L_interrupt1:
;EXIT_INT0.c,43 :: 		INTCON.INTF = 0;           // Clear flag
	BCF        INTCON+0, 1
;EXIT_INT0.c,44 :: 		}
L_interrupt0:
;EXIT_INT0.c,45 :: 		}
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

EXIT_INT0____?ag:

L_end_EXIT_INT0___?ag:
	RETURN
; end of EXIT_INT0____?ag
