/****************************************************************************************************/
#ifndef __EMIOS_H        /*prevent duplicated includes*/
#define __EMIOS_H

/*****************************************************************************************************
* Include files
*****************************************************************************************************/

/** Core Modules */
/** Variable types and common definitions */
    #include    "typedefs.h"
  
  
  
  /*****************************************************************************************************
* Declaration of module wide FUNCTIONS
*****************************************************************************************************/

/** PIT Low level initialization */
void EMIOS_device_init(void);

/* PIT Low level channel configuration */
void EMIOS_channel_configure(uint8_t channel);

/** PIT Low level Start procedure */
void EMIOS_channel_start(uint8_t channel);

/** PIT Low level Stop procedure */
void EMISO_channel_stop(uint8_t channel);

/** PIT Channel 0 ISR  */
void EMIOS_channel_0_isr( void  );
  
  
  
  
     
    
#endif /* __EMIOS_H */




