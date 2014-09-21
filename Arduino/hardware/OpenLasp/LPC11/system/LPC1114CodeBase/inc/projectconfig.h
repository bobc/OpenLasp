/**************************************************************************/
/*! 
    @file     projectconfig.h
    @author   K. Townsend (microBuilder.eu)

    @section LICENSE

    Software License Agreement (BSD License)

    Copyright (c) 2010, microBuilder SARL
    All rights reserved.

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

#ifndef _PROJECTCONFIG_H_
#define _PROJECTCONFIG_H_

#include "lpc111x.h"
#include "sysdefs.h"

/*=========================================================================
    BOARD SELECTION

    Because several boards use this code library with sometimes slightly
    different pin configuration, you will need to specify which board you
    are using by enabling one of the following definitions. The code base
    will then try to configure itself accordingly for that board.
    -----------------------------------------------------------------------*/
    #define CFG_BRD_LPC1114_BARE_28
    
    #define CFG_BRD 	CFG_BRD_LPC1114_BARE_28
/*=========================================================================*/




/*=========================================================================
    FIRMWARE VERSION SETTINGS
    -----------------------------------------------------------------------*/
    #define CFG_FIRMWARE_VERSION_MAJOR            (0)
    #define CFG_FIRMWARE_VERSION_MINOR            (8)
    #define CFG_FIRMWARE_VERSION_REVISION         (0)
/*=========================================================================*/


/*=========================================================================
    CORE CPU SETTINGS
    -----------------------------------------------------------------------

    CFG_CPU_CCLK    Value is for reference only.  'core/cpu/cpu.c' must
                    be modified to change the clock speed, but the value
                    should be indicated here since CFG_CPU_CCLK is used by
                    other peripherals to determine timing.

    Note:           At 36MHz 1 tick = ~27.777ns or 0.02777us
    -----------------------------------------------------------------------*/
    #define CFG_CPU_CCLK              (36000000)
/*=========================================================================*/


/*=========================================================================
    Power Management (PMU Settings)
    -----------------------------------------------------------------------

    CFG_PMU_USEPOWERPROFILES    If set to 1 LPC1100L power profiles will
                                be used, otherwise they will be ignored.
                                This should only be set for L-series chips.
    CFG_PMU_POWERPROFILE        The default power profile to use for normal
                                program execution.  This can be any of the
                                following value from core/pmu/pmu.h:

                                  pmuPowerProfile_Default
                                  pmuPowerProfile_Performance
                                  pmuPowerProfile_Efficiency
                                  pmuPowerProfile_LowCurrent

    Note: There is an internal check in the pmu code to make sure that the
    chip actually supports power profiles, so these can be safely enabled
    on non L series MCUs.
    -----------------------------------------------------------------------*/
    #define CFG_PMU_USEPOWERPROFILES  (1)
    #define CFG_PMU_POWERPROFILE      (pmuPowerProfile_Efficiency)
/*=========================================================================*/


/*=========================================================================
    VOLTAGE REGULATOR
    -----------------------------------------------------------------------

    CFG_VREG_VCC_MAIN     Output voltage of the regulator in millivolts
    CFG_VREG_ALT_PRESENT  0 if no alternative voltage is available, 1
                          if it is available (TPS780, etc.)
    CFG_VREG_ALT_VCC      Alternate output voltage in millivolts on the
                          vreg in sleep or low-power mode.  (Only relevant
                          for dual-output regulators like the TPS780, etc.)
    CFG_VREG_ALT_PORT     GPIO port to enable alternate VREG output
    CFG_VREG_ALT_PIN      GPIO pin to enable alternate VREG output
    CFG_VREG_ALT_REG32    IOCON Register for the alt. output enable pin

    -----------------------------------------------------------------------*/
    #define CFG_VREG_VCC_MAIN         (3300)    // 3.3V * 1000
    #define CFG_VREG_ALT_PRESENT      (0)
    #define CFG_VREG_ALT_PRESENT      (0)
    #define CFG_VREG_ALT_VCC          (3300)
    #define CFG_VREG_ALT_PORT         (2)
    #define CFG_VREG_ALT_PIN          (10)
    #define CFG_VREG_ALT_REG32        (IOCON_PIO2_10)
/*=========================================================================*/


/*=========================================================================
    BATTERY
    -----------------------------------------------------------------------

    CFG_BAT                   If this field is defined it indicates
                              that a user selectable voltage divider is
                              connected to the batter/power supply
    CFG_BAT_ENPORT            The port to enable to battery voltage divider
    CFG_BAT_ENPIN             The pin to enable the battery voltage divider
    CFG_BAT_ADC               The adc port where that the battery is connected
    CFG_BAT_SUPPLYVOLTAGE     The regulated supply voltage in millivolts
    CFG_BAT_MULTIPLIER        Multiplier to convert the adc result to
                              battery voltage - ((R1 + R2) / R2) * 1000

    Note:                     For an example of using this information to
                              determine the battery/power-supply voltage
                              level see 'projects/commands/cmd_sysinfo.c'

                              These settings are not relevant to all boards!
                              'tools/schematics/AT86RF212LPC1114_v1.6.pdf'
                              show how 'BAT' is meant to be connected/used
    -----------------------------------------------------------------------*/
    // #define CFG_BAT
    #define CFG_BAT_ENPORT              (2)
    #define CFG_BAT_ENPIN               (11)
    #define CFG_BAT_ENREG32             (IOCON_PIO2_11)
    #define CFG_BAT_ADC                 (0)
    #define CFG_BAT_MULTIPLIER          (0)
/*=========================================================================*/


/*=========================================================================
    SYSTICK TIMER
    -----------------------------------------------------------------------

    CFG_SYSTICK_DELAY_IN_MS   The number of milliseconds between each tick
                              of the systick timer.
							  
    -----------------------------------------------------------------------*/
    #define CFG_SYSTICK_DELAY_IN_MS     (1)
/*=========================================================================*/


/*=========================================================================
    GPIO INTERRUPTS
    -----------------------------------------------------------------------

    IF you wish to use the GPIO interrupt handlers elsewhere in your code,
    you should probably define a seperate IRQHandler for the appropriate
    GPIO bank rather than using the definitions in core/gpio/gpio.c (to
    avoid causing problems in other projects, and to make updates easier,
    etc.)  To disable the default IRQHandler, simply comment out the
    define below for the appropriate GPIO bank and implement the handler
    somewhere else.

    GPIO_ENABLE_IRQ0    If defined, PIOINT0_IRQHandler will be declared and
                        handled in core/gpio/gpio.c
    GPIO_ENABLE_IRQ1    If defined, PIOINT1_IRQHandler will be declared and
                        handled in core/gpio/gpio.c
    GPIO_ENABLE_IRQ2    If defined, PIOINT2_IRQHandler will be declared and
                        handled in core/gpio/gpio.c
    GPIO_ENABLE_IRQ3    If defined, PIOINT3_IRQHandler will be declared and
                        handled in core/gpio/gpio.c

    -----------------------------------------------------------------------*/
    // #define GPIO_ENABLE_IRQ0
    // #define GPIO_ENABLE_IRQ1
    // #define GPIO_ENABLE_IRQ2
    // #define GPIO_ENABLE_IRQ3
/*=========================================================================*/


/*=========================================================================
    UART
    -----------------------------------------------------------------------

    CFG_UART_BAUDRATE         The default UART speed.  This value is used 
                              when initialising UART, and should be a 
                              standard value like 57600, 9600, etc.
    CFG_UART_BUFSIZE          The length in bytes of the UART RX FIFO. This
                              will determine the maximum number of received
                              characters to store in memory.

    -----------------------------------------------------------------------*/
    #define CFG_UART_BAUDRATE           (115200)
    #define CFG_UART_BUFSIZE            (128)
/*=========================================================================*/


/*=========================================================================
    ADC
    -----------------------------------------------------------------------

    ADC_AVERAGING_ENABLE      To get better results, the ADC code can take
                              a number of samples and return the average
                              value.  This is slower, but can give more
                              accurate results compared to single-reading.
                              
                              To enable averaging, set ADC_AVERAGING_ENABLE
                              to a non-zero value.
    ADC_AVERAGING_SAMPLES     The number of ADC samples to read and
                              average if ADC averaging is enabled.

    -----------------------------------------------------------------------*/
    #define ADC_AVERAGING_ENABLE    (1)
    #define ADC_AVERAGING_SAMPLES   (5)
/*=========================================================================*/


/*=========================================================================
    ON-BOARD LED
    -----------------------------------------------------------------------

    CFG_LED_PORT              The port for the on board LED
    CFG_LED_PIN               The pin for the on board LED
    CFG_LED_ON                The pin state to turn the LED on (0 = low, 1 = high)
    CFG_LED_OFF               The pin state to turn the LED off (0 = low, 1 = high)

    -----------------------------------------------------------------------*/
    #define CFG_LED_PORT                (3)
    #define CFG_LED_PIN                 (5)
    #define CFG_LED_ON                  (0)
    #define CFG_LED_OFF                 (1)
/*=========================================================================*/


/*=========================================================================
    MICRO-SD CARD
    -----------------------------------------------------------------------

    CFG_SDCARD                If this field is defined SD Card and Fat32
                              file system support will be included
    CFG_SDCARD_READONLY       If this is set to 1, all commands to
                              write to the SD card will be removed
                              saving some flash space (-Os).
    CFG_SDCARD_CDPORT         The card detect port number
    CFG_SDCARD_CDPIN          The card detect pin number
    CFG_SDCARD_CDREG32        IOCON Register for the CD pin
    CFG_SDCARD_ENPORT         The power enable port number
    CFG_SDCARD_ENPIN          The power enable pin number
    CFG_SDCARD_ENREG32        IOCON Register for the EN pin

    DEPENDENCIES:             SDCARD requires the use of SSP1.

    Note:                     These settings are not relevant to all boards!
                              'tools/schematics/AT86RF212LPC1114_v1.6.pdf'
                              show how SDCARD is meant to be connected/used
    -----------------------------------------------------------------------*/
    // #define CFG_SDCARD
    #define CFG_SDCARD_READONLY         (0)
    #define CFG_SDCARD_CDPORT           (2)
    #define CFG_SDCARD_CDPIN            (4)
    #define CFG_SDCARD_CDREG32          (IOCON_PIO2_4)
    #define CFG_SDCARD_ENPORT           (2)
    #define CFG_SDCARD_ENPIN            (5)
    #define CFG_SDCARD_ENREG32          (IOCON_PIO2_5)
/*=========================================================================*/


/*=========================================================================
    PRINTF REDIRECTION
    -----------------------------------------------------------------------

    CFG_PRINTF_UART           Will cause all printf statements to be 
                              redirected to UART
    CFG_PRINTF_NEWLINE        This should be either "\r\n" for Windows or
                              "\n" for *nix

    Note: If no printf redirection definitions are present, all printf
    output will be ignored, though this will also save ~350 bytes flash.

    NOTE: PRINTF Support =    ~350 bytes Flash (-Os)
    -----------------------------------------------------------------------*/
    #define CFG_PRINTF_UART
    #define CFG_PRINTF_NEWLINE          "\r\n"
/*=========================================================================*/


/*=========================================================================
    COMMAND LINE INTERFACE
    -----------------------------------------------------------------------

    CFG_INTERFACE             If this field is defined the UART or USBCDC
                              based command-line interface will be included
    CFG_INTERFACE_MAXMSGSIZE  The maximum number of bytes to accept for an
                              incoming command
    CFG_INTERFACE_PROMPT      The command prompt to display at the start
                              of every new data entry line

    NOTE:                     The command-line interface will use either
                              USB-CDC or UART depending on whether
                              CFG_PRINTF_UART or CFG_PRINTF_USBCDC are 
                              selected.
    -----------------------------------------------------------------------*/
    //  #define CFG_INTERFACE
    #define CFG_INTERFACE_MAXMSGSIZE    (256)
    #define CFG_INTERFACE_PROMPT        "LPC1114 >> "
/*=========================================================================*/


/*=========================================================================
    PWM SETTINGS
    -----------------------------------------------------------------------

    CFG_PWM                     If this is defined, a basic PWM driver
                                will be included using 16-bit Timer 1 and
                                Pin 1.9 (MAT0) for the PWM output.  In
                                order to allow for a fixed number of
                                pulses to be generated, some PWM-specific
                                code is required in the 16-Bit Timer 1
                                ISR.  See "core/timer16/timer16.c" for
                                more information.
    CFG_PWM_DEFAULT_PULSEWIDTH  The default pulse width in ticks
    CFG_PWM_DEFAULT_DUTYCYCLE   The default duty cycle in percent

    DEPENDENCIES:               PWM output requires the use of 16-bit
                                timer 1 and pin 1.9 (CT16B1_MAT0).
    -----------------------------------------------------------------------*/
    #define CFG_PWM
    #define CFG_PWM_DEFAULT_PULSEWIDTH  (CFG_CPU_CCLK / 1000)
    #define CFG_PWM_DEFAULT_DUTYCYCLE   (50)
/*=========================================================================*/



/*=========================================================================
  CONFIG FILE VALIDATION
  -------------------------------------------------------------------------
  Basic error checking to make sure that incompatible defines are not 
  enabled at the same time, etc.

  =========================================================================*/

#if !defined CFG_BRD
  #error "You must define a target board"
#endif

// #if defined CFG_BRD_LPC1114_REFDESIGN && defined CFG_BRD_LPC1114_802154WIRELESS
//   #error "Only one target board can be defined at a time (CFG_BRD_LPC1114_REFDESIGN or CFG_BRD_LPC1114_802154WIRELESS)"
// #endif

// ----------------------------------------------------------------------------
#ifdef CFG_INTERFACE
  #ifndef CFG_PRINTF_UART
    #error "CFG_INTERFACE can not be used without CFG_PRINTF_UART"
  #endif
#endif

#ifdef CFG_CHIBI
  #if !defined CFG_I2CEEPROM
    #error "CFG_CHIBI requires CFG_I2CEEPROM to store and retrieve addresses"
  #endif
  #ifdef CFG_STEPPER
    #error "CFG_CHIBI and CFG_STEPPER can not be defined at the same time since they both use CT16B0"
  #endif
  #if CFG_CHIBI_PROMISCUOUS != 0 && CFG_CHIBI_PROMISCUOUS != 1
    #error "CFG_CHIBI_PROMISCUOUS must be equal to either 1 or 0"
  #endif
#endif

#ifdef CFG_ST7565
  #ifdef CFG_STEPPER
    #error "CFG_ST7565 and CFG_STEPPER can not be defined at the same time since they both use pins 2.8 and 2.9"
  #endif
  #ifdef CFG_SSD1306
    #error "CFG_ST7565 and CFG_SSD1306 can not be defined at the same time"
  #endif
#endif

#ifdef CFG_RSA
  #if CFG_RSA_BITS != 64 && CFG_RSA_BITS != 32
    #error "CFG_RSA_BITS must be equal to either 32 or 64."
  #endif
#endif

#if CFG_VREG_ALT_PRESENT != 1 && CFG_VREG_ALT_PRESENT != 0
  #error "CFG_VREG_ALT_PRESENT must be equal to either 1 or 0"
#endif

#if ADC_AVERAGING_ENABLE && ADC_AVERAGING_SAMPLES < 1
  #error "ADC_AVERAGING_SAMPLES must be 1 or higher when ADC averaging is enabled"
#endif

#endif


