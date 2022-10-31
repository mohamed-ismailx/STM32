/*
 * IR.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: kcsstore.com
 */

#include "LSTD_TYPES.h"
#include "GPIO_Interface.h"
#include "EXTI_Interface.h"
#include "SysTick_Interface.h"
#include "NVIC_Interface.h"
#include "Macros.h"
#include "IR.h"

GPIO_Pin_Configuration  RGBx[RGB_Pins] = {{GPIOA,IR_RGB_Blue_Pin,GPO_Push_Pull_2MHZ_Speed},
										  {GPIOA,IR_RGB_Green_Pin,GPO_Push_Pull_2MHZ_Speed},
										  {GPIOA,IR_RGB_Red_Pin,GPO_Push_Pull_2MHZ_Speed}};

EXTI_Configuration EXTI0_ENB = {EXTI_Line_Zero,EXTI_GPIOA,EXTI_Input_Floating,EXTI_Falling,&__IR_Get_Frame_By_EXTI__};



volatile u32 Frame_Data[Frame_Size] = {Null};
volatile u8 Frame_Counter = Null;
volatile u8 Start_Falling_Flag = Null;
volatile u8 FDatax = Null;


void __IR_RGB_Initialization__(void)
{

	u8 Loop;

	__NVIC_Enable_Interrupt_Peripheral__(NVIC_Position_EXTI0);

	__EXTI_Enable_Line__(&EXTI0_ENB);

	for(Loop = Null;Loop < RGB_Pins;Loop++)
	{
		__GPIO_Set_Pin_Direction__(&RGBx[Loop]);
	}

}



void __IR_RGB_Off__(void)
{

	u8 Loop;

	for(Loop = Null;Loop < RGB_Pins;Loop++)
	{
		__GPIO_Write_Pin_LOW__(&RGBx[Loop]);
	}

}


void __IR_RGB_Mix_Color__(u8 Color)
{

	switch(Color)
	{
		case IR_RGB_Red:
			__GPIO_Write_Pin_HIGH__(&RGBx[IR_RGB_Red]);
			break;

		case IR_RGB_Blue:
			__GPIO_Write_Pin_HIGH__(&RGBx[IR_RGB_Blue]);
			break;

		case IR_RGB_Green:
			__GPIO_Write_Pin_HIGH__(&RGBx[IR_RGB_Green]);
			break;

		case IR_RGB_Color_one:
			__GPIO_Write_Pin_HIGH__(&RGBx[IR_RGB_Green]);
			__GPIO_Write_Pin_HIGH__(&RGBx[IR_RGB_Blue]);
			break;

		case IR_RGB_Color_Two:
			__GPIO_Write_Pin_HIGH__(&RGBx[IR_RGB_Blue]);
			__GPIO_Write_Pin_HIGH__(&RGBx[IR_RGB_Red]);
			break;

		case IR_RGB_Color_Three:
			__GPIO_Write_Pin_HIGH__(&RGBx[IR_RGB_Green]);
			__GPIO_Write_Pin_HIGH__(&RGBx[IR_RGB_Red]);
			break;

		case IR_RGB_Color_Four:
			__GPIO_Write_Pin_HIGH__(&RGBx[IR_RGB_Blue]);
			__GPIO_Write_Pin_HIGH__(&RGBx[IR_RGB_Green]);
			__GPIO_Write_Pin_HIGH__(&RGBx[IR_RGB_Red]);
			break;


	}


}


void __IR_Get_Data_By_SysTick__(void)
{
	 u8 Counterx = Null;

	if((Frame_Data[Counterx] >= 10000) && (Frame_Data[Counterx + 17] <= 14000))   // Check Start
	{


		for(Counterx = Null;Counterx < 8;Counterx++)
		{

			if((Frame_Data[Counterx + 17] >= 980) && (Frame_Data[Counterx + 17] <= 1125))   // 0
			{
				Clear(FDatax,Counterx);
			}


			else if((Frame_Data[Counterx + 17] >= 2080) && (Frame_Data[Counterx + 17] <= 2250))  //  1
			{
				Set(FDatax,Counterx);
			}

		}
	}

	Frame_Counter = Null;
	Start_Falling_Flag = Null;
}



void __IR_Get_Frame_By_EXTI__(void)
{

	u32 Read_Elapsed_Time = Null;

	if(Start_Falling_Flag == Null)
	{
		__SysTick_Single_Mode__(500,SysTick_ms,&__IR_Get_Data_By_SysTick__);
		Start_Falling_Flag = 1;

	}
	else
	{
		__SysTick_Elapsed_Timer__(&Read_Elapsed_Time,SysTick_us);
		Frame_Data[Frame_Counter] = Read_Elapsed_Time;
		__SysTick_Single_Mode__(500,SysTick_ms,&__IR_Get_Data_By_SysTick__);
		Frame_Counter++;
	}

	__EXTI_Disable_Pending_Flag__(&EXTI0_ENB);

}


void __IR_RGB_Control__(void)
{

		switch (FDatax)
		{

			case IR_Off:
				__IR_RGB_Off__();
				__GPIO_Write_Pin_HIGH__(&RGBx[IR_RGB_Red]);
				break;

			case IR_Mode:
				__IR_RGB_Off__();
				__GPIO_Write_Pin_HIGH__(&RGBx[IR_RGB_Blue]);
				break;

			case IR_Mute:
				__IR_RGB_Off__();
				__GPIO_Write_Pin_HIGH__(&RGBx[IR_RGB_Green]);
				break;

			case IR_Play_Pause:
				__IR_RGB_Off__();
				__GPIO_Write_Pin_HIGH__(&RGBx[IR_RGB_Green]);
				__GPIO_Write_Pin_HIGH__(&RGBx[IR_RGB_Blue]);
				break;

			case IR_Previous:
				__IR_RGB_Off__();
				__GPIO_Write_Pin_HIGH__(&RGBx[IR_RGB_Blue]);
				__GPIO_Write_Pin_HIGH__(&RGBx[IR_RGB_Red]);
				break;

			case IR_Next:
				__IR_RGB_Off__();
				__GPIO_Write_Pin_HIGH__(&RGBx[IR_RGB_Green]);
				__GPIO_Write_Pin_HIGH__(&RGBx[IR_RGB_Red]);
				break;

			case IR_Low_Vol:
				__IR_RGB_Off__();
				__GPIO_Write_Pin_HIGH__(&RGBx[IR_RGB_Blue]);
				__GPIO_Write_Pin_HIGH__(&RGBx[IR_RGB_Green]);
				__GPIO_Write_Pin_HIGH__(&RGBx[IR_RGB_Red]);
				break;

			case IR_High_Vol:

				break;

			case IR_RPT:

				break;

			case IR_USD:

				break;

			case IR_Zero:

				break;

			case IR_One:

				break;

			case IR_Two:

				break;

			case IR_Three:

				break;

			case IR_Four:

				break;

			case IR_Five:

				break;

			case IR_Six:

				break;

			case IR_Seven:

				break;

			case IR_Eight:

				break;

			case IR_Nine:

				break;

			default:
	//			asm("NOP");
				break;
		}



}

