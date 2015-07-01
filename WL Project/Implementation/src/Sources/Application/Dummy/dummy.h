/*******************************************************************************/
/**
\file       dummy.h
\brief      Dummy Functions
\author     Francisco Martinez
\version    1.0
\date       04/04/2014
*/
/*******************************************************************************/

#ifndef _DUMMY_H        /*prevent duplicated includes*/
#define _DUMMY_H

/*-- Includes ----------------------------------------------------------------*/

/** Core modules */
/** Variable types and common definitions */

#include "typedefs.h"

/*-- Variables ---------------------------------------------------------------*/

/*-- Types Definitions -------------------------------------------------------*/




typedef enum
{
 NULO   = 0,
 AUTO   = 1,
 MANUAL = 2,
 PINCH  = 3
} T_WL_STATUS;


typedef struct 
{
const	T_UBYTE cub_ID;
		T_UBYTE rub_TopTable;
	   T_UWORD ruw_Countus;
}T_BUTTONSTRUCT;


typedef struct 
{
	T_UBYTE rub_LedPosition;
	T_UBYTE ruw_allLeds[12];
}T_LEDSTRUCT;


/*-- Defines -----------------------------------------------------------------*/


/*-- Function Prototypes -----------------------------------------------------*/

void dummy_500us(void);
void dummy_Init_endlessloop(void);
void dummy_Check_Button_Press(void);
void dummy_Check_Time_Press(void);
void dummy_Led_Response(void);
#endif /* _DUMMY_H */

/*******************************************************************************/
