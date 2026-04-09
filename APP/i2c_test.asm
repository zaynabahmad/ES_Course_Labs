
_app_i2c_test:

;i2c_test.c,5 :: 		void app_i2c_test(void)
;i2c_test.c,7 :: 		u8 ackStatus = 0;
;i2c_test.c,8 :: 		u16 delayValue = 0;
	CLRF       app_i2c_test_delayValue_L0+0
;i2c_test.c,10 :: 		GPIO_setPinDirection(GPIO_PORTD, GPIO_PIN0, GPIO_OUTPUT);
	MOVLW      3
	MOVWF      FARG_GPIO_setPinDirection_port+0
	CLRF       FARG_GPIO_setPinDirection_pin+0
	CLRF       FARG_GPIO_setPinDirection_direction+0
	CALL       _GPIO_setPinDirection+0
;i2c_test.c,12 :: 		I2C_Init();
	CALL       _I2C_Init+0
;i2c_test.c,14 :: 		while(1)
L_app_i2c_test0:
;i2c_test.c,16 :: 		I2C_Start();
	CALL       _I2C_Start+0
;i2c_test.c,19 :: 		ackStatus = I2C_Write(0xA0);
	MOVLW      160
	MOVWF      FARG_I2C_Write_txValue+0
	CALL       _I2C_Write+0
;i2c_test.c,21 :: 		if(ackStatus == 0)
	MOVF       R0+0, 0
	XORLW      0
	BTFSS      STATUS+0, 2
	GOTO       L_app_i2c_test2
;i2c_test.c,23 :: 		I2C_Write(0x00);
	CLRF       FARG_I2C_Write_txValue+0
	CALL       _I2C_Write+0
;i2c_test.c,24 :: 		I2C_Write(0x55);
	MOVLW      85
	MOVWF      FARG_I2C_Write_txValue+0
	CALL       _I2C_Write+0
;i2c_test.c,25 :: 		LED_On(GPIO_PORTD, GPIO_PIN0);
	MOVLW      3
	MOVWF      FARG_LED_On_port+0
	CLRF       FARG_LED_On_pin+0
	CALL       _LED_On+0
;i2c_test.c,26 :: 		}
	GOTO       L_app_i2c_test3
L_app_i2c_test2:
;i2c_test.c,29 :: 		LED_Off(GPIO_PORTD, GPIO_PIN0);
	MOVLW      3
	MOVWF      FARG_LED_Off_port+0
	CLRF       FARG_LED_Off_pin+0
	CALL       _LED_Off+0
;i2c_test.c,30 :: 		}
L_app_i2c_test3:
;i2c_test.c,32 :: 		I2C_Stop();
	CALL       _I2C_Stop+0
;i2c_test.c,34 :: 		for(delayValue = 0; delayValue < 10000; delayValue++)
	CLRF       app_i2c_test_delayValue_L0+0
L_app_i2c_test4:
	MOVLW      128
	MOVWF      R0+0
	MOVLW      128
	XORLW      39
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__app_i2c_test8
	MOVLW      16
	SUBWF      app_i2c_test_delayValue_L0+0, 0
L__app_i2c_test8:
	BTFSC      STATUS+0, 0
	GOTO       L_app_i2c_test5
	INCF       app_i2c_test_delayValue_L0+0, 1
;i2c_test.c,37 :: 		}
	GOTO       L_app_i2c_test4
L_app_i2c_test5:
;i2c_test.c,38 :: 		}
	GOTO       L_app_i2c_test0
;i2c_test.c,39 :: 		}
L_end_app_i2c_test:
	RETURN
; end of _app_i2c_test
