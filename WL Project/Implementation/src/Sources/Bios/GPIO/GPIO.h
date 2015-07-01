/*******************************************************************************/
/**

\file       GPIO.h
\brief      Macro definitions for registers access and I/O handling
\author     Abraham Tezmol
\version    0.2
\date       09/05/2013
*/
/*******************************************************************************/

#ifndef _GPIO_H        /*prevent duplicated includes*/
#define _GPIO_H

/*-- Includes ----------------------------------------------------------------*/

/** Core modules */
/** MCU derivative information */
#include "MCU_derivative.h"
/** Variable types and common definitions */
#include "typedefs.h"

/*-- Variables ---------------------------------------------------------------*/

/*-- Types Definitions -------------------------------------------------------*/

/*-- Defines -----------------------------------------------------------------*/

#define LED0                        34
#define LED1      					35
#define LED2       					36
#define LED3       					37
#define LED4        				38
#define LED5                        39
#define LED6      					40
#define LED7       					41
#define LED8       					42
#define LED9        				44

#define LED_GREEN    				46
#define LED_BLUE       				47

#define BUTTON_UP      			    64
#define BUTTON_DOWN      			65
#define BUTTON_ANTIPINCH      		66

#define UP                          0
#define DOWN                        1
#define ANTIPINCH                   2



#define GPIO_INPUT					0
#define GPIO_OUTPUT					1

#define GPIO_OPEN_DRAIN_DISABLE		0
#define GPIO_OPEN_DRAIN_ENABLE		1

/*-- Macros ------------------------------------------------------------------*/
/* Indicator LEDs handling */

/** Set LED */ 
#define LED_ON(channel)                     (SIU.GPDO[channel].B.PDO =  1)
/** Clear LED */ 
#define LED_OFF(channel)                    (SIU.GPDO[channel].B.PDO =  0)
/** Toggle LED */ 
#define LED_TOGGLE(channel)                 (SIU.GPDO[channel].B.PDO ^= 1) 


#define STATUS_LED(channel)                 (SIU.GPDO[channel].B.PDO)

#define HIGH(channel)                       (!SIU.GPDI[channel].R)
#define LOW(channel)                        (SIU.GPDI[channel].R)



/*-- Function Prototypes -----------------------------------------------------*/

void vfnGPIO_Init_channel(uint8_t channel, uint8_t input_output, uint8_t Open_drain);
void vfnGPIO_Output(uint8_t channel, uint8_t logical_value);
void vfnGPIO_FlashMainLED(void);
void vfnGPIO_LED_Init(void);



#endif /* _GPIO_H */

/*******************************************************************************/
