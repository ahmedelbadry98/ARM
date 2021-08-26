/**********************************************************/
/* Author    : Ahmed Elbadry                              */
/* Date      : 22 August 2020                             */
/* Version   : V01                                        */
/**********************************************************/
#ifndef EXTI_INTRTFACE_H
#define EXTI_INTERFACE_H


void MEXTI_VoidInit(); /* for line and mode */

void MEXTI_VoidEnableEXTI(u8 Copy_U8Line) ; /* Enable Interrupt */

void MEXTI_VoidDisableEXTI(u8 Copy_U8Line); /* Disable Interrupt */

void MEXTI_VoidSwTrigger(u8 Copy_U8Line)  ; /* fires SW interrupts */

void MEXTI_VoidSetSignalLatch(u8 Copy_U8Line , u8 Copy_U8Mode )  ; /* Enable Mode in runtime */








#ednif