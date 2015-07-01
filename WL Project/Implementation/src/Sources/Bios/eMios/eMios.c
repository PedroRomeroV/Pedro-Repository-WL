/*****************************************************************************************************
* Include files
*****************************************************************************************************/

/* MCU-specific derivative */
#include "MCU_derivative.h" 
/* Data types */
#include "typedefs.h"

#include "IntcInterrupts.h"

/* Own Headers */
#include "eMios.h"



/** PIT Low level initialization */
void EMIOS_device_init(void)
{
	EMIOS_0.MCR.B.GPRE= 63;   	/* Divide 64 MHz sysclk by 63+1 = 64 for 1MHz eMIOS clk*/
	EMIOS_0.MCR.B.GPREN = 1;			/* Enable eMIOS clock */
	EMIOS_0.MCR.B.GTBE = 1;  			/* Enable global time base */
	EMIOS_0.MCR.B.FRZ = 1;    			/* Enable stopping channels when in debug mode */

}


/* PIT Low level channel configuration */
void EMIOS_channel_configure(uint8_t channel)
{
	
}

/** PIT Low level Start procedure */
void EMIOS_channel_start(uint8_t channel)
{
	
}

/** PIT Low level Stop procedure */
void EMISO_channel_stop(uint8_t channel)
{
	
}

/** PIT Channel 0 ISR  */
void EMIOS_channel_0_isr( void  )
{
	
}
  