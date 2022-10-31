/*
 * SysTick_Program.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: kcsstore.com
 */
#include "LSTD_TYPES.h"
#include "stm32f103xx.h"
#include "SysTick_Interface.h"
#include "Macros.h"


static void(*SysTick_Set_Call_Back_ptr)(void);

static volatile u8 SysTick_Flag = Disable;

void __SysTick_Initialization__(void)
{
	SysTick->CTRL.Bits_Access.CLKSOURCE = SysTick_AHB_Per_8_Clk;

}


u8 __SysTick_Delay__(u32 Time,u8 Time_Scale)
{

	u8 Execution_State = Execution_Correct;

	switch(Time_Scale)
	{
		case SysTick_us:
			SysTick->LOAD.Bits_Access.RELOAD = Time;
			break;

		case SysTick_ms:
			SysTick->LOAD.Bits_Access.RELOAD = ((Time * 0.001) / (0.000001));
			break;

		default:
			Execution_State = Execution_Error;
			break;
	}

	SysTick->CTRL.Bits_Access.ENABLE = Enable;

	while(SysTick->CTRL.Bits_Access.COUNTFLAG == Null);

	SysTick->CTRL.Bits_Access.ENABLE = Disable;

	SysTick->VAL.Bits_Access.CURRENT = Null;

	SysTick->LOAD.Bits_Access.RELOAD = Null;

	return Execution_State;

}



u8 __SysTick_Single_Mode__(u32 Time,u8 Time_Scale,void (*SysTick_ptr)(void))
{

	u8 Execution_State = Execution_Correct;

	if((SysTick_ptr != NULL) && (SysTick_Flag == Disable))
	{

		switch(Time_Scale)
			{
				case SysTick_us:
					SysTick->LOAD.Bits_Access.RELOAD = Time;
					break;

				case SysTick_ms:
					SysTick->LOAD.Bits_Access.RELOAD = ((Time * 0.001) / (0.000001));
					break;

				default:
					Execution_State = Execution_Error;
					break;
			}

		SysTick->CTRL.Bits_Access.ENABLE = Enable;
		SysTick_Set_Call_Back_ptr = SysTick_ptr;
		SysTick->CTRL.Bits_Access.TICKINT = Enable;
		SysTick->VAL.Bits_Access.CURRENT = Null;
		SysTick_Flag = Enable;
	}

	else
		Execution_State = Execution_Error;


	return Execution_State;
}



u8 __SysTick_Mult_Shot_Timer__(u32 Time,u8 Time_Scale,void (*SysTick_ptr)(void))
{

	u8 Execution_State = Execution_Correct;

	if(SysTick_ptr != NULL)
	{

		switch(Time_Scale)
			{
				case SysTick_us:
					SysTick->LOAD.Bits_Access.RELOAD = Time - 1;
					break;

				case SysTick_ms:
					SysTick->LOAD.Bits_Access.RELOAD = (((Time * 0.001) / (0.000001)) - 1);
					break;

				default:
					Execution_State = Execution_Error;
					break;
			}

		SysTick_Set_Call_Back_ptr = SysTick_ptr;
		SysTick->VAL.Bits_Access.CURRENT = Null;
		SysTick->CTRL.Bits_Access.TICKINT = Enable;
		SysTick->CTRL.Bits_Access.ENABLE = Enable;

	}

	else
		Execution_State = Execution_Error;


	return Execution_State;


}



void __SysTick_Stop_Timer__(void)
{
	SysTick->CTRL.Bits_Access.ENABLE = Disable;
}



void __SysTick_Start_Timer__(void)
{
	SysTick->CTRL.Bits_Access.ENABLE = Enable;
}




void __SysTick_Restart_Timer__(void)
{
	SysTick->VAL.Bits_Access.CURRENT = Null;
//	SysTick->CTRL.Bits_Access.ENABLE = Disable;
}



u8 __SysTick_Elapsed_Timer__(u32 *Elapsed_Time,u8 Time_Scale)
{

	u8 Execution_State = Execution_Correct;

	if(Elapsed_Time != NULL)
	{

		switch(Time_Scale)
				{
					case SysTick_us:
						*Elapsed_Time = SysTick->LOAD.Bits_Access.RELOAD - SysTick->VAL.Bits_Access.CURRENT;
						break;

					case SysTick_ms:
						*Elapsed_Time = (SysTick->LOAD.Bits_Access.RELOAD - SysTick->VAL.Bits_Access.CURRENT) / 100;
						break;

					default:
						Execution_State = Execution_Error;
						break;
				}
	}

	else
		Execution_State = Execution_Error;


	return Execution_State;

}





u8 __SysTick_Remaining_Timer__(u32 *Remaining_Time,u8 Time_Scale)
{

	u8 Execution_State = Execution_Correct;

	if(Remaining_Time != NULL)
	{

		switch(Time_Scale)
				{
					case SysTick_us:
						*Remaining_Time = SysTick->VAL.Bits_Access.CURRENT;
						break;

					case SysTick_ms:
						*Remaining_Time = SysTick->VAL.Bits_Access.CURRENT / 100;
						break;

					default:
						Execution_State = Execution_Error;
						break;
				}

	}

	else
		Execution_State = Execution_Error;


	return Execution_State;

}



//void SysTick_Handler(void)     //Mult Shot
//{
//
//	SysTick_Set_Call_Back_ptr();
//
//}


//
//
//void SysTick_Handler(void)     //single shot
//{
//
//	SysTick_Set_Call_Back_ptr();
//
//		SysTick->CTRL.Bits_Access.TICKINT = Disable;
//		SysTick->VAL.Bits_Access.CURRENT = Null;
//		SysTick->LOAD.Bits_Access.RELOAD = Null;
//		SysTick->CTRL.Bits_Access.ENABLE = Disable;
//
//
//}
//

void SysTick_Handler(void)     //single shot For DAC
{

	static volatile u16 DAC_Counter = Null;

	SysTick_Set_Call_Back_ptr();

	if(DAC_Counter == (9566))
	{
		SysTick_Flag = Disable;
		SysTick->CTRL.Bits_Access.TICKINT = Disable;
		SysTick->VAL.Bits_Access.CURRENT = Null;
		SysTick->LOAD.Bits_Access.RELOAD = Null;
		SysTick->CTRL.Bits_Access.ENABLE = Disable;


		DAC_Counter = Null;
	}
	DAC_Counter++;

}
