/*
  Arduino.h - Main include file for the Arduino SDK

	LPC100 series
	
  Copyright (c) 2014 Bob Cousins.
  
  #GPL2

*/

#ifndef Arduino_h
#define Arduino_h

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "analog.h"
#include "digital.h"
#include "timing.h"



/* sketch */
extern void setup( void ) ;
extern void loop( void ) ;


#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

void yield(void);


#define NOT_A_PORT           0

#define NOT_AN_INTERRUPT 		-1

typedef enum _EPioType
{
  PIO_NOT_A_PIN, 	/* Not under control of a peripheral. */
  PIO_PERIPH_A, 	/* The pin is controlled by the associated signal of peripheral A. */
  PIO_PERIPH_B, 	/* The pin is controlled by the associated signal of peripheral B. */
  PIO_INPUT, 			/* The pin is an input. */
  PIO_OUTPUT_0, 	/* The pin is an output and has a default level of 0. */
  PIO_OUTPUT_1 		/* The pin is an output and has a default level of 1. */
} EPioType ;


/*  Default pin configuration (no attribute). */
#define PIO_DEFAULT                 (0u << 0)
/*  The internal pin pull-up is active. */
#define PIO_PULLUP                  (1u << 0)
/*  The internal glitch filter is active. */
#define PIO_DEGLITCH                (1u << 1)
/*  The pin is open-drain. */
#define PIO_OPENDRAIN               (1u << 2)
/*  The internal debouncing filter is active. */
#define PIO_DEBOUNCE                (1u << 3)
/*  Enable additional interrupt modes. */
#define PIO_IT_AIME                 (1u << 4)
/*  Interrupt High Level/Rising Edge detection is active. */
#define PIO_IT_RE_OR_HL             (1u << 5)
/*  Interrupt Edge detection is active. */
#define PIO_IT_EDGE                 (1u << 6)

typedef enum _EAnalogChannel
{
  NO_ADC=-1,
  ADC0=0,
  ADC1,
  ADC2,
  ADC3,
  ADC4,
  ADC5
} EAnalogChannel ;

// Definitions for PWM channels
typedef enum _EPWMChannel
{
  NOT_ON_PWM=-1,
  PWM_CH0=0,
  PWM_CH1,
  PWM_CH2,
  PWM_CH3,
  PWM_CH4,
  PWM_CH5,
  PWM_CH6,
  PWM_CH7
} EPWMChannel ;

// Definitions for TC channels
typedef enum _ETCChannel
{
  NOT_ON_TIMER=-1,
  CT16_B0_MAT0,
  CT16_B0_MAT1,
  CT16_B0_MAT2,
	
  CT16_B1_MAT0,
  CT16_B1_MAT1,
  CT16_B1_MAT2,

  CT32_B0_MAT0,
  CT32_B0_MAT1,
  CT32_B0_MAT2,
  CT32_B0_MAT3,
  
  CT32_B1_MAT0,
  CT32_B1_MAT1,
  CT32_B1_MAT2,
  CT32_B1_MAT3

} ETCChannel ;

/**
 * Pin Attributes to be OR-ed
 */
#define PIN_ATTR_COMBO         (1UL<<0)
#define PIN_ATTR_ANALOG        (1UL<<1)
#define PIN_ATTR_DIGITAL       (1UL<<2)
#define PIN_ATTR_PWM           (1UL<<3)
#define PIN_ATTR_TIMER         (1UL<<4)

/* Types used for the table below */
typedef struct _PinDescription
{
  uint8_t 	ubPort ;
  uint8_t	 	ubPin ;
  
  EPioType 				ulPinType ;
  uint32_t 				ulPinConfiguration ;
  uint32_t 				ulPinAttribute ;
  EAnalogChannel 	ulAnalogChannel ; 			/* Analog pin in the Arduino context (label on the board) */
  EAnalogChannel	ulADCChannelNumber ; 	/* ADC Channel number in the SAM device */
  EPWMChannel 		ulPWMChannel ;
  ETCChannel 			ulTCChannel ;
} PinDescription ;

/* Pins table to be instantiated in variant.cpp */
extern const PinDescription g_APinDescription[] ;


#ifdef __cplusplus
} // extern "C"

#include "serial.h"

#endif // __cplusplus

// Include board variant
#include "variant.h"


#endif // Arduino_h
