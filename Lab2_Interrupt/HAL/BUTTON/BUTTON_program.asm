
_BUTTON_Init:

;BUTTON_program.c,10 :: 		void BUTTON_Init(void)
;BUTTON_program.c,12 :: 		EXT_INT0_Init();                              /* Configure RB0 as input, clear flag */
	CALL       _EXT_INT0_Init+0
;BUTTON_program.c,13 :: 		EXT_INT0_SetEdge(EXT_INT_FALLING_EDGE);       /* Trigger on button press (LOW) */
	CLRF       FARG_EXT_INT0_SetEdge_edge_type+0
	CALL       _EXT_INT0_SetEdge+0
;BUTTON_program.c,14 :: 		EXT_INT0_Enable();                            /* Enable INT0 + GIE */
	CALL       _EXT_INT0_Enable+0
;BUTTON_program.c,15 :: 		}
L_end_BUTTON_Init:
	RETURN
; end of _BUTTON_Init

_BUTTON_SetCallback:

;BUTTON_program.c,17 :: 		void BUTTON_SetCallback(void (*ptr)(void))
;BUTTON_program.c,19 :: 		EXT_INT0_SetCallback(ptr);                    /* Pass callback down to MCAL */
	MOVF       FARG_BUTTON_SetCallback_ptr+0, 0
	MOVWF      FARG_EXT_INT0_SetCallback_ptr+0
	MOVF       FARG_BUTTON_SetCallback_ptr+1, 0
	MOVWF      FARG_EXT_INT0_SetCallback_ptr+1
	MOVF       FARG_BUTTON_SetCallback_ptr+2, 0
	MOVWF      FARG_EXT_INT0_SetCallback_ptr+2
	MOVF       FARG_BUTTON_SetCallback_ptr+3, 0
	CALL       _EXT_INT0_SetCallback+0
;BUTTON_program.c,20 :: 		}
L_end_BUTTON_SetCallback:
	RETURN
; end of _BUTTON_SetCallback
