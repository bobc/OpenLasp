/* 
   Contributors:
   Copyright (c) 2014 Bob Cousins bobcousins42@googlemail.com       
*/

/*
 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

// **************************************************************************
// Description:
//
// **************************************************************************

// --------------------------------------------------------------------------
// Includes
// --------------------------------------------------------------------------

#include "Arduino.h"

#include "analog.h"

#include "adc.h"

// --------------------------------------------------------------------------
// Externals
// --------------------------------------------------------------------------

// --------------------------------------------------------------------------
// Local defines
// --------------------------------------------------------------------------

// --------------------------------------------------------------------------
// Types
// --------------------------------------------------------------------------

// --------------------------------------------------------------------------
// Variables
// --------------------------------------------------------------------------

// --------------------------------------------------------------------------
// Public Variables
// --------------------------------------------------------------------------

// --------------------------------------------------------------------------
// Private Variables
// --------------------------------------------------------------------------

// --------------------------------------------------------------------------
// Function prototypes
// --------------------------------------------------------------------------

// --------------------------------------------------------------------------
// Private functions
// --------------------------------------------------------------------------

// --------------------------------------------------------------------------
// Public functions
// --------------------------------------------------------------------------

// --------------------------------------------------------------------------
//
// --------------------------------------------------------------------------

// --------------------------------------------------------------------------
//! @brief
//! @param[in]
//! @param[out]
//! @return
// --------------------------------------------------------------------------

// https://code.google.com/p/arduino/source/browse/trunk/hardware/arduino/cores/arduino/WMath.cpp
int32_t map(int32_t x, int32_t in_min, int32_t in_max, int32_t out_min, int32_t out_max)
{
  int32_t value=(x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
  return value;
}


uint16_t analogRead (uint8_t pin)
{
	return 	adcRead_adc (g_APinDescription [pin].ulADCChannelNumber);
}

void analogWrite(uint8_t analogOutPin, uint16_t value)
{
//todo: other pins

	pwmInit ();

  pwmSetDutyCycle(map (value, 0, 255, 0, 100));
  pwmSetFrequencyInMicroseconds(100);	// 10 kHz   

  pwmStart();
}
