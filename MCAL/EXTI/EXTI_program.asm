
_EXTI_voidEnable:

;EXTI_program.c,7 :: 		void EXTI_voidEnable(void)
;EXTI_program.c,9 :: 		SET_BIT(INTCON,7); // GIE
	BSF        11, 7
;EXTI_program.c,10 :: 		SET_BIT(INTCON,4); // INTE
	BSF        11, 4
;EXTI_program.c,11 :: 		}
L_end_EXTI_voidEnable:
	RETURN
; end of _EXTI_voidEnable
