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
static volatile u32 SysTick_Ticks;



void __SysTick_Init__(void)
{
	SysTick->CTRL.Bits_Access.CLKSOURCE = SysTick_AHB_Per_8_Clk;

}


void __SysTick_Delay__(u32 Time_ms)
{

	SysTick->LOAD.Bits_Access.RELOAD = ((Time_ms * 0.001) / (0.000001));

	SysTick->CTRL.Bits_Access.ENABLE = Enable;

	while(SysTick->CTRL.Bits_Access.COUNTFLAG == Null);

	SysTick->CTRL.Bits_Access.ENABLE = Disable;

	SysTick->VAL.Bits_Access.CURRENT = Null;

	SysTick->LOAD.Bits_Access.RELOAD = Null;

}



u8 __SysTick_Single_Mode__(u32 Time_ms,void (*SysTick_ptr)(void))
{

	u8 Execution_State = Execution_Correct;

	if(SysTick_ptr != NULL)
	{
		SysTick_Ticks = ((Time_ms * 0.001) / (0.000001));
		SysTick_Set_Call_Back_ptr = SysTick_ptr;
		SysTick->CTRL.Bits_Access.TICKINT = Enable;
		SysTick->VAL.Bits_Access.CURRENT = Null;
		SysTick->LOAD.Bits_Access.RELOAD = ((Time_ms * 0.001) / (0.000001));
		SysTick->CTRL.Bits_Access.ENABLE = Enable;

	}

	else
		Execution_State = Execution_Error;


	return Execution_State;
}



u8 __SysTick_Mult_Shot_Timer__(u32 Time_ms,void (*SysTick_ptr)(void))
{

	u8 Execution_State = Execution_Correct;

	if(SysTick_ptr != NULL)
	{
		SysTick_Ticks = ((Time_ms * 0.001) / (0.000001));
		SysTick->CTRL.Bits_Access.TICKINT = Enable;
		SysTick_Set_Call_Back_ptr = SysTick_ptr;
		SysTick->VAL.Bits_Access.CURRENT = Null;
		SysTick->LOAD.Bits_Access.RELOAD = ((Time_ms * 0.001) / (0.000001));
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
	SysTick->CTRL.Bits_Access.ENABLE = Disable;
}



u8 __SysTick_Elapsed_Timer__(u32 *Elapsed_Time)
{

	u8 Execution_State = Execution_Correct;

	if(Elapsed_Time != NULL)
	{

		*Elapsed_Time = (SysTick_Ticks) - (SysTick->VAL.Bits_Access.CURRENT);

	}

	else
		Execution_State = Execution_Error;


	return Execution_State;

}





u8 __SysTick_Remaining_Timer__(u32 *Remaining_Time)
{

	u8 Execution_State = Execution_Correct;

	if(Remaining_Time != NULL)
	{

		*Remaining_Time = SysTick->VAL.Bits_Access.CURRENT;

	}

	else
		Execution_State = Execution_Error;


	return Execution_State;

}


//
//void SysTick_Handler(void)     //Mult Shot
//{
//
//	SysTick_Set_Call_Back_ptr();
//
////	SysTick->CTRL.Bits_Access.TICKINT = Disable;
////	SysTick->VAL.Bits_Access.CURRENT = Null;
////	SysTick->LOAD.Bits_Access.RELOAD = Null;
////	SysTick->CTRL.Bits_Access.ENABLE = Disable;
//
//
//}


void SysTick_Handler(void)     //single shot
{

	SysTick_Set_Call_Back_ptr();
	SysTick->CTRL.Bits_Access.TICKINT = Disable;
	SysTick->VAL.Bits_Access.CURRENT = Null;
	SysTick->LOAD.Bits_Access.RELOAD = Null;
	SysTick->CTRL.Bits_Access.ENABLE = Disable;


}
