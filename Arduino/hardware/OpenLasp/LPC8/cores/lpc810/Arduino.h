/*
  Arduino.h - Main include file for the Arduino SDK

  Copyright (c) 2014 ChrisMicro.  All right reserved.

*/

#ifndef Arduino_h
#define Arduino_h

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//!#include "LPC8xx.h"
#include "gpio.h"
#include "uart.h"
#include "adc.h"
#include "sct.h"
#include "tone.h"


#define INPUT 	0
#define OUTPUT 	1

#define LOW 	0
#define HIGH 	1

// adc
#define A1 1 // channel 1

#ifdef __cplusplus
extern "C"{
#endif // __cplusplus

#include "mrt.h"

void pinMode(uint8_t pin, uint8_t mode);
void digitalWrite(uint8_t pin, uint8_t value);
void digitalToggle(uint8_t Pin);
int digitalRead(uint8_t pin);
void delay(uint32_t milliSeconds);
void Serial_begin(uint32_t baudRate);
void Serial_print(char * string);
void Serial_println(char * string);
void Serial_printnumber(uint32_t number);
uint32_t millis();
uint16_t analogRead(uint8_t channel );
void analogWrite(uint8_t analogOutPin, uint16_t value);
int32_t map(int32_t x, int32_t in_min, int32_t in_max, int32_t out_min, int32_t out_max);

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus



#endif // Arduino_h
