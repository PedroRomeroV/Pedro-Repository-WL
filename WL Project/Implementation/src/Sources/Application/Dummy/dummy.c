/*******************************************************************************/
/**
\file       dummy.c
\brief      Dummy Functions
\author     Francisco Martinez
\version    1.0
\date       04/04/2014
*/
/****************************************************************************************************/

/*****************************************************************************************************
* Include files
*****************************************************************************************************/

/** Core modules */
/** Variable types and common definitions */
#include "typedefs.h"

/** Own headers */
#include "dummy.h"

/* GPIO routines prototypes */ 
#include "GPIO.h"

/** Used modules */

/*****************************************************************************************************
* Definition of module wide VARIABLEs 
*****************************************************************************************************/

/*****************************************************************************************************
* Declaration of module wide FUNCTIONs 
*****************************************************************************************************/

/*****************************************************************************************************
* Definition of module wide MACROs / #DEFINE-CONSTANTs 
*****************************************************************************************************/

/*****************************************************************************************************
* Declaration of module wide TYPEs 
*****************************************************************************************************/

/*****************************************************************************************************
* Definition of module wide (CONST-) CONSTANTs 
*****************************************************************************************************/

/*****************************************************************************************************
* Code of module wide FUNCTIONS
*****************************************************************************************************/


/****************************************************************************************************/
/**
* \brief    Turn a combination of 4 LEDs with a unique blinking pattern, this funcation shall be 
* \brief    called periodically to operate. 
* \author   Francisco Martinez
* \return   void
*/





/*******************************************************/
/*       Definicion Global de Tabla y puntero           */



T_BUTTONSTRUCT *rps_ButtonPtr;
T_BUTTONSTRUCT rs_Button_table[3]=
{
	{ BUTTON_UP,        10 ,0 },
	{ BUTTON_DOWN,      0 ,0 },
	{ BUTTON_ANTIPINCH, 0 ,0},
};



T_LEDSTRUCT *rps_LedPtr;
T_LEDSTRUCT rs_Led_table=
{
0,
{
	LED0,LED1,LED2,LED3,LED4,LED5,LED6,LED7,LED8,LED9,LED_GREEN,LED_BLUE
}
};

T_WL_STATUS re_WL_Status;
T_UWORD ruw_TransitionTime;


/*******************************************************/






/*******************************************************/




void dummy_Init_endlessloop(void)
{
rps_ButtonPtr = &rs_Button_table[0];
rps_LedPtr = &rs_Led_table;
ruw_TransitionTime=MILISECONDS_400;  //800 para iniciar en alto   0 para bajo
re_WL_Status=NULO;

/**/
do {}while(1);

}

/*******************************************************/  
void dummy_Check_Button_Press(void)
{
	auto T_SBYTE lsb_Total_push=0;
 	if(HIGH(BUTTON_UP))
	{
		rps_ButtonPtr = &rs_Button_table[UP];
		lsb_Total_push++;	
	}
	if(HIGH(BUTTON_DOWN))
	{
		rps_ButtonPtr = &rs_Button_table[DOWN];
		lsb_Total_push++;
	}
	if(HIGH(BUTTON_ANTIPINCH))
	{
		rps_ButtonPtr = &rs_Button_table[ANTIPINCH];
		lsb_Total_push++;
	}
	rps_ButtonPtr->ruw_Countus++;

	if(lsb_Total_push == 0 )
	{
		// esto es que no se presiono ningun boton
		rs_Button_table[UP].ruw_Countus=0;
		rs_Button_table[DOWN].ruw_Countus=0;
		rs_Button_table[ANTIPINCH].ruw_Countus=0;
			if(re_WL_Status == MANUAL) //se deja de presionar manual por lo tanto se apagan los led y se deja de incrementar
		{
		re_WL_Status=NULO;
		ruw_TransitionTime=MILISECONDS_400;	
		LED_OFF(LED_GREEN);
		LED_OFF(LED_BLUE);
		}

	}
	if(lsb_Total_push > 1 )
	{
		// esto es  que se presionarion demasiados botos
		rs_Button_table[UP].ruw_Countus=0;
		rs_Button_table[DOWN].ruw_Countus=0;
		rs_Button_table[ANTIPINCH].ruw_Countus=0;
		ruw_TransitionTime=MILISECONDS_400;	
		re_WL_Status=NULO;
		LED_OFF(LED_GREEN);
		LED_OFF(LED_BLUE);
		
	}
	
	
	
}

/*******************************************************/



void dummy_Check_Time_Press(void)
{
	if( rps_ButtonPtr->ruw_Countus > MILISECONDS_10)  ///10 MILI SEC  
	{
		//se ha considerado un boton valido por lo tanto  se pregunta cual fue 

		if(rps_ButtonPtr->cub_ID == BUTTON_UP)
		{
			LED_ON(LED_BLUE);
			LED_OFF(LED_GREEN);	
					re_WL_Status=AUTO;
		}
		if(rps_ButtonPtr->cub_ID == BUTTON_DOWN)
		{
			LED_ON(LED_GREEN);
			LED_OFF(LED_BLUE);
					re_WL_Status=AUTO;
		}
		if(rps_ButtonPtr->cub_ID == BUTTON_ANTIPINCH)
		{	
			rps_ButtonPtr->ruw_Countus--;
			if(STATUS_LED(LED_BLUE) )
			{
				re_WL_Status=PINCH;
				LED_ON(LED_GREEN);
				LED_OFF(LED_BLUE);
			}	
			
		}
		if( rps_ButtonPtr->ruw_Countus > MILISECONDS_500)
		{
//		 LED_ON(LED_BLUE);
			//run trassiton time activate  manual
			re_WL_Status=MANUAL;		
			//evita overflow
		
		}
	}
}
/*******************************************************/
void dummy_Led_Response(void)
{
static T_UBYTE	 rub_FlagDelay=1;
	if(MILISECONDS_400 < ruw_TransitionTime  && rub_FlagDelay)
	{
		ruw_TransitionTime=0;
		if(rps_ButtonPtr->cub_ID == BUTTON_UP)
		{
			if(rs_Led_table.rub_LedPosition != rps_ButtonPtr->cub_TopList)
			{
			LED_ON(rs_Led_table.cub_allLeds[rs_Led_table.rub_LedPosition]);
			rs_Led_table.rub_LedPosition++;
			}
			if(rs_Led_table.rub_LedPosition == rps_ButtonPtr->cub_TopList)  //tope de la tabla
			{
				re_WL_Status=NULO;
				ruw_TransitionTime=MILISECONDS_400;	
				LED_OFF(LED_GREEN);
				LED_OFF(LED_BLUE);
			}
		}
		if(rps_ButtonPtr->cub_ID == BUTTON_DOWN)
		{
			if(rs_Led_table.rub_LedPosition != rps_ButtonPtr->cub_TopList)  //fondo de la tabla
			{
				rs_Led_table.rub_LedPosition--;
				LED_OFF(rs_Led_table.cub_allLeds[rs_Led_table.rub_LedPosition]);
			}
			if(rs_Led_table.rub_LedPosition == rps_ButtonPtr->cub_TopList)
			{
				re_WL_Status=NULO;
				ruw_TransitionTime=MILISECONDS_400;	
				LED_OFF(LED_GREEN);
				LED_OFF(LED_BLUE);
			}
		}
		if(rps_ButtonPtr->cub_ID == BUTTON_ANTIPINCH  )
		{
			if(rs_Led_table.rub_LedPosition != rps_ButtonPtr->cub_TopList)  //fondo de la tabla
			{
				rs_Led_table.rub_LedPosition--;
				LED_OFF(rs_Led_table.cub_allLeds[rs_Led_table.rub_LedPosition]);
				
			}
			if(rs_Led_table.rub_LedPosition == rps_ButtonPtr->cub_TopList)
			{
				rub_FlagDelay=0;
				ruw_TransitionTime=0;	
				LED_OFF(LED_GREEN);
				LED_OFF(LED_BLUE);
				//super dalay()
			}	
		}
	}
	if(ruw_TransitionTime == SECONDS_5) 
		{
		ruw_TransitionTime=MILISECONDS_400;
		re_WL_Status=NULO;	
		rub_FlagDelay=1;
		}
}

/*******************************************************/



void dummy_500us(void)
{

if(re_WL_Status != PINCH)
{
dummy_Check_Button_Press();
dummy_Check_Time_Press();
}
if(re_WL_Status)
{
	ruw_TransitionTime++;
}
dummy_Led_Response();

}

