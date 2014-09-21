/*
  Contributors:
  Copyright (c) 2014 Bob Cousins bobcousins42@googlemail.com
*/
/* **************************************************************************
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
****************************************************************************/

// **************************************************************************
// Description:
//
// **************************************************************************

#ifndef _DIGITAL_H
#define _DIGITAL_H

// --------------------------------------------------------------------------
// Includes
// --------------------------------------------------------------------------

#include <stdint.h>

// --------------------------------------------------------------------------
// Defines
// --------------------------------------------------------------------------

#define LOW 	0
#define HIGH 	1

#define INPUT 				0
#define OUTPUT 				1
#define INPUT_PULLUP	2


// --------------------------------------------------------------------------
// Types
// --------------------------------------------------------------------------

// --------------------------------------------------------------------------
// Public Variables
// --------------------------------------------------------------------------

// --------------------------------------------------------------------------
// Public functions
// --------------------------------------------------------------------------
#ifdef __cplusplus
extern "C"{
#endif // __cplusplus

void pinMode(uint8_t pin, uint8_t mode);
void digitalWrite(uint8_t pin, uint8_t value);
void digitalToggle(uint8_t Pin);
int digitalRead(uint8_t pin);

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

// --------------------------------------------------------------------------
//
// --------------------------------------------------------------------------

#endif // _DIGITAL_H

