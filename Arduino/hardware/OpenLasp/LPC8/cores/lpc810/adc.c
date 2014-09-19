/**************************************************************************/
/*!
    @file     adc.c
    @author   ChrisMicro
    @author   unknown others
    @brief    ADC functions, LPC810 has no ADC therefore other tricks are used

    @section LICENSE see below for my code contribution

*/
/**************************************************************************/
#include "LPC8xx.h"
#include "adc.h"
#include "mrt.h"

uint16_t read_adc2();

// tbd: channel selection
void init_adc(uint8_t channel)
{
	 // Enable AHB clock to the ACMP
	 LPC_SYSCON->SYSAHBCLKCTRL |=  (1 << 19);

	 // Enable fixed function ACMP_I2. This function is connected on pin PIO0_1
	 LPC_SWM->PINENABLE0 &= (~0x2);

	 // Initialize the comparator ICMP_2
	 LPC_SYSCON->PDRUNCFG &= ~((1 << 15)); // power up ACMP

}

uint16_t read_adc(uint8_t channel)
{
	return read_adc2(); // tbd: other channels
}

/*
 *
 * Use ACMP_2 as a simple 5 bit SAR adc
 *
 * copied from:
 * http://blog.nano-age.co.uk/2014/08/creating-5-bit-successive-approximation.html
 *
 * LICENSE: unclear
 *
 * */

uint16_t read_adc2()
{
	int min = 0, max = 63, value = 31, count, compstat, laststat;

	LPC_CMP->CTRL = (0x2 << 8) | (0x3 << 25); /* positive input ACMP0_I2 , negative input voltage ladder , 20mV hysteresis */

	while (!((value == min) || (value == max)))
	{
		  count = 0;
		  LPC_CMP->LAD = 1 | (value); /* ladder Enable | Vref=Vdd | value */

		  delayMicroseconds(15); // 15us worst case for ladder to settle

		  laststat = (LPC_CMP->CTRL >> 21) & 1;

		  // wait till reading is the same 3 times in row
		  do
		  {
			  delayMicroseconds(1); // minimum wait time: 0.5us

			  compstat = (LPC_CMP->CTRL >> 21) & 1;
			  if (compstat == laststat)
				   count++;
			  else
				   count = 0;
			  laststat = compstat;
		  } while (count < 3);

		  // Binary divide
		  if (compstat)
		  {
			   min = value;
			   value = value + ((max - value) >> 1);
		  } else
		  {
			   max = value;
			   value = value - ((value - min) >> 1);
		  }
	}
	return value >> 1;
}

/***********************************************************************************

    Software License Agreement (BSD License)

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

***********************************************************************************/


