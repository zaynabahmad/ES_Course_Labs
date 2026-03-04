
_EXT_INT0_SetCallback:

;EXT_INT_program.c,26 :: 		void EXT_INT0_SetCallback(void (*ptr)(void))
;EXT_INT_program.c,28 :: 		EXT_INT0_Callback = ptr;
	MOVF       FARG_EXT_INT0_SetCallback_ptr+0, 0
	MOVWF      EXT_INT_program_EXT_INT0_Callback+0
	MOVF       FARG_EXT_INT0_SetCallback_ptr+1, 0
	MOVWF      EXT_INT_program_EXT_INT0_Callback+1
	MOVF       FARG_EXT_INT0_SetCallback_ptr+2, 0
	MOVWF      EXT_INT_program_EXT_INT0_Callback+2
	MOVF       FARG_EXT_INT0_SetCallback_ptr+3, 0
;EXT_INT_program.c,29 :: 		}
L_end_EXT_INT0_SetCallback:
	RETURN
; end of _EXT_INT0_SetCallback

_EXT_INT0_Init:

;EXT_INT_program.c,32 :: 		void EXT_INT0_Init(void)
;EXT_INT_program.c,35 :: 		SET_BIT(TRISB, 0);
	BSF        TRISB+0, 0
;EXT_INT_program.c,38 :: 		CLEAR_BIT(OPTION_REG, INTEDG_BIT);
	BCF        OPTION_REG+0, 6
;EXT_INT_program.c,41 :: 		EXT_INT0_ClearFlag();
	CALL       _EXT_INT0_ClearFlag+0
;EXT_INT_program.c,42 :: 		}
L_end_EXT_INT0_Init:
	RETURN
; end of _EXT_INT0_Init

_EXT_INT0_SetEdge:

;EXT_INT_program.c,45 :: 		void EXT_INT0_SetEdge(uint8 edge_type)
;EXT_INT_program.c,47 :: 		if(edge_type == EXT_INT_RISING_EDGE)
	MOVF       FARG_EXT_INT0_SetEdge_edge_type+0, 0
	XORLW      1
	BTFSS      STATUS+0, 2
	GOTO       L_EXT_INT0_SetEdge0
;EXT_INT_program.c,48 :: 		SET_BIT(OPTION_REG, INTEDG_BIT);
	BSF        OPTION_REG+0, 6
	GOTO       L_EXT_INT0_SetEdge1
L_EXT_INT0_SetEdge0:
;EXT_INT_program.c,50 :: 		CLEAR_BIT(OPTION_REG, INTEDG_BIT);
	BCF        OPTION_REG+0, 6
L_EXT_INT0_SetEdge1:
;EXT_INT_program.c,51 :: 		}
L_end_EXT_INT0_SetEdge:
	RETURN
; end of _EXT_INT0_SetEdge

_EXT_INT0_Enable:

;EXT_INT_program.c,54 :: 		void EXT_INT0_Enable(void)
;EXT_INT_program.c,56 :: 		SET_BIT(INTCON, INTE_BIT);   /* Enable external interrupt */
	BSF        INTCON+0, 4
;EXT_INT_program.c,57 :: 		SET_BIT(INTCON, GIE_BIT);    /* Enable global interrupt   */
	BSF        INTCON+0, 7
;EXT_INT_program.c,58 :: 		}
L_end_EXT_INT0_Enable:
	RETURN
; end of _EXT_INT0_Enable

_EXT_INT0_Disable:

;EXT_INT_program.c,61 :: 		void EXT_INT0_Disable(void)
;EXT_INT_program.c,63 :: 		CLEAR_BIT(INTCON, INTE_BIT);
	BCF        INTCON+0, 4
;EXT_INT_program.c,64 :: 		}
L_end_EXT_INT0_Disable:
	RETURN
; end of _EXT_INT0_Disable

_EXT_INT0_ClearFlag:

;EXT_INT_program.c,67 :: 		void EXT_INT0_ClearFlag(void)
;EXT_INT_program.c,69 :: 		CLEAR_BIT(INTCON, INTF_BIT);
	BCF        INTCON+0, 1
;EXT_INT_program.c,70 :: 		}
L_end_EXT_INT0_ClearFlag:
	RETURN
; end of _EXT_INT0_ClearFlag

_interrupt:
	MOVWF      R15+0
	SWAPF      STATUS+0, 0
	CLRF       STATUS+0
	MOVWF      ___saveSTATUS+0
	MOVF       PCLATH+0, 0
	MOVWF      ___savePCLATH+0
	CLRF       PCLATH+0

;EXT_INT_program.c,80 :: 		void interrupt(void)
;EXT_INT_program.c,83 :: 		if(READ_BIT(INTCON, INTF_BIT))
	MOVF       INTCON+0, 0
	MOVWF      R1+0
	RRF        R1+0, 1
	BCF        R1+0, 7
	BTFSS      R1+0, 0
	GOTO       L_interrupt2
;EXT_INT_program.c,86 :: 		if(EXT_INT0_Callback != 0)
	MOVF       EXT_INT_program_EXT_INT0_Callback+0, 0
	MOVWF      R1+0
	MOVF       EXT_INT_program_EXT_INT0_Callback+1, 0
	MOVWF      R1+1
	MOVF       EXT_INT_program_EXT_INT0_Callback+2, 0
	MOVWF      R1+2
	MOVF       EXT_INT_program_EXT_INT0_Callback+3, 0
	MOVWF      R1+3
	MOVLW      0
	MOVWF      R0+0
	XORWF      R1+3, 0
	BTFSS      STATUS+0, 2
	GOTO       L__interrupt12
	MOVF       R0+0, 0
	XORWF      R1+2, 0
	BTFSS      STATUS+0, 2
	GOTO       L__interrupt12
	MOVF       R0+0, 0
	XORWF      R1+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__interrupt12
	MOVF       R1+0, 0
	XORLW      0
L__interrupt12:
	BTFSC      STATUS+0, 2
	GOTO       L_interrupt3
;EXT_INT_program.c,88 :: 		EXT_INT0_Callback();
	MOVF       EXT_INT_program_EXT_INT0_Callback+0, 0
	MOVWF      ___DoICPAddr+0
	MOVF       EXT_INT_program_EXT_INT0_Callback+1, 0
	MOVWF      ___DoICPAddr+1
	CALL       _____DoIFC+0
;EXT_INT_program.c,89 :: 		}
L_interrupt3:
;EXT_INT_program.c,92 :: 		EXT_INT0_ClearFlag();
	CALL       _EXT_INT0_ClearFlag+0
;EXT_INT_program.c,93 :: 		}
L_interrupt2:
;EXT_INT_program.c,94 :: 		}
L_end_interrupt:
L__interrupt11:
	MOVF       ___savePCLATH+0, 0
	MOVWF      PCLATH+0
	SWAPF      ___saveSTATUS+0, 0
	MOVWF      STATUS+0
	SWAPF      R15+0, 1
	SWAPF      R15+0, 0
	RETFIE
; end of _interrupt

EXT_INT_program____?ag:

L_end_EXT_INT_program___?ag:
	RETURN
; end of EXT_INT_program____?ag
