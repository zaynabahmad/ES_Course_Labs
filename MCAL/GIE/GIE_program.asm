
_GIE_voidEnable:

;GIE_program.c,5 :: 		void GIE_voidEnable(void) {
;GIE_program.c,6 :: 		INTCON |= (1 << 7);
	BSF        11, 7
;GIE_program.c,7 :: 		}
L_end_GIE_voidEnable:
	RETURN
; end of _GIE_voidEnable

_GIE_voidDisable:

;GIE_program.c,9 :: 		void GIE_voidDisable(void) {
;GIE_program.c,10 :: 		INTCON &= ~(1 << 7);
	BCF        11, 7
;GIE_program.c,11 :: 		}
L_end_GIE_voidDisable:
	RETURN
; end of _GIE_voidDisable
