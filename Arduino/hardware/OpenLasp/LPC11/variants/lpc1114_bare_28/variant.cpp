/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "variant.h"

extern "C" {
// microbuilder LPC1114CodeBase
#include "gpio.h"
#include "systick.h"
#include "cpu.h"
#include "pmu.h"
#include "adc.h"
}

/*   Arduino     |    LPC1114
 * "Pin"| Label  |  pin   |  Functions  
 *  ----+--------+--------+------------
 *    0 | RX0    |  P1_6  |  RXD					PWM
 *    1 | TX0    |  P1_7  |  TXD          PWM
 *    2 | D2     |  P0_5  |       SDA
 *    3 | D3     |  P0_4  |       SCL
 *    4 | D4     |  P0_3  |
 *    5 | D5     |  P0_7  |
 *    6 | D6     |  P0_1  |               PWM
 *    7 | D7     |  P1_5  |
 *    8 | D8     |  P1_8  |
 *    9 | D9     |  P1_9  |               PWM
 *   10 | D10    |  P0_2  |       SS
 *   11 | D11    |  P0_9  |       MOSI    PWM
 *   12 | D12    |  P0_8  |       MISO    PWM
 *   13 | D13    |  P0_6  |       SCK
 *    
 *   14 | A0     |  P0_1  |  AD0          PWM
 *   15 | A1     |  P1_0  |  AD1
 *   16 | A2     |  P1_1  |  AD2          PWM
 *   17 | A3     |  P1_2  |  AD3          PWM
 *   18 | A4     |  P1_4  |  AD5          PWM
 *
 *   19 |        |  P0_0  |  RESET
 *   20 |        |  P0_10 |  SWCLK        PWM
 *   21 |        |  P1_3  |  SWDIO				PWM
 *    
 */

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Pins descriptions
 */
 // Port  Pin   Periph        PinConfig     PinType                           AnChan  ADCNum  PWMChan      TimerChan
extern const PinDescription g_APinDescription[]=
{
  // 0 .. 13 - Digital pins
  // ----------------------
  // 0/1 - UART (Serial)
  { 1,    6,    PIO_PERIPH_A, PIO_DEFAULT,  PIN_ATTR_DIGITAL,                 NO_ADC, NO_ADC, NOT_ON_PWM,  CT32_B0_MAT0 },
  { 1,    7,    PIO_PERIPH_A, PIO_DEFAULT,  PIN_ATTR_DIGITAL,                 NO_ADC, NO_ADC, NOT_ON_PWM,  CT32_B0_MAT1 },

  // 2
  { 0, 		5,		PIO_PERIPH_B, PIO_DEFAULT, (PIN_ATTR_DIGITAL|PIN_ATTR_TIMER), NO_ADC, NO_ADC, NOT_ON_PWM,  NOT_ON_TIMER},
  { 0,		4,		PIO_PERIPH_B, PIO_DEFAULT, (PIN_ATTR_DIGITAL|PIN_ATTR_TIMER), NO_ADC, NO_ADC, NOT_ON_PWM,  NOT_ON_TIMER},
  { 0,		3,		PIO_PERIPH_B, PIO_DEFAULT, (PIN_ATTR_DIGITAL|PIN_ATTR_TIMER), NO_ADC, NO_ADC, NOT_ON_PWM,  NOT_ON_TIMER},

  // 5
  { 0,		7,		PIO_PERIPH_B, PIO_DEFAULT, (PIN_ATTR_DIGITAL|PIN_ATTR_TIMER), NO_ADC, NO_ADC, NOT_ON_PWM,  NOT_ON_TIMER},
  { 0,		1,		PIO_PERIPH_B, PIO_DEFAULT, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM),   NO_ADC, NO_ADC, NOT_ON_PWM,  CT32_B0_MAT2 },
  { 1,		5,		PIO_PERIPH_B, PIO_DEFAULT, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM),   NO_ADC, NO_ADC, NOT_ON_PWM,  NOT_ON_TIMER },
  { 1,		8,		PIO_PERIPH_B, PIO_DEFAULT, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM),   NO_ADC, NO_ADC, NOT_ON_PWM,  NOT_ON_TIMER },
  { 1,		9,		PIO_PERIPH_B, PIO_DEFAULT, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM),   NO_ADC, NO_ADC, NOT_ON_PWM,  CT16_B1_MAT0 },
  // 10
  { 0,		2,		PIO_PERIPH_B, PIO_DEFAULT, (PIN_ATTR_DIGITAL|PIN_ATTR_TIMER), NO_ADC, NO_ADC, NOT_ON_PWM,  NOT_ON_TIMER},
  { 0,		9,		PIO_PERIPH_B, PIO_DEFAULT, (PIN_ATTR_DIGITAL|PIN_ATTR_TIMER), NO_ADC, NO_ADC, NOT_ON_PWM,  CT16_B0_MAT1},
  { 0,		8,		PIO_PERIPH_B, PIO_DEFAULT, (PIN_ATTR_DIGITAL|PIN_ATTR_TIMER), NO_ADC, NO_ADC, NOT_ON_PWM,  CT16_B0_MAT0},

  // 13
  { 0,		6,		PIO_PERIPH_B, PIO_DEFAULT, (PIN_ATTR_DIGITAL|PIN_ATTR_TIMER), NO_ADC, NO_ADC, NOT_ON_PWM,  NOT_ON_TIMER},

  // Analog pins
  // ----------------------
  { 0, 11,    	PIO_INPUT,    PIO_DEFAULT, PIN_ATTR_ANALOG,                   ADC0,   ADC0,   NOT_ON_PWM,  CT32_B0_MAT3 }, // AD0

  { 1, 0, 			PIO_INPUT,    PIO_DEFAULT, PIN_ATTR_ANALOG,                   ADC1,   ADC1,   NOT_ON_PWM,  NOT_ON_TIMER }, // AD1
  { 1, 1,       PIO_INPUT,    PIO_DEFAULT, PIN_ATTR_ANALOG,                   ADC2,   ADC2,   NOT_ON_PWM,  CT32_B1_MAT0 }, // AD2
  { 1, 2,       PIO_INPUT,    PIO_DEFAULT, PIN_ATTR_ANALOG,                   ADC3,   ADC3,   NOT_ON_PWM,  CT32_B1_MAT1 }, // AD3
  { 1, 4,       PIO_INPUT,    PIO_DEFAULT, PIN_ATTR_ANALOG,                   ADC4,   ADC5,   NOT_ON_PWM,  CT32_B1_MAT3 } // AD4

  // END
} ;

#ifdef __cplusplus
}
#endif

// ----------------------------------------------------------------------------
/*
 * UART objects
 */
//RingBuffer rx_buffer1;

SerialClass Serial (0);

void serialEvent() __attribute__((weak));
void serialEvent() { }

// IT handlers
// void UART_Handler(void)
// {
//   Serial.IrqHandler();
// }

// ----------------------------------------------------------------------------

void serialEventRun(void);

void serialEventRun(void)
{
  if (Serial.available()) serialEvent();
}

// ----------------------------------------------------------------------------

#ifdef __cplusplus
extern "C" {
#endif

void __libc_init_array(void);

void variant_init( void )
{
  cpuInit();
  systickInit((CFG_CPU_CCLK / 1000) * CFG_SYSTICK_DELAY_IN_MS);
  gpioInit();
  pmuInit();
  adcInit();    // Init adc pins to avoid wasting 60uA in deep sleep

// ----------------------------------------------------------------------------


  // Initialize C library
//?  __libc_init_array();

  // Disable pull-up on every pin
  
  
}

#ifdef __cplusplus
}
#endif

