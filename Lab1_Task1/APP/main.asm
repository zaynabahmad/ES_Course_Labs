
main_delay_count:

;main.c,43 :: 		static void delay_count(unsigned long count)
;main.c,46 :: 		for(i = 0; i < count; i++)
	CLRF       R4+0
	CLRF       R4+1
	CLRF       R4+2
	CLRF       R4+3
L_main_delay_count0:
	MOVF       FARG_main_delay_count_count+3, 0
	SUBWF      R4+3, 0
	BTFSS      STATUS+0, 2
	GOTO       L_main_delay_count10
	MOVF       FARG_main_delay_count_count+2, 0
	SUBWF      R4+2, 0
	BTFSS      STATUS+0, 2
	GOTO       L_main_delay_count10
	MOVF       FARG_main_delay_count_count+1, 0
	SUBWF      R4+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L_main_delay_count10
	MOVF       FARG_main_delay_count_count+0, 0
	SUBWF      R4+0, 0
L_main_delay_count10:
	BTFSC      STATUS+0, 0
	GOTO       L_main_delay_count1
	MOVF       R4+0, 0
	MOVWF      R0+0
	MOVF       R4+1, 0
	MOVWF      R0+1
	MOVF       R4+2, 0
	MOVWF      R0+2
	MOVF       R4+3, 0
	MOVWF      R0+3
	INCF       R0+0, 1
	BTFSC      STATUS+0, 2
	INCF       R0+1, 1
	BTFSC      STATUS+0, 2
	INCF       R0+2, 1
	BTFSC      STATUS+0, 2
	INCF       R0+3, 1
	MOVF       R0+0, 0
	MOVWF      R4+0
	MOVF       R0+1, 0
	MOVWF      R4+1
	MOVF       R0+2, 0
	MOVWF      R4+2
	MOVF       R0+3, 0
	MOVWF      R4+3
;main.c,49 :: 		}
	GOTO       L_main_delay_count0
L_main_delay_count1:
;main.c,50 :: 		}
L_end_delay_count:
	RETURN
; end of main_delay_count

main_blink_leds:

;main.c,52 :: 		static void blink_leds(unsigned long on_time, unsigned long off_time)
;main.c,55 :: 		LED_On(LED1_PORT, LED1_PIN);
	MOVLW      1
	MOVWF      FARG_LED_On_port+0
	CLRF       FARG_LED_On_pin+0
	CALL       _LED_On+0
;main.c,56 :: 		LED_On(LED2_PORT, LED2_PIN);
	MOVLW      1
	MOVWF      FARG_LED_On_port+0
	MOVLW      1
	MOVWF      FARG_LED_On_pin+0
	CALL       _LED_On+0
;main.c,57 :: 		delay_count(on_time);
	MOVF       FARG_main_blink_leds_on_time+0, 0
	MOVWF      FARG_main_delay_count_count+0
	MOVF       FARG_main_blink_leds_on_time+1, 0
	MOVWF      FARG_main_delay_count_count+1
	MOVF       FARG_main_blink_leds_on_time+2, 0
	MOVWF      FARG_main_delay_count_count+2
	MOVF       FARG_main_blink_leds_on_time+3, 0
	MOVWF      FARG_main_delay_count_count+3
	CALL       main_delay_count+0
;main.c,60 :: 		LED_Off(LED1_PORT, LED1_PIN);
	MOVLW      1
	MOVWF      FARG_LED_Off_port+0
	CLRF       FARG_LED_Off_pin+0
	CALL       _LED_Off+0
;main.c,61 :: 		LED_Off(LED2_PORT, LED2_PIN);
	MOVLW      1
	MOVWF      FARG_LED_Off_port+0
	MOVLW      1
	MOVWF      FARG_LED_Off_pin+0
	CALL       _LED_Off+0
;main.c,62 :: 		delay_count(off_time);
	MOVF       FARG_main_blink_leds_off_time+0, 0
	MOVWF      FARG_main_delay_count_count+0
	MOVF       FARG_main_blink_leds_off_time+1, 0
	MOVWF      FARG_main_delay_count_count+1
	MOVF       FARG_main_blink_leds_off_time+2, 0
	MOVWF      FARG_main_delay_count_count+2
	MOVF       FARG_main_blink_leds_off_time+3, 0
	MOVWF      FARG_main_delay_count_count+3
	CALL       main_delay_count+0
;main.c,63 :: 		}
L_end_blink_leds:
	RETURN
; end of main_blink_leds

_main:

;main.c,66 :: 		void main(void)
;main.c,69 :: 		LED_Init(LED1_PORT, LED1_PIN);
	MOVLW      1
	MOVWF      FARG_LED_Init_port+0
	CLRF       FARG_LED_Init_pin+0
	CALL       _LED_Init+0
;main.c,70 :: 		LED_Init(LED2_PORT, LED2_PIN);
	MOVLW      1
	MOVWF      FARG_LED_Init_port+0
	MOVLW      1
	MOVWF      FARG_LED_Init_pin+0
	CALL       _LED_Init+0
;main.c,72 :: 		SWITCH_Init(SW1_PORT, SW1_PIN);
	MOVLW      1
	MOVWF      FARG_SWITCH_Init_port+0
	MOVLW      2
	MOVWF      FARG_SWITCH_Init_pin+0
	CALL       _SWITCH_Init+0
;main.c,73 :: 		SWITCH_Init(SW2_PORT, SW2_PIN);
	MOVLW      1
	MOVWF      FARG_SWITCH_Init_port+0
	MOVLW      3
	MOVWF      FARG_SWITCH_Init_pin+0
	CALL       _SWITCH_Init+0
;main.c,76 :: 		while(1)
L_main3:
;main.c,78 :: 		uint8 sw1_state = SWITCH_Read(SW1_PORT, SW1_PIN);
	MOVLW      1
	MOVWF      FARG_SWITCH_Read_port+0
	MOVLW      2
	MOVWF      FARG_SWITCH_Read_pin+0
	CALL       _SWITCH_Read+0
	MOVF       R0+0, 0
	MOVWF      main_sw1_state_L1+0
;main.c,79 :: 		uint8 sw2_state = SWITCH_Read(SW2_PORT, SW2_PIN);
	MOVLW      1
	MOVWF      FARG_SWITCH_Read_port+0
	MOVLW      3
	MOVWF      FARG_SWITCH_Read_pin+0
	CALL       _SWITCH_Read+0
	MOVF       R0+0, 0
	MOVWF      main_sw2_state_L1+0
;main.c,81 :: 		if(sw1_state == SWITCH_PRESSED)
	MOVF       main_sw1_state_L1+0, 0
	XORLW      0
	BTFSS      STATUS+0, 2
	GOTO       L_main5
;main.c,84 :: 		blink_leds(DELAY_200MS, DELAY_200MS);
	MOVLW      64
	MOVWF      FARG_main_blink_leds_on_time+0
	MOVLW      156
	MOVWF      FARG_main_blink_leds_on_time+1
	MOVLW      0
	MOVWF      FARG_main_blink_leds_on_time+2
	MOVLW      0
	MOVWF      FARG_main_blink_leds_on_time+3
	MOVLW      64
	MOVWF      FARG_main_blink_leds_off_time+0
	MOVLW      156
	MOVWF      FARG_main_blink_leds_off_time+1
	MOVLW      0
	MOVWF      FARG_main_blink_leds_off_time+2
	MOVLW      0
	MOVWF      FARG_main_blink_leds_off_time+3
	CALL       main_blink_leds+0
;main.c,85 :: 		}
	GOTO       L_main6
L_main5:
;main.c,86 :: 		else if(sw2_state == SWITCH_PRESSED)
	MOVF       main_sw2_state_L1+0, 0
	XORLW      0
	BTFSS      STATUS+0, 2
	GOTO       L_main7
;main.c,89 :: 		blink_leds(DELAY_500MS, DELAY_500MS);
	MOVLW      160
	MOVWF      FARG_main_blink_leds_on_time+0
	MOVLW      134
	MOVWF      FARG_main_blink_leds_on_time+1
	MOVLW      1
	MOVWF      FARG_main_blink_leds_on_time+2
	MOVLW      0
	MOVWF      FARG_main_blink_leds_on_time+3
	MOVLW      160
	MOVWF      FARG_main_blink_leds_off_time+0
	MOVLW      134
	MOVWF      FARG_main_blink_leds_off_time+1
	MOVLW      1
	MOVWF      FARG_main_blink_leds_off_time+2
	MOVLW      0
	MOVWF      FARG_main_blink_leds_off_time+3
	CALL       main_blink_leds+0
;main.c,90 :: 		}
	GOTO       L_main8
L_main7:
;main.c,94 :: 		LED_Off(LED1_PORT, LED1_PIN);
	MOVLW      1
	MOVWF      FARG_LED_Off_port+0
	CLRF       FARG_LED_Off_pin+0
	CALL       _LED_Off+0
;main.c,95 :: 		LED_Off(LED2_PORT, LED2_PIN);
	MOVLW      1
	MOVWF      FARG_LED_Off_port+0
	MOVLW      1
	MOVWF      FARG_LED_Off_pin+0
	CALL       _LED_Off+0
;main.c,96 :: 		}
L_main8:
L_main6:
;main.c,97 :: 		}
	GOTO       L_main3
;main.c,98 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
