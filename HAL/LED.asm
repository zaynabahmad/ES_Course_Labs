
_LED_Init:

;LED.c,3 :: 		void LED_Init(void)
;LED.c,5 :: 		TRISC.F0 = 0;
	BCF        TRISC+0, 0
;LED.c,6 :: 		PORTC.F0 = 0;
	BCF        PORTC+0, 0
;LED.c,7 :: 		}
L_end_LED_Init:
	RETURN
; end of _LED_Init

_LED_Toggle:

;LED.c,9 :: 		void LED_Toggle(void)
;LED.c,11 :: 		PORTC.F0 = ~PORTC.F0;
	MOVLW      1
	XORWF      PORTC+0, 1
;LED.c,12 :: 		}
L_end_LED_Toggle:
	RETURN
; end of _LED_Toggle
