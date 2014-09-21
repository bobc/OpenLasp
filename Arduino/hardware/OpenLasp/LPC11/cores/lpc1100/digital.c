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

#include <stdint.h>

#include "Arduino.h"

#include "gpio.h"

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

void pinMode(uint8_t pin, uint8_t mode)
{
	if (mode == OUTPUT) 
	 	gpioSetDir (g_APinDescription [pin].ubPort, 1 << g_APinDescription [pin].ubPin, gpioDirection_Output);
	else	 	
	 	gpioSetDir (g_APinDescription [pin].ubPort, 1 << g_APinDescription [pin].ubPin, gpioDirection_Input);
	
}

void digitalWrite(uint8_t pin, uint8_t value)
{
	gpioSetValue (g_APinDescription [pin].ubPort, 1 << g_APinDescription [pin].ubPin, value);
}

void digitalToggle(uint8_t pin)
{
	uint8_t value = gpioGetValue (g_APinDescription [pin].ubPort, 1 << g_APinDescription [pin].ubPin);
	 
	gpioSetValue (g_APinDescription [pin].ubPort, 1 << g_APinDescription [pin].ubPin, ~value);
}

int digitalRead(uint8_t pin)
{
	return gpioGetValue (g_APinDescription [pin].ubPort, 1 << g_APinDescription [pin].ubPin);
}
