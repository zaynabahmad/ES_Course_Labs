# --- Microcontroller and Compiler Settings ---
MCU = 16F877A
CC = xc8-cc
DFP_PATH = "C:/Users/Ziad/Desktop/Academic/College zewail city/Courses/CIE/Year 4/CIE 408 Embedded Systems/Compiler/Microchip.PIC16Fxxx_DFP.1.7.162/xc8"
CFLAGS = -mcpu=$(MCU) -Os -mdfp=$(DFP_PATH)

# --- Include Directories (Where your .h files live) ---
INCLUDES = -IAPP -IMCAL -IHAL -ISERVICES  

# --- Source Files (Where your .c files live) ---
SRCS = APP/main.c \
       HAL/LED/LED.c \
       HAL/MOTOR/MOTOR.c \
       MCAL/GPIO/GPIO.c \
       MCAL/INT/INT.c \
       MCAL/TIMER/TIMER.c \
       MCAL/TIMER/TIMER2/TIMER2.c \
       MCAL/PWM/PWM.c\

# --- Output Name ---
TARGET = Lab_2.hex

# --- Build Rules ---
all: $(TARGET)

$(TARGET): $(SRCS) 
	$(CC) $(CFLAGS) $(INCLUDES) $(SRCS) -o $(TARGET)

clean:
	del /Q /F *.elf *.cmf *.hxl *.sym *.sdb *.o *.p1 *.d *.s *.lst *.rlf __eeprom.* startup.*