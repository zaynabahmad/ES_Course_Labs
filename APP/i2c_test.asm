
_i2c_test_run:

;i2c_test.c,3 :: 		void i2c_test_run(void) {
;i2c_test.c,4 :: 		I2C_Master_Init(100000);
	MOVLW      160
	MOVWF      FARG_I2C_Master_Init_Clock+0
	MOVLW      134
	MOVWF      FARG_I2C_Master_Init_Clock+1
	MOVLW      1
	MOVWF      FARG_I2C_Master_Init_Clock+2
	MOVLW      0
	MOVWF      FARG_I2C_Master_Init_Clock+3
	CALL       _I2C_Master_Init+0
;i2c_test.c,5 :: 		I2C_Master_Start();
	CALL       _I2C_Master_Start+0
;i2c_test.c,6 :: 		I2C_Master_Write(0xA0);
	MOVLW      160
	MOVWF      FARG_I2C_Master_Write_Data+0
	CALL       _I2C_Master_Write+0
;i2c_test.c,7 :: 		I2C_Master_Write(0x00);
	CLRF       FARG_I2C_Master_Write_Data+0
	CALL       _I2C_Master_Write+0
;i2c_test.c,8 :: 		I2C_Master_Write(0xFF);
	MOVLW      255
	MOVWF      FARG_I2C_Master_Write_Data+0
	CALL       _I2C_Master_Write+0
;i2c_test.c,9 :: 		I2C_Master_Stop();
	CALL       _I2C_Master_Stop+0
;i2c_test.c,10 :: 		}
L_end_i2c_test_run:
	RETURN
; end of _i2c_test_run
