/*****************************************/
/* Author  :  Ahmed Elbadry              */
/* Version :  V01                        */
/* Date    :  6 SEPTMBER 2020            */
/*****************************************/
#ifndef SCHEDULER_PRIVATE_H
#define SCHEDULER_PRIVATE_H

#define 		NULL 					(0)

#define			TASK_SUSPENDED			1

#define			TASK_READY				2


typedef struct
{
	u16 Period;
	void (*TaskHandler)(void);
	u16	firstDelay;
	u8 State;
}Task;

static Task OStasks[NUM_OF_TASKS] = {NULL};


static void SCHEDULER(void)
{
	//static u16 Local_u16TickCounter=0;
	u8 Local_u8TaskCounter;
	/*Increment of Scheduler tick counter*/

		/*Loop on the tasks*/
		for(Local_u8TaskCounter=0;Local_u8TaskCounter<NUM_OF_TASKS;Local_u8TaskCounter++)
		{
			/*chack that task isn't deleted or suspended */
			if((OStasks[Local_u8TaskCounter].TaskHandler != NULL) && (OStasks[Local_u8TaskCounter].State == TASK_READY) )
			{
				/*Check until the first delay equal to zero*/
				if(OStasks[Local_u8TaskCounter].firstDelay == 0)
				{
					OStasks[Local_u8TaskCounter].firstDelay=OStasks[Local_u8TaskCounter].Period-1;
					/*Invoke the task function*/
					OStasks[Local_u8TaskCounter].TaskHandler();
				}
				else
				{
					/*Decrement the first delay*/
					OStasks[Local_u8TaskCounter].firstDelay--;
				}
			}
			else
			{
				/*Do nothing*/
			}
		}
}

#endif
