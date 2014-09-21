/**************************************************************************/
/*!
    @file     main.cpp

    @section LICENSE

		Redistribution and use in source and binary forms, with or without
		modification, are permitted provided that the following conditions are met:
		
			1. Redistributions of source code must retain the above copyright
			notice, this list of conditions and the following disclaimer.
			
			2. Redistributions in binary form must reproduce the above copyright
			notice, this list of conditions and the following disclaimer in the
			documentation and/or other materials provided with the distribution.
			
			3. Neither the name of the copyright holders nor the
			names of its contributors may be used to endorse or promote products
			derived from this software without specific prior written permission.
		
		THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ''AS IS'' AND ANY
		EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
		WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
		DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE FOR ANY
		DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
		(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
		LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
		ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
		(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
		SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


    Contributors:
    	Copyright (c) 2014, Bob Cousins

		This file contains the Arduino main() function.
		
*************************************************************************/


#define ARDUINO_MAIN
#include "Arduino.h"

extern "C" {

/**
 * Empty yield() hook.
 *
 * This function is intended to be used by library writers to build
 * libraries or sketches that supports cooperative threads.
 *
 * Its defined as a weak symbol and it can be redefined to implement a
 * real cooperative scheduler.
 */
static void __empty() {
	// Empty
}
void yield(void) __attribute__ ((weak, alias("__empty")));

} // extern "C"


int main(void)
{
  /* Initialise the variant */
	variant_init();

  setup();
  
  while(1) 
	{
		loop();
	}
	
	return 0;
}

/******************************************************************************
**************************************************************************/
