/*****************************************/
/* Author  :  Ahmed Elbadry              */
/* Version :  V01                        */
/* Date    :  6 SEPTMBER 2020            */
/*****************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"

#include "scheduler_interface.h"
#include "scheduler_config.h"
#include "scheduler_private.h"


//#define NULL ((void *)0)


void OS_voidCreateTask(u8 Copy_u8TaskID,u16 period,void (*ptr)(void),u16 Copy_u16firstDelay)
{
	OStasks[Copy_u8TaskID].Period = period;
	OStasks[Copy_u8TaskID].TaskHandler = ptr;
	OStasks[Copy_u8TaskID].firstDelay = Copy_u16firstDelay;
	OStasks[Copy_u8TaskID].State = TASK_READY;
}

void OS_voidStart(void)
{
	MSTK_voidInit();

	/*when HSE=8Mhz , sytem tick is 1ms*/
	MSTK_voidSetIntervalPeriodic(1000 , SCHEDULER );

}

void OS_voidSuspendTask(u8 Copy_u8TaskID)
{
	OStasks[Copy_u8TaskID].State=TASK_SUSPENDED;
}

void OS_voidResumeTask(u8 Copy_u8TaskID)
{
	OStasks[Copy_u8TaskID].State=TASK_READY;
}

void OS_voidDeleteTask(u8 Copy_u8TaskID)
{
	OStasks[Copy_u8TaskID].TaskHandler=NULL;
}
