/*********************************************************************************/
/* Author    : Ahmed Elbadry                                                     */
/* Version   : V01                                                               */
/* Date      : September 2020                                                    */
/*********************************************************************************/ 
#ifndef IR_INTERFACE_H
#define IR_INTERFACE_H

#define TIMER_VALUE              150000UL
#define END_OF_CODE              (u8)33

#define DATA_COMMEND_START_EDGE  17
#define DATA_COMMEND_END_EDGE    25

#define LOGIC1_RANGE             2000





void IR_VoidInit          ( void );
u8 IR_u8GetButton        ( void );
 

#endif /* IR_INTERFACE_H_ */
