
_Timer_Task:

;main.c,9 :: 		void Timer_Task(void)
;main.c,11 :: 		counter_led1++;
	INCF       main_counter_led1+0, 1
;main.c,12 :: 		counter_led2++;
	INCF       main_counter_led2+0, 1
;main.c,15 :: 		if(counter_led2 >= 10)
	MOVLW      10
	SUBWF      main_counter_led2+0, 0
	BTFSS      STATUS+0, 0
	GOTO       L_Timer_Task0
;main.c,17 :: 		LED_Toggle(_PORTC,0);
	MOVLW      2
	MOVWF      FARG_LED_Toggle_port+0
	CLRF       FARG_LED_Toggle_pin+0
	CALL       _LED_Toggle+0
;main.c,18 :: 		counter_led2 = 0;
	CLRF       main_counter_led2+0
;main.c,19 :: 		}
L_Timer_Task0:
;main.c,22 :: 		if(counter_led1 >= 20)
	MOVLW      20
	SUBWF      main_counter_led1+0, 0
	BTFSS      STATUS+0, 0
	GOTO       L_Timer_Task1
;main.c,24 :: 		LED_Toggle(_PORTC,1);
	MOVLW      2
	MOVWF      FARG_LED_Toggle_port+0
	MOVLW      1
	MOVWF      FARG_LED_Toggle_pin+0
	CALL       _LED_Toggle+0
;main.c,25 :: 		counter_led1 = 0;
	CLRF       main_counter_led1+0
;main.c,26 :: 		}
L_Timer_Task1:
;main.c,27 :: 		}
L_end_Timer_Task:
	RETURN
; end of _Timer_Task

_main:

;main.c,29 :: 		void main()
;main.c,32 :: 		LED_Init(_PORTC,0);
	MOVLW      2
	MOVWF      FARG_LED_Init_port+0
	CLRF       FARG_LED_Init_pin+0
	CALL       _LED_Init+0
;main.c,33 :: 		LED_Init(_PORTC,1);
	MOVLW      2
	MOVWF      FARG_LED_Init_port+0
	MOVLW      1
	MOVWF      FARG_LED_Init_pin+0
	CALL       _LED_Init+0
;main.c,36 :: 		TIMER0_SetCallback(Timer_Task);
	MOVLW      _Timer_Task+0
	MOVWF      FARG_TIMER0_SetCallback_ptr+0
	MOVLW      hi_addr(_Timer_Task+0)
	MOVWF      FARG_TIMER0_SetCallback_ptr+1
	MOVLW      0
	MOVWF      FARG_TIMER0_SetCallback_ptr+2
	MOVLW      0
	CALL       _TIMER0_SetCallback+0
;main.c,37 :: 		TIMER0_Init();
	CALL       _TIMER0_Init+0
;main.c,39 :: 		while(1)
L_main2:
;main.c,42 :: 		}
	GOTO       L_main2
;main.c,43 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
