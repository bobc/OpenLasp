/**************************************************************************/
/*!
    @file     tone.c
    @author   ChrisMicro

    @brief    sound generator

    @section LICENSE see below for my code contribution

*/
/**************************************************************************/
#include "arduino.h"
#include "tone.h"
#include "mrt.h"

uint8_t TonePin;

void arduinoSound(uint16_t frequency, uint16_t duration_ms)
{
	uint16_t n;
	uint32_t delay_us;

	delay_us=1000000UL/frequency/2;
	//cli();
	for(n=0;n<(duration_ms*1000/delay_us);n++)
	{
      digitalToggle(TonePin);
	  delayMicroseconds(delay_us);
	}
	//sei();
}

void tone(uint8_t pin, uint32_t frequency, uint16_t duration_ms)
{
	pinMode(pin, OUTPUT);
	TonePin=pin;
	arduinoSound(frequency, duration_ms);
}

void noTone(uint8_t pin)
{
	// tbd
}
