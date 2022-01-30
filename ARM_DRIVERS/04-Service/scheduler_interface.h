/*****************************************/
/* Author  :  Ahmed Elbadry              */
/* Version :  V01                        */
/* Date    :  6 SEPTMBER 2020            */
/*****************************************/
#ifndef SCHEDULER_INTERFACE_H
#define SCHEDULER_INTERFACE_H

//Example: OS_voidCreateTask(0,1000,func,0);
void OS_voidCreateTask(u8 Copy_u8TaskID,u16 period,void (*ptr)(void),u16 Copy_u16firstDelay);
void OS_voidStart(void);

void OS_voidSuspendTask(u8 Copy_u8TaskID);
void OS_voidResumeTask(u8 Copy_u8TaskID);
void OS_voidDeleteTask(u8 Copy_u8TaskID);

#endif /* OS_H_ */
