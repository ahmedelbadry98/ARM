/**********************************************************/
/* Author    : Ahmed Elbadry                              */
/* Date      : 22 August 2020                             */
/* Version   : V01                                        */
/**********************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "EXTI_private.h"


void MEXTI_VoidInit()
{
	#if   EXTI_MODE == RISING_AGE 
		SET_BIT( EXTI->RTSR , EXTI_LINE );
	#elif EXTI_MODE == FALLING_AGE
		SET_BIT( EXTI->FTSR , EXTI_LINE );
	#elif EXTI_MODE == ON_CHANGE
		SET_BIT( EXTI->RTSR , EXTI_LINE );
		SET_BIT( EXTI->FTSR , EXTI_LINE );
	#else 
		#error "Wrong Mode/Line Choice"
	#endif
	/* Disable interrupt */
	CLR_BIT(EXTI->IMR , EXTI_LINE);
}

void MEXTI_VoidEnableEXTI(u8 Copy_U8Line)
{
	SET_BIT(EXTI->IMR , Copy_U8Line);
}

void MEXTI_VoidDisableEXTI(u8 Copy_U8Line)
{
	CLR_BIT(EXTI->IMR , Copy_U8Line);
}

void MEXTI_VoidSwTrigger(u8 Copy_U8Line)
{
	SET_BIT(EXTI->SWIER , Copy_U8Line);
}

void MEXTI_VoidSetSignalLatch(u8 Copy_U8Line , u8 Copy_U8Mode ) 
{
	Switch(Copy_U8Mode)
	{
		case RISING_AGE:  SET_BIT( EXTI->RTSR , Copy_U8Line ); break;
		
		case FALLING_AGE: SET_BIT( EXTI->FTSR , Copy_U8Line ); break;
		
		case ON_CHANGE:   SET_BIT( EXTI->RTSR , Copy_U8Line );
		                  SET_BIT( EXTI->FTSR , Copy_U8Line ); break;	
	}
	
}
