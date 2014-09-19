/**************************************************************************/
/*!
    @file     mrt.c
    @author   K. Townsend
    @author   ChrisMicro
    @brief    Multi-rate timer (mrt) helper functions

    @section LICENSE see below

    Software License Agreement (BSD License)

    Copyright (c) 2013, K. Townsend (microBuilder.eu)
    All rights reserved.


    9.2014 / ChrisMicro / Arduino millis(), micros() function added


*/
/**************************************************************************/
#include "LPC8xx.h"
#include "mrt.h"

// from http://blog.nano-age.co.uk/2014/08/microsecond-delays-using-lpc810s-multi.html
// MRT3 (halt_clk) bus stall mode , no interrupts
#define INIT_US_TIMER { LPC_MRT->Channel[3].CTRL |= (0x02 << 1);}
#define halt_clk(c) LPC_MRT->Channel[3].INTVAL = (c-3)

volatile uint32_t mrt_counter = 0;

void MRT_IRQHandler(void)
{
  if ( LPC_MRT->Channel[0].STAT & MRT_STAT_IRQ_FLAG )
  {
    LPC_MRT->Channel[0].STAT = MRT_STAT_IRQ_FLAG;      /* clear interrupt flag */
    mrt_counter++;
  }
  return;
}

void mrtInit(uint32_t delay)
{
  /* Enable clock to MRT and reset the MRT peripheral */
  LPC_SYSCON->SYSAHBCLKCTRL |=  (0x1<<10);
  LPC_SYSCON->PRESETCTRL    &= ~(0x1<<7);
  LPC_SYSCON->PRESETCTRL    |=  (0x1<<7);

  mrt_counter = 0;
  LPC_MRT->Channel[0].INTVAL = delay;
  LPC_MRT->Channel[0].INTVAL |= 0x1UL<<31;

  LPC_MRT->Channel[0].CTRL = MRT_REPEATED_MODE|MRT_INT_ENA;

  /* Enable the MRT Interrupt */
#if NMI_ENABLED
  NVIC_DisableIRQ( MRT_IRQn );
  NMI_Init( MRT_IRQn );
#else
  NVIC_EnableIRQ(MRT_IRQn);
#endif

  INIT_US_TIMER;
  return;
}

void mrtDelay(uint32_t ticks)
{
  mrt_counter = 0;
  while(mrt_counter < ticks);
}

uint32_t millis()
{
	return mrt_counter;
}

uint32_t micros()
{
	return mrt_counter*1000; // tbd: change timer resolution
}

inline void delayMicroseconds(uint32_t us)
{
	halt_clk(us*30); // us delay for 30MHz clk
}
/******************************************************************************
 *
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
*/
/**************************************************************************/
