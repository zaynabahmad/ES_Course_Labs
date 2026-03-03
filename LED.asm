
_LED_Init:

;LED.c,1 :: 		void LED_Init() {
;LED.c,2 :: 		TRISD.F0 = 0; // Let's assume LED is on RD0 (based on your snippet)
	BCF        TRISD+0, 0
;LED.c,3 :: 		PORTD.F0 = 0;
	BCF        PORTD+0, 0
;LED.c,4 :: 		}
L_end_LED_Init:
	RETURN
; end of _LED_Init

_LED_Toggle:

;LED.c,6 :: 		void LED_Toggle() {
;LED.c,7 :: 		PORTD.F0 = ~PORTD.F0;
	MOVLW      1
	XORWF      PORTD+0, 1
;LED.c,8 :: 		}
L_end_LED_Toggle:
	RETURN
; end of _LED_Toggle
