/*
 * LEDMXD.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: kcsstore.com
 */

#include "LSTD_TYPES.h"
#include "GPIO_Interface.h"
#include "LEDMXD.h"
#include "SysTick_Interface.h"



GPIO_Pin_Initialization Rowx[LEDMXD_No_Rows] = {{LEDMXD_Row_Zero_Port,LEDMXD_Row_Zero_Pin,GPO_Push_Pull_2MHZ_Speed},
		                                        {LEDMXD_Row_One_Port,LEDMXD_Row_One_Pin,GPO_Push_Pull_2MHZ_Speed},
												{LEDMXD_Row_Two_Port,LEDMXD_Row_Two_Pin,GPO_Push_Pull_2MHZ_Speed},
												{LEDMXD_Row_Three_Port,LEDMXD_Row_Three_Pin,GPO_Push_Pull_2MHZ_Speed},
												{LEDMXD_Row_Four_Port,LEDMXD_Row_Four_Pin,GPO_Push_Pull_2MHZ_Speed},
												{LEDMXD_Row_Five_Port,LEDMXD_Row_Five_Pin,GPO_Push_Pull_2MHZ_Speed},
												{LEDMXD_Row_Six_Port,LEDMXD_Row_Six_Pin,GPO_Push_Pull_2MHZ_Speed},
												{LEDMXD_Row_Seven_Port,LEDMXD_Row_Seven_Pin,GPO_Push_Pull_2MHZ_Speed}};




GPIO_Pin_Initialization Columnx[LEDMXD_No_Columns] = {{LEDMXD_Column_Zero_Port,LEDMXD_Column_Zero_Pin,GPO_Push_Pull_2MHZ_Speed},
													  {LEDMXD_Column_One_Port,LEDMXD_Column_One_Pin,GPO_Push_Pull_2MHZ_Speed},
													  {LEDMXD_Column_Two_Port,LEDMXD_Column_Two_Pin,GPO_Push_Pull_2MHZ_Speed},
													  {LEDMXD_Column_Three_Port,LEDMXD_Column_Three_Pin,GPO_Push_Pull_2MHZ_Speed},
													  {LEDMXD_Column_Four_Port,LEDMXD_Column_Four_Pin,GPO_Push_Pull_2MHZ_Speed},
													  {LEDMXD_Column_Five_Port,LEDMXD_Column_Five_Pin,GPO_Push_Pull_2MHZ_Speed},
													  {LEDMXD_Column_Six_Port,LEDMXD_Column_Six_Pin,GPO_Push_Pull_2MHZ_Speed},
													  {LEDMXD_Column_Seven_Port,LEDMXD_Column_Seven_Pin,GPO_Push_Pull_2MHZ_Speed}};




void __LEDMXD_Initialization__(void)
{
	u8 Loop;

	for(Loop = Null;Loop < LEDMXD_No_Row_Column;Loop++)
	{
		__GPIO_Set_Pin_Direction__(&Rowx[Loop]);
		__GPIO_Set_Pin_Direction__(&Columnx[Loop]);
		__GPIO_Write_Pin_LOW__(&Rowx[Loop]);
		__GPIO_Write_Pin_HIGH__(&Columnx[Loop]);
	}

}



void __LEDMXD_Disable_Columns__(void)
{
	u8 Loop;

	for(Loop = Null;Loop < LEDMXD_No_Row_Column;Loop++)
	{
		__GPIO_Write_Pin_HIGH__(&Columnx[Loop]);
	}

}


void __LEDMXD_Disable_Rows__(void)
{
	u8 Loop;

	for(Loop = Null;Loop < LEDMXD_No_Row_Column;Loop++)
	{
		__GPIO_Write_Pin_LOW__(&Rowx[Loop]);
	}

}




void __LEDMXD_Display__(u8 *Character)
{

	u8 Loop;

	for(Loop = Null;Loop < LEDMXD_No_Rows;Loop++)
	{
		/* Set Rows  */
		__LEDMXD_Set_Rows__(&Character[Loop]);

		/* Enable Column */
		__GPIO_Write_Pin_LOW__(&Columnx[Loop]);


		/* Delay  */
		__SysTick_Delay__(2.5);

		/* Disable Column  */
		__GPIO_Write_Pin_HIGH__(&Columnx[Loop]);

	}


}


void __LEDMXD_Set_Rows__(u8 *Row)
{

	u8 Check_Array[LEDMXD_No_Rows] = {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
	u8 Loop;

	for(Loop = Null;Loop < LEDMXD_No_Rows;Loop++)
	{
		if((Check_Array[Loop] & *Row))
		{
			__GPIO_Write_Pin_HIGH__(&Rowx[Loop]);
		}
		else
		{
			__GPIO_Write_Pin_LOW__(&Rowx[Loop]);
		}

	}

}


