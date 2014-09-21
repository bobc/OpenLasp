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

#include "serial.h"

#include "uart.h"

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

/*
 *
 */

// Constructors ////////////////////////////////////////////////////////////////

SerialClass::SerialClass (uint8_t uartNum)
{

}

// Public Methods //////////////////////////////////////////////////////////////

//TODO:

int SerialClass::peek( void )
{
}

int SerialClass::read( void )
{
}

void SerialClass::flush( void )
{
  // Wait for transmission to complete
}

size_t SerialClass::write( const uint8_t uc_data )
{
  // Send character

  return 1;
}


void SerialClass::begin(uint32_t baudRate)
{
	uartInit(baudRate);
}

void SerialClass::end()
{

}

int	SerialClass::available()
{
//
}

void SerialClass::IrqHandler( void )
{
}

//

void SerialClass::print(char * string)
{
	printf("%s",string);
}

void SerialClass::print(uint32_t number)
{
	printf("%d ",number);
}

void SerialClass::println(char * string)
{
	printf("%s\n\r",string);
}


