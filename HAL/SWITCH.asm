
_SWITCH_Init:

;SWITCH.c,3 :: 		void SWITCH_Init(unsigned char pin)
;SWITCH.c,5 :: 		TRISB.F0 = 1;
	BSF        TRISB+0, 0
;SWITCH.c,6 :: 		}
L_end_SWITCH_Init:
	RETURN
; end of _SWITCH_Init
