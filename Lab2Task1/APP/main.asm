
_delay_ms:

;main.c,5 :: 		void delay_ms(int ms)
;main.c,8 :: 		for(i = 0; i < ms; i++)
	CLRF       R2+0
	CLRF       R2+1
L_delay_ms0:
	MOVLW      128
	XORWF      R2+1, 0
	MOVWF      R0+0
	MOVLW      128
	XORWF      FARG_delay_ms_ms+1, 0
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__delay_ms17
	MOVF       FARG_delay_ms_ms+0, 0
	SUBWF      R2+0, 0
L__delay_ms17:
	BTFSC      STATUS+0, 0
	GOTO       L_delay_ms1
;main.c,9 :: 		for(j = 0; j < 1000; j++);
	CLRF       R4+0
	CLRF       R4+1
L_delay_ms3:
	MOVLW      128
	XORWF      R4+1, 0
	MOVWF      R0+0
	MOVLW      128
	XORLW      3
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__delay_ms18
	MOVLW      232
	SUBWF      R4+0, 0
L__delay_ms18:
	BTFSC      STATUS+0, 0
	GOTO       L_delay_ms4
	MOVF       R4+0, 0
	ADDLW      1
	MOVWF      R0+0
	MOVLW      0
	BTFSC      STATUS+0, 0
	ADDLW      1
	ADDWF      R4+1, 0
	MOVWF      R0+1
	MOVF       R0+0, 0
	MOVWF      R4+0
	MOVF       R0+1, 0
	MOVWF      R4+1
	GOTO       L_delay_ms3
L_delay_ms4:
;main.c,8 :: 		for(i = 0; i < ms; i++)
	MOVF       R2+0, 0
	ADDLW      1
	MOVWF      R0+0
	MOVLW      0
	BTFSC      STATUS+0, 0
	ADDLW      1
	ADDWF      R2+1, 0
	MOVWF      R0+1
	MOVF       R0+0, 0
	MOVWF      R2+0
	MOVF       R0+1, 0
	MOVWF      R2+1
;main.c,9 :: 		for(j = 0; j < 1000; j++);
	GOTO       L_delay_ms0
L_delay_ms1:
;main.c,10 :: 		}
L_end_delay_ms:
	RETURN
; end of _delay_ms

_main:

;main.c,24 :: 		int main()
;main.c,27 :: 		ADCON1 = 0x06;  // all PORTA pins Digital
	MOVLW      6
	MOVWF      ADCON1+0
;main.c,30 :: 		GPIO_Init();
	CALL       _GPIO_Init+0
;main.c,31 :: 		LED_Init(LED1_PORT, LED1_PIN, LED2_PORT, LED2_PIN);
	MOVLW      1
	MOVWF      FARG_LED_Init_port1+0
	CLRF       FARG_LED_Init_pin1+0
	MOVLW      1
	MOVWF      FARG_LED_Init_port2+0
	MOVLW      1
	MOVWF      FARG_LED_Init_pin2+0
	CALL       _LED_Init+0
;main.c,34 :: 		setpindirection(SW1_PORT, SW1_PIN, INPUT);
	MOVLW      1
	MOVWF      FARG_setpindirection_port+0
	MOVLW      2
	MOVWF      FARG_setpindirection_pin+0
	MOVLW      1
	MOVWF      FARG_setpindirection_direction+0
	CALL       _setpindirection+0
;main.c,35 :: 		setpindirection(SW2_PORT, SW2_PIN, INPUT);
	MOVLW      1
	MOVWF      FARG_setpindirection_port+0
	MOVLW      3
	MOVWF      FARG_setpindirection_pin+0
	MOVLW      1
	MOVWF      FARG_setpindirection_direction+0
	CALL       _setpindirection+0
;main.c,37 :: 		while(1)
L_main6:
;main.c,40 :: 		if(getpinvalue(SW1_PORT, SW1_PIN) == 0)
	MOVLW      1
	MOVWF      FARG_getpinvalue_port+0
	MOVLW      2
	MOVWF      FARG_getpinvalue_pin+0
	CALL       _getpinvalue+0
	MOVF       R0+0, 0
	XORLW      0
	BTFSS      STATUS+0, 2
	GOTO       L_main8
;main.c,43 :: 		LED_On(LED1_PORT, LED1_PIN);
	MOVLW      1
	MOVWF      FARG_LED_On_port+0
	CLRF       FARG_LED_On_pin+0
	CALL       _LED_On+0
;main.c,44 :: 		LED_Off(LED2_PORT, LED2_PIN);
	MOVLW      1
	MOVWF      FARG_LED_Off_port+0
	MOVLW      1
	MOVWF      FARG_LED_Off_pin+0
	CALL       _LED_Off+0
;main.c,45 :: 		delay_ms(200);
	MOVLW      3
	MOVWF      R11+0
	MOVLW      8
	MOVWF      R12+0
	MOVLW      119
	MOVWF      R13+0
L_main9:
	DECFSZ     R13+0, 1
	GOTO       L_main9
	DECFSZ     R12+0, 1
	GOTO       L_main9
	DECFSZ     R11+0, 1
	GOTO       L_main9
;main.c,47 :: 		LED_Off(LED1_PORT, LED1_PIN);
	MOVLW      1
	MOVWF      FARG_LED_Off_port+0
	CLRF       FARG_LED_Off_pin+0
	CALL       _LED_Off+0
;main.c,48 :: 		LED_On(LED2_PORT, LED2_PIN);
	MOVLW      1
	MOVWF      FARG_LED_On_port+0
	MOVLW      1
	MOVWF      FARG_LED_On_pin+0
	CALL       _LED_On+0
;main.c,49 :: 		delay_ms(200);
	MOVLW      3
	MOVWF      R11+0
	MOVLW      8
	MOVWF      R12+0
	MOVLW      119
	MOVWF      R13+0
L_main10:
	DECFSZ     R13+0, 1
	GOTO       L_main10
	DECFSZ     R12+0, 1
	GOTO       L_main10
	DECFSZ     R11+0, 1
	GOTO       L_main10
;main.c,50 :: 		}
	GOTO       L_main11
L_main8:
;main.c,52 :: 		else if(getpinvalue(SW2_PORT, SW2_PIN) == 0)
	MOVLW      1
	MOVWF      FARG_getpinvalue_port+0
	MOVLW      3
	MOVWF      FARG_getpinvalue_pin+0
	CALL       _getpinvalue+0
	MOVF       R0+0, 0
	XORLW      0
	BTFSS      STATUS+0, 2
	GOTO       L_main12
;main.c,55 :: 		LED_On(LED1_PORT, LED1_PIN);
	MOVLW      1
	MOVWF      FARG_LED_On_port+0
	CLRF       FARG_LED_On_pin+0
	CALL       _LED_On+0
;main.c,56 :: 		LED_Off(LED2_PORT, LED2_PIN);
	MOVLW      1
	MOVWF      FARG_LED_Off_port+0
	MOVLW      1
	MOVWF      FARG_LED_Off_pin+0
	CALL       _LED_Off+0
;main.c,57 :: 		delay_ms(500);
	MOVLW      6
	MOVWF      R11+0
	MOVLW      19
	MOVWF      R12+0
	MOVLW      173
	MOVWF      R13+0
L_main13:
	DECFSZ     R13+0, 1
	GOTO       L_main13
	DECFSZ     R12+0, 1
	GOTO       L_main13
	DECFSZ     R11+0, 1
	GOTO       L_main13
	NOP
	NOP
;main.c,59 :: 		LED_Off(LED1_PORT, LED1_PIN);
	MOVLW      1
	MOVWF      FARG_LED_Off_port+0
	CLRF       FARG_LED_Off_pin+0
	CALL       _LED_Off+0
;main.c,60 :: 		LED_On(LED2_PORT, LED2_PIN);
	MOVLW      1
	MOVWF      FARG_LED_On_port+0
	MOVLW      1
	MOVWF      FARG_LED_On_pin+0
	CALL       _LED_On+0
;main.c,61 :: 		delay_ms(500);
	MOVLW      6
	MOVWF      R11+0
	MOVLW      19
	MOVWF      R12+0
	MOVLW      173
	MOVWF      R13+0
L_main14:
	DECFSZ     R13+0, 1
	GOTO       L_main14
	DECFSZ     R12+0, 1
	GOTO       L_main14
	DECFSZ     R11+0, 1
	GOTO       L_main14
	NOP
	NOP
;main.c,62 :: 		}
	GOTO       L_main15
L_main12:
;main.c,66 :: 		LED_Off(LED1_PORT, LED1_PIN);
	MOVLW      1
	MOVWF      FARG_LED_Off_port+0
	CLRF       FARG_LED_Off_pin+0
	CALL       _LED_Off+0
;main.c,67 :: 		LED_Off(LED2_PORT, LED2_PIN);
	MOVLW      1
	MOVWF      FARG_LED_Off_port+0
	MOVLW      1
	MOVWF      FARG_LED_Off_pin+0
	CALL       _LED_Off+0
;main.c,68 :: 		}
L_main15:
L_main11:
;main.c,69 :: 		}
	GOTO       L_main6
;main.c,72 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
