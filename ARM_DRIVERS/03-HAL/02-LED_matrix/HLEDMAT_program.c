/*********************************************************************************/
/* Author    : Ahmed Elbadry                                                     */
/* Version   : V01                                                               */
/* Date      : 31 August 2020                                                    */
/*********************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"

#include "HLEDMAT_interface.h"
#include "HLEDMAT_private.h"
#include "HLEDMAT_config.h"

void HLEDMAT_voidInit(void)
{

	GPIO_VoidSetPinDirection(HLEDMAT_ROW_0,OUTPUT_SPEED_2MHZ_PP);
	GPIO_VoidSetPinDirection(HLEDMAT_ROW_1,OUTPUT_SPEED_2MHZ_PP);
	GPIO_VoidSetPinDirection(HLEDMAT_ROW_2,OUTPUT_SPEED_2MHZ_PP);
	GPIO_VoidSetPinDirection(HLEDMAT_ROW_3,OUTPUT_SPEED_2MHZ_PP);
	GPIO_VoidSetPinDirection(HLEDMAT_ROW_4,OUTPUT_SPEED_2MHZ_PP);
	GPIO_VoidSetPinDirection(HLEDMAT_ROW_5,OUTPUT_SPEED_2MHZ_PP);
	GPIO_VoidSetPinDirection(HLEDMAT_ROW_6,OUTPUT_SPEED_2MHZ_PP);
	GPIO_VoidSetPinDirection(HLEDMAT_ROW_7,OUTPUT_SPEED_2MHZ_PP);
	
	
	GPIO_VoidSetPinDirection(HLEDMAT_COL_0,OUTPUT_SPEED_2MHZ_PP);
	GPIO_VoidSetPinDirection(HLEDMAT_COL_1,OUTPUT_SPEED_2MHZ_PP);
	GPIO_VoidSetPinDirection(HLEDMAT_COL_2,OUTPUT_SPEED_2MHZ_PP);
	GPIO_VoidSetPinDirection(HLEDMAT_COL_3,OUTPUT_SPEED_2MHZ_PP);
	GPIO_VoidSetPinDirection(HLEDMAT_COL_4,OUTPUT_SPEED_2MHZ_PP);
	GPIO_VoidSetPinDirection(HLEDMAT_COL_5,OUTPUT_SPEED_2MHZ_PP);
	GPIO_VoidSetPinDirection(HLEDMAT_COL_6,OUTPUT_SPEED_2MHZ_PP);
	GPIO_VoidSetPinDirection(HLEDMAT_COL_7,OUTPUT_SPEED_2MHZ_PP);
}

void HLEDMAT_voidDisplay(u8 *Copy_u8Data)
{

	while(1)
	{
      DisableAllColumns();
      GPIO_VoidSetPinValue(HLEDMAT_COL_0,LOW);
      SetRowValues(Copy_u8Data[0]);
      MSTK_voidSetBusyWait(2500); //2.5 ms

      DisableAllColumns();
      GPIO_VoidSetPinValue(HLEDMAT_COL_1,LOW);
      SetRowValues(Copy_u8Data[1]);
      MSTK_voidSetBusyWait(2500); //2.5 ms

      DisableAllColumns();
      GPIO_VoidSetPinValue(HLEDMAT_COL_2,LOW);
      SetRowValues(Copy_u8Data[2]);
      MSTK_voidSetBusyWait(2500); //2.5 ms

      DisableAllColumns();
      GPIO_VoidSetPinValue(HLEDMAT_COL_3,LOW);
      SetRowValues(Copy_u8Data[3]);
      MSTK_voidSetBusyWait(2500); //2.5 ms

      DisableAllColumns();
      GPIO_VoidSetPinValue(HLEDMAT_COL_4,LOW);
      SetRowValues(Copy_u8Data[4]);
      MSTK_voidSetBusyWait(2500); //2.5 ms

      DisableAllColumns();
      GPIO_VoidSetPinValue(HLEDMAT_COL_5,LOW);
      SetRowValues(Copy_u8Data[5]);
      MSTK_voidSetBusyWait(2500); //2.5 ms

      DisableAllColumns();
      GPIO_VoidSetPinValue(HLEDMAT_COL_6,LOW);
      SetRowValues(Copy_u8Data[6]);
      MSTK_voidSetBusyWait(2500); //2.5 ms

      DisableAllColumns();
      GPIO_VoidSetPinValue(HLEDMAT_COL_7,LOW);
      SetRowValues(Copy_u8Data[7]);
      MSTK_voidSetBusyWait(2500); //2.5 ms

	}

}




static void DisableAllColumns()
{
	GPIO_VoidSetPinValue(HLEDMAT_COL_0,HIGH);
	GPIO_VoidSetPinValue(HLEDMAT_COL_1,HIGH);
	GPIO_VoidSetPinValue(HLEDMAT_COL_2,HIGH);
	GPIO_VoidSetPinValue(HLEDMAT_COL_3,HIGH);
	GPIO_VoidSetPinValue(HLEDMAT_COL_4,HIGH);
	GPIO_VoidSetPinValue(HLEDMAT_COL_5,HIGH);
	GPIO_VoidSetPinValue(HLEDMAT_COL_6,HIGH);
	GPIO_VoidSetPinValue(HLEDMAT_COL_7,HIGH);
}


static void SetRowValues(u8 Copy_U8Value)
{
	 u8 Local_u8Bit;
	 Local_u8Bit = GET_BIT(Copy_U8Value,0);
	 GPIO_VoidSetPinValue(HLEDMAT_ROW_0,Local_u8Bit);
	 Local_u8Bit = GET_BIT(Copy_U8Value,1);
	 GPIO_VoidSetPinValue(HLEDMAT_ROW_1,Local_u8Bit);
	 Local_u8Bit = GET_BIT(Copy_U8Value,2);
	 GPIO_VoidSetPinValue(HLEDMAT_ROW_2,Local_u8Bit);
	 Local_u8Bit = GET_BIT(Copy_U8Value,3);
	 GPIO_VoidSetPinValue(HLEDMAT_ROW_3,Local_u8Bit);
	 Local_u8Bit = GET_BIT(Copy_U8Value,4);
	 GPIO_VoidSetPinValue(HLEDMAT_ROW_4,Local_u8Bit);
	 Local_u8Bit = GET_BIT(Copy_U8Value,5);
	 GPIO_VoidSetPinValue(HLEDMAT_ROW_5,Local_u8Bit);
	 Local_u8Bit = GET_BIT(Copy_U8Value,6);
	 GPIO_VoidSetPinValue(HLEDMAT_ROW_6,Local_u8Bit);
	 Local_u8Bit = GET_BIT(Copy_U8Value,7);
	 GPIO_VoidSetPinValue(HLEDMAT_ROW_7,Local_u8Bit);
}
